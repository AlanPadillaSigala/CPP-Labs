#ifndef COLA_H
#define COLA_H
#include "lista.h"

#define NADA 0

class Cola : public Lista{
private:
    Nodo *inicio;
    Nodo *fin;
public:
    Cola();
    int insertar(std::string dato)override;
    int eliminar(int)override;
    std::string tomar_primero()override;
    bool vacia()override;
    void todo();

};

enum Menu{
    NOMBRE=1,
    SIG_TURNO,
    SALIR
};

void menu_funcion();

#endif // COLA_H
