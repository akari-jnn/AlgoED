#include <iostream>
using namespace std;
const int N = 10;
const int M = 10;

int encontrarArtefactos(char matriz[N][M],int posX,int posY,int alcance,int arriba,int abajo) {
    if (alcance==-1) return 0;

    int artefactoEncontrado=0;
    int artefactosArriba=0;
    int artefactosAbajo=0;

    if (matriz[posX][posY]=='A') {
        artefactoEncontrado++;
    }
    matriz[posX][posY]='*';

    if (arriba==1) {
        artefactosArriba=
            encontrarArtefactos(matriz,posX-1,posY-1,alcance-1,1,0)+
            encontrarArtefactos(matriz,posX-1,posY,alcance-1,1,0)+
            encontrarArtefactos(matriz,posX-1,posY+1,alcance-1,1,0);
    }
    if (abajo==1) {
        artefactosAbajo=
            encontrarArtefactos(matriz,posX+1,posY-1,alcance-1,0,1)+
            encontrarArtefactos(matriz,posX+1,posY,alcance-1,0,1)+
            encontrarArtefactos(matriz,posX+1,posY+1,alcance-1,0,1);
    }

    return artefactoEncontrado+artefactosArriba+artefactosAbajo;
}

void imprimirMatriz(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<<matriz[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    char matriz[N][M]={
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','A','A',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ','A',' ',' ','A',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };

    imprimirMatriz(matriz);
    cout<<encontrarArtefactos(matriz,5,5,3,1,1);
    cout<<endl;
    imprimirMatriz(matriz);

    return 0;
}
