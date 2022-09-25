#include "pila.h"
#include "lista.h"

Pila::Pila()
{
    this->cima = NULL;
}

int Pila::insertar(std::string dato){
    Nodo *nodo_pila = new Nodo ();
    nodo_pila->dato=dato;
    nodo_pila->siguiente=cima;
    cima = nodo_pila;
    return 1;
}
int Pila::eliminar(int){
    Nodo *borrar = this->cima;
    cima=borrar->siguiente;
    delete borrar;
    return 1;
}
std::string Pila::tomar_primero(){
    return cima->dato;
}

//Funcion para analizar sintaxis
int analizador_sintaxis(){
    Pila prueba;

    char sintaxis[]="{[()]}"; //-----------------------------------------------Cadena Ingresada

    int tam=sizeof (sintaxis);
    std::cout<<"Cadena ingresada: "<<std::endl;
    std::cout<<sintaxis<<std::endl;

    for(int i=0; i<tam-1; i++){
        if(sintaxis[i]=='(' | sintaxis[i]=='[' | sintaxis[i]=='{'){
            std::string datos(LONG_CADENA, sintaxis[i]);
            prueba.insertar(datos);
        }
        else{
            if(sintaxis[i]==')'){
                if(prueba.tomar_primero()!= "("){
                    return 0;
                }
                else{
                    prueba.eliminar(NADA);
                }
            }
            else{
                if(sintaxis[i]==']'){
                    if(prueba.tomar_primero()!="["){
                        return 0;
                    }
                    else{
                        prueba.eliminar(NADA);
                    }
                }
                else{
                    if(sintaxis[i]=='}'){
                        if(prueba.tomar_primero()!="{"){
                            return 0;
                        }
                        else{
                            prueba.eliminar(NADA);
                        }
                    }
                }
            }
        }
    }
    return 1;
}
