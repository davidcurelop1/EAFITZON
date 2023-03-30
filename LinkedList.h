#pragma once
#include <iostream>
#include <exception>
#include "Node.h"
using namespace std;

class LinkedList
{
public:
    Node* Head;
    Node* Tail;

    LinkedList()
    {
        Head = NULL;
        Tail = NULL;
    }

    void printList()
    {
        int i = 1;
        Node* current = Head;
        cout << "Estos son todos los productos\n-----------------------------------------\n";
        while (current != NULL)
        {
            cout << i << ": ";
            current->producto.printProducto();
            current = current->next;
            cout << "-----------------------------------------\n";
            i++;
        }
    }

    void printListSorted()
    {
        int i = 1;
        Node* current = Head;
        cout << "Estos son los productos de deporte\n-----------------------------------------\n";
        while (current != NULL)
        {
            if (current->producto.getTipo().compare("Deporte") == 0)
            {
                cout << i << ": ";
                current->producto.printProducto();
                i++;
            }
            current = current->next;
        }
        current = Head;
        cout << "Estos son los productos de tecnologia\n-----------------------------------------\n";
        while (current != NULL)
        {
            if (current->producto.getTipo().compare("Tecnologia") == 0)
            {
                cout << i << ": ";
                current->producto.printProducto();
                cout << "-----------------------------------------\n";
                i++;
            }
            current = current->next;
        }
        current = Head;
        cout << "Estos son los productos restantes\n-----------------------------------------\n";
        while (current != NULL)
        {
            if (current->producto.getTipo().compare("Tecnologia") != 0 && current->producto.getTipo().compare("Deporte") != 0)
            {
                cout << i << ": ";
                current->producto.printProducto();
                cout << "-----------------------------------------\n";
                i++;
            }
            current = current->next;
        }
    }

    Producto get(int index)
    {
        Node* current = Head;

        if (index < 0 || index > size())
        {
            // throw IndexOutOfBounds(index, size());
        }
        for (int i = 0; i < index && current != NULL; i++)
        {
            current = current->next;
        }
        return current->producto;
    }

    int size()
    {
        Node* current = Head;
        int n = 0;
        while (current != NULL)
        {
            n += 1;
            current = current->next;
        }
        return n;
    }

    void addElementEnd(Producto p)
    {
        Node* temp = new Node();
        temp->producto = p;
        temp->next = NULL;
        temp->previous = NULL;

        if (Head == NULL)
        {
            Head = temp;
            Tail = temp;
        }
        else
        {
            Tail->next = temp;
            temp->previous = Tail;
            Tail = temp;
        }
    }

    void set(int index, Producto p)
    {
        Node* current = Head;
        // try
        // {
        if (index < 0 || index > size())
        {
            // throw IndexOutOfBounds(index, size());
        }
        for (int i = 0; i < index && current != NULL; i++)
        {
            current = current->next;
        }
        current->producto = p;
        // }
        /* catch (IndexOutOfBounds &ex)
         {
             cout << ex.what();
         }*/
    }

    bool contains(Producto p)
    {
        Node* current = Head;
        while (current != NULL)
        {
            int id = current->producto.getId();
            if (id == p.getId())
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int index(int id)
    {
        Node* current = Head;
        int i = 0;

        while (current != NULL)
        {
            if (id == current->producto.getId())
            {
                return i;
            }
            current = current->next;
            i++;
        }
        return -1;
    }

    void eliminar(int index)
    {
        Node* current = Head;
        for (int i = 0; i < index && current != NULL; i++)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            if (current->previous != NULL)
            {
                current->previous->next = current->next;
            }
            else
            {
                Head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->previous = current->previous;
            }
        }
    }

    void addElementStart(Producto p)
    {
        Node* temp = new Node();
        temp->producto = p;
        temp->next = NULL;
        temp->previous = NULL;

        if (Head == NULL)
        {
            Head = temp;
            Tail = temp;
        }
        else
        {
            temp->next = Head;
            Head = temp;
        }
    }
};

