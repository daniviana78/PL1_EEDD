#include <iostream>
#include <ctime>
#include <iomanip>

#include "pizzeria.h"
#include "cola.h"
#include "pila.h"



using namespace std;

Pedido generarPedido(int contador_recibidos)
{

    Pedido pedido_generado= {" ", 0, " ", " ", 0, false, " "};
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
        Pedido p = c.valorFrente();
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

void mostrarCajas(Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, int contador_retirados, int enviadas_norte, int enviadas_sur, int enviadas_este, int enviadas_oeste)
{

    int num_pedidos_caja_norte= contarElementosPila(caja_norte);
    int num_pedidos_caja_sur= contarElementosPila(caja_sur);
    int num_pedidos_caja_este= contarElementosPila(caja_este);
    int num_pedidos_caja_oeste= contarElementosPila(caja_oeste);


    while(num_pedidos_caja_norte>CAP_CAJA)
    {
        num_pedidos_caja_norte=num_pedidos_caja_norte-CAP_CAJA;
    }

    while(num_pedidos_caja_sur>CAP_CAJA)
    {
        num_pedidos_caja_sur=num_pedidos_caja_sur-CAP_CAJA;
    }

    while(num_pedidos_caja_este>CAP_CAJA)
    {
        num_pedidos_caja_este=num_pedidos_caja_este-CAP_CAJA;
    }

    while(num_pedidos_caja_oeste>CAP_CAJA)
    {
        num_pedidos_caja_oeste=num_pedidos_caja_oeste-CAP_CAJA;
    }

    cout << "=== CAJAS TERMICA ===" << endl;
    cout << "Zona Norte -> activa: " << num_pedidos_caja_norte << "/6 \t" << "enviadas: " << enviadas_norte << endl;
    cout << "Zona Sur -> activa: " << num_pedidos_caja_sur << "/6 \t" << "enviadas: " << enviadas_sur << endl;
    cout << "Zona Este -> activa: " << num_pedidos_caja_este << "/6 \t" << "enviadas: " << enviadas_este << endl;
    cout << "Zona Oeste -> activa: " << num_pedidos_caja_oeste << "/6 \t" << "enviadas: " << enviadas_oeste << endl;
    cout << "Total de cajas enviadas: " << enviadas_norte +enviadas_sur+enviadas_este+enviadas_oeste << endl;
    cout << "Pedidos enviados o retirados: " << (enviadas_norte +enviadas_sur+enviadas_este+enviadas_oeste) * CAP_CAJA + contador_retirados << endl;
    cout << "\n";

}

void mostrarFinalizados(Cola &finalizados){

    if (finalizados.esVacia())
    {
        cout << "\nNo hay pedidos finalizados.\n" << endl;
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


    while (!finalizados.esVacia())
    {
        Pedido p = finalizados.valorFrente();
        finalizados.desencolar();

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
        finalizados.encolar(aux.valorFrente());
        aux.desencolar();
    }
}


void avanzarPaso(Cola &recibidos, Cola &prep_especial, Cola &cocina, Cola &exp_norte, Cola &exp_sur, Cola &exp_este, Cola &exp_oeste, Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, int &enviadas_norte, int &enviadas_sur, int &enviadas_este, int &enviadas_oeste, Cola &finalizados)
{
    for(int n=0; !exp_norte.esVacia() && n<N_PEDIDOS_PASO; n++)
    {

        if (contarElementosPila(caja_norte)>=CAP_CAJA){

            while (!caja_norte.esVacia()){
                Pedido p = caja_norte.valorCima();
                p.estado="Enviado";
                caja_norte.desapilar();
                finalizados.encolar(p);
            }
            enviadas_norte++;

        }

        Pedido p= exp_norte.valorFrente();
        p.estado="Caja";
        exp_norte.desencolar();


        caja_norte.apilar(p);

    }

    for(int s=0; !exp_sur.esVacia() && s<N_PEDIDOS_PASO; s++)
    {

        if (contarElementosPila(caja_sur)>=CAP_CAJA){

            while (!caja_sur.esVacia()){
                Pedido p= caja_sur.valorCima();
                p.estado="Enviado";
                caja_sur.desapilar();
                finalizados.encolar(p);
            }
            enviadas_sur++;

        }


        Pedido p= exp_sur.valorFrente();
        p.estado="Caja";
        exp_sur.desencolar();

        caja_sur.apilar(p);
    }

    for(int e=0; !exp_este.esVacia() && e<N_PEDIDOS_PASO; e++)
    {

        if (contarElementosPila(caja_este)>=CAP_CAJA){

            while (!caja_este.esVacia()){
                Pedido p = caja_este.valorCima();
                p.estado="Enviado";
                caja_este.desapilar();
                finalizados.encolar(p);
            }
            enviadas_este++;

        }

        Pedido p= exp_este.valorFrente();
        p.estado="Caja";
        exp_este.desencolar();

        caja_este.apilar(p);
    }

    for(int o=0; !exp_oeste.esVacia() && o<N_PEDIDOS_PASO; o++)
    {
        if (contarElementosPila(caja_oeste)>=CAP_CAJA){

            while (!caja_oeste.esVacia()){
                Pedido p = caja_oeste.valorCima();
                p.estado="Enviado";
                caja_oeste.desapilar();
                finalizados.encolar(p);
            }
            enviadas_oeste++;

        }

        Pedido p= exp_oeste.valorFrente();
        p.estado="Caja";
        exp_oeste.desencolar();

        caja_oeste.apilar(p);
    }

    for (int k=0; !cocina.esVacia() && k<N_PEDIDOS_PASO; k++)
    {

        Pedido p= cocina.valorFrente();
        cocina.desencolar();
        p.estado= "Expedicion";

        int zona= p.zona_reparto;

        switch(zona)
        {

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


    for (int j=0; !prep_especial.esVacia() &&  j<N_PEDIDOS_PASO; j++)
    {

        Pedido p= prep_especial.valorFrente();
        prep_especial.desencolar();
        p.estado= "Cocina";

        cocina.encolar(p);

    }

    for (int i=0; !recibidos.esVacia() && i<N_PEDIDOS_PASO; i++)
    {
        Pedido p= recibidos.valorFrente();
        recibidos.desencolar();

        if (p.personalizada==true)
        {
            p.estado= "Preparacion especial";
            prep_especial.encolar(p);

        }

        else
        {
            p.estado= "Cocina";
            cocina.encolar(p);

        }
    }

}

int contarElementosPila(Pila &p)
{

    Pila aux;
    int contador=0;
    while(!p.esVacia())
    {
        aux.apilar(p.valorCima());
        p.desapilar();
        contador++;
    }

    while(!aux.esVacia())
    {
        p.apilar(aux.valorCima());
        aux.desapilar();
    }

    return contador;
}
void menuVerCajaActiva(Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste)
{
    int zona;
    cout << "\nSeleccione la zona a consultar:" << endl;
    cout << "0 -> Norte" << endl;
    cout << "1 -> Sur" << endl;
    cout << "2 -> Este" << endl;
    cout << "3 -> Oeste" << endl;
    cout << "Opcion: ";
    cin >> zona;
    cout << "\n";

    switch (zona)
    {
    case 0:
        cout << "=== CAJA ACTIVA: Zona Norte ===" << endl;
        verCajaActiva(caja_norte);
        break;
    case 1:
        cout << "=== CAJA ACTIVA: Zona Sur ===" << endl;
        verCajaActiva(caja_sur);
        break;
    case 2:
        cout << "=== CAJA ACTIVA: Zona Este ===" << endl;
        verCajaActiva(caja_este);
        break;
    case 3:
        cout << "=== CAJA ACTIVA: Zona Oeste ===" << endl;
        verCajaActiva(caja_oeste);
        break;
    default:
        cout << "Zona no valida." << endl;
        break;
    }
}

void verCajaActiva(Pila &caja)
{


    cout << "(cima)" << endl;

    if (caja.esVacia())
    {
        cout << "\nNo hay pedidos en la caja.\n" << endl;
        return;
    }

    Pila aux;


    while (!caja.esVacia())
    {
        Pedido p = caja.valorCima();
        caja.desapilar();

        cout << setw(7) << p.id_pedido << " - " << setw(9) << p.tipo_pizza << endl;

        aux.apilar(p);
    }

    while (!aux.esVacia())
    {
        caja.apilar(aux.valorCima());
        aux.desapilar();
    }

    cout << "(fondo)\n" << endl;
}

bool menuRetirarPedido (Pila &caja_norte, Pila &caja_sur, Pila &caja_este, Pila &caja_oeste, Cola &finalizados)
    {
        int zona;
        string identificador;
        cout << "\nSeleccione la zona en la que se realizara la busqueda:" << endl;
        cout << "0 -> Norte" << endl;
        cout << "1 -> Sur" << endl;
        cout << "2 -> Este" << endl;
        cout << "3 -> Oeste" << endl;
        cout << "Opcion: ";

        cin >> zona;

        cout << "Introduzca el identificador del pedido buscado: " << endl;

        cin >> identificador;

        switch (zona)
        {
        case 0:
            return retirarPedido(caja_norte, identificador, finalizados);
            break;
        case 1:
            return retirarPedido(caja_sur, identificador, finalizados);
            break;
        case 2:
            return retirarPedido(caja_este, identificador, finalizados);
            break;
        case 3:
            return retirarPedido(caja_oeste, identificador, finalizados);
            break;
        default:
            cout << "Zona no valida." << endl;
            return false;
            break;
        }
    }

 bool retirarPedido(Pila &caja, string identificador, Cola &finalizados){

     bool encontrado= false;
     Pila aux;
     while (!caja.esVacia()){
         Pedido p= caja.valorCima();
         if(p.id_pedido==identificador){
            p.estado= "Retirado";
            finalizados.encolar(p);
            caja.desapilar();
            encontrado= true;
            break;
         }
         caja.desapilar();
         aux.apilar(p);
     }

     while (!aux.esVacia()){
        Pedido p= aux.valorCima();
        aux.desapilar();
        caja.apilar(p);
     }

     if (encontrado==false){
        cout << "No se ha encontrado un pedido con ese identificador.\n" << endl;

     }
     return encontrado;
 }









