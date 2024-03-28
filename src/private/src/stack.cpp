#include "private/include/stack.h"
#include <stdio.h>

Stack::Stack() {
    m_entity = -1;
}

Stack::Stack(size_t entity){
    m_entity = entity;
}

Stack::Stack(const Stack& other){
    this->m_entity = other.m_entity;
}

Stack::Stack(Stack&& other) {
    this->m_entity = other.m_entity;
}

Stack& Stack::operator=(const Stack& other) {
    this->m_entity = other.m_entity;
    return *this;
}

Stack::~Stack(){}