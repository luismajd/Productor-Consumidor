#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include <iostream>

using namespace std;

class Nodo
{
    private:
        Nodo *sig;
        char elemento;
    public:
        Nodo(){ sig = nullptr; }
        friend class Contenedor;
};

class Contenedor
{
    private:
        Nodo *primero;
        void Agregar(char);
    public:
        Contenedor();
        Contenedor(unsigned short);
        void AgregarN(int, int);
        void RetirarN(int, int);
        void Mostrar();
};

Contenedor::Contenedor()
{
    primero = nullptr;
}

Contenedor::Contenedor(unsigned short n)
{
    primero = nullptr;

    for(unsigned short i=0; i<n; i++)
    {
        Agregar('_');
    }
}

void Contenedor::Agregar(char elemento)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->elemento = elemento;

    if(primero)
    {
        Nodo *actual;
        actual = primero;

        while(actual->sig != primero)
        {
            actual = actual->sig;
        }

        actual->sig = nuevo;
        nuevo->sig = primero;
    }
    else
    {
        primero = nuevo;
        nuevo->sig = primero;
    }
}

void Contenedor::AgregarN(int pos, int n)
{
    Nodo *actual;
    actual = primero;

    //Posicionarse donde se encuentra el productor.
    for(int i=0; i<pos; i++)
    {
        actual = actual->sig;
    }

    //Marcar 'n' casillas a partir de la posicion del productor.
    for(int i=0; i<n; i++)
    {
        actual->elemento = '*';
        actual = actual->sig;
    }
}

void Contenedor::RetirarN(int pos, int n)
{
    Nodo *actual;
    actual = primero;

    //Posicionarse donde se encuentra el consumidor.
    for(int i=0; i<pos; i++)
    {
        actual = actual->sig;
    }

    //Desmarcar 'n' casillas a partir de la posicion del productor.
    for(int i=0; i<n; i++)
    {
        actual->elemento = '_';
        actual = actual->sig;
    }
}

void Contenedor::Mostrar()
{
    if(primero)
    {
        Nodo *actual;
        actual = primero;

        while(actual->sig != primero)
        {
            cout<<actual->elemento<<" ";
            actual = actual->sig;
        }
        cout<<actual->elemento<<endl<<endl;
    }
}

#endif // CONTENEDOR_H
