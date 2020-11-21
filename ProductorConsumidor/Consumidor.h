#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include "Agente.h"

class Consumidor : public Agente
{
    public:
        Consumidor();
        bool IntentarTrabajar(int);
        void Consumir(int, int&);
};

#endif // CONSUMIDOR_H
