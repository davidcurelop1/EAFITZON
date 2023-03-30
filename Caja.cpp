#pragma once
#include "Cliente.h"
#include "Coordinador.h"
#include "LinkedList.h"
#include <exception>
#include <iostream>
using namespace std;


    int Caja::ElegirCliente() 
        {
        cout << "Elija el tipo de usuario: \n1. Cliente\n2. Coordinador\n";
        int cliente;
        cin >> cliente;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Entrada no valida. Por favor ingrese un valor entero." << endl;
            return ElegirCliente();
        }
        if (cliente == 1 || cliente == 2) {
            return cliente;
        }
        else {
            ElegirCliente();
        }
        return ElegirCliente();
    }

    void Caja::caja() {

        int cliente = ElegirCliente();
        Cliente usuario;
        Coordinador coord;

        if (cliente == 1) {
            usuario.MenuCliente();
        }
        if (cliente == 2) {
            coord.MenuCoordinador();
        }
    }

    LinkedList Caja::productos;