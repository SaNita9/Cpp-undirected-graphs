#include <iostream>
#include <string>
#include "util.h"
#include "structure.h"
#include "test.h"
#include "def.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

void introducere(){
    string s =" Grafuri neorientate ";
    border(s, s.length());    
    cout<<"(proiect realizat de Niţă Sara)\n\n";
    ecran_nou(1);
    meniu_prin();
}

void iesire(){
    string s = " Vă mulţumesc!";
    border(s, s.length()-1);
}

void meniu_prin(){
    cout<<"\n1.  Definiţii"<<endl;
    cout<<"2.  Test"<<endl;
    cout<<"3.  Ieşire"<<endl;
    int opt = select(10);
    ecran_nou(2);
    switch(opt) {
        case 1:
            definitii();
            break;
        case 2:
            test();
            break;
        case 3:
            iesire();
            break;
        default:
            meniu_prin();
    }
}