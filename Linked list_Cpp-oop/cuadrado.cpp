#include "cuadrado.h"

Cuadrado::Cuadrado(int num){
    //eleva al cuadrado
    this->num= num * num;
}

std::ostream& operator << (std::ostream &out, const Cuadrado&numero){
    out<<numero.num;
    return out;
}

std::istream& operator >> (std::istream &in, Cuadrado&numero){
    in>>numero.num;
    return in;
}

bool Cuadrado::operator == (const Cuadrado&numer){
    bool n3;
    n3 = this->num = numer.num;
    return n3;
}
