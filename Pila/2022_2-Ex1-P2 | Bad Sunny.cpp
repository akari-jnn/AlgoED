#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void correcionesMusicales(int nTiempos,int *frecuencias) {
    Pila pila;
    construir(pila);

    int durMax=0,freqMax=0,maxArea=0;
    for (int i = 0; i <= nTiempos; i++) {
        int freqActual = (i == nTiempos) ? 0 : frecuencias[i];

        while (!esPilaVacia(pila) and freqActual < frecuencias[cima(pila).numero]) {
            int idxDesapilado = desapilar(pila).numero;
            int h = frecuencias[idxDesapilado];

            int izq;
            if (esPilaVacia(pila)) {
                izq=0;
            }else {
                izq=cima(pila).numero + 1;
            }
            int der = i - 1;
            int duracion = der - izq + 1;
            int area = h * duracion;
            if (area > maxArea) {
                maxArea = area;
                freqMax = h;
                durMax = duracion;
            }
        }
        if (i < nTiempos) {
            apilar(pila, {i});
        }
    }
    destruir(pila);

    cout<<"Frecuencia: "<<freqMax<<endl;
    cout<<"Tiempo: "<<durMax<<endl;
}

int main() {
    int frecuencias[11]={1,2,1,4,5,6,4,5,2,2,1};
    correcionesMusicales(11,frecuencias);
    return 0;
}
