#ifndef PILA_H
#define PILA_H
#include "lista.h"

#define NADA 0
#define LONG_CADENA 1

class Pila : public Lista {
private:
    Nodo *cima;
public:
    Pila();
    int insertar(std::string dato) override;
    int eliminar(int) override;
    std::string tomar_primero() override;
    void todo();
};

//funcion externa a clase para analizar sintaxis
int analizador_sintaxis();

#endif // PILA_H
