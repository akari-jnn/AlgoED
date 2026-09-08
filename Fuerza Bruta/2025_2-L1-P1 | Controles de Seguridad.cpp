#include <iostream>
#include <cmath>
using namespace std;

int const CONTROLES = 8;

void imprimirRecursos(int combinacion) {
    bool esPrimero=true;
    for (int j = 0; j < CONTROLES; ++j) {
        if (combinacion%2==1) {
            if (esPrimero) {
                cout<<'{';
                esPrimero=false;
            }else {
                cout<<',';
            }
            cout<<j+1;
        }
        combinacion=combinacion/2;
    }
    cout<<'}';
}

int main() {
    int P,B,F;
    cout<<"La suma de costos no puede exceder: P = ";
    cin>>P;
    cout<<"La suma de beneficios debe ser estrictamente mayor igual que: B = ";
    cin>>B;
    cout<<"La suma de falsos negativos no debe superar: F = ";
    cin>>F;

    int costo[CONTROLES]={35000,24000,30000,27000,10000,7000,6000,40000};
    int beneficio[CONTROLES]={80,60,70,48,20,35,10,40};
    int falsosNegativos[CONTROLES]={1,3,2,1,1,2,1,3};

    int combinaciones=pow(2,CONTROLES);

    for (int i = 0; i < combinaciones; i++) {
        int combinacion=i;
        int sumaDeCostos=0;
        int sumaDeBeneficios=0;
        int sumaDeFalsosNegativos=0;
        for (int j = 0; j < CONTROLES; ++j) {
            if (combinacion%2==1) {
                sumaDeCostos+=costo[j];
                sumaDeBeneficios+=beneficio[j];
                sumaDeFalsosNegativos+=falsosNegativos[j];
            }
            combinacion=combinacion/2;
        }
        if (sumaDeCostos<=P and sumaDeBeneficios>=B and sumaDeFalsosNegativos<=F) {
            cout<<"Recursos: ";
            imprimirRecursos(i);
            cout<<", Costo total: "<<sumaDeCostos<<", Beneficio: "<<sumaDeBeneficios
                <<", Falsos Negativos: "<<sumaDeFalsosNegativos<<endl;
        }
    }

    return 0;
}
