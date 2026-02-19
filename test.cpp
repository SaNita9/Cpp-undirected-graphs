#include "structure.h"
#include "util.h"
#include <iostream>
#include <cstring>

using namespace std;

float sround(float var){
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

int citire_numar(){
    bool ok; char s[101];
    do{
        ok=1;
        cout<<"Răspuns: ";
        cin.getline(s, 100);
        if(!is_number(s)){
            cout<<"Valoare invalidă. Încercaţi din nou.\n";
        ok=0; 
        }
        else
            return stoi(string(s));
    }while(!ok);
    return -1;
}

void citire_cuvant(char s[1000]){
    bool ok, inceput = 1; int i;
        do{
            cout<<"Răspuns: ";
            cin.getline(s, 999);
            ok=1;
            for(i=0; i<strlen(s) && ok; i++){
                s[i]=tolower(s[i]);
                if(!litera(s[i]) && s[i]!=' '){
                    ok=0;
                    cout<<"Cuvântul nu poate conţine caractere speciale(inclusiv diactritice) sau cifre. \n";
                }
            
            }
            if(strlen(s)==0) ok=0;
        }while(!ok);
}

char citire_grila(){
    bool ok; char s[1000]; int v[4], i;
    do{
        cout<<"Introduceţi varianta a, b, c sau d: ";
        cin.getline(s, 999);
        ok=1;
        v[0]=v[1]=v[2]=v[3]=0;
        for(i=0; i<strlen(s) && ok; i++){
            s[i]=tolower(s[i]);
            if(!litera(s[i]) && !cifra(s[i]) == 1){
                strcpy(s+i, s+i+1);
                i--;
            }
            if(cifra(s[i]) || !strchr("abcd", s[i]))
                ok=0;
            v[s[i]-'a']=1;
        }
        if(v[0]+v[1]+v[2]+v[3]!=1)
            ok=0;
        if(!ok)
            cout<<endl<<"Nu există aceasta opţiune. Încercaţi din nou.\n";
    }while(!ok);
    return s[0];
}

bool check_ans(int rx, char rc, char rs[50], int mode){
    bool corect=0;
    if(mode==1){
        int x;
        x= citire_numar();
        if (x==rx){
            cout<<"Raspuns corect!"<<endl<<endl;
            corect=1;
        }
        else 
            cout<<"Raspuns greşit! Varianta corectă era "<<rx<<"."<<endl<<endl;
            
    }else if(mode==2){
        char s[1000];
        citire_cuvant(s);
        if(strstr(s, rs)){
            cout<<"Răspuns corect!"<<endl<<endl;
            corect=1;
        }
        else 
            cout<<"Răspuns greşit! Varianta corectă era \""<<rs<<"\"."<<endl<<endl;
    }
    else if(mode==3){
        char c;
        c=citire_grila();
        if (c==rc){
            cout<<"Răspuns corect!"<<endl<<endl;
            corect=1;
        }
        else 
            cout<<"Răspuns greşit! Varianta corectă era "<<rc<<")."<<endl<<endl;
    }
    
    ecran_nou(4); 
    return corect;
}

void test(){
    
    float score=0, nota;
    char c_null=' ', s_null[50]=" ", rs[50]; 
    titlu("Exerciţii şi probleme pentru fixarea cunoştinţelor");
    cout<<"Acest test conţine 12 itemi.\n\n";
    cout<<"Apăsaţi tasta \"Enter\" pentru a trece la prima întrebare.\n";
    cin.getline(rs,49);
    ecran_nou(2);
//1
    cout<<"1. Care este gradul maxim posibil pentru un nod dintr-un arbore cu 10 noduri?"<<endl;
    if(check_ans(9, c_null, s_null, 1))
        score++;
//2
    cout<<"2. Scrieţi cuvântul care completează enunţul: Într-un graf neorientat, muchia (a,b) este [...] cu un vârfurile a şi b.  \n";
    strcpy(rs, "incidenta");
    if (check_ans(0, c_null, rs , 2))
        score++;
//3
    cout<<"3. Câte grafuri neorientate, distincte, cu 4 vârfuri, se pot construi? Două grafuri se consideră distincte dacă matricele lor de adiacenţă sunt diferite."<<endl;
    cout<<" a) 24 \n b) 4 \n c) 4^6  \n d) 2^6 \n";
    if (check_ans(0, 'd', s_null, 3))
        score++;
//4
    cout<<"4. Se consideră graful neorientat cu 8 noduri, numerotate de la 1 la 8, şi muchiile [1,2], [1,6], [1,7], [2,3], [2,6], [3,6], [3,4], [4,5], [4,8], [5,6], [7,8]. Care este gradul minim al unui nod din acest graf?"<<endl;
    if (check_ans(2, c_null, s_null, 1))
        score++;
//5    
    cout<<"5. Fie n un număr natural impar mai mare decât 2 şi G un graf neorientat cu n noduri, în care fiecare nod este adiacent cu exact n-1 noduri. Graful G este întotdeauna (în afară de conex):"<<endl;
    strcpy(rs, "eulerian");
    if (check_ans(0, c_null, rs , 2))
        score++;
//6    
    cout<<"6. Matricea de adiacenţă a unui graf neorientat G are numărul valorilor de 1 egal cu jumătate din numărul valorilor de 0. Care dintre numerele de mai jos poate fi numărul de noduri ale grafului G?"<<endl;
    cout<<" a) 11 \n b) 12 \n c) 13 \n d) 14 \n";   
    if (check_ans(0, 'b', s_null, 3))
        score++;
//7    
    cout<<"7. Se consideră un graf neorientat G cu 12 noduri şi 7 muchii. Care este numărul maxim de componente conexe din care poate fi format graful G?"<<endl;
    if (check_ans(8, c_null, s_null, 1))
        score++;
//8    
    cout<<"8. Cum se numeşte un graf neorientat în care există drum între oricare două vârfuri?  \n";
    strcpy(rs, "conex");
    if (check_ans(0, c_null, rs , 2))
        score++;
//9    
    cout<<"9. Într-un graf neorientat cu 20 muchii, fiecare nod al grafului are gradul un număr nenul. Doar patru dintre noduri au gradul un număr par, restul nodurilor având gradele numere impare."<<endl;
    cout<<"Care este numărul maxim de noduri pe care poate să le aibă graful? (Introduceţi varianta a, b, c sau d)\n";
    cout<<" a) 36 \n b) 32 \n c) 16 \n d) 10 \n";
    if (check_ans(0, 'a', s_null, 3))
        score++;
//10    
    cout<<"10. Se consideră graful neorientat definit prin mulţimea vârfurilor {1,2,3,4,5,6} şi mulţimea muchiilor {[1,2],[2,3],[3,4],[3,5],[4,5],[1,3],[2,6],[2,4],[4,6]}."<<endl;
    cout<<"Care este numărul minim de muchii ce pot fi eliminate astfel încât graful parţial obţinut să nu mai fie conex?\n";
    if (check_ans(2, c_null, s_null, 1))
        score++;
//11    
    cout<<"11. Cum se numeşte un drum care vizitează o singură dată toate vârfurile unui graf?\n";
    strcpy(rs, "hamiltonian");
    if (check_ans(0, c_null, rs , 2))
        score++;
//12    
    cout<<"12. Care este numărul de muchii care trebuie eliminate dintr-un graf neorientat, complet, cu 7 noduri, astfel încât graful parţial obţinut să fie arbore?"<<endl;
    cout<<" a) 1 \n b) 15 \n c) 6 \n d) 21 \n";
    if (check_ans(0, 'b', s_null, 3))
        score++;
//nota
    cout<<endl;
    nota = sround(score/12)*10;
    cout<<"Aţi obtinut nota "<<nota<<"/10 ("<<score<<"/12 răspunsuri corecte)"<<endl;
    if (score>=8)
        cout<<"Felicitări! \n";
    else if(score>=5)
        cout<<"Mai încercaţi! Sunteţi pe drumul cel bun!\n";
    else if(score>=0)
        cout<<"Of! Mai încercaţi!\n";
    
    ecran_nou(3);
    meniu_prin();
}
