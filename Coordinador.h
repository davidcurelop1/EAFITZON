#pragma once
#include <iostream>
#include <exception>
#include <string>
#include "Producto.h"
#include "ProductoDeporte.h"
#include "ProductoTecnologia.h"
#include "ProductoExtranjero.h"
#include "Caja.h"
using namespace std;

class Coordinador
{
private:
    void AgregarArticulo()
    {
        string nombre;
        int id;
        float precio;
        int cantidad;
        string tipo;
        cout << "Ingrese nombre del articulo";
        cin >> nombre;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return AgregarArticulo();
        }
        cout << "Ingrese id del articulo";
        cin >> id;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return AgregarArticulo();
        }
        cout << "Ingrese precio del articulo";
        cin >> precio;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return AgregarArticulo();
        }
        cout << "Ingrese cantidad del articulo";
        cin >> cantidad;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return AgregarArticulo();
        }
        cout << "Ingrese el tipo del articulo";
        cin >> tipo;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return AgregarArticulo();
        }

        Producto prod = Producto(nombre, id, precio, cantidad, tipo);

        if (tipo.compare("Deporte") == 0)
        {
            prod = ProductoDeporte(nombre, id, precio, cantidad);
        }
        else if (tipo.compare("Tecnologia") == 0)
        {
            ProductoTecnologia prod = ProductoTecnologia(nombre, id, precio, cantidad);
        }
        else if (tipo.compare("Extranjero") == 0) {
            ProductoExtranjero prod = ProductoExtranjero(nombre, id, precio, cantidad);
        }

        if (Caja::productos.contains(prod) == false)
        {
            Caja::productos.addElementEnd(prod);
        }
        else
        {
            int index = Caja::productos.index(id);
            Producto oldProd = Caja::productos.get(index);
            int oldCantidad = oldProd.getCantidad();
            int newCantidad = oldCantidad + prod.getCantidad();
            oldProd.setCantidad(newCantidad);
            Caja::productos.set(index, oldProd);
        }
    }

    void atributoModificado(int id)
    {
        int index = Caja::productos.index(id);
        Producto oldProd = Caja::productos.get(index);
        int articulo;
        cout << "Que desea modificar?\n1. Nombre\n2. ID\n3. Precio\n4. Cantidad\n5. Tipo";
        cin >> articulo;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return atributoModificado(id);
        }

        if (articulo == 1)
        {
            cout << "Ingrese el nuevo nombre";
            cin.ignore(10, '\n');
            string nombre;
            getline(cin, nombre);
            oldProd.setNombre(nombre);
        }
        if (articulo == 2)
        {
            int ID;
            cout << "Ingrese el nuevo ID";
            cin >> ID;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                return atributoModificado(id);
            }
            oldProd.setId(ID);
        }
        if (articulo == 3)
        {
            int precio;
            cout << "Ingrese el nuevo precio";
            cin >> precio;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                return atributoModificado(id);
            }
            oldProd.setPrecio(precio);
        }
        if (articulo == 4)
        {
            int cantidad;
            cout << "Ingrese la nueva cantidad";
            cin >> cantidad;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                return atributoModificado(id);
            }
            oldProd.setCantidad(cantidad);
        }
        if (articulo == 5)
        {
            cout << "Ingrese el nuevo tipo";
            cin.ignore(10, '\n');
            string tipo;
            getline(cin, tipo);
            oldProd.setTipo(tipo);
        }
        string modificarOtro;
        cout << "Si desea modificar otro dato ingrese 1\nSi no desea modificar mas ingrese cualquier tecla\n";
        cin >> modificarOtro;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return atributoModificado(id);
        }
        Caja::productos.set(index, oldProd);
        if (modificarOtro.compare("1") == 0)
        {
            atributoModificado(id);
        }
    }

    void modificarArticulo()
    {
        int id;
        cout << "Ingrese el id:\n";
        cin >> id;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return modificarArticulo();
        }
        atributoModificado(id);
    }

    void articuloEliminar(int id)
    {
        int index = Caja::productos.index(id);

        if (index >= 0 && Caja::productos.contains(Caja::productos.get(index)) == true)
        {
            Producto prod = Caja::productos.get(index);
            Caja::productos.eliminar(index);
        }
        else
        {
            cout << "Ese id no existe, ingrese otro id\n";
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                return articuloEliminar(id);
            }
            articuloEliminar(id);
        }
    }

    void eliminarArticulo()
    {
        int id;
        cout << "Ingrese el id:\n";
        cin >> id;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return articuloEliminar(id);
        }
        articuloEliminar(id);
    }

public:
    void MenuCoordinador()
    {
        int input = 0;
        while (input != 4)
        {
            cout << "Que desea hacer?\n1. Agregar articulo\n2. Modificar articulo\n3. Eliminar articulo\n4. Salir\n";
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                return MenuCoordinador();
            }

            if (input == 1)
            {
                AgregarArticulo();
                Caja::productos.printList();
            }
            if (input == 2)
            {
                modificarArticulo();
            }
            if (input == 3)
            {
                eliminarArticulo();
            }
            if (input == 5)
            {
                Caja::productos.printList();
            }
        }
    }
};
