#include "excepcionlista.h"

ExcepcionLista::ExcepcionLista(int num_error)
{
        this->error_msg = "Error: ";
        switch (num_error) {
        case LISTA_VACIA :
            this->error_msg += "La lista esta vacia";

            break;
        case POSICION_INVALIDA:
            this->error_msg += "Posicion invalida";
            break;
        case ERROR_MEMORIA:
            this->error_msg += "Error de memoria";
            break;
        }
}

const char * ExcepcionLista :: what() const throw(){
    return error_msg.c_str();
}
