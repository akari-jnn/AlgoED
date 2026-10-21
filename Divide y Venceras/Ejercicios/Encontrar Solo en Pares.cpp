#include <iostream>
using namespace std;

int encontrarSoloEnPares(int *arreglo,int inicio,int fin) {
    if (inicio==fin) return arreglo[inicio];
    int medio=(inicio+fin)/2;
    if (medio%2==0) {
        if (arreglo[medio]==arreglo[medio+1]) {
            return encontrarSoloEnPares(arreglo,medio+2,fin);
        } else {
            return encontrarSoloEnPares(arreglo,inicio,medio);
        }
    }else {
        if (arreglo[medio]==arreglo[medio-1]) {
            return encontrarSoloEnPares(arreglo,medio+1,fin);
        }else {
            return encontrarSoloEnPares(arreglo,inicio,medio-1);
        }
    }
}

int main() {
    int arreglo[11]={1,1,3,3,4,5,5,7,7,8,8};
    int numeroSolo=encontrarSoloEnPares(arreglo,0,10);
    cout<<numeroSolo;
    return 0;
}
