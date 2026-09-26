#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

void reordenaLista(Lista &lista) {
    if (lista.inicio==nullptr or lista.inicio->siguiente==nullptr) return;

    NodoLista *inicioA=nullptr,*inicioB=nullptr,*inicioC=nullptr,
                *finA=nullptr,*finB=nullptr,*finC=nullptr;
    NodoLista *recorrido=lista.inicio;

    //Separamos por tipo de produccion
    while (recorrido!=nullptr) {
        if (recorrido->elemento.tipo=='A') {
            if (inicioA==nullptr) {
                inicioA=recorrido;
                finA=recorrido;
            }else {
                finA->siguiente=recorrido;
                finA=recorrido;
            }
        }else if (recorrido->elemento.tipo=='B') {
            if (inicioB==nullptr) {
                inicioB=recorrido;
                finB=recorrido;
            }else {
                finB->siguiente=recorrido;
                finB=recorrido;
            }
        }else if (recorrido->elemento.tipo=='C') {
            if (inicioC==nullptr) {
                inicioC=recorrido;
                finC=recorrido;
            }else {
                finC->siguiente=recorrido;
                finC=recorrido;
            }
        }
        //Avanza el puntero recorrido
        recorrido=recorrido->siguiente;
    }
    //Cerramos las minilistas en caso hayan sido llenadas
    if (finA != nullptr) finA->siguiente=nullptr;
    if (finB != nullptr) finB->siguiente=nullptr;
    if (finC != nullptr) finC->siguiente=nullptr;

    //Reordenamos la lista
    NodoLista *recorridoNuevo;
    bool esInicioLista=true;
    while (true) {
        if (inicioA!=nullptr) {
            if (esInicioLista) {
                lista.inicio=inicioA;
                recorridoNuevo=inicioA;
                esInicioLista=false;
            }else {
                recorridoNuevo->siguiente=inicioA;
                recorridoNuevo=recorridoNuevo->siguiente;
            }
            inicioA=inicioA->siguiente;
        }
        if (inicioB!=nullptr) {
            if (esInicioLista) {
                lista.inicio=inicioB;
                recorridoNuevo=inicioB;
                esInicioLista=false;
            }else {
                recorridoNuevo->siguiente=inicioB;
                recorridoNuevo=recorridoNuevo->siguiente;
            }
            inicioB=inicioB->siguiente;
        }
        if (inicioC!=nullptr) {
            if (esInicioLista) {
                lista.inicio=inicioC;
                recorridoNuevo=inicioC;
                esInicioLista=false;
            }else {
                recorridoNuevo->siguiente=inicioC;
                recorridoNuevo=recorridoNuevo->siguiente;
            }
            inicioC=inicioC->siguiente;
        }

        if (inicioA==nullptr and inicioB==nullptr and inicioC==nullptr) break;
    }
}

int main() {
    Lista lista;
    construir(lista);
    ElementoLista elemento;
    elemento.codigo=7;
    elemento.tipo='B';
    insertarAlFinal(lista, elemento);
    elemento.codigo=2;
    elemento.tipo='A';
    insertarAlFinal(lista, elemento);
    elemento.codigo=9;
    elemento.tipo='C';
    insertarAlFinal(lista, elemento);
    elemento.codigo=5;
    elemento.tipo='A';
    insertarAlFinal(lista, elemento);
    elemento.codigo=6;
    elemento.tipo='B';
    insertarAlFinal(lista, elemento);

    cout<<"Entrada: ";
    imprimir(lista);

    reordenaLista(lista);

    cout<<"Salida: ";
    imprimir(lista);

    return 0;
}
