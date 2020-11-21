#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "Agente.h"

class Productor : public Agente
{
    public:
        Productor();
        bool IntentarTrabajar(int);
        void Producir(int, int&);
};

#endif // PRODUCTOR_H
