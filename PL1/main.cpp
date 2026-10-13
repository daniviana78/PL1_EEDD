#include <iostream>
#include <ctime>


#include "pizzeria.h"
#include "cola.h"


using namespace std;

int main()
{
    Cola recibidos;
    Cola prep_especial;
    Cola cocina;
    Cola exp_norte;
    Cola exp_sur;
    Cola exp_este;
    Cola exp_oeste;
    srand(time(NULL));
    int respuesta;
    int contador_recibidos=0;


    do{
        cout << "=== MENU ===" << endl;
        cout << "Elija alguna de las siguientes opciones: " << endl;
        cout << "1- Generar N pedidos." << endl;
        cout << "2- Mostrar pedidos realizados." << endl;
        cout << "0- Salir." << endl;

        cin >> respuesta;

        switch(respuesta){

        case 1:
            {

                cout << "Introduzca el numero de pedidos que quiere generar: " << endl;
                int n_pedidos;
                cin >> n_pedidos;

                for (int i=0; i<n_pedidos; i++){
                    contador_recibidos++;
                    pedido nuevo_pedido= generarPedido(contador_recibidos);
                    recibidos.encolar(nuevo_pedido);
                }
                break;
            }
        case 2:
            {
             mostrarPedidos(recibidos);
             break;
            }
        case 0:
            {
                break;
            }

        }
    }while (respuesta != 0);

    return 0;
}
