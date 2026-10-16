#include <iostream>
#include "BibliotecaLista/NodoLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

int aislarEquipos(Lista &lista,NodoLista *nodoActual) {
    if (nodoActual == nullptr) {
        lista.inicio = nullptr;
        lista.finCom = nullptr;
        lista.iniSeg = nullptr;
        return 0;
    }
    int cantCom = aislarEquipos(lista, nodoActual->siguiente);
    if (nodoActual->elemento.codigo < 0) {
        if (lista.finCom == nullptr) {
            lista.finCom = nodoActual;
        }
        nodoActual->siguiente = lista.inicio;
        lista.inicio = nodoActual;
        cantCom++;
    } else {
        nodoActual->siguiente = lista.iniSeg;
        lista.iniSeg = nodoActual;
    }

    if (lista.finCom != nullptr) {
        lista.finCom->siguiente = lista.iniSeg;
    } else {
        lista.inicio = lista.iniSeg;
    }
    return cantCom;
}

int main() {
    Lista lista;
    construir(lista);

    // insertarAlFinal(lista,{101});
    // insertarAlFinal(lista,{-102});
    // insertarAlFinal(lista,{103});
    // insertarAlFinal(lista,{-104});
    // insertarAlFinal(lista,{-105});
    // insertarAlFinal(lista,{106});

    // insertarAlFinal(lista,{201});
    // insertarAlFinal(lista,{202});
    // insertarAlFinal(lista,{203});
    // insertarAlFinal(lista,{204});

    // insertarAlFinal(lista,{-301});
    // insertarAlFinal(lista,{-302});
    // insertarAlFinal(lista,{-303});
    // insertarAlFinal(lista,{-304});

    // insertarAlFinal(lista,{401});
    // insertarAlFinal(lista,{402});
    // insertarAlFinal(lista,{403});
    // insertarAlFinal(lista,{-404});
    // insertarAlFinal(lista,{-405});

    insertarAlFinal(lista,{-501});
    insertarAlFinal(lista,{502});
    insertarAlFinal(lista,{503});
    insertarAlFinal(lista,{504});
    insertarAlFinal(lista,{505});

    cout<<"Lista original: "<<endl;
    imprimirEquipos(lista);

    int cantEquiposComprometidos=aislarEquipos(lista,lista.inicio);

    cout<<"Lista reorganizada: "<<endl;
    imprimirEquipos(lista);
    cout<<"Equipos comprometidos: "<<cantEquiposComprometidos<<endl;

    return 0;
}
