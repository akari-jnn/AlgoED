#include <iostream>
using namespace std;

const int F=2;
const int C=2;

int hallarSumaMaxima(int matriz[F][C],int posX,int posY) {
    if (posX==F-1 and posY==C-1) {
        return matriz[posX][posY];
    }
    if (posX==F or posY==C) {
        //Camino no valido
        return -9999999;
    }

    //Camino derecha
    int derecha=matriz[posX][posY]+hallarSumaMaxima(matriz,posX,posY+1);
    //Camino abajo
    int abajo=matriz[posX][posY]+hallarSumaMaxima(matriz,posX+1,posY);

    return max(derecha,abajo);
}

int main() {
    int matriz[F][C]={
        { 3, 5},
        {-2, 4}
    };

    int sumaMax=hallarSumaMaxima(matriz,0,0);
    cout<<"Suma maxima: "<<sumaMax<<endl;

    return 0;
}
