#include "pila.h"
#include <iostream>

using namespace std;

//Constructor de la Pila
Pila::Pila() : cima(NULL) {}

//Destructor de la Pila
Pila::~Pila()
{
    //Mientras existan elementos en la pila se desapilan
    while (!esVacia())
    {
        desapilar();
    }
}

//Insertar elemento
void Pila::apilar(Pedido v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
    nuevo = new Nodo(v, cima); //Se crea un nodo nuevo
    cima = nuevo; //El comienzo de la pila es el nuevo nodo
}

//Desapilar elemento
void Pila::desapilar()
{
    if (esVacia()) return; //Si la pila está vacía no devuelve nada
    pNodo aux; //Var aux para manipular el nodo
    aux = cima; //aux apunta al primer elemento de la pila
    cima = cima->siguiente; //Se asigna a pila toda la pila menos
//el primer elemento
    delete aux; //Se borra el nodo liberando memoria
}

//Valor de la cima
Pedido Pila::valorCima()
{
    if (cima == NULL) //Otra forma de comprobar si la pila está vacía
    {
        cout << "Error: Pila vacia al consultar la cima." << endl;
        pedido vacio= {" ", 0, " ", " ", 0, false, " "};
        return vacio;
    }
    return cima->valor;
}
//Pila vacia
bool Pila::esVacia()
{
    return cima == NULL;
}
