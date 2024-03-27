#version 330

out vec4 FragColor;

in vec2 Uv;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedoSpec;
uniform sampler2D u_shadow_map[6];
uniform mat4 u_light_space[6];
uniform vec3 u_camera_position;

vec3 FragPos;
vec3 Normal;
vec3 Diffuse;
vec4 FragPosLightSpace[6];

struct Light{
  vec3 position;
  vec3 attenuation;
  vec3 direction;
  vec3 color;

  int type;

  float cut_off;
  float outer_cut_off;

  float strength;

  vec3 diffuse;
  vec3 specular;
};

uniform Light light;

Light CalcLight(vec3 light_direction, vec3 light_color){
    vec3 viewDir = normalize(u_camera_position - FragPos);
    Light light;

    float diff = max(dot(Normal, light_direction),0.0);
    light.diffuse = diff * light_color * Diffuse;

    vec3 reflectDir = reflect(-light_direction, Normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);

    light.specular = 0.5 * spec * vec3(1.0, 1.0, 1.0) * Diffuse;

    return light;
}

vec3 CalcPointLight(vec3 light_position, vec3 light_color, vec3 light_attenuation){
    vec3 lightDir  = light_position - FragPos;
    float distance = length(lightDir);
    lightDir = normalize(lightDir);
    Light light = CalcLight(lightDir, light_color);

    float k0 = light_attenuation.x; // constant light_attenuation
    float k1 = light_attenuation.y; // linear light_attenuation
    float k2 = light_attenuation.z; // cuadratic light_attenuation

    float attenuationAmount = 1.0 / (k0 + (k1*distance) + k2 * (distance*distance));

    light.diffuse *= attenuationAmount;
    light.specular *= attenuationAmount;

    return light.diffuse + light.specular;
}

vec3 CalcSpotLight(vec3 light_position, vec3 light_direction, vec3 light_color, vec3 light_attenuation, float cut_off, float outer_cut_off){

    vec3 lightDir  = normalize(light_position - FragPos);
    cut_off = cos(cut_off * 3.1415/180.0);
    outer_cut_off = cos(outer_cut_off * 3.1415/180.0);
    Light light = CalcLight(lightDir, light_color);

    float distance = length(light_position - FragPos);

    float k0 = light_attenuation.x; // constant light_attenuation
    float k1 = light_attenuation.y; // linear light_attenuation
    float k2 = light_attenuation.z; // cuadratic light_attenuation

    float attenuationAmount = 1.0 / (k0 + (k1*distance) + k2* (distance*distance));
    light.diffuse *= attenuationAmount ;
    light.specular *= attenuationAmount;
    float theta = dot(lightDir,normalize(-light_direction));//0.5

    float epsilon = (cut_off - outer_cut_off); // 0.9978 - 0.953 /
    float intensity = clamp((theta - outer_cut_off) / epsilon, 0.0, 1.0); //  0.5 - 0.953 / 0.9978 - 0.953
    light.diffuse  *= intensity;
    light.specular *= intensity;

    return light.diffuse + light.specular;
}

vec3 CalcDirectionalLight(vec3 light_direction, vec3 light_color){

    vec3 lightDir = normalize(-light_direction); // need to be checked

    float diff = max(dot(Normal, lightDir), 0.0);
    vec3 diffuse = diff * light_color * Diffuse;


    vec3 viewDir = normalize(u_camera_position - FragPos);

    vec3 reflectDir = reflect(-lightDir, Normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);

    vec3 specular = 0.5 * spec * vec3(1.0, 1.0, 1.0) * Diffuse;

    return diffuse + specular;
}

float ShadowCalculation(vec4 fragPosLightSpace, vec3 light_position, sampler2D shadow_texture)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;

    // transform to [0,1] range
    projCoords = (projCoords * 0.5 + 0.5);

    if (projCoords.x >= 1.0 || projCoords.x <= 0.0 ||
        projCoords.y >= 1.0 || projCoords.y <= 0.0){
        return 0.0;
    }

    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadow_texture, projCoords.xy).r;
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(Normal);
    vec3 lightDir = normalize(light_position - FragPos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
    // check whether current frag pos is in shadow
    // float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
    // PCF
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadow_texture, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadow_texture, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;
        }
    }
    shadow /= 9.0;

    // keep the shadow at 0.0 when outside the far_plane region of the light's frustum.
    if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}

void main(){
  FragPos = texture(gPosition, Uv).rgb;
  Normal = texture(gNormal, Uv).rgb;
  Diffuse = texture(gAlbedoSpec, Uv).rgb;

  for(int i = 0; i < 6; ++i){
    FragPosLightSpace[i] = u_light_space[i] * vec4(FragPos, 1.0);
  }

  vec3 result;
  float shadow = 0.0;

  if (light.type == 0){ // point light
    result += CalcPointLight(light.position, light.color, light.attenuation);
    for (int i = 0; i < 6; i++){
      shadow += ShadowCalculation(FragPosLightSpace[i], light.position, u_shadow_map[i]);
    }
  }
  else if (light.type == 1){ // spotlight
    result += CalcSpotLight(light.position, light.direction, light.color, light.attenuation, light.cut_off, light.outer_cut_off);
    shadow += ShadowCalculation(FragPosLightSpace[0], light.position, u_shadow_map[0]);
  }
  else if (light.type == 2){ // directional light
    result += CalcDirectionalLight(light.direction, light.color);
    shadow += ShadowCalculation(FragPosLightSpace[0], light.position, u_shadow_map[0]);
  }
  else if (light.type == 3){ // ambient light
    result += light.strength * light.color * Diffuse;
  }

  result = ((1.0 - shadow) * result);
  FragColor = vec4(result, 1.0);
}
