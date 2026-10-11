#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "pizzeria.h"

class Nodo
{
private:
    pedido valor;
    Nodo *siguiente;
    friend class Cola;
public:
// Declaración del constructor del Nodo
    Nodo(pedido p, Nodo *sig = NULL)
    {
        valor = p;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

class Cola
{
private:
    pNodo primero; // Puntero al primer elemento
    pNodo ultimo; // Puntero al último elemento
public:
    Cola(); // Declaración de Constructor y Destructor
    ~Cola();
    void encolar(pedido p); // Declaración de Operaciones Modificadoras
    void desencolar();
    pedido valorFrente(); // Declaración de Operaciones Observadoras
    bool esVacia();
};


#endif // COLA_H_INCLUDED
