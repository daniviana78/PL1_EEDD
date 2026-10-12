#include <iostream>
#include <ctime>
#include <iomanip>

#include "pizzeria.h"
#include "cola.h"


using namespace std;

pedido generarPedido(int contador_pedidos){

    pedido pedido_generado= {" ", 0, " ", " ", " ", false, " "};
    string tipos_pizza[]= {"Margarita", "Barbacoa", "Vegetal", "Hawaiana", "Romana", "Cuatro quesos"};
    string tamanos_pizza[]= {"Mediana", "Grande"};
    string zonas_reparto[]= {"Norte", "Sur", "Este","Oeste"};

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

void mostrarPedidos(Cola &recibidos) {
    if (recibidos.esVacia()) {
        cout << "\nNo hay pedidos en la cola de recibidos.\n" << endl;
        return;
    }

    Cola aux;

    cout << "\n=== RECIBIDOS ===" << endl;


    cout << left
         << setw(10) << "Pedido"
         << setw(10) << "Cliente"
         << setw(16) << "Pizza"
         << setw(10) << "Tamano"
         << setw(10) << "Zona"
         << setw(8)  << "Pers"
         << setw(12) << "Estado" << endl;


    while (!recibidos.esVacia()) {
        pedido p = recibidos.valorFrente();
        recibidos.desencolar();

        cout << left
             << setw(10) << p.id_pedido
             << setw(10) << p.id_cliente
             << setw(16) << p.tipo_pizza
             << setw(10) << p.tamano
             << setw(10) << p.zona_reparto
             << setw(8)  << (p.personalizada ? "Si" : "No")
             << setw(12) << p.estado << endl;

        aux.encolar(p);
    }


    while (!aux.esVacia()) {
        recibidos.encolar(aux.valorFrente());
        aux.desencolar();
    }
}



