#pragma once
#include "Producto.h"

class ProductoDeporte : public Producto {
public:
    ProductoDeporte(string nombre, int id, float precio, int cantidad) {
        this->nombre = nombre;
        this->id = id;
        this->precio = precio;
        this->cantidad = cantidad;
        this->tipo = "Deporte";
    }


    float getPrecio()
    {
        return 102030;
    }
};