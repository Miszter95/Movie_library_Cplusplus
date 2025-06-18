#include "dokumentum_filmek.h"

//Az adattagok beallito fuggvenye

Dokumentum_filmek::Dokumentum_filmek(std::string cim_,int kiadas_,int lejatszas_,double pont,std::string leir):Filmek(cim_,kiadas_,lejatszas_,pont),leiras(leir)
{
}

const std::string Dokumentum_filmek::getLeiras() const{         //Adattagok visszaadasa függvények
    return leiras;
}

int Dokumentum_filmek::getKorhatar() const{
    return -1;
}

