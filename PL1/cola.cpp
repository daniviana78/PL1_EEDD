#include "cola.h"
#include <iostream>

using namespace std;


//Constructor de la Cola
Cola::Cola() : primero(NULL), ultimo(NULL) {}
//Destructor de la Cola
Cola::~Cola()
{
    //Mientras existan elementos en la pila se desencolan
    while (!esVacia())
    {
        desencolar();
    }
}

//Insertar elemento
void Cola::encolar(pedido p)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
    nuevo = new Nodo(p); //Se crea un nodo nuevo
// El antiguo último apunta al nuevo
    if (ultimo != NULL) ultimo->siguiente = nuevo;
    ultimo = nuevo; // El nuevo pasa a ser el último
// Si la cola estaba vacía, primero y último coinciden
    if (primero == NULL) primero = nuevo;
}

//Desencolar elemento
void Cola::desencolar()
{
    if (primero == NULL) return; // Si está vacía, no hace nada
    pNodo aux; //Var aux para manipular el nodo
    aux = primero; //aux apunta al primer elemento de la cola
    primero = primero->siguiente; // El frente avanza al siguiente nodo
    delete aux; //Se borra el nodo liberando memoria
// Si la cola quedó vacía, el último también debe ser NULL
    if (primero == NULL) ultimo = NULL;
}

//Valor del primer elemento
pedido Cola::valorFrente()
{
    if (primero == NULL) //Otra forma de comprobar si la cola está vacía
    {
        cout << "Error: Cola vacia al consultar el frente." << endl;
        pedido vacio = {" ", 0, " ", " ", 0, false, " "};
        return vacio;
    }
    return primero->valor;
}
//Cola vacia
bool Cola::esVacia()
{
    return primero == NULL;
}
