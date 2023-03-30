#pragma once
#include "Producto.h"

class ProductoExtranjero : public Producto {
public:
    float impuesto = 0.10;
    ProductoExtranjero(string nombre, int id, float precio, int cantidad) {
        this->nombre = nombre;
        this->id = id;
        this->precio = precio;
        this->cantidad = cantidad;
        this->tipo = "Extranjero";
    }

    virtual float getPrecio() override{
        return (this->precio + (this->precio * this->impuesto));
    }
};
