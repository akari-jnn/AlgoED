#include <iostream>
using namespace std;
/* "Un cajero debe dar el vuelto exacto
     * usando la mínima cantidad de monedas posibles" */

const int M=8;

bool calcularVuelto(int *monedas,int vuelto,int pos) {
    if (vuelto==0) return true;
    if (pos==M) return false;
    if (vuelto>=monedas[pos]) {
        //El billete es correcto
        //Se vuelve a probar el mismo
        bool seImprime=calcularVuelto(monedas,vuelto-monedas[pos],pos);
        if (seImprime) {
            cout<<monedas[pos]<<endl;
            return true;
        }
    }
    return calcularVuelto(monedas,vuelto,pos+1);
}

int main() {

    int monedas[M]={200,100,50,20,10,5,2,1};
    int vuelto;

    cout<<"Ingrese el monto del vuelto del cliente:";
    cin>>vuelto;

    calcularVuelto(monedas,vuelto,0);

    return 0;
}
