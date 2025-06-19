#ifndef FILMEK_H
#define FILMEK_H
#include <iostream>
#include "memtrace.h"

class Filmek
{
    public:
        Filmek(std::string,int,int,double);
        std::string getCim() const { return  cim; }
        int getKiadas() const { return  kiadas; }
        int getLejatszas() const { return  lejatszas; }
        double getIMDBpont() const { return  IMDBpont; }
        virtual const std::string getLeiras() const = 0;
        virtual int getKorhatar() const = 0;
        virtual ~Filmek();
    private:
        std::string cim;
        int kiadas;
        int lejatszas;
        double IMDBpont;

};

#endif
