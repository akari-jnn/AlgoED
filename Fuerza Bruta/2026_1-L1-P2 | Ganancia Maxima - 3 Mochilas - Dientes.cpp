#include <iostream>
#include <cmath>
using namespace std;
const int DIENTES = 8;
const int TIPO = 4;
const int CITAS = 3;

void imprimirDienteDeCita(int combinacion,int cita) {
    for (int j=0;j<DIENTES;j++) {
        if (combinacion%4==cita) {
            cout<<"Cita: "<<cita<<" Diente: "<<j+1<<endl;
        }
        combinacion=combinacion/4;
    }
}

int main() {
    int tipoDiente[DIENTES]={1,1,2,3,3,4,4,4};
    int cantidadCaries[DIENTES]={3,1,0,1,2,1,2,3};
    // 1. Incisivo, 2. Canino, 3. Pre-molar, 4. Molar
    int duracion[TIPO]={5,7,10,12};
    int ganancia[TIPO]={20,30,35,42};
    int citas[CITAS+1]={0,60,45,50};

    int combinaciones=pow(CITAS+1,DIENTES);
    int numero;
    int cita1,cita2,cita3;
    int combinacionMaxima=-1;
    int gananciaObtenida,gananciaMaxima=-1;
    for (int i=0;i<combinaciones;i++) {
        numero=i;
        cita1=0,cita2=0,cita3=0;
        gananciaObtenida=0;
        for (int j=0;j<DIENTES;j++) {
            if (numero%4==1) {
                //Cita 1
                cita1+=cantidadCaries[j]*duracion[tipoDiente[j]-1];
            }else if (numero%4==2) {
                //Cita 2
                cita2+=cantidadCaries[j]*duracion[tipoDiente[j]-1];
            }else if (numero%4==3) {
                //Cita 3
                cita3+=cantidadCaries[j]*duracion[tipoDiente[j]-1];
            }

            if (numero%4!=0) {
                gananciaObtenida+=ganancia[tipoDiente[j]-1]*cantidadCaries[j];
            }

            numero=numero/4;
        }
        if (cita1<=citas[1] and cita2<=citas[2] and cita3<=citas[3]) {
            if (gananciaMaxima<gananciaObtenida) {
                gananciaMaxima=gananciaObtenida;
                combinacionMaxima=i;
            }
        }
    }

    for (int i=0;i<CITAS;i++) {
        imprimirDienteDeCita(combinacionMaxima,i+1);
    }
    cout<<"La ganancia maxima es: "<<gananciaMaxima<<endl;
    return 0;
}
