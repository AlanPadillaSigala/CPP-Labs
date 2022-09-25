#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "excepcionlista.h"
#include "cuadrado.h"

#define PRIMER_NODO 1
#define SEGUNDO_NODO 2

template <class T>
class Nodo{
public:
    T dato;
    Nodo *siguiente;

    Nodo();
};

template <class T>
class Lista{
private:
    int posicion_nodo;
    Nodo<T> *principio_lista;
    Nodo<T> *aux;
public:
    Lista();
    void insertar_primero(T dato);
    int insertar(T dato);
    int insertar_en(T dato, int posicion);
    T tomar(int posicion);
    int buscar(T cancion);
    int eliminar(int posicion);
    void mostrar_todo();
    int modificar(int posicion, T dato);
    bool vacia();
    void purga();
    int tamano();
    T tomar_primero();
    T operator [] (int posicion);
};
//-----------------------------------------------------------------------------

//constructor nodo
template <class T>
Nodo<T>::Nodo(){
    this->siguiente = NULL;
}
//constructor lista
template <class T>
Lista<T>::Lista(){
    this->principio_lista = NULL;
    this->posicion_nodo=0;
}

//---------------------------------------------funciones insertar
//Funcion para agregar nodos al inicio
template <class T>
void Lista<T>::insertar_primero(T dato){
    try{
    //crea el nodo para poder ingresarlo a lista
    Nodo<T> *nuevo_nodo = new Nodo<T>();
    //el nuevo nodo recibe dato y lo almacena en dato
    nuevo_nodo->dato = dato;
    Nodo<T> *temporal = principio_lista;
    if(principio_lista==temporal){
        principio_lista = nuevo_nodo;
    }
    nuevo_nodo->siguiente = temporal;

    }
    catch(std::bad_alloc &error_num){
        try{
        throw ExcepcionLista(ListaExcepcion::ERROR_MEMORIA);
        }catch(ExcepcionLista &err){
            std::cout<<error_num.what() <<std::endl;
        }
    }
}

//Funcion para agregar nodos al final
template <class T>
int Lista<T>::insertar(T dato){
      try{
      Nodo<T> *nuevo_nodo = new Nodo<T>();
      nuevo_nodo->dato = dato;
      Nodo<T> *ultimo = principio_lista;

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
      }
    catch(std::bad_alloc &error_num){
        try{
        throw ExcepcionLista(ListaExcepcion::ERROR_MEMORIA);
        }catch(ExcepcionLista &err){
            std::cout<<error_num.what() <<std::endl;
        }
    }
}

template <class T>
int Lista<T>::insertar_en(T dato, int posicion){
    try{
    //si no hay datos o se quiere la posicion 1
    if(posicion==PRIMER_NODO){
        insertar_primero(dato);
    }
    //ingresa posicion apartir del nodo 2
    //mientras sea menor a la cantidad de nodos
    else if(posicion > PRIMER_NODO && posicion <= posicion_nodo){
        try{
        Nodo<T> *antes=NULL;
        Nodo<T> *prev=principio_lista;
        Nodo<T> *inserta_nodo = new Nodo<T>();
        inserta_nodo->dato = dato;

        for(int i=SEGUNDO_NODO; i<=posicion; i++){
            antes = prev;
            prev=prev->siguiente;
        }
        antes->siguiente=inserta_nodo;
        inserta_nodo->siguiente=prev;
        }
        catch(std::bad_alloc &error_num){
            try{
            throw ExcepcionLista(ListaExcepcion::ERROR_MEMORIA);
            }catch(ExcepcionLista &err){
                std::cout<<error_num.what() <<std::endl;
            }
        }
    }
    posicion_nodo++;
    //Si no se cumplen las condiciones retorna error
    if (posicion == 0 || vacia()==true || posicion > posicion_nodo) throw ExcepcionLista(ListaExcepcion::POSICION_INVALIDA); //Error No hay posicion 0 ò la lista esta vacia
    }
    catch(ExcepcionLista &err){
        std::cout<<err.what() <<std::endl;
    }
}

//-----------------------------------------Funcion Tomar
template <class T>
T Lista<T>::tomar(int posicion){
    try{
        if (vacia()==true){
            throw 0;
        }
        Nodo<T> *recorrer = principio_lista;
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
            throw ExcepcionLista(ListaExcepcion::POSICION_INVALIDA);
        }
    } catch(ExcepcionLista &err){
        std::cout<<err.what() <<std::endl;
    } catch (int){
        try{
        throw ExcepcionLista(ListaExcepcion::LISTA_VACIA);
        } catch (ExcepcionLista &err){
            std::cout<<err.what() <<std::endl;
        }
    }
}

//--------------------------------------Funcion Buscar
template <class T>
int Lista<T>::buscar(T cancion){
    try{
        if(vacia()==true){
            throw ExcepcionLista(ListaExcepcion::LISTA_VACIA);
        }
        Nodo<T> *aux = principio_lista;
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
    } catch (ExcepcionLista &err){
        std::cout<<err.what() <<std::endl;
    }
}

//-------------------------------------Funcion Eliminar
template <class T>
int Lista<T>::eliminar(int posicion){
    try{
        if (vacia()==true){
            throw 0;
        }
        Nodo<T> *borrar = principio_lista;
        Nodo<T> *antes_borrar = NULL;

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
                throw ExcepcionLista(ListaExcepcion::POSICION_INVALIDA);
            }
    } catch(ExcepcionLista &err){
        std::cout<<err.what() <<std::endl;
    } catch(const int){
        try{
        throw ExcepcionLista(ListaExcepcion::LISTA_VACIA);
        } catch (ExcepcionLista &err){
            std::cout<<err.what() <<std::endl;
        }
    }
}

//-------------------------------------Funcion Mostrar Todo
template <class T>
void Lista<T>::mostrar_todo(){
    Nodo<T> *muestra = principio_lista;
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
template <class T>
int Lista<T>::modificar(int posicion, T dato){
    try{
        if (vacia()==true){
            throw 0;
        }
        Nodo<T> *modifica = principio_lista;

        if (posicion >= PRIMER_NODO && posicion-1 <= posicion_nodo){
            //busca a partir del primer nodo la posicion
            for (int i=PRIMER_NODO; i<=posicion-1; i++){
                modifica=modifica->siguiente;
            }
            modifica->dato=dato;
            return 1;
        }
        //si la posicion ingresada es mayor que el numero
        // de nodos envia el error
        else{
            throw ExcepcionLista(ListaExcepcion::POSICION_INVALIDA);
        }
    } catch(ExcepcionLista &err){
        std::cout<<err.what() <<std::endl;
    } catch(const int){
        try{
        throw ExcepcionLista(ListaExcepcion::LISTA_VACIA);
        } catch (ExcepcionLista &err) {
            std::cout<<err.what() <<std::endl;
        }
    }
}

//--------------------------------Funcion Vacia
template <class T>
bool Lista<T>::vacia(){
    //si la lista esta vacia
    if (principio_lista==NULL){
        return true;
    }
    //si no se ejecuta el if la lista
    //contiene datos
    return false;
}

//---------------------------Funcion Purga
template <class T>
void Lista<T>::purga(){
    while(principio_lista != NULL){
        eliminar(posicion_nodo);
    }
}

//--------------------------Funcion Tamaño
template <class T>
int Lista<T>::tamano(){
    //retorna el numero de nodos creados
    // (elementos de la lista)
    return posicion_nodo;
}

//----------------------------------Funcion Tomar Primero
template <class T>
T Lista<T>::tomar_primero(){

    try{
        if(vacia()==true){
            throw ExcepcionLista(ListaExcepcion::LISTA_VACIA);
        }
        //retorna el resultado de ejecutar la funcion tomar
        //en la posicion del primer nodo
        return tomar(PRIMER_NODO);
    } catch (ExcepcionLista &err){
        std::cout<<err.what() <<std::endl;
    }
}

template <class T>
T Lista<T>::operator [] (int posicion){
    return tomar(posicion);
}

#endif // LISTA_H
