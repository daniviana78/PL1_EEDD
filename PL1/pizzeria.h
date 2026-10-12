#include <iostream>

#ifndef PIZZERIA_H_INCLUDED
#define PIZZERIA_H_INCLUDED

#define PROB_PERSONALIZACION 20

using namespace std;

struct pedido
{

    string id_pedido;
    int id_cliente;
    string tipo_pizza;
    string tamano;
    string zona_reparto;
    bool personalizada;
    string estado;

};

class Cola;

pedido generarPedido();
void mostrarPedidos(Cola &recibidos);

#endif // PIZZERIA_H_INCLUDED

