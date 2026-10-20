#include <iostream>

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "pizzeria.h"

using namespace std;

class Nodo
{
private:
    Pedido valor;
    Nodo *siguiente;
    friend class Pila;
public:
// Declaración del constructor del Nodo
    Nodo(Pedido v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

class Pila
{
private:
    pNodo cima;
public:
    Pila(); // Declaración de Constructor y Destructor
    ~Pila();
    void apilar(Pedido v); // Declaración de Operaciones Modificadoras
    void desapilar();
    Pedido valorCima(); // Declaración de Operaciones Observadoras
    bool esVacia();
};


#endif // PILA_H_INCLUDED
