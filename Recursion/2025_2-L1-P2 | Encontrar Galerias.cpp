#include <iostream>
using namespace std;

const int N = 6;
const int M = 11;

bool robotMinero(char matriz[N][M], int posX, int posY, char id) {
    if (posY == -1) {
        if (posX < 0) return false;

        if (matriz[posX][0] == ' ') {
            bool exito = robotMinero(matriz, posX, 0, id);
            if (exito) {
                robotMinero(matriz, N - 1, -1, id + 1);
                return true;
            }
        }
        return robotMinero(matriz, posX - 1, -1, id);
    }

    if (posX < 0 || posX >= N || posY < 0 || posY >= M || matriz[posX][posY] != ' ') {
        return false;
    }
    if (posY == M - 1) {
        matriz[posX][posY] = id;
        return true;
    }
    matriz[posX][posY] = '.';
    bool exito = robotMinero(matriz, posX + 1, posY, id) or
                 robotMinero(matriz, posX, posY + 1, id) or
                 robotMinero(matriz, posX - 1, posY, id);
    if (exito) {
        matriz[posX][posY] = id;
        return true;
    } else {
        matriz[posX][posY] = ' ';
        return false;
    }
}

void imprimirMina(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
}

int main() {
    char matriz[N][M]={
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' '}
    };
    imprimirMina(matriz);
    cout<<endl;
    robotMinero(matriz,N-1,-1,'1');
    imprimirMina(matriz);
    return 0;
}
