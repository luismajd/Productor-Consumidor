#include "Consumidor.h"
#define N 20

Consumidor::Consumidor()
{
    nombre = "Consumidor";
    color = 9;
}

bool Consumidor::IntentarTrabajar(int semaforo)
{
    Hablar("intentando trabajar");

    return semaforo > 0;
}

void Consumidor::Consumir(int cantidad, int &semaforo)
{
    Hablar("trabajando");

    cantidad = (cantidad > semaforo)? semaforo : cantidad;

    semaforo -= cantidad;
    posicion = (posicion + cantidad) % N;
}
