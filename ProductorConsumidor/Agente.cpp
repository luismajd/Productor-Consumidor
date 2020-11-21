#include "Agente.h"
#include "txtcolor.h"

Agente::Agente()
{
    dormido = true;
    posicion = 0;
}

void Agente::Despertar()
{
    Hablar("despertando");

    dormido = false;
}

void Agente::Dormir(bool noPudoTrabajar)
{
    Hablar("durmiendo", noPudoTrabajar);

    dormido = true;
}

void Agente::Hablar(string estado, bool noPudoTrabajar)
{
    TextColor(color);

    if(noPudoTrabajar)
        cout<<nombre<<": No pude trabajar. Estoy "<<estado<<endl;
    else
        cout<<nombre<<": Estoy "<<estado<<endl;
    TextColor(15);
}
