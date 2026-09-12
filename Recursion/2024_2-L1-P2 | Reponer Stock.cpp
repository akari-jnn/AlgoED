#include <iostream>
using namespace std;

const int N = 5;
const int M = 5;

void reponerStock(int matriz[N][M],int matrizAux[N][M],int posX,int posY,int &maximo) {
    if (posX==N-1 and posY==M) {
        return;
    }
    if (posY==M) {
        reponerStock(matriz,matrizAux,posX+1,0,maximo);
    }else {
        if (matriz[posX][posY]>maximo) {
            maximo=matriz[posX][posY];
        }
        reponerStock(matriz,matrizAux,posX,posY+1,maximo);
        matrizAux[posX][posY]=maximo-matriz[posX][posY];
    }
}

void imprimirMatriz(int matriz[N][M]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout<<matriz[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int matriz[N][M]={
        {4,3,6,8,7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };
    int matrizAux[N][M]={};

    cout<<"Imagen 1:"<<endl;
    imprimirMatriz(matriz);

    int maximo=-1;
    reponerStock(matriz,matrizAux,0,0,maximo);

    cout<<endl;
    cout<<"Resultado:"<<endl;
    imprimirMatriz(matrizAux);

    return 0;
}
