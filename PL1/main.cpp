#include <iostream>
#include <ctime>


#include "pizzeria.h"
#include "cola.h"


using namespace std;

int main()
{
    Cola cola_pedidos;
    srand(time(NULL));

    cout << "=== MENU ===" << endl;
    cout << "Elija alguna de las siguientes opciones: " << endl;
    cout << "1- Generar N pedidos." << endl;
    cout << "2- Mostrar pedidos realizados." << endl;
    cout << "0- Salir." << endl;

    int respuesta;
    cin >> respuesta;

    switch(respuesta){

    case 1:
        {

            cout << "Introduzca el numero de pedidos que quiere generar: " << endl;
            int n_pedidos;
            cin >> n_pedidos;

            for (int i=0; i<n_pedidos; i++){
                pedido nuevo_pedido= generarPedido();
                cola_pedidos.encolar(nuevo_pedido);
            }
            break;
        }
    case 2:
        {
         mostrarPedidos(cola_pedidos);
         break;
        }
    case 0:
        {
            cout << "Saliendo" << endl;
            break;
        }

    }
    while (respuesta != 0);

    return 0;
}
