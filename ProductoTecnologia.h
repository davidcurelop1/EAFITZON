#pragma once
#include "Producto.h"

class ProductoTecnologia : public Producto {
public:
    ProductoTecnologia(string nombre, int id, float precio, int cantidad) {
        this->nombre = nombre;
        this->id = id;
        this->precio = precio;
        this->cantidad = cantidad;
        this->tipo = "Tecnologia";
    }

    float getPrecio()
    {
        return this->precio;
    }
};
