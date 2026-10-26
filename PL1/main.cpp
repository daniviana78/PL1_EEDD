#include <iostream>
#include <ctime>

#include "pizzeria.h"
#include "cola.h"
#include "pila.h"

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
    Pila caja_norte;
    Pila caja_sur;
    Pila caja_este;
    Pila caja_oeste;
    srand(time(NULL));
    int respuesta;
    int contador_recibidos = 0;

    do
    {
        cout << "=== MENU ===" << endl;
        cout << "Elija alguna de las siguientes opciones: " << endl;
        cout << "1- Generar N pedidos." << endl;
        cout << "2- Ejecutar un paso de simulación." << endl;
        cout << "3- Mostrar el estado del sistema." << endl;
        cout << "4- Ver la caja activa de una zona." << endl;
        cout << "0- Salir." << endl;

        cin >> respuesta;

        switch(respuesta)
        {
            case 1:
            {
                cout << "Introduzca el numero de pedidos que quiere generar: " << endl;
                int n_pedidos;
                cin >> n_pedidos;

                for (int i = 0; i < n_pedidos; i++)
                {
                    contador_recibidos++;
                    Pedido nuevo_pedido = generarPedido(contador_recibidos);
                    recibidos.encolar(nuevo_pedido);
                }
                break;
            }
            case 2:
            {
                avanzarPaso(recibidos, prep_especial, cocina, exp_norte, exp_sur, exp_este, exp_oeste, caja_norte, caja_sur, caja_este, caja_oeste);
                break;
            }
            case 3:
            {
                cout << "\n=== RECIBIDOS ===" << endl;
                mostrarPedidos(recibidos);

                cout << "\n=== PREPARACION ESPECIAL ===" << endl;
                mostrarPedidos(prep_especial);

                cout << "\n=== COCINA ===" << endl;
                mostrarPedidos(cocina);

                cout << "\n=== EXPEDICION NORTE ===" << endl;
                mostrarPedidos(exp_norte);

                cout << "\n=== EXPEDICION SUR ===" << endl;
                mostrarPedidos(exp_sur);

                cout << "\n=== EXPEDICION ESTE ===" << endl;
                mostrarPedidos(exp_este);

                cout << "\n=== EXPEDICION OESTE ===" << endl;
                mostrarPedidos(exp_oeste);

                break;
            }
            case 4:
            {
                menuVerCajaActiva(caja_norte, caja_sur, caja_este, caja_oeste);
                break;
            }
            case 0:
            {
                break;
            }
        }
    }
    while (respuesta != 0);

    return 0;
}
