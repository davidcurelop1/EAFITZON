#pragma once
#pragma once
#include "Producto.h"

class Node
{
public:
    Producto producto;
    Node* next = NULL;
    Node* previous = NULL;
};