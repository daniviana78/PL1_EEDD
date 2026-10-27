#include <iostream>

#ifndef PIZZERIA_H_INCLUDED
#define PIZZERIA_H_INCLUDED

#define PROB_PERSONALIZACION 20
#define ZONAS 4
#define N_PEDIDOS_PASO 10
#define CAP_CAJA 6


using namespace std;

struct Pedido
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
class Pila;

Pedido generarPedido(int contador_pedidos);
void mostrarPedidos(Cola &c);
void mostrarCajas(Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, int contador_retirados);
void avanzarPaso(Cola &recibidos, Cola &prep_especial, Cola &cocina, Cola &exp_norte, Cola &exp_sur, Cola &exp_este, Cola &exp_oeste, Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste);
void menuVerCajaActiva(Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste);
int contar_elementos_pila(Pila &p);
void verCajaActiva(Pila &caja);
bool menuRetirarPedido (Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste);
bool retirarPedido(Pila &caja, string identificador);


#endif // PIZZERIA_H_INCLUDED

