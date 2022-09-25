#include<iostream>
#include "lista.h"

//constructor nodo
Nodo::Nodo(){
    this->siguiente = NULL;
}
//constructor lista
Lista::Lista(){
    this->principio_lista = NULL;
    this->posicion_nodo=0;
}

//---------------------------------------------funciones insertar
//Funcion para agregar nodos al inicio
void Lista::insertar_primero(std::string dato){
    //crea el nodo para poder ingresarlo a lista
    Nodo *nuevo_nodo = new Nodo();
    //el nuevo nodo recibe dato y lo almacena en dato
    nuevo_nodo->dato = dato;

    Nodo *temporal = principio_lista;
    if(principio_lista==temporal){
        principio_lista = nuevo_nodo;
    }
    nuevo_nodo->siguiente = temporal;
}

//Funcion para agregar nodos al final
int Lista::insertar(std::string dato){
      Nodo *nuevo_nodo = new Nodo();
      nuevo_nodo->dato = dato;
      Nodo *ultimo = principio_lista;

      //si no hay datos en lista entonces crea un nodo al inicio
      if(ultimo==NULL){
          insertar_primero(dato);
      }
      //Si ya hay nodos, crear al final
      else{
          //recorre lista hasta llegar al final
          while(ultimo->siguiente != NULL){
              ultimo=ultimo->siguiente;
          }
          ultimo->siguiente = nuevo_nodo;
      }
      posicion_nodo++;
      return 1;
}

int Lista::insertar_en(std::string dato, int posicion){
    //si no hay datos o se quiere la posicion 1
    if(posicion==PRIMER_NODO){
        insertar_primero(dato);
    }
    //ingresa posicion apartir del nodo 2
    //mientras sea menor a la cantidad de nodos
    else if(posicion > PRIMER_NODO && posicion <= posicion_nodo){
        Nodo *antes=NULL;
        Nodo *prev=principio_lista;
        Nodo *inserta_nodo = new Nodo();
        inserta_nodo->dato = dato;

        for(int i=SEGUNDO_NODO; i<=posicion; i++){
            antes = prev;
            prev=prev->siguiente;
        }
        antes->siguiente=inserta_nodo;
        inserta_nodo->siguiente=prev;
    }
    posicion_nodo++;
    //Si no se cumplen las condiciones retorna error
    if (posicion == 0 || vacia()==true || posicion > posicion_nodo) return -1; //Error No hay posicion 0 ò la lista esta vacia
}

//-----------------------------------------Funcion Tomar
std::string Lista::tomar(int posicion){
    Nodo *recorrer = principio_lista;
    int indice=PRIMER_NODO;
    //recorre lista
    while(recorrer != NULL){
        //si existe la posicion, retorna dato
        if(posicion==indice){
            return recorrer->dato;
        }
    recorrer = recorrer->siguiente;
    indice++;
    }
    //si no esta el dato, retorna cadena vacia
    if(recorrer==NULL){
        return "";
    }
}

//--------------------------------------Funcion Buscar
int Lista::buscar(std::string cancion){
    Nodo *aux = principio_lista;
    int posicion = PRIMER_NODO;
    //recorrer toda la lista
    while(aux != NULL){
        //si encuentra dato, retorna la posicion
        if(cancion==aux->dato){
            return posicion;
        }
    aux = aux->siguiente;
    posicion ++;
    }
    //si termino de recorrer en lista, retorna error
    if(aux==NULL){
        return -1;
    }
}

//-------------------------------------Funcion Eliminar
int Lista::eliminar(int posicion){
    Nodo *borrar = principio_lista;
    Nodo *antes_borrar = NULL;

        //Si la lista contiene datos
        if (vacia()==false && posicion<=posicion_nodo){
            //No hay posicion 0, retorna error
            if(posicion==0) return -1;
            //Elimina el primer nodo
            if(posicion==PRIMER_NODO){
                principio_lista=principio_lista->siguiente;
                delete borrar;
            }
            //Elimina nodo apartir del nodo 2
            else if(posicion > PRIMER_NODO && posicion <= posicion_nodo){
            for (int i=SEGUNDO_NODO; i<=posicion; i++){
                antes_borrar=borrar;
                borrar=borrar->siguiente;
            }
                antes_borrar->siguiente=borrar->siguiente;
                delete borrar;
            }
            posicion_nodo--;
            return 1;
        }
        //Si no se cumple retorna el error
        else{
            return -1;
        }
}

//-------------------------------------Funcion Mostrar
void Lista::mostrar_todo(){
    Nodo *muestra = principio_lista;
    int numero_nodos=PRIMER_NODO;

    //imprime "lista:" para indicar el inicio de lista
    std::cout<<"- Lista: -"<<std::endl;
    while(muestra != NULL){
        //imprime el numero de nodos seguido del dato
        std::cout<< numero_nodos <<") ";
        std::cout<<muestra->dato<<"\n";

        muestra = muestra ->siguiente;
        numero_nodos++;
    }
    //imprime "fin" para indicar el final de lista
    std::cout<<"- fin -"<<std::endl;
}

//-------------------------------------------------------Funcion Modificar
int Lista::modificar(int posicion, std::string dato){
    Nodo *modifica = principio_lista;

    if (posicion >= PRIMER_NODO && posicion-1 <= posicion_nodo){
        //busca a partir del primer nodo la posicion
        for (int i=PRIMER_NODO; i<=posicion-1; i++){
            modifica=modifica->siguiente;
        }
        modifica->dato=dato;
        return 1;
    }
    //si la posicion ingresada es mayor que el numero
    // de nodos retorna un error
    else{
        return -1;
    }
}

//--------------------------------Funcion Vacia
bool Lista::vacia(){
    //si la lista esta vacia
    if (principio_lista==NULL){
        return true;
    }
    //si no se ejecuta el if la lista
    //contiene datos
    return false;
}

//---------------------------Funcion Purga
void Lista::purga(){
    while(principio_lista != NULL){
        eliminar(posicion_nodo);
    }
}

//--------------------------Funcion Tamaño
int Lista::tamano(){
    //retorna el numero de nodos creados
    // (elementos de la lista)
    return posicion_nodo;
}

//----------------------------------Funcion Tomar Primero
std::string Lista::tomar_primero(){
    //retorna el resultado de ejecutar la funcion tomar
    //en la posicion del primer nodo
    return tomar(PRIMER_NODO);
}
