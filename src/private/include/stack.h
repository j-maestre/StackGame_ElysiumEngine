#pragma once
#include "engine/elysium.h"


class Stack{

    public:

        Stack();
        Stack(size_t entity);
        ~Stack();
        Stack(const Stack&);
        Stack(Stack&&);

        Stack& operator=(const Stack& other);
    private:
    size_t m_entity;
};