#include <iostream>
#include "lista.h"
#include "cuadrado.h"

using namespace std;

//template <class T>
void prueba();

int main()
{
    prueba();
    return 0;
}

//template <class T>
void prueba(){
    Lista<class Cuadrado> p;
    int n;

    cout<<"Guarda Numero y eleva al cuadrado:"<<endl;

    cout<<"------------Excepcion------------"<<endl;
    cout<<"Ejecuta tomar primero:\n"<<p.tomar_primero()<<endl;
    cout<<"Modificar:\n"<<p.modificar(2,3)<<endl;
    cout<<"Eliminar:\n"<<p.eliminar(5)<<endl;
    cout<<"---------------------------------"<<endl;

    n >> p.insertar(2);
    n >> p.insertar(4);
    n >> p.insertar(5);
    n >> p.insertar(9);

    cout<<endl;

    p.mostrar_todo();

    cout <<"\nTomar el primero\n"<<p.tomar_primero()<<endl;

    cout<<"\nToma el dato en la posicion 2:"<<endl;
    cout<<p[2];

    cout<<"\nElimina el dato en la posicion 1\n"<<endl;
    p.eliminar(1);


    cout<<"------------Excepcion------------"<<endl;
    cout<<"\nElimina el dato en la posicion 10:"<<endl;
    p.eliminar(10);
    cout<<"\nToma el dato en la posicion 10:"<<endl;
    cout<<p[10]<<endl;
    cout<<"\nInserta en la posicion 10:"<<endl;
    p.insertar_en(2, 10);
    cout<<"---------------------------------"<<endl;

    cout<<"\nMuestra el primer dato:"<<endl;
    cout<<p.tomar_primero()<<endl;

    cout<<"inserta numero 1:"<<endl;
    p.insertar(1);

    cout<<"inserta numero 2 en posicion 3:"<<endl;
    p.insertar_en(2,3);

    p.mostrar_todo();
}
