#include <vector>

#include "engine/elysium.h"
//#include "private/include/stack.h"
#include <iostream>

#define TOTAL_STACKS 39


const float default_scale = 5.0f;
const float stack_speed = 3.0f;

struct Stack{
	size_t id;
	float scale = default_scale;
	bool moving = true;
	float direction = 1.0f;
};


std::vector<std::shared_ptr<Texture>> textures;
std::vector<SceneObject> objects;
//static Stack stacks[TOTAL_STACKS];
static Stack stacks[TOTAL_STACKS];

static float current_scale = default_scale; // Scale used for the newest stack based on last scale
static float max_distance = 4.0f;
static float current_height = TOTAL_STACKS * 2.0f;
static float distance_between_stacks = 2.0f;

static bool clicked = false;
static bool clicked_last_frame = false;

static unsigned int score_user = 0;

static bool end_game = false;


bool MoveStack(int id_stack, double dt, Elysium& e, Input& in){

	clicked_last_frame = clicked;
	bool ret = false;
	

	int id_last = TOTAL_STACKS - 1;
	if(id_stack != 0){
		id_last = id_stack - 1;
	}
	
	Stack& stack = stacks[id_stack];
	Stack& stack_last = stacks[id_last];

	Transform* t = e.ecs.get_entity_component<Transform>(stack.id);
	Transform* t2 = e.ecs.get_entity_component<Transform>(stack_last.id);

	// Spawn con la escala del anterior
	t->scale_[0] = t2->scale_[0];

	// Check input
	if (in.isMouseButtonPressed("MOUSE LEFT")) {
		//printf("MOUSE LEFT\n");
		
		if (!clicked || !clicked_last_frame) {
			// Check only one click per time
			stack.moving = false;
			ret = true;
			clicked = true;
			score_user++;

			// Comprobar lo cerca que me he quedado
			// between default_distance
			printf("Position-> %f\n",t->position_[0]);

			// Margen de error para el perfect
			if (t->position_[0] < 0.1f && t->position_[0] > -0.1f) {
				printf("Perfect!\n");
			}else{
				// Pillo lo que me he pasado
				float abs = std::abs(t->position_[0]);
				t->scale_[0] -= abs;
				if (t->scale_[0] <= 0.0f) {
					t->scale_[0] = 0.0f;
					end_game = true;
				}
				t->position_[0] = 0.0f;
			}

			

		}
	}else {
		clicked = false;
	}

	// Check distance
	if (t->position_[0] >= max_distance) {
		stack.direction *= -1.0f;
		t->position_[0] = max_distance - 0.01f;
	}

	if (t->position_[0] <= (-max_distance)) {
		stack.direction *= -1.0f;
		t->position_[0] = (-max_distance) + 0.01f;
	}



	// Moving
	if (stack.moving) {
		t->position_[0] += (dt * stack.direction) * stack_speed;
	}

	
	printf("hola %f dt: %f\n", t->position_[0], dt);


	// Cuando detecte el click, dejar de mover al bicho, comprobar la posicion y aumentar el stack actual
	
	
	return ret;
}



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
	camera_pos.position_ = { 0.0f, ((float)TOTAL_STACKS * 2.0f) + 25.0f, 35.0f};
	camera_pos.rotation_ = { 0.0f, -0.6f, -1.0f };
	camera_pos.scale_ = { 1.0f, 1.0f, 1.0f };
	camera.setSpeedModify(10.0f);
	ely.ecs.set_entity_component_value(camera_entity, camera);
	ely.ecs.set_entity_component_value(camera_entity, camera_pos);
	

	
		
	for (int i = 0; i < TOTAL_STACKS; i++) {
		std::string path = "../assets/cube_textures/color";
		path += std::to_string(i);
		path += ".png";
		std::shared_ptr<Texture> texture = ely.resource.Load<Texture>(path.c_str());
		textures.push_back(texture);
	}

	// TOTAL_STACKS
	for (int i = 0; i < TOTAL_STACKS; i++) {
		auto brick = ely.ecs.add_entity();
		
		Stack s;
		s.id = brick;
		stacks[i] = s;

		Transform tr;
		tr.position_ = { 0.0f, (float)i * distance_between_stacks, 0.0f};
		tr.rotation_ = { 0.0f,0.0f,0.0f };
		tr.scale_ = { default_scale, 1.0f, default_scale };

	
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

	auto text_1 = ely.ecs.add_entity();
	UIText score("Score: ", 25.0f, 25.0f, 1.0f, { 0.1f,0.8f,0.1f });
	ely.ecs.set_entity_component_value(text_1, score);

	auto text_2 = ely.ecs.add_entity();
	UIText auxiliar2("", (1024.0f * 0.5f) - 250.0f, 400.0f, 1.3f, { 0.1f,1.0f,0.1f });
	ely.ecs.set_entity_component_value(text_2, auxiliar2);

	Light ambientlight(Light::Type::kAmbient_Light);
	auto ambient_entity = ely.ecs.add_entity();
	ely.ecs.set_entity_component_value(ambient_entity, ambientlight);

	Light directional_light(Light::Type::kDirectional_Light);
	directional_light.direction = glm::vec3(1.0f, -0.5f, -1.0f);
	directional_light.color = glm::vec3(0.5f, 0.5f, 0.5f);
	auto directional_entity = ely.ecs.add_entity();
	ely.ecs.set_entity_component_value(directional_entity, directional_light);


	Input input{w.get()};

	int current_stack = TOTAL_STACKS-1; // this must be between 0 and TOTAL_STACK
	double count = 0.0;
	unsigned int frame_count = 0;


	Transform* transform_cam = ely.ecs.get_entity_component<Transform>(camera_entity);
	while (!w.isDone()) {
		w.frame();

		ps.apply(ely.ecs);
		ely.cam.apply();
		ely.graph.apply();

		if (frame_count >= 20 && !end_game) {
			if (MoveStack(current_stack, w.getDeltaTime(), ely, input)) {
				current_stack++;
				current_stack %= TOTAL_STACKS;
				stacks[current_stack].moving = true;
				if (!end_game) {
					Transform* t = ely.ecs.get_entity_component<Transform>(stacks[current_stack].id);
					t->position_[1] = current_height;
				}
				current_height += distance_between_stacks;
				transform_cam->position_[1] += distance_between_stacks;
			}
		}else if(frame_count > 20){
			UIText* edit_text2 = ely.ecs.get_entity_component<UIText>(text_2);
			std::string text = "FINAL SCORE  " + std::to_string(score_user);
			edit_text2->text_ = text;
		}
		ely.cam.updateEditorCamera(w.getDeltaTime());


		UIText* edit_text2 = ely.ecs.get_entity_component<UIText>(text_1);
		std::string entityName = "Score: ";
		entityName += std::to_string(score_user);
		edit_text2->text_ = entityName;

		



		tex_sys.apply(ely.ecs, w);

		

		frame_count++;
		w.render();
	};

	return 0;
}