#include <vector>

#include "engine/elysium.h"
#include "private/include/stack.h"

#define TOTAL_STACKS 39

int main(int, char**) {

	Engine e;

	auto maybe_w = Window::create(e, 1024, 768, "Banjo Game");

	if (!maybe_w.has_value()) { return -1; }
	auto& w = maybe_w.value();

	PhongSystem ps;

	Elysium ely(&w);

	std::unique_ptr<char> buffer_tex_fs = ReadFile("../assets/text_shader.fs");
	std::unique_ptr<char> buffer_tex_vs = ReadFile("../assets/text_shader.vs");

	auto maybe_tex_vs = Shader::create(Shader::kType_Vertex, buffer_tex_vs.get(), (unsigned int)strlen(buffer_tex_vs.get()));
	auto maybe_tex_fs = Shader::create(Shader::kType_Fragment, buffer_tex_fs.get(), (unsigned int)strlen(buffer_tex_fs.get()));

	if (!maybe_tex_fs.has_value() || !maybe_tex_vs.has_value()) { return -1; }

	TextSystem tex_sys(maybe_tex_vs.value(), maybe_tex_fs.value(), "../assets/NunitoSans.ttf");

	Primitives primitive(&ely.resource);
	ely.ecs.add_component_class<UIText>();

	auto camera_entity = ely.ecs.add_entity();
	Camera camera(camera_entity, w, true);
	Transform camera_pos;
	camera_pos.position_ = { 0.0f, 25.0f, 35.0f };
	camera_pos.rotation_ = { 0.0f, -0.6f, -1.0f };
	camera_pos.scale_ = { 1.0f, 1.0f, 1.0f };
	camera.setSpeedModify(10.0f);
	ely.ecs.set_entity_component_value(camera_entity, camera);
	ely.ecs.set_entity_component_value(camera_entity, camera_pos);
	

	std::vector<std::shared_ptr<Texture>> textures;
	std::vector<SceneObject> objects;
	Stack stacks[TOTAL_STACKS];

	for (int i = 0; i < 3; i++) {
		std::string path{ "../assets/cube_textures/color" };
		path += std::to_string(i);
		path += ".png";

		printf("Path-> %s\n", path.c_str());

		std::shared_ptr<Texture> texture = ely.resource.Load<Texture>(path.c_str());
		textures.push_back(texture);
	}	

	// TOTAL_STACKS
	for (int i = 0; i < 3; i++) {
		auto brick = ely.ecs.add_entity();
		Transform tr;
		tr.position_ = { 0.0f, (float)i * 2.0f, 0.0f};
		tr.rotation_ = { 0.0f,0.0f,0.0f };
		tr.scale_ = { 5.0f, 1.0f, 5.0f };

	
		//std::shared_ptr<Texture> texture = std::make_shared<Texture>(Texture{path.c_str()});
		//Texture texture{"../assets/cube_textures/color0.png"};

		SceneObject cube_first(primitive.getCube(), textures[i], brick);
		objects.push_back(cube_first);

		ely.ecs.set_entity_component_value(brick, cube_first);
		ely.ecs.set_entity_component_value(brick, tr);
		//Stack s{brick};
		//stacks[0] = s;
	}
	

	//std::shared_ptr<Geometry> cube = primitive.getCube();	

	//auto text_1 = ely.ecs.add_entity();
	//UIText auxiliar("Jumps: ", 25.0f, 25.0f, 1.0f, { 0.5f,0.8f,0.2f });
	//ely.ecs.set_entity_component_value(text_1, auxiliar);

	//auto text_2 = ely.ecs.add_entity();
	//UIText auxiliar2("", 400.0f, 400.0f, 1.0f, { 1.0f,0.0f,0.0f });
	//ely.ecs.set_entity_component_value(text_2, auxiliar2);

	Light ambientlight(Light::Type::kAmbient_Light);
	auto ambient_entity = ely.ecs.add_entity();
	ely.ecs.set_entity_component_value(ambient_entity, ambientlight);

	Light directional_light(Light::Type::kDirectional_Light);
	directional_light.direction = glm::vec3(1.0f, -0.5f, -1.0f);
	directional_light.color = glm::vec3(0.5f, 0.5f, 0.5f);
	auto directional_entity = ely.ecs.add_entity();
	ely.ecs.set_entity_component_value(directional_entity, directional_light);


	while (!w.isDone()) {
		w.frame();

		ps.apply(ely.ecs);
		ely.cam.apply();
		ely.graph.apply();
		ely.cam.updateEditorCamera(w.getDeltaTime());

		
        
		w.render();
	};

	return 0;
}