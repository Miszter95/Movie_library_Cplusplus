#ifndef CSALADI_FILMEK_H
#define CSALADI_FILMEK_H
#include <iostream>
#include "memtrace.h"
#include "filmek.h"

class Csaladi_filmek: public Filmek
{
    public:
        Csaladi_filmek(std::string,int,int,double,int);
        int getKorhatar() const;
        const std::string getLeiras() const;
    private:
        int korhatar;
};

#endif
