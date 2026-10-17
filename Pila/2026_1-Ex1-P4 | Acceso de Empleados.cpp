#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

bool verificarSecuencia(char *secuencia) {
    //El primero no puede ser minuscula
    if ('a' <= secuencia[0] and secuencia[0] <= 'z') return false;

    Pila pila;
    construir(pila);

    //Recorremos el arreglo
    for (int i = 0; secuencia[i]; i++) {
        if ('A' <= secuencia[i] and secuencia[i] <= 'Z') {
            apilar(pila, {secuencia[i]});
        } else {
            if (esPilaVacia(pila)) {
                return false;
            }
            ElementoPila ele = desapilar(pila);
            if (ele.letra + 32 != secuencia[i]) {
                return false;
            }
        }
    }
    if (esPilaVacia(pila)) {
        return true;
    }
    return false;
}

int main() {
    char secuencia[20];
    cout << "Ingresar la secuencia: " << endl;
    cin >> secuencia;

    if (verificarSecuencia(secuencia)) {
        cout << "Secuencia valida" << endl;
    } else {
        cout << "Secuencia invalida" << endl;
    }

    //Valor 'a': 97
    //Valor 'A': 65
    //Diferencia: 32

    return 0;
}
