#include <iostream>
#include "BibliotecaPila/ElementoPila.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"

using namespace std;

void hallarIncrementos(int cantContagios,int *contagiados, int *arregloResultado) {
    Pila pilaAux;
    construir(pilaAux);

    for (int i = 0; i < cantContagios; i++) {
        while (true) {
            if (esPilaVacia(pilaAux)) {
                arregloResultado[i]=i;
                break;
            }
            if (contagiados[cima(pilaAux).numero]<=contagiados[i]) {
                desapilar(pilaAux);
            }else {
                arregloResultado[i]=i-cima(pilaAux).numero-1;
                break;
            }
        }
        apilar(pilaAux,{i});
    }

    destruir(pilaAux);
}


int main() {
    int cantContagios;
    cout<<"Ingresa la cantidad de contagios diarios: ";
    cin>>cantContagios;

    int contagiados[cantContagios];
    for (int i = 0; i < cantContagios; i++) {
        cin>>contagiados[i];
    }

    int arregloResultado[cantContagios];
    hallarIncrementos(cantContagios,contagiados,arregloResultado);

    for (int i = 0; i < cantContagios; i++) {
        cout<<arregloResultado[i]<<' ';
    }

    return 0;
}
