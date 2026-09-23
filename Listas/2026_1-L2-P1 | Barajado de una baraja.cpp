#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Estructuras.h"

void crear_baraja(Baraja &baraja) {
    baraja.inicio = nullptr;
    baraja.fin = nullptr;
    baraja.longitud = 0;

    char palo[4]={'C','D','T','E'};

    for (int i=0;i<4;i++) {
        for (int j=1;j<=13;j++) {
            Carta carta={j,palo[i]};
            NodoBaraja* ultimoNodo = baraja.fin;
            NodoBaraja* nuevo = new NodoBaraja;
            nuevo->carta = carta;
            nuevo->siguiente = nullptr;
            if (ultimoNodo == nullptr) {
                baraja.inicio = nuevo;
                baraja.fin = nuevo;
            }else {
                ultimoNodo->siguiente = nuevo;
                baraja.fin = nuevo;
            }
            baraja.longitud++;
        }
    }
}

NodoBaraja* extraer_en_posicion(Baraja &baraja, int posicion) {
    if (baraja.inicio == nullptr) return nullptr;
    if (posicion>baraja.longitud or posicion<1) return nullptr;
    NodoBaraja *anterior=nullptr,*recorrido=baraja.inicio;
    // Se recorre hasta la posicion
    for (int i = 1; i < posicion; i++) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    // Extraer el nodo segun su ubicación
    if (anterior == nullptr) {
        // Caso A: Se extrae el primer nodo (posicion == 1)
        baraja.inicio = recorrido->siguiente;
        // Si era el único nodo en la lista, actualizamos el fin
        if (baraja.inicio == nullptr) {
            baraja.fin = nullptr;
        }
    } else {
        // Caso B: Se extrae al medio o al final
        anterior->siguiente = recorrido->siguiente;
        // Si se extrajo el último nodo, actualizamos el fin
        if (recorrido->siguiente == nullptr) {
            baraja.fin = anterior;
        }
    }
    recorrido->siguiente = nullptr;
    baraja.longitud--;
    return recorrido;
}

void barajar(Baraja &baraja) {
    if (baraja.inicio == nullptr or baraja.longitud <= 1) {
        return;
    }
    int longBaraja=baraja.longitud;
    for (int i = longBaraja; i>0; i--) {
        int posicion_aleatoria = (rand() % i) + 1;
        NodoBaraja *extraido = extraer_en_posicion(baraja,posicion_aleatoria);
        baraja.fin->siguiente=extraido;
        baraja.fin=extraido;
        baraja.longitud++;
    }
}

void destruir(Baraja &baraja) {
    NodoBaraja * recorrido = baraja.inicio;

    while (recorrido != nullptr) {
        NodoBaraja * NodoBarajaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoBarajaAEliminar;
    }
    baraja.inicio = nullptr;
    baraja.fin = nullptr;
    baraja.longitud = 0;
}

int main() {
    srand(time(nullptr));
    struct Baraja baraja;
    crear_baraja(baraja);
    // ... (código opcional para imprimir y probar) ...
    destruir(baraja);
    return 0;
}
