#include <iostream>
using namespace std;

int encontrarPalabraEnTexto(char *texto,int posT,char *palabra,int posP) {
    //Caso base: Termino de leer el texto
    if (texto[posT]==0) return 0;
    int cantEncontrada=0;
    if (palabra[posP]==texto[posT]) {
        if (palabra[posP+1]==0 and (texto[posT+1]==0 or texto[posT+1]==' ')) {
            //Encontramos la palabra
            bool inicioValido = (posT - posP == 0) or (texto[posT - posP - 1] == ' ');
            if(inicioValido){
                cantEncontrada++;
            }
            //Buscamos una nueva
            cantEncontrada+=encontrarPalabraEnTexto(texto,posT+1,palabra,0);
        }else {
            //Seguimos verificando si es la palabra
            cantEncontrada+=encontrarPalabraEnTexto(texto,posT+1,palabra,posP+1);
        }
    }else {
        cantEncontrada+=encontrarPalabraEnTexto(texto,posT+1,palabra,0);
    }
    return cantEncontrada;
}

int main() {
    char texto[100];
    cout<<"Ingrese un texto: ";
    cin.getline(texto,100);

    char palabra[30];
    cout<<"Ingrese una palabra: ";
    cin>>palabra;

    cout<<"Se encontro "<<palabra<<" en el texto "
        <<encontrarPalabraEnTexto(texto,0,palabra,0)<<" veces";

    return 0;
}
