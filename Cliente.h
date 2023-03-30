#pragma once
#include <iostream>
#include <exception>
#include "LinkedList.h"
#include "Producto.h"
#include "Caja.h"
using namespace std;


class Cliente
{
public:
    void MenuCliente()
    {
        int input = 0;
        while (input != 4)
        {
            cout << "Que desea hacer?\n1. Comprar articulo\n2. Pagar\n3. Mostrar carrito\n4. Salir\n";
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                return MenuCliente();
            }
            if (input == 1)
            {
                comprarArticulo();
            }
            if (input == 2)
            {
                pagar();
            }
            if (input == 3)
            {
                mostrarCarrito();
            }
        }
    }

private:
    LinkedList carrito = LinkedList();

    void checkCantidadProducto(int index)
    {
        Producto prodCheck = Caja::productos.get(index);
        if (prodCheck.getCantidad() <= 0)
        {
            Caja::productos.eliminar(index);
        }
    }

    void comprarArticulo()
    {
        cout << "Estos son los articulos disponibles:\n";
        Caja::productos.printListSorted();
        int idEscogido;
        cout << "Ingrese el ID de el producto que desea comprar:\n";
        cin >> idEscogido;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return comprarArticulo();
        }
        int index = Caja::productos.index(idEscogido);
        if (index == -1)
        {
            cout << "Ese ID no existe, elija uno de la lista\n";
            comprarArticulo();
        }
        else
        {
            Producto tempProduct = Caja::productos.get(index);
            if (carrito.contains(tempProduct))
            {
                Producto productosProd = tempProduct;
                productosProd.setCantidad(productosProd.getCantidad() - 1);
                Caja::productos.set(index, productosProd);
                int oldIndex = carrito.index(idEscogido);
                Producto oldProd = carrito.get(oldIndex);
                oldProd.setCantidad(oldProd.getCantidad() + 1);
                carrito.set(oldIndex, oldProd);
                int continuar;
                cout << "Ingrese 1 si desea continuar, de lo contrario ingrese cualquier otro numero\n";
                cin >> continuar;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                    return comprarArticulo();
                }
                checkCantidadProducto(index);
                if (continuar == 1)
                {
                    comprarArticulo();
                }
            }
            else
            {
                Producto productosProd = tempProduct;
                productosProd.setCantidad(productosProd.getCantidad() - 1);
                Caja::productos.set(index, productosProd);
                tempProduct.setCantidad(1);
                carrito.addElementEnd(tempProduct);
                int continuar;
                checkCantidadProducto(index);
                cout << "Ingrese 1 si desea continuar, de lo contrario ingrese cualquier otro numero\n";
                cin >> continuar;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
                    return comprarArticulo();
                }
                if (continuar == 1)
                {
                    comprarArticulo();
                }
            }
        }
    }

    void mostrarCarrito()
    {
        carrito.printList();
    }

    int getPrecioTotal()
    {
        Node* current = carrito.Head;
        int total = 0;
        while (current != NULL)
        {
            total += current->producto.getCantidad() * current->producto.getPrecio();
            current = current->next;
        }
        return total;
    }

    float getPrecioDescuento()
    {
        Node* current = carrito.Head;
        Producto* prod = &current->producto;
        float total = 0;
        while (current != NULL)
        {
            cout << prod->getPrecio();
            if (current->producto.getCantidad() > 1) {
                total += (current->producto.getCantidad() * prod->getPrecio()) - (current->producto.getCantidad() * prod->getPrecio() * 0.10);
            }
            else
            {
                total += current->producto.getCantidad() * current->producto.getPrecio();
            }
            current = current->next;
        }
        return total;
    }

    void cancelarCompra()
    {
        Node* currentCarrito = carrito.Head;
        while (currentCarrito != NULL)
        {
            if (Caja::productos.contains(currentCarrito->producto))
            {
                int id = currentCarrito->producto.getId();
                int index = Caja::productos.index(id);
                Producto tempProducto = Caja::productos.get(index);
                tempProducto.setCantidad(tempProducto.getCantidad() + currentCarrito->producto.getCantidad());
                Caja::productos.set(index, tempProducto);
            }
            else
            {
                Caja::productos.addElementEnd(currentCarrito->producto);
            }
            currentCarrito = currentCarrito->next;
        }
        carrito = LinkedList();
    }

    void pagar()
    {
        cout << "El precio sin descuento es: " << getPrecioTotal() << "\nEl precio total es: " << getPrecioDescuento() << "\nSi desea continuar ingrese Y de lo contrario ingrese N\n";
        string respuesta;
        cin >> respuesta;
        if (respuesta.compare("Y") == 0 || respuesta.compare("y") == 0)
        {
            cout << "Pago exitoso\n";
            carrito = LinkedList();
        }
        if (respuesta.compare("N") == 0 || respuesta.compare("n") == 0)
        {
            cancelarCompra();
            cout << "Compra cancelada\n";
        }
    }
};
