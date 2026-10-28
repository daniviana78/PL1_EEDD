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
void mostrarCajas(Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, int contador_retirados, int enviadas_norte, int enviadas_sur, int enviadas_este, int enviadas_oeste);
void mostrarFinalizados(Cola &finalizados);
void avanzarPaso(Cola &recibidos, Cola &prep_especial, Cola &cocina, Cola &exp_norte, Cola &exp_sur, Cola &exp_este, Cola &exp_oeste, Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, int &enviadas_norte, int &enviadas_sur, int &enviadas_este, int &enviadas_oeste, Cola &finalizados);
int contar_elementos_pila(Pila &p);
void menuVerCajaActiva(Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste);
void verCajaActiva(Pila &caja);
bool menuRetirarPedido (Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, Cola &finalizados);
bool retirarPedido(Pila &caja, string identificador, Cola &finalizados);



#endif // PIZZERIA_H_INCLUDED

