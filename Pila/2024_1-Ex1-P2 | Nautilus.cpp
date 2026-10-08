#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
#define MAX 100

void imprimirCamino(int n,char *instrucciones) {
    Pila pila;
    construir(pila);

    //Recorremos las instrucciones
    for(int i=0;i<=n;i++) {
        if (instrucciones[i]=='S' or i==n) {
            cout<<i+1<<' ';
            while (not esPilaVacia(pila)) {
                cout<<desapilar(pila).numero<<' ';
            }
        }else if (instrucciones[i]=='B') {
            apilar(pila,{i+1});
        }else {
            cout<<"ERROR: Instruccion incorrecta. Solo ingresar 'S' o 'B'."<<endl;
            destruir(pila);
            break;
        }
    }

    destruir(pila);
}

int main() {
    char instrucciones[MAX];
    cout<<"Ingresa las instrucciones sin espacios (Ej. SSBS):";
    cin>>instrucciones;

    int cantInstrucciones=0;
    for(int i=0;instrucciones[i];i++) {
        cantInstrucciones++;
    }

    imprimirCamino(cantInstrucciones,instrucciones);

    return 0;
}
