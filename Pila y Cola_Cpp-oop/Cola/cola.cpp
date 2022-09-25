#include "cola.h"

Cola::Cola()
{
    this->inicio=NULL;
    this->fin=NULL;
}

int Cola::insertar(std::string dato){
    Nodo* nodo_cola = new Nodo();
    nodo_cola->dato=dato;
    nodo_cola->siguiente=NULL;
    if(inicio == NULL){
        inicio=nodo_cola;
    }
    else{
        fin->siguiente=nodo_cola;
    }
    fin=nodo_cola;
    return 1;
}

int Cola::eliminar(int){
    Nodo *borrar=this->inicio;
    if(this->inicio->siguiente==NULL){
        this->inicio=NULL;
        this->fin=NULL;
        delete borrar;
    }
    else{
        this->inicio = this->inicio->siguiente;
        delete borrar;
    }
    return 1;
}

std::string Cola::tomar_primero(){
return this->inicio->dato;
}

bool Cola::vacia(){
    if (inicio == NULL) return true;
    else return false;
}

//funcion externa para mostrar menu
void menu_funcion(){
    int opcion;
    std::string nombre;
    Cola prueba;

    //carga datos para prueba de ejecucion.
    prueba.insertar("AlanPadilla");
    prueba.insertar("Lucas");
    prueba.insertar("MariaGodoy");
    std::cout<<"--- 3 Datos cargados para ejecucionde prueba ---\n"<<std::endl;

    do{
        std::cout<<"-------------------MENU-------------------"<<std::endl;
        std::cout<<"Bienvenido a atencion al cliente:"<<std::endl;
        std::cout<<"1) Digite su nombre"<<std::endl;
        std::cout<<"2) Siguiente turno"<<std::endl;
        std::cout<<"3) Salir"<<std::endl;
        std::cout<<"Opcion: ";
        std::cin>>opcion;
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<std::endl;

        switch (opcion){
        case NOMBRE:
            std::cout<<"Digite su primer nombre:"<<std::endl;
            std::cin>>nombre;
            prueba.insertar(nombre);
            break;
        case SIG_TURNO:
            if(prueba.vacia()==true){
                std::cout<<"No hay personas en la cola de espera"<<std::endl;
            }
            else{
            std::cout<<"{"<<prueba.tomar_primero()<<"} favor de pasar a ventanilla\n"<<std::endl;
            prueba.eliminar(NADA);
            }
            break;
        case SALIR:
            break;
        }
    }while(opcion < SALIR);
}
