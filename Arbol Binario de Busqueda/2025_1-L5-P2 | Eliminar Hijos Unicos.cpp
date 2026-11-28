#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

bool esHoja(const NodoArbolBinarioBusqueda *nodo) {
    return not esNodoVacio(nodo) and
           esNodoVacio(nodo->izquierda) and
           esNodoVacio(nodo->derecha);
}

void eliminarHijosUnicos(ArbolBinarioBusqueda &arbol) {
    if (esArbolVacio(arbol)) return;

    Pila pila;
    construir(pila);

    NodoArbolBinarioBusqueda *actual = arbol.raiz;
    NodoArbolBinarioBusqueda *ultimoVisitado = nullptr;

    while (not esNodoVacio(actual) or not esPilaVacia(pila)) {
        if (not esNodoVacio(actual)) {
            apilar(pila, {0, 0, actual});
            actual = actual->izquierda;
        } else {
            NodoArbolBinarioBusqueda *tope = cima(pila).nodo;

            // Si tiene subárbol derecho y aún no se ha visitado, bajar por la derecha
            if (not esNodoVacio(tope->derecha) and ultimoVisitado != tope->derecha) {
                actual = tope->derecha;
            } else {
                // Ambos subárboles de 'tope' ya fueron visitados (Post-Orden)
                // Evaluamos si 'tope' tiene un único hijo que sea hoja
                if (not esNodoVacio(tope->izquierda) and esNodoVacio(tope->derecha)) {
                    if (esHoja(tope->izquierda)) {
                        delete tope->izquierda;
                        tope->izquierda = nullptr;
                    }
                } else if (esNodoVacio(tope->izquierda) and not esNodoVacio(tope->derecha)) {
                    if (esHoja(tope->derecha)) {
                        delete tope->derecha;
                        tope->derecha = nullptr;
                    }
                }

                ultimoVisitado = desapilar(pila).nodo;
            }
        }
    }
}

int main() {

    ArbolBinarioBusqueda arbol;
    construir(arbol);
    int cadena[]={100,50,150,25,75,125,175,30,200,28};
    int cantidad=sizeof(cadena)/sizeof(cadena[0]);
    for (int i=0;i<cantidad;i++) {
        insertar(arbol,{cadena[i]});
    }

    cout << "Antes (En-Orden):   ";
    recorrerEnOrden(arbol);
    cout << endl;

    eliminarHijosUnicos(arbol);

    cout << "Despues (En-Orden): ";
    recorrerEnOrden(arbol);
    cout << endl;

    return 0;
}
