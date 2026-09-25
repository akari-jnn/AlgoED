#include <iostream>
using namespace std;

void hanoi(int n,char origen,char auxiliar,char destino) {
    if (n==0) return;

    hanoi(n-1,origen,auxiliar,destino);
    cout<<"Mover el paquete "<<n<<" del almacen "<<origen
        <<" hacia el almacen "<<auxiliar<<endl;
    hanoi(n-1,destino,auxiliar,origen);
    cout<<"Mover el paquete "<<n<<" del almacen "<<auxiliar
        <<" hacia el almacen "<<destino<<endl;
    hanoi(n-1,origen,auxiliar,destino);
}

int main() {
    int cantDiscos;
    cout<<"Ingrese la cantidad de discos a mover: ";
    cin>>cantDiscos;
    hanoi(cantDiscos,'A','B','C');
    return 0;
}
