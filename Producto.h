#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Producto
{
protected:
    string nombre;
    int id;
    float precio;
    int cantidad;
    string tipo;
    float precioDescontado = precio;

public:
    Producto(string nombre, int id, float precio, int cantidad, string tipo)
    {
        this->nombre = nombre;
        this->id = id;
        this->precio = precio;
        this->cantidad = cantidad;
        this->tipo = tipo;
    }

    Producto()
    {
        this->nombre = "------";
        this->id = 0;
        this->precio = 0;
        this->cantidad = 0;
        this->tipo = "------";
    }

    virtual float getPrecio()
    {
        if (this->tipo.compare("Extranjero") == 0) {
            return (this->precio + (this->precio * 0.10));
        }else {
            return this->precio;
        }
    }

    string getNombre()
    {
        
        return this->nombre;
    }

    int getId()
    {
        return this->id;
    }

    int getCantidad()
    {
        return this->cantidad;
    }

    string getTipo()
    {
        return this->tipo;
    }

    void setPrecio(float p)
    {
        this->precio = p;
    }

    void setNombre(string n)
    {
        this->nombre = n;
    }

    void setId(int i)
    {
        this->id = i;
    }

    void setCantidad(int c)
    {
        this->cantidad = c;
    }

    void setTipo(string t)
    {
        this->tipo = t;
    }

    void printProducto()
    {
        cout << "Nombre: " << this->nombre << "\nPrecio: " << this->precio << "\nID: " << this->id << "\nCantidad: " << cantidad << "\nTipo: " << tipo << endl;
    }
};
