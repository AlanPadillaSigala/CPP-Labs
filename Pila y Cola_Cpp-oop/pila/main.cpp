#include <iostream>
#include <string>
#include "lista.h"
#include "pila.h"

using namespace std;

void prueba_pila(int analisis);

int main()
{
    prueba_pila(analizador_sintaxis());
    return 0;
}

void prueba_pila(int analisis){
    if (analisis == 0){
        cout<<"Cadena Erronea"<<endl;
    }
    else cout<<"Correcto"<<endl;
}
