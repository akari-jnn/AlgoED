#include <iostream>
using namespace std;

const int N=10;

int obtenerCandidato(int aportes[N][N],int candidatoActual,int siguiente,int cantAves) {
    if (siguiente==cantAves) return candidatoActual;
    if (aportes[siguiente][candidatoActual]>0 and aportes[candidatoActual][siguiente]==0) {
        return obtenerCandidato(aportes,candidatoActual,siguiente+1,cantAves);
    }else {
        return obtenerCandidato(aportes,siguiente,siguiente+1,cantAves);
    }
}

int main() {
    int aportes[N][N]={
        {100,0,50,40,30,20,30,0,80,0},
        {50,100,0,40,30,20,20,0,10,25},
        {80,30,100,40,30,0,30,20,10,60},
        {50,0,0,100,30,0,50,30,30,90},
        {50,10,10,10,100,0,10,50,10,50},
        {20,0,0,0,0,100,90,20,40,20},
        {0,0,0,0,0,0,100,0,0,0},
        {0,0,0,0,0,0,50,100,50,20},
        {20,0,0,40,0,0,90,0,100,10},
        {0,10,0,0,0,0,10,0,60,100}
    };

    int candidato=obtenerCandidato(aportes,0,1,N);
    int candidatoFinal=obtenerCandidato(aportes,candidato,0,candidato);
    if (candidato!=candidatoFinal and aportes[candidatoFinal][candidatoFinal]<=0) {
        candidatoFinal=-1;
    }
    cout<<candidatoFinal;

    return 0;
}
