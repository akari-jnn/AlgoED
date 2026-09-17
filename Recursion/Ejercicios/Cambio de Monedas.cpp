#include <iostream>
using namespace std;
/* "Un cajero debe dar el vuelto exacto
     * usando la mínima cantidad de monedas posibles" */

bool calcularVuelto(int *monedas,int vuelto,int pos) {
    //Caso base
    if (pos==8 or vuelto<=0) return false;
    //Universo A: Se consiera
    if ()
    //Universo B: No se considera
}

int main() {

    int monedas[8]={200,100,50,20,10,5,2,1};
    int vuelto;

    cout<<"Ingrese el monto del vuelto del cliente:";
    cin>>vuelto;

    calcularVuelto(monedas,vuelto,0);

    return 0;
}
