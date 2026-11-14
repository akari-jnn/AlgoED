#include <iostream>
using namespace std;

void imprimirArreglo(const int *arreglo,int tam) {
    cout<<'{';
    for (int i=0;i<tam;i++) {
        cout<<arreglo[i];
        if (i!=tam-1) {
            cout<<", ";
        }
    }
    cout<<'}'<<endl;
}

void merge(int *arreglo,int inicio,int medio,int fin) {
    int n1_izq = medio - inicio + 1;
    int n2_der = fin - medio;

    int izquierda[n1_izq];
    int derecha[n2_der];

    for (int i = 0; i < n1_izq; i++) {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < n2_der; j++) {
        derecha[j] = arreglo[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    for (int k = inicio; k <= fin; k++) {
        if (i < n1_izq and (j >= n2_der or izquierda[i] <= derecha[j])) {
            arreglo[k] = izquierda[i];
            i++;
        } else {
            arreglo[k] = derecha[j];
            j++;
        }
    }
}

void mergesort(int *arreglo,int inicio,int fin) {
    if (inicio<fin) {
        int medio=(inicio+fin)/2;
        mergesort(arreglo,inicio,medio);
        mergesort(arreglo,medio+1,fin);
        merge(arreglo,inicio,medio,fin);
    }
}

int main() {
    int arreglo[]={64,21,94,56,23,87,11,8,53,90,17,37};
    int tam=sizeof(arreglo)/sizeof(arreglo[0]);

    imprimirArreglo(arreglo,tam);

    mergesort(arreglo,0,tam-1);

    imprimirArreglo(arreglo,tam);

    return 0;
}
