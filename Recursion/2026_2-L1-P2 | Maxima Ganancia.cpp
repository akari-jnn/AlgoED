#include <iostream>
using namespace std;

const int N=5;

int encontrarMaximaGanancia(int pos,int presupuesto,int *costo,int *ganancia) {
    if (pos==N or presupuesto==0) return 0;
    int seConsidera=0;
    if (costo[pos]<=presupuesto) {
        seConsidera=ganancia[pos]+encontrarMaximaGanancia(pos+1,presupuesto-costo[pos],costo,ganancia);
    }
    int noSeConsidera=encontrarMaximaGanancia(pos+1,presupuesto,costo,ganancia);
    if (seConsidera>noSeConsidera) {
        return seConsidera;
    }
    return noSeConsidera;
}

int main() {
    int costo[N]={100,50,50,150,100};
    int ganancia[N]={500,200,300,700,400};
    int presupuesto=300;

    int maximaGanancia=encontrarMaximaGanancia(0,presupuesto,costo,ganancia);
    cout<<maximaGanancia<<endl;

    return 0;
}
