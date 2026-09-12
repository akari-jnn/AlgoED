#include <iostream>
#include <cmath>
using namespace std;

const int TABLAS = 6;
const int DISCOS = 3;

void imprimirTablasDisco(int combinacion, int disco) {
    bool esPrimero=true;
    cout<<"Disco "<<disco+1<<": ";
    for (int i=0;i<TABLAS;i++) {
        if (combinacion%DISCOS==disco) {
            if (esPrimero) {
                esPrimero=false;
            }else {
                cout<<", ";
            }
            cout<<i+1;
        }
        combinacion=combinacion/DISCOS;
    }
}

int main() {
    int tablas[TABLAS] = {150, 100, 80, 50, 120, 10};
    int discos[DISCOS] = {250, 200, 200};
    int combinaciones = pow(DISCOS, TABLAS);
    int mayorPerformance=-1;
    int discoPerformance,combinacionMenorPerformance;

    for (int i = 0; i < combinaciones; i++) {
        int numero = i;
        int disco1=discos[0],disco2=discos[1],disco3=discos[2];

        for (int j = 0; j < TABLAS; j++) {
            if (numero%DISCOS==0) {
                disco1-=tablas[j];
                cout<<'0';
            }else if (numero%DISCOS==1) {
                disco2-=tablas[j];
                cout<<'1';
            }else if (numero%DISCOS==2) {
                disco3-=tablas[j];
                cout<<'2';
            }
            numero=numero/DISCOS;
        }
        cout<<endl;
        int performance;
        int disco;

        if (0<=disco1 and 0<=disco2 and 0<=disco3) {
            performance=disco1;
            disco=1;
            if (disco2<performance) {
                performance=disco2;
                disco=2;
            }
            if (disco3<performance) {
                performance=disco3;
                disco=3;
            }
        }else {
            performance=-1;
        }

        if (performance>mayorPerformance) {
            mayorPerformance=performance;
            discoPerformance=disco;
            combinacionMenorPerformance=i;
        }
    }

    for (int i = 0;i<DISCOS;i++) {
        imprimirTablasDisco(combinacionMenorPerformance,i);
        cout<<endl;
    }
    cout<<"Esta solución tiene una velocidad mínima de grupo de "
        <<mayorPerformance<<" IOPs que se da en el disco "<<discoPerformance
        <<endl;
    return 0;
}
