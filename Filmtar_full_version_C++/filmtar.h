#ifndef FILMTAR_H
#define FILMTAR_H
#include <string.h>
#include <fstream>
#include "memtrace.h"
#include "filmek.h"

class Filmtar
{
    public:
        Filmtar();
        ~Filmtar();
        void berak(Filmek*);
        void kiir();
        void ckeres(std::string);
        void kkeres(int);
        void lkeres(int);
        void pkeres(double);
        void fajlbakiir();
        void rendez(int);
        void kiiras(Filmek*);

    private:
        Filmek** Tarolo;
        int meret;
};

#endif
