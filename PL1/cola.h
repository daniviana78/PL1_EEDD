#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "pizzeria.h"

class NodoCola
{
private:
    Pedido valor;
    NodoCola *siguiente;
    friend class Cola;
public:
// Declaración del constructor del NodoCola
    NodoCola(Pedido p, NodoCola *sig = NULL)
    {
        valor = p;
        siguiente = sig;
    }
};
typedef NodoCola *pNodoCola;

class Cola
{
private:
    pNodoCola primero; // Puntero al primer elemento
    pNodoCola ultimo; // Puntero al último elemento
public:
    Cola(); // Declaración de Constructor y Destructor
    ~Cola();
    void encolar(Pedido p); // Declaración de Operaciones Modificadoras
    void desencolar();
    Pedido valorFrente(); // Declaración de Operaciones Observadoras
    bool esVacia();
};


#endif // COLA_H_INCLUDED
