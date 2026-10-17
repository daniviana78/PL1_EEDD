#include <iostream>

#ifndef PIZZERIA_H_INCLUDED
#define PIZZERIA_H_INCLUDED

#define PROB_PERSONALIZACION 20
#define ZONAS 4
#define N_PEDIDOS_PASO 10


using namespace std;

struct pedido
{

    string id_pedido;
    int id_cliente;
    string tipo_pizza;
    string tamano;
    int zona_reparto;
    bool personalizada;
    string estado;

};

class Cola;

pedido generarPedido(int contador_pedidos);
void mostrarPedidos(Cola &c);
void avanzarPaso(Cola &recibidos, Cola &prep_especial, Cola &cocina, Cola &exp_norte, Cola &exp_sur, Cola &exp_este, Cola &exp_oeste);


#endif // PIZZERIA_H_INCLUDED

