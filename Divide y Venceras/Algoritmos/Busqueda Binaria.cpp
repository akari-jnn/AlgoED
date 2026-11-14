#include <iostream>
using namespace std;

void imprimirArreglo(const int *arreglo,int tam) {
    cout<<'{';
    for (int i=0;i<tam;i++) {
        cout<<arreglo[i];
        if (i!=tam-1) {
            cout<<',';
        }
    }
    cout<<'}'<<endl;
}

int busquedaBinaria(int *arreglo,int inicio,int fin,int numero) {
    if (inicio > fin) return -1;
    int medio=(inicio+fin)/2;
    if (arreglo[medio]==numero) {
        return medio;
    }
    if (arreglo[medio]<numero) {
        return busquedaBinaria(arreglo,medio+1,fin,numero);
    }
    return busquedaBinaria(arreglo,inicio,medio-1,numero);
}

int main() {
    int arreglo[]={8,11,17,21,23,37,53,56,64,87,90,94};
    int tam=sizeof(arreglo)/sizeof(arreglo[0]);
    imprimirArreglo(arreglo,tam);

    int numero=23;
    cout<<"Buscamos el numero: "<<numero<<endl;
    int posic=busquedaBinaria(arreglo,0,tam-1,numero);
    cout<<"Posicion: "<<posic;

    return 0;
}
