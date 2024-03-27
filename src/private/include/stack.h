#pragma once
#include "engine/elysium.h"


class Stack{

    public:
        Stack(Primitives& p, Elysium& e, int index);
        ~Stack();
        Stack(const Stack&) = delete;
        Stack(Stack&&) = delete;

    private:

    std::shared_ptr<Texture> m_texture;
};