#pragma once
#include "LinkedList.h"
#include <exception>
#include <iostream>
using namespace std;

class Caja {
public:
    static LinkedList productos;

    static int ElegirCliente();

    static void caja();
};
