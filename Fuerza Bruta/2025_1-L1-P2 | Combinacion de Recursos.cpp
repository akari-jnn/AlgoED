#include <iostream>
#include <cmath>
using namespace std;

const int REC = 10;
enum Recursos {Fire,IDS,MonRed,SisAut,IPS,IDSAv,Honey,DetInt,SegCor,GesCen};

int main() {
    int costo[REC]={50,40,80,70,85,140,55,130,30,150};
    int seguridad[REC]={120,110,140,130,160,250,100,240,90,300};
    int dependencias[REC][REC]={
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {Fire,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {Fire,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {Fire,IDS,-1,-1,-1,-1,-1,-1,-1,-1},
        {IDS,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {IDS,MonRed,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {Fire,IDS,IPS,-1,-1,-1,-1,-1,-1,-1}
        };

    int presupuesto,nivelSeguridad;
    cout<<"Ingrese el presupuesto (en miles de soles): ";
    cin>>presupuesto;
    cout<<"Ingrese el nivel de seguridad minimo requerido: ";
    cin>>nivelSeguridad;
    int presupuesto80=0.8*presupuesto;

    int combinaciones=pow(2,REC);
    bool esPrimeraValida=true;

    for (int i=0;i<combinaciones;i++) {
        int seleccionados[REC]{};
        int numero=i;

        for (int j = 0; j < REC; j++) {
            seleccionados[j] = numero%2;
            numero/= 2;
        }

        int totalGastado=0;
        int totalSeguridad=0;
        bool sinDependencias=false;

        for(int j=0;j<REC;j++) {
            if (seleccionados[j]==1) {
                totalGastado+=costo[j];
                totalSeguridad+=seguridad[j];

                int k=0;
                while (dependencias[j][k]!=-1) {
                    int req = dependencias[j][k];
                    if (seleccionados[req] == 0) {
                        sinDependencias = true;
                        break;
                    }
                    k++;
                }
            }
            if (sinDependencias) break;
        }

        if (presupuesto80<=totalGastado and totalGastado<=presupuesto
            and totalSeguridad>=nivelSeguridad and !sinDependencias) {

            if (esPrimeraValida) {
                cout<<"Combinaciones validas (Costo entre "<<presupuesto80
                    <<" y "<<presupuesto<<" miles y Nivel de seguridad >="
                    <<nivelSeguridad<<"):"<<endl;
                esPrimeraValida=false;
            }

            cout<<"Combinacion "<<i<<" Recursos: ";
            for(int m=0;m<REC;m++) {
                if (seleccionados[m] == 1) {
                    cout << "R" << m + 1 << " ";
                }
            }
            cout<<" | Costo: "<<totalGastado<<" miles | Nivel de Seguridad: "
                <<totalSeguridad<<endl;
        }
    }
    if (esPrimeraValida) {
        cout<<"No se encontraron combinaciones que cumplan con lo solicitado"<<endl;
    }
    return 0;
}
