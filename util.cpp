#include <string>
#include <iostream>
#include <cstring>    
#include <string>
#include <chrono>
#include <thread>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void border(string str, int len){
    int i;
    cout<<"\n";
    for(i=0; i<=(len); i+=2)
        cout<<"* ";
    cout<<endl<<str<<endl;
    for(i=0; i<=(len); i+=2)
        cout<<"* ";
    cout<<endl<<endl;
}
void titlu(string t){
    int i;
    string line="";
    cout<<endl<<t<<endl;
    for(i=0; i<t.length()-1; i++)
        line+="-";
    cout<<line<<endl;
}

void ecran_nou(int mode){

    if(mode==1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Apăsaţi tasta \"Enter\" pentru a continua: ";
        char x[100];
        cin.getline(x, 100);
    }
    else if(mode==2)
        std::this_thread::sleep_for(std::chrono::nanoseconds(100));
    else if(mode==3){
            cout<<endl;
            cout<<"Apăsaţi tasta \"Enter\" pentru a reveni la meniul anterior: ";
            char x[100];
            cin.getline(x, 100);
        }
    else if(mode==4){
            cout<<"Apăsaţi tasta \"Enter\" pentru a continua: ";
            char x[100];
            cin.getline(x, 100);
        }

    if(system("clear")==-1)
        cout<<"A intervenit o eroare- vă rog, resetaţi programul!";
}

bool cifra(char c){
    if(c>='0' && c<='9')
        return 1;
    return 0;
}

bool litera(char c){
    if(c>='a' && c<='z')
        return 1;
    return 0;
}

bool is_number(char s[101]) {
    if (strlen(s) == 0) 
    return 0;
    for (int i = 0; s[i]; i++) {
        if (!cifra(s[i]) && s[i] != ' ')
            return 0;
    }
    return 1;
}

bool is_in_interval(char s[101], int a, int b){
    
    if (strlen(s) == 0) 
        return 0;
    
    int x = stoi(string(s));
    return (x>=a && x<=b);
}

int select(int n){
    char opt[101]=""; bool ok;
    do{
        ok=1;
        cout<<endl<<"Introduceţi opţiunea dorită: ";
        cin.getline(opt, 100);
        if(!is_number(opt))
            ok=0; 
        else if(!is_in_interval(opt, 1, n))
            ok=0;
        if(!ok)
            cout<<endl<<"Nu există aceasta opţiune. Încercaţi din nou.";
    }while(!ok);
    
    return stoi(string(opt));
}

void yesno(char s[101]){
    bool ok = 0;
    int i;
    do{
        cin.getline(s, 100);
        ok=1;
        for(i=0; i<strlen(s); i++){
            s[i]=(char)tolower(s[i]);
            if((s[i]>'a' && s[i]<='z' && s[i]!='d' && s[i]!='n' && s[i]!='u') || (cifra(s[i])))
                ok=0;
        }
        if(strlen(s)==0) ok=0;
        
        if(strstr(s, "da")&& strstr(s, "nu"))
            ok=0;
        if(strstr(s, "da")==NULL && strchr(s, 'd'))
            ok=0;
        if(strstr(s, "nu")==NULL && strchr(s, 'n'))
            ok=0;
        if(!ok)
            cout<<"Nu există aceasta opţiune. Încercaţi din nou."<<endl;
        
    }while(!ok);
}