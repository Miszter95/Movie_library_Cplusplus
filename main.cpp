#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include "memtrace.h"
#include "filmek.h"
#include "csaladi_filmek.h"
#include "dokumentum_filmek.h"
#include "filmtar.h"

template<class tipus>
tipus bemenetlekerdezes(int valasztipus){                //felhasználó általi bemenet kezelése
    std::string valasztszoveg ="";
    std::string valaszts = "";
    int szhossz = 0;
    int sorszam = 0;
    bool igennem = true;
    do{
    std::cin>>valasztszoveg;
    igennem = true;
    sorszam = 0;
    szhossz = valasztszoveg.length();
    for(int i=0;i<szhossz;i++){
    if(sorszam<1){
        if(valasztszoveg[i]=='.'){
                i++;
        if((isdigit(valasztszoveg[i]))!= true){
            std::cout<<"Nem szamot irtal be!\nProbald ujra!"<<std::endl;
            sorszam++;
            igennem = false;
    }}}}
    }while(igennem != true);
    if(valasztipus == 0){
    int valasztas = atoi(valasztszoveg.c_str());
    return valasztas;}
    else if(valasztipus == 1){
    double valasztas = atof(valasztszoveg.c_str());
    return valasztas;
    }
    return 0;
}

int main()
{
    std::string szoveg = "";
    int valaszto = 0;
    std::string cim = "";
    int lejido = 0;
    int kiadas = 0;
    double pont = 0.0;
    int kor = 0;
    std::string leir = "";
    int sor = 0;
    std::string szovege = "";
    int kiad = 0;
    int lejatsz = 0;
    double IMDB = 0.0;
    int valasz = 0;
    int valasza = 0;
    int valaszom = 0;
    int addvalasz = 0;

    std::ifstream mreadpointer;       //a fajl megnyitasa es hibakezeles ha nem sikerul
    mreadpointer.open("filmek.txt");
    if(mreadpointer.fail()){
        std::cout<<"Hiba a fajl megnyitasakor!\nA program leall!"<<std::endl;
        return 0;
    }

    Filmtar film;
    std::cout<<"Filmtar\n"<<"Keszitette: Boldizsar Andras\n"<<std::endl;
    while(!mreadpointer.eof())        //betoltom a programba a faljbol az adatokat
    {
        std::getline(mreadpointer,szoveg);
        if(sor!=7){
        sor++;}
        else{
        sor=0;
        sor++;}
        if(sor==1){
        valaszto = atoi(szoveg.c_str());}
        else if(sor==2){
        cim = szoveg;}
        else if(sor==3){
        kiadas = atoi(szoveg.c_str());}
        else if(sor==4){
        lejido = atoi(szoveg.c_str());}
        else if(sor==5){
        pont = atof(szoveg.c_str());}
        if(valaszto==1 && sor==6){
        kor = atoi(szoveg.c_str());
        film.berak(new Csaladi_filmek(cim,kiadas,lejido,pont,kor));
        }
        else if(valaszto==2 && sor==6){
        leir = szoveg;
        film.berak(new Dokumentum_filmek(cim,kiadas,lejido,pont,leir));
        }
        }
    mreadpointer.close();
    do{                                         //Menurendszer
            std::cout<<"Valaszd ki melyik opciot szeretned! (szamokkal)"<<std::endl;
            std::cout<<"1: A filmek kiirasa minden adataval\n2: A filmek kozotti kereses valamilyen feltetellel\n3: A filmek rendezese\n4: A filmek kiirasa egy fajlba!\n5: Uj tag felvetele\n6: Exit"<<std::endl;
            std::cout<<std::endl;
            valasz = bemenetlekerdezes<int>(0);
            std::cout<<std::endl;
        switch(valasz){
           case 1:
               film.kiir();
               break;
           case 2:
                do{
    std::cout<<"Valaszd ki mi szerint szeretnel keresni! (szamokkal)"<<std::endl;
    std::cout<<"1: Cim szerinti\n2: Kiadasi ev szerinti\n3: Lejatszasi ido szerinti\n4: IMDB pont szerinti\n5: Exit"<<std::endl;
    std::cout<<std::endl;
    valasza = bemenetlekerdezes<int>(0);
    std::cout<<std::endl;
    switch(valasza){
        case 1:
            std::cout<<"Ird be a keresett film cimet!"<<std::endl;
            std::cin.ignore();
            std::getline (std::cin,szovege);
            std::cout<<std::endl;
            film.ckeres(szovege);
            std::cout<<std::endl;
            break;
        case 2:
            std::cout<<"Ird be a keresett film kiadasi evet!"<<std::endl;
            kiad = bemenetlekerdezes<int>(0);
            std::cout<<std::endl;
            film.kkeres(kiad);
            std::cout<<std::endl;
            break;
        case 3:
            std::cout<<"Ird be a keresett film lejatszasi idejet! (percben)\nAz ennel rovidebb filmeket is meg fogja jeleniteni!"<<std::endl;
            lejatsz = bemenetlekerdezes<int>(0);
            std::cout<<std::endl;
            film.lkeres(lejatsz);
            std::cout<<std::endl;
            break;
        case 4:
            std::cout<<"Ird be a keresett film IMDB pontjat!"<<std::endl;
            IMDB = bemenetlekerdezes<double>(1);
            std::cout<<std::endl;
            film.pkeres(IMDB);
            std::cout<<std::endl;
            break;
        case 5:
            break;
        default:
            std::cout<<"Rossz szamot irtal be!\nProbald ujra!"<<std::endl;
            std::cout<<std::endl;
            break;
    }
                }while(valasza!=5);
            break;
        case 3:
             do{
    std::cout<<"Valaszd ki mi szerint szeretnel rendezni! (szamokkal)"<<std::endl;
    std::cout<<"1: Cim szerinti\n2: Kiadasi ev szerinti\n3: Lejatszasi ido szerinti (perc)\n4: IMDB pont szerinti\n5: Exit"<<std::endl;
    std::cout<<std::endl;
    valaszom = bemenetlekerdezes<int>(0);
    std::cout<<std::endl;
    switch(valaszom){
        case 1:
            film.rendez(valaszom);
            break;
        case 2:
            film.rendez(valaszom);
            break;
        case 3:
            film.rendez(valaszom);
            break;
        case 4:
            film.rendez(valaszom);
            break;
        case 5:
            break;
        default:
            std::cout<<"Rossz szamot irtal be!\nProbald ujra!"<<std::endl;
            std::cout<<std::endl;
            break;
    }
                }while(valaszom!=5);
            break;
        case 4:
            film.fajlbakiir();
            std::cout<<"A filmek kiirasa a lemasolt.txt fajlba!"<<std::endl;
            std::cout<<std::endl;
            break;
        case 5:
            do{
            std::cout<<"Valaszd ki milyen tipusu filmet szeretnel felvenni! (szammal)"<<std::endl;
            std::cout<<"1: Csaladi film\n2: Dokumentum film\n3: Exit"<<std::endl;
            std::cout<<std::endl;
            addvalasz = bemenetlekerdezes<int>(0);
            if(addvalasz!=1 && addvalasz!=2 && addvalasz!=3){
            std::cout<<"Rossz szamot irtal be!\nProbald ujra!"<<std::endl;
            std::cout<<std::endl;
            }
            if(addvalasz==1 || addvalasz==2){
            std::cout<<"Add meg a film cimet! (ekezet nelkul)"<<std::endl;
            std::cin.ignore();
            std::getline (std::cin,cim);
            std::cout<<std::endl;
            std::cout<<"Add meg a film kiadasi evet!"<<std::endl;
            kiadas = bemenetlekerdezes<int>(0);
            std::cout<<std::endl;
            std::cout<<"Add meg a film lejatszasi idejet! (percben)"<<std::endl;
            lejido = bemenetlekerdezes<int>(0);
            std::cout<<std::endl;
            std::cout<<"Add meg a film IMDB pontjat!"<<std::endl;
            IMDB = bemenetlekerdezes<double>(1);
            std::cout<<std::endl;
            }
            if(addvalasz==1){
                std::cout<<"Add meg a film korhatarat!"<<std::endl;
                kor = bemenetlekerdezes<int>(0);
                film.berak(new Csaladi_filmek(cim,kiadas,lejido,pont,kor));
                std::cout<<std::endl;
            }
            else if(addvalasz==2){
                std::cout<<"Add meg a film leirasat! (ekezet nelkul)"<<std::endl;
                std::cin.ignore();
                std::getline (std::cin,leir);
                film.berak(new Dokumentum_filmek(cim,kiadas,lejido,pont,leir));
                std::cout<<std::endl;
            }
            }while(addvalasz!=1 && addvalasz!=2 && addvalasz!=3);
            break;
        case 6:
            break;
        default:
            std::cout<<"Rossz szamot irtal be!\nProbald ujra!"<<std::endl;
            std::cout<<std::endl;
            break;
        }
    }while(valasz!=6);

    return 0;
}
