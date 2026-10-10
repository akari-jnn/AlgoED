#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
#define MAX 100

void encontrarMayCantPilasPeque(int cantNum, int *num) {
    int pilasMenores[MAX];

    Pila pila1;
    construir(pila1);
    int ant;
    //De izquierda a derecha
    for (int i = 0; i < cantNum; i++) {
        while (not esPilaVacia(pila1) and num[i] > num[cima(pila1).numero]) {
            desapilar(pila1);
        }
        if (esPilaVacia(pila1)) {
            ant=-1;
        }else {
            ant=cima(pila1).numero;
        }
        pilasMenores[i] = i-ant-1;
        apilar(pila1,{i});
    }
    destruir(pila1);

    Pila pila2;
    construir(pila2);
    for (int i=cantNum-1;i>=0;i--) {
        while (not esPilaVacia(pila2) and num[i] > num[cima(pila2).numero]) {
            desapilar(pila2);
        }
        if (esPilaVacia(pila2)) {
            ant=cantNum;
        }else {
            ant=cima(pila2).numero;
        }
        pilasMenores[i] += ant-i-1;
        apilar(pila2,{i});
    }
    destruir(pila2);

    int maxPilasMenores=-1,posMaxPilasMenores;
    for (int i=0;i<cantNum;i++) {
        if (pilasMenores[i] > maxPilasMenores) {
            maxPilasMenores = pilasMenores[i];
            posMaxPilasMenores = i;
        }
    }
    cout<<"Posicion = "<<posMaxPilasMenores<<", con "
        <<maxPilasMenores<<" pilas pequenas alrededor."<<endl;
}

int main() {
    int cantNum;
    cout<<"Ingrese la cantidad de numeros: ";
    cin>>cantNum;

    int numeros[MAX];
    cout<<"Ingrese los numeros: "<<endl;
    for(int i=0;i<cantNum;i++) {
        cin>>numeros[i];
    }

    encontrarMayCantPilasPeque(cantNum, numeros);

    return 0;
}
