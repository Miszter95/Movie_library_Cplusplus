#include "filmek.h"

//Filmek osztaly konstruktora, amely inicializalja az adattagjait

Filmek::Filmek(std::string cim_,int ki,int le,double IMDB):cim(cim_),kiadas(ki),lejatszas(le),IMDBpont(IMDB)
{
}

Filmek::~Filmek(){}
