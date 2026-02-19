#include <iostream>
#include "util.h"
#include "structure.h"
using std::cin;
using std::cout;
using std::endl;

void definitii(){
    titlu("Graf neorientat");
    cout<<"Se numeşte graf neorientat, o pereche ordonată de mulţimi (X,U), unde:"<<endl;
    cout<<"* X este o mulţime finită şi nevidă (mulţimea vârfurilor sau nodurilor); \n* U este o mulţime de perechi neordonate de elemente din mulţimea X (mulţimea muchiilor).";
    cout<<"\nObservaţii: \n1. Pentru x, y ∈X, (x, y) sau [x, y] reprezintă o muchie; dacă există această muchie, spunem că x şi y sunt vârfuri adiacente în graf."<<endl;
    cout<<"2. Pentru muchia u = (x, y), vârful x este incident cu u, respectiv vârful y este incident cu muchia u."<<endl<<endl;

    titlu("Lanţ");
    cout<<"Se numeşte lanţ în graful neorientat G, o succesiune de vârfuri L = (x1, x2,…, xk), unde x1, x2,…, xkX, cu proprietatea că oricare două vârfuri consecutive sunt adiacente ( adică, există, în graf, muchiile (x1, x2),( x2, x3),…, (xk-1, xk))."<<endl<<endl;

    titlu("Ciclu");
    cout<<"Se numeşte ciclu în graful neorientat G, un lanţ C = (x1, x2,…, xk), unde x1, x2,…, xkX, cu proprietatea că x1 = xk şi muchiile (x1, x2), (x2, x3),…, (xk-1, xk) sunt distincte două câte două."<<endl<<endl;
    ecran_nou(4);
    
    titlu("Graf parţial");
    cout<<"Un graf parţial al unui graf G este un graf G1=(X, V), cu V  U. \nPentru un graf neorientat dat, un graf parţial poate fi graful însuşi sau se poate obţine dîn G păstrând toate vârfurile dar suprimând una sau mai multe muchii."<<endl<<endl;
     
    titlu("Subgraf");
    cout<<"Un subgraf al unui graf G este un graf G’ = (Y, V), cu Y  X şi V  U, unde V va conţine numai muchiile care au ambele extremităţi în noua mulţime Y. \nPentru un graf neorientat dat, un subgraf se poate obţine din G eliminând unul sau mai multe vârfuri şi pastrând doar acele muchii care au ambele extremităţi în mulţimea vârfurilor rămase."<<endl<<endl;

    titlu("Graf complet");
    cout<<"Un graf neorientat în care oricare două vârfuri sunt adiacente, se numeşte graf complet. \n \n";
    ecran_nou(4);
    
    titlu("Graf bipartit");
    cout<<"Un graf G=(X, U) se numeşte graf bipartit dacă există două mulţimi nevide A şi B astfel încât X=A ∪ B, A ∩ B = ∅ şi orice muchie u a lui G are o extremitate în A iar cealaltă în B. Mulţimile A şi B formează o partiţie a lui X." <<endl<<endl;   

    titlu("Graf bipartit complet");
    cout<<"Un graf bipartit G=(X,U) se numeşte bipartit complet dacă pentru oricare două vârfuri x∈A şi y∈B, există în graf muchia [x,y]; adică [x,y]∈U"<<endl<<endl;     
    ecran_nou(3);
    meniu_prin();
 }