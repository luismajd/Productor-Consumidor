#include <iostream>
#include <conio.h>
#include <time.h>

#include "Contenedor.h"
#include "Productor.h"
#include "Consumidor.h"

#define ESC 27
#define N 20

using namespace std;

int main()
{
    Productor productor;
    Consumidor consumidor;
    Contenedor contenedor(N);

    char tecla;
    int decision;
    int cantidad;

    int semaforo = 0;

    srand(time(NULL));

    do
    {
        cout<<endl;
        cout<<"El productor se encuentra en la posicion "<<productor.posicion<<endl;
        cout<<"El consumidor se encuentra en la posicion "<<consumidor.posicion<<endl;
        contenedor.Mostrar();

        decision = rand()%(2);   //Aleatorio entre 0 y 1
        cantidad = rand()%(8)+3; //Aleatorio del 3 al 10
        if(decision == 0)
        {
            consumidor.Dormir();
            productor.Despertar();

            if(productor.IntentarTrabajar(semaforo))
            {
                contenedor.AgregarN(productor.posicion, cantidad);
                productor.Producir(cantidad, semaforo);
                cout<<"El productor acaba de producir "<<cantidad<<" elementos"<<endl;
            }
            else
            {
                productor.Dormir(1);
            }
        }
        else
        {
            productor.Dormir();
            consumidor.Despertar();

            if(consumidor.IntentarTrabajar(semaforo))
            {
                contenedor.RetirarN(consumidor.posicion, cantidad);
                consumidor.Consumir(cantidad, semaforo);
                cout<<"El consumidor acaba de consumir "<<cantidad<<" elementos"<<endl;
            }
            else
            {
                consumidor.Dormir(1);
            }
        }
        tecla = getch();
    }
    while(tecla != ESC);

    return 0;
}
