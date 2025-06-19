#include "filmtar.h"

void Filmtar::kiiras(Filmek* film){
    std::cout<<film->getCim()<<std::endl;
    std::cout<<film->getKiadas()<<std::endl;
    std::cout<<film->getLejatszas()<<std::endl;
    std::cout<<film->getIMDBpont()<<std::endl;
    if(film->getKorhatar()!=-1)
    std::cout<<film->getKorhatar()<<std::endl;
    if(film->getLeiras()!="")
    std::cout<<film->getLeiras()<<std::endl;
    std::cout<<std::endl;

}

Filmtar::Filmtar()              //A Filmtar osztaly adattagjainak kezdoerteket ad
{
    meret = 0;
    Tarolo = new Filmek*[meret];
}

void Filmtar::berak(Filmek* film){                 //A Taroloba berak egy tagot
    Filmek** temp = new Filmek*[meret+1];
    for(int i=0;i<meret;++i){
        temp[i] = Tarolo[i];
    }
    delete [] Tarolo;
    temp[meret]  = film;
    meret++;
    Tarolo = temp;
}

Filmtar::~Filmtar(){                //A Tarolo destruktora
    for(int i=0;i<meret;++i){
        delete Tarolo[i];
    }
    delete [] Tarolo;
}

void Filmtar::kiir(){               //A Tarolo tagjainak kiiratasa
    for(int i=0;i<meret;++i){
        std::cout<<Tarolo[i]->getCim()<<std::endl;
        std::cout<<Tarolo[i]->getKiadas()<<std::endl;
        std::cout<<Tarolo[i]->getLejatszas()<<std::endl;
        std::cout<<Tarolo[i]->getIMDBpont()<<std::endl;
        if(Tarolo[i]->getKorhatar()!=-1)
        std::cout<<Tarolo[i]->getKorhatar()<<std::endl;
        if(Tarolo[i]->getLeiras()!="")
        std::cout<<Tarolo[i]->getLeiras()<<std::endl;
        std::cout<<std::endl;
    }
}

void Filmtar::ckeres(std::string szoveg){     //A Taroloban cim szerint keres
    int sora = 0;
    for(int i=0;i<meret;++i){
        std::string c = Tarolo[i]->getCim();
        if(c.compare(szoveg)==0){
        kiiras(Tarolo[i]);
    }
    else{
        sora++;
        if(sora==meret){
        std::cout<<"Ilyen film nem talalhato!"<<std::endl;
        std::cout<<std::endl;}}
        }
}

void Filmtar::kkeres(int szam){             //A Taroloban kiadasi ev szerint keres
    int sora = 0;
    for(int i=0;i<meret;++i){
        if(Tarolo[i]->getKiadas()==szam){
        kiiras(Tarolo[i]);
    }
   else{
        sora++;
        if(sora==meret){
        std::cout<<"Ilyen film nem talalhato!"<<std::endl;
        std::cout<<std::endl;}}
        }
}

void Filmtar::lkeres(int szam){                 //A Taroloban lejatszasi ido szerint keres
    int sora = 0;
    for(int i=0;i<meret;++i){
        if(Tarolo[i]->getLejatszas()<=szam){
        kiiras(Tarolo[i]);
   }
    else{
        sora++;
        if(sora==meret){
        std::cout<<"Ilyen film nem talalhato!"<<std::endl;
        std::cout<<std::endl;}}
    }}

void Filmtar::pkeres(double szam){                  //A Taroloban IMDB pont szerint keres
   int sora = 0;
   for(int i=0;i<meret;++i){
        if(Tarolo[i]->getIMDBpont()==szam){
        kiiras(Tarolo[i]);
    }
    else{
        sora++;
        if(sora==meret){
        std::cout<<"Ilyen film nem talalhato!"<<std::endl;
        std::cout<<std::endl;}}
}}

void Filmtar::fajlbakiir(){                 //A Tarolo tagjait kiirja a lemasolt.txt fajlba
    std::ofstream fout("lemasolt.txt");
    if(fout.is_open()){
    for(int i=0;i<meret;++i){
        if(Tarolo[i]->getKorhatar()>-1){
            fout<<1<<std::endl;}
        else {
            fout<<2<<std::endl;}
        fout<<Tarolo[i]->getCim()<<std::endl;
        fout<<Tarolo[i]->getKiadas()<<std::endl;
        fout<<Tarolo[i]->getLejatszas()<<std::endl;
        fout<<Tarolo[i]->getIMDBpont()<<std::endl;
        if(Tarolo[i]->getKorhatar()!=-1)
        fout<<Tarolo[i]->getKorhatar()<<std::endl;
        if(Tarolo[i]->getLeiras()!="")
        fout<<Tarolo[i]->getLeiras()<<std::endl;
        fout<<std::endl;
        }}
        fout.close();
}

void Filmtar::rendez(int szam){                 //A Tarolot rendezo fuggveny, amely
    Filmek* csere;                              //a parameterként kapott szam szerint rendez
    for(int i=meret-1;0<i;--i){
        for(int j=0;j<i;++j){
            const char * c = Tarolo[j]->getCim().c_str();
            const char * d = Tarolo[j+1]->getCim().c_str();
            if(strcmp(c,d)>0 && szam==1){
            csere = Tarolo[j];
            Tarolo[j] = Tarolo[j+1];
            Tarolo[j+1] = csere;
            }
            else if(Tarolo[j]->getKiadas()>Tarolo[j+1]->getKiadas() && szam==2){
            csere = Tarolo[j];
            Tarolo[j] = Tarolo[j+1];
            Tarolo[j+1] = csere;
            }
            else if(Tarolo[j]->getLejatszas()>Tarolo[j+1]->getLejatszas() && szam==3){
            csere = Tarolo[j];
            Tarolo[j] = Tarolo[j+1];
            Tarolo[j+1] = csere;
        }
        else if(Tarolo[j]->getIMDBpont()>Tarolo[j+1]->getIMDBpont() && szam==4){
            csere = Tarolo[j];
            Tarolo[j] = Tarolo[j+1];
            Tarolo[j+1] = csere;
        }
    }
}
}

