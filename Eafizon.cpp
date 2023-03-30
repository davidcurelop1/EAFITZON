// Eafizon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Caja.h"
#include "Producto.h"
#include "ProductoDeporte.h"
#include "ProductoTecnologia.h"
#include "ProductoExtranjero.h"

int main()
{
    ProductoExtranjero prod1 = ProductoExtranjero("Extranjero", 1, 2000, 10);
    ProductoTecnologia prod2 = ProductoTecnologia("Tecnologia", 2, 2000, 10);
    ProductoDeporte prod3 = ProductoDeporte("Deporte", 3, 2000, 10);
    Caja::productos.addElementEnd(prod1);
    Caja::productos.addElementEnd(prod2);
    Caja::productos.addElementEnd(prod3);
    cout << prod1.getPrecio();
    while (true)
    {
        Caja::caja();
    }
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
