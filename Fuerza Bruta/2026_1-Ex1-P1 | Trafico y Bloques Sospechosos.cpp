#include <iostream>
using namespace std;

const int F=4;
const int C=4;

void calcularBloquesSospechosos(int trafico[F][C],int H,int W,int U) {
    int numero=0;

    //Posicion de referencia [x][y]
    for (int x=0;x<F;x++) {
        for (int y=0;y<C;y++) {

            //Tamanio de la figura a formar
            for (int ancho=0;ancho<W;ancho++) {
                for (int altura=0;altura<H;altura++) {

                    //Sumas a realizar
                    if (x+altura<F and y+ancho<C) {
                        int sumaBloque=0;
                        for (int j=0;j<=altura;j++) {
                            for (int i=0;i<=ancho;i++) {
                                sumaBloque+=trafico[x+j][y+i];
                            }
                        }
                        if (sumaBloque>U) {
                            numero++;
                            cout<<"Bloque sospechoso "<<numero<<": "<<endl;
                            cout<<"Fila inicial: "<<x<<endl;
                            cout<<"Columna inicial: "<<y<<endl;
                            cout<<"Fila final: "<<x+altura<<endl;
                            cout<<"Columna final: "<<y+ancho<<endl;
                            cout<<"Suma: "<<sumaBloque<<endl;
                            cout<<endl;
                        }
                    }
                }
            }
        }
    }
    if (numero==0) {
        cout<<"No se encontraron patrones sospechosos"<<endl;
    }
}

int main() {
    int H=2,W=2,U=50;
    int trafico[F][C]={
        {1,2,3,4},
        {5,20,1,2},
        {3,25,4,1},
        {1,2,30,3}
    };

    cout<<"Matriz evaluada: "<<endl;
    for(int i=0;i<F;i++) {
        for(int j=0;j<C;j++) {
            cout<<trafico[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Altura maxima del bloque: "<<H<<endl;
    cout<<"Ancho maximo del bloque: "<<W<<endl;
    cout<<"Umbral sospechoso: "<<U<<endl;
    cout<<endl;

    calcularBloquesSospechosos(trafico,H,W,U);

    return 0;
}
