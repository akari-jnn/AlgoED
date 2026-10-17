#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;

void numerosBinarios(int numero) {
    Cola cola;
    construir(cola);
    encolar(cola,{1});
    int contador=numero;
    while (true) {
        ElementoCola ele;
        ele=desencolar(cola);
        cout<<ele.codigo;
        contador--;
        if (contador==0) break;
        cout<<", ";
        encolar(cola,{ele.codigo*10});
        encolar(cola,{ele.codigo*10+1});
    }
}

int main() {
    int N;
    cout<<"Ingrese N: ";
    cin>>N;
    if (N>0) {
        cout<<"N = "<<N<<" => ";
        numerosBinarios(N);
    }else {
        cout<<"N debe ser mayor que 0"<<endl;
    }
    return 0;
}
