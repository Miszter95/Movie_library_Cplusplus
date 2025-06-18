#ifndef DOKUMENTUM_FILMEK_H
#define DOKUMENTUM_FILMEK_H
#include <iostream>
#include "memtrace.h"
#include "filmek.h"

class Dokumentum_filmek: public Filmek
{
    public:
        Dokumentum_filmek(std::string,int,int,double,std::string);
        const std::string getLeiras() const;
        int getKorhatar() const;
    private:
        std::string leiras;

};

#endif
