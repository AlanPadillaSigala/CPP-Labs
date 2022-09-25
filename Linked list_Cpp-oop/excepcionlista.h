#ifndef EXCEPCIONLISTA_H
#define EXCEPCIONLISTA_H
#include <exception>
#include <iostream>

class ExcepcionLista : public std::exception{
private:
    std::string error_msg;
public:
    ExcepcionLista(int num_error);
    const char *what() const throw();
};

enum ListaExcepcion{
    LISTA_VACIA,
    POSICION_INVALIDA,
    ERROR_MEMORIA,
};

#endif // EXCEPCIONLISTA_H
