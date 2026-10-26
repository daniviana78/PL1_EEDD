#include <iostream>

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "pizzeria.h"

using namespace std;

class NodoPila
{
private:
    Pedido valor;
    NodoPila *siguiente;
    friend class Pila;
public:
// Declaración del constructor del NodoPila
    NodoPila(Pedido v, NodoPila *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef NodoPila *pNodoPila;

class Pila
{
private:
    pNodoPila cima;
public:
    Pila(); // Declaración de Constructor y Destructor
    ~Pila();
    void apilar(Pedido v); // Declaración de Operaciones Modificadoras
    void desapilar();
    Pedido valorCima(); // Declaración de Operaciones Observadoras
    bool esVacia();
};


#endif // PILA_H_INCLUDED
