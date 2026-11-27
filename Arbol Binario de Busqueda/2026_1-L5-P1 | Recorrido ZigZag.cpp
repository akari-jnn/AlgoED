#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
using namespace std;

void zigZagOrder(const ArbolBinarioBusqueda &arbol) {
    //En caso no haya nada en el arbol
    if (esArbolVacio(arbol)) return;
    
    //Recorrido ZigZag
    Pila pila1, pila2;
    construir(pila1);
    construir(pila2);
    apilar(pila1,{0,0,arbol.raiz});
    bool haciaDerecha=true;
    int nivel=1;
    
    while (not esPilaVacia(pila1) or not esPilaVacia(pila2)) {
        cout<<"Nivel "<<nivel<<": ";
        if (haciaDerecha) {
            while (not esPilaVacia(pila1)) {
                ElementoPila ele = desapilar(pila1);
                cout<<ele.nodo->elemento.numero<<' ';
                if (not esNodoVacio(ele.nodo->izquierda))
                    apilar(pila2,{0,0,ele.nodo->izquierda});
                if (not esNodoVacio(ele.nodo->derecha))
                    apilar(pila2,{0,0,ele.nodo->derecha});
            }
            haciaDerecha=false;
        }else {
            while (not esPilaVacia(pila2)) {
                ElementoPila ele = desapilar(pila2);
                cout<<ele.nodo->elemento.numero<<' ';
                if (not esNodoVacio(ele.nodo->derecha))
                    apilar(pila1,{0,0,ele.nodo->derecha});
                if (not esNodoVacio(ele.nodo->izquierda))
                    apilar(pila1,{0,0,ele.nodo->izquierda});
            }
            haciaDerecha=true;
        }
        cout<<endl;
        nivel++;
    }
}

int main() {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    int cadena[]={9,4,14,1,6,11,16,19};
    int cantidad=sizeof(cadena)/sizeof(cadena[0]);
    for (int i=0;i<cantidad;i++) {
        insertar(arbol,{cadena[i]});
    }

    zigZagOrder(arbol);

    return 0;
}
