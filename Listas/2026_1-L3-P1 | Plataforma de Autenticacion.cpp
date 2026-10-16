#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

int contarOcurrencias(int numero,const Lista &lista) {
    if (esListaVacia(lista)) return 0;
    int cantOcurrencias = 0;
    NodoLista *recorrido=lista.inicio;
    while(recorrido!=nullptr) {
        if (recorrido->elemento.codigo==numero) {
            cantOcurrencias++;
        }
        recorrido=recorrido->siguiente;
    }
    return cantOcurrencias;
}

bool verificarEnLista(int numero,const Lista &lista) {
    if (esListaVacia(lista)) return false;
    NodoLista *recorrido=lista.inicio;
    while(recorrido!=nullptr) {
        if (recorrido->elemento.codigo==numero) {
            return true;
        }
        recorrido=recorrido->siguiente;
    }
    return false;
}

void eliminarTodasLasOcurrencias(Lista &lista,const Lista &sospechosos) {
    if (esListaVacia(sospechosos)) return;
    NodoLista *recorridoSospechosos=sospechosos.inicio;

    //Avanzo en la lista de sospechosos
    while(recorridoSospechosos!=nullptr) {
        int codigo=recorridoSospechosos->elemento.codigo;
        //Avanzo en la lista original
        NodoLista *anteriorLista=nullptr;
        NodoLista *recorridoLista=lista.inicio;
        while (recorridoLista!=nullptr) {
            if (recorridoLista->elemento.codigo==recorridoSospechosos->elemento.codigo) {
                NodoLista *NodoAEliminar=recorridoLista;
                if (anteriorLista==nullptr) {
                    recorridoLista=recorridoLista->siguiente;
                    recorridoLista=lista.inicio;
                }else {
                    anteriorLista->siguiente=recorridoLista->siguiente;
                    recorridoLista = recorridoLista->siguiente;
                }
                delete NodoAEliminar;
                lista.longitud--;
            }else {
                anteriorLista=recorridoLista;
                recorridoLista=recorridoLista->siguiente;
            }
        }
        recorridoSospechosos=recorridoSospechosos->siguiente;
    }
}

void generarListaDeSospechosos(const Lista &lista,Lista &sospechosos) {
    NodoLista *recorrido=lista.inicio;

    while (recorrido!=nullptr) {
        int ocurrencias=contarOcurrencias(recorrido->elemento.codigo,lista);
        //¿Tiene más de 3 intentos fallidos?
        if (ocurrencias>=3) {
            //¿Esta en lista de sospechosos?
            if (not verificarEnLista(recorrido->elemento.codigo,sospechosos)){
                insertarAlFinal(sospechosos,recorrido->elemento);
            }
        }
        recorrido=recorrido->siguiente;
    }
}

int main() {
    Lista lista;
    construir(lista);

    insertarAlFinal(lista,{410});
    insertarAlFinal(lista,{102});
    insertarAlFinal(lista,{205});
    insertarAlFinal(lista,{102});
    insertarAlFinal(lista,{205});
    insertarAlFinal(lista,{330});
    insertarAlFinal(lista,{102});
    insertarAlFinal(lista,{205});
    insertarAlFinal(lista,{410});
    insertarAlFinal(lista,{205});
    insertarAlFinal(lista,{777});

    cout<<"Lista de intentos fallidos: "<<endl;
    imprimir(lista);

    Lista sospechosos;
    construir(sospechosos);
    generarListaDeSospechosos(lista,sospechosos);
    cout<<"Lista de usuarios sospechosos: "<<endl;
    imprimir(sospechosos);

    eliminarTodasLasOcurrencias(lista,sospechosos);
    cout<<"Lista depurada: "<<endl;
    imprimir(lista);

    return 0;
}
