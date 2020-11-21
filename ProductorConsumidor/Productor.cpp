#include "Productor.h"
#define N 20

Productor::Productor()
{
    nombre = "Productor";
    color = 12;
}

bool Productor::IntentarTrabajar(int semaforo)
{
    Hablar("intentando trabajar");

    return semaforo < N;
}

void Productor::Producir(int cantidad, int &semaforo)
{
    Hablar("trabajando");

    cantidad = (cantidad > N - semaforo)? N - semaforo : cantidad;

    semaforo += cantidad;
    posicion = (posicion + cantidad) % N;
}
