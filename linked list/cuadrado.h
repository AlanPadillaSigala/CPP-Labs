#ifndef CUADRADO_H
#define CUADRADO_H
#include <iostream>

class Cuadrado{
private:
    int num;
public:
    Cuadrado(int num = 0);
    friend  std::ostream& operator << (std::ostream &, const Cuadrado&);
    friend std::istream& operator >> (std::istream &, Cuadrado&);
    bool operator == (const Cuadrado&);
};

#endif // CUADRADO_H
