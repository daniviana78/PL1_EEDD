#include <iostream>
#include <ctime>
#include <iomanip>

#include "pizzeria.h"
#include "cola.h"



using namespace std;

pedido generarPedido(int contador_recibidos)
{

    pedido pedido_generado= {" ", 0, " ", " ", 0, false, " "};
    string tipos_pizza[]= {"Margarita", "Barbacoa", "Vegetal", "Hawaiana", "Romana", "Cuatro quesos"};
    string tamanos_pizza[]= {"Mediana", "Grande"};

    pedido_generado.id_pedido= "P" + to_string(10000 + contador_recibidos);
    pedido_generado.id_cliente= 100 + (rand() % 900);
    pedido_generado.tipo_pizza= tipos_pizza[rand()%6];
    pedido_generado.tamano= tamanos_pizza[rand()%2];
    pedido_generado.zona_reparto= rand()%ZONAS;
    int porcentaje= rand() % 100;
    pedido_generado.personalizada= (porcentaje < PROB_PERSONALIZACION);
    pedido_generado.estado= "Recibido";

    return pedido_generado;
}

void mostrarPedidos(Cola &c)
{
    if (c.esVacia())
    {
        cout << "\nNo hay pedidos en la cola.\n" << endl;
        return;
    }

    Cola aux;

    cout << setw(7) << "Pedido" << " | "
         << setw(7) << "Cliente" << " | "
         << setw(13) << "Pizza" << " | "
         << setw(7) << "Tamano" << " | "
         << setw(5) << "Zona" << " | "
         << setw(4) << "Pers" << " | "
         << "Estado" << endl;


    cout << "-----------------------------------------------------------------" << endl;


    while (!c.esVacia())
    {
        pedido p = c.valorFrente();
        c.desencolar();

        cout << setw(7) << p.id_pedido << " | "
             << setw(7) << p.id_cliente << " | "
             << setw(13) << p.tipo_pizza << " | "
             << setw(7) << p.tamano << " | "
             << setw(5) << p.zona_reparto << " | "
             << setw(4) << (p.personalizada ? "Si" : "No") << " | "
             << p.estado << endl;

        aux.encolar(p);
    }


    while (!aux.esVacia())
    {
        c.encolar(aux.valorFrente());
        aux.desencolar();
    }
}

void avanzarPaso(Cola &recibidos, Cola &prep_especial, Cola &cocina, Cola &exp_norte, Cola &exp_sur, Cola &exp_este, Cola &exp_oeste)
{
    for (int k=0; !cocina.esVacia() && k<N_PEDIDOS_PASO; k++){

            pedido p= cocina.valorFrente();
            cocina.desencolar();

            int zona= p.zona_reparto;

            switch(zona){

            case 0:
                {
                exp_norte.encolar(p);
                break;
            }

            case 1:
                {
                exp_sur.encolar(p);
                break;
            }

            case 2:
                {
                exp_este.encolar(p);
                break;
            }

            case 3:
                {
                exp_oeste.encolar(p);
                break;
            }

            }
        }


    for (int j=0; !prep_especial.esVacia() &&  j<N_PEDIDOS_PASO; j++){

        pedido p= prep_especial.valorFrente();
        prep_especial.desencolar();

        cocina.encolar(p);

    }

    for (int i=0;!recibidos.esVacia() && i<N_PEDIDOS_PASO; i++)
    {
        pedido p= recibidos.valorFrente();
        recibidos.desencolar();

        if (p.personalizada==true)
        {

            prep_especial.encolar(p);

        }

        else
        {

            cocina.encolar(p);

        }
    }



}










