#include "private/include/stack.h"
#include <stdio.h>

Stack::Stack(Primitives& p, Elysium& ely, int index){
    auto player = ely.ecs.add_entity();
    Transform tr;
	tr.position_ = { 0.0f, 0.0f, 0.0f };
	tr.rotation_ = { 0.0f,0.0f,0.0f };
	tr.scale_ = { 5.0f, 1.0f, 5.0f };
    
    std::string path("../assets/cube_textures/color");
    path += std::to_string(index);
    path += ".png";

    printf("PATH-> %s\n", path.c_str());


	m_texture = ely.resource.Load<Texture>(path.c_str());
	SceneObject cube_first(p.getCube(), m_texture, player);
	ely.ecs.set_entity_component_value(player, cube_first);
	ely.ecs.set_entity_component_value(player, tr);
}

Stack::~Stack(){}