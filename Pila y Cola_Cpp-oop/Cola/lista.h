#ifndef LISTA_H
#define LISTA_H
#include <iostream>

#define PRIMER_NODO 1
#define SEGUNDO_NODO 2

class Nodo{
public:
    std::string dato;
    Nodo *siguiente;

    Nodo();
};

class Lista{
private:
    int posicion_nodo;
    Nodo *principio_lista;
    Nodo *aux;
public:
    Lista();
    void insertar_primero(std::string dato);
    virtual int insertar(std::string dato);
    int insertar_en(std::string dato, int posicion);
    std::string tomar(int posicion);
    int buscar(std::string cancion);
    virtual int eliminar(int posicion);
    void mostrar_todo();
    int modificar(int posicion, std::string dato);
    virtual bool vacia();
    void purga();
    int tamano();
    virtual std::string tomar_primero();
};

#endif // LISTA_H
