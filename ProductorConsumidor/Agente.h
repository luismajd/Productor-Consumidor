#ifndef AGENTE_H
#define AGENTE_H
#include <iostream>

using namespace std;

class Agente
{
    protected:
        string nombre;
        int color;
        bool dormido;
        void Hablar(string, bool noPudoTrabajar = false);
    public:
        int posicion;
        Agente();
        void Despertar();
        void Dormir(bool noPudoTrabajar = false);
};

#endif // AGENTE_H
