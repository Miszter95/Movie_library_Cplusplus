#include "csaladi_filmek.h"

//Az adattagok beallito fuggvenye

Csaladi_filmek::Csaladi_filmek(std::string cim_,int kiadas_,int lejatszas_,double pont,int kor):Filmek(cim_,kiadas_,lejatszas_,pont),korhatar(kor)
{
}

int Csaladi_filmek::getKorhatar() const {           //Adattagok visszaadasa fuggvenyek
    return korhatar;
}

const std::string Csaladi_filmek::getLeiras() const{
    return "";
}
