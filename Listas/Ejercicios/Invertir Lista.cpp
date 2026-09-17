#include <iostream>
#include "BibliotecaLista/funcionesLista.cpp"

using namespace std;

void invertirLista(Lista &lista) {
    NodoLista *anterior=nullptr,*recorrido=lista.inicio,*siguiente;
    while (recorrido!=nullptr) {
        siguiente=recorrido->siguiente;
        recorrido->siguiente=anterior;
        anterior=recorrido;
        recorrido=siguiente;
    }
    lista.inicio=anterior;
}

int main() {
    Lista lista;
    construir(lista);
    ElementoLista elemento;
    elemento={100};
    insertarAlFinal(lista,elemento);
    elemento={2};
    insertarAlFinal(lista,elemento);
    elemento={7};
    insertarAlFinal(lista,elemento);
    elemento={3};
    insertarAlFinal(lista,elemento);

    imprimir(lista);
    invertirLista(lista);
    imprimir(lista);
    return 0;
}
