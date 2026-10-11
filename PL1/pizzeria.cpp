#include <iostream>
#include <ctime>

#include "pizzeria.h"
#include "cola.h"


using namespace std;

pedido generarPedido(){

    pedido pedido_generado= {" ", 0, " ", " ", " ", false, " "};
    int contador_pedidos= 0;
    string tipos_pizza[]= {"Margarita", "Barbacoa", "Vegetal", "Hawaiana", "Romana", "Cuatro quesos"};
    string tamanos_pizza[]= {"Mediana", "Grande"};
    string zonas_reparto[]= {"Norte", "Sur", "Este","Oeste"};

    contador_pedidos++;
    pedido_generado.id_pedido= "P" + to_string(10000 + contador_pedidos);
    pedido_generado.id_cliente= 100 + (rand() % 900);
    pedido_generado.tipo_pizza= tipos_pizza[rand()%6];
    pedido_generado.tamano= tamanos_pizza[rand()%2];
    pedido_generado.zona_reparto= zonas_reparto[rand()%4];
    int porcentaje= rand() % 100;
    pedido_generado.personalizada= (porcentaje < PROB_PERSONALIZACION);
    pedido_generado.estado= "Recibido";

    return pedido_generado;
}



