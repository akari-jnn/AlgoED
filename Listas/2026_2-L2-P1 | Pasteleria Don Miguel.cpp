/*-------- Ingrediente.h --------*/

#ifndef LISTAS_INGREDIENTE_H
#define LISTAS_INGREDIENTE_H

struct Ingrediente {
    int codigo;
    int cantidad;
};

#endif //LISTAS_INGREDIENTE_H

/*-------------------------------*/

#include <iostream>
#include "Ingrediente.h"
#include "BibliotecaLista/NodoLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

void descontarDelAlmacen(ElementoLista ele,Ingrediente *almacen,int cantIngredientesAlmacen) {
    for (int i = 0; i < cantIngredientesAlmacen; i++) {
        for (int j = 0; j < ele.cantIngredientes; j++) {
            int codigoIngrediente=ele.Ingredientes[j].codigo;
            int cantIngrediente=ele.Ingredientes[j].cantidad;
            if (almacen[i].codigo==codigoIngrediente) {
                almacen[i].cantidad-=cantIngrediente;
            }
        }
    }
}

bool esPosiblePrepararlo(NodoLista *recorrido,Ingrediente *almacen,int cantIngredientesAlmacen) {
    for (int i = 0; i < recorrido->elemento.cantIngredientes; i++) {
        int codigoIngrediente=recorrido->elemento.Ingredientes[i].codigo;
        int cantIngrediente=recorrido->elemento.Ingredientes[i].cantidad;

        bool encontrado=false,haySuficiente=false;
        for (int j = 0; j < cantIngredientesAlmacen; j++) {
            if (codigoIngrediente==almacen[j].codigo) {
                encontrado=true;
                if (cantIngrediente<=almacen[j].cantidad) {
                    haySuficiente=true;
                }
            }
        }
        if (not encontrado) {
            return false;
        }
        if (not haySuficiente) {
            return false;
        }
    }
    descontarDelAlmacen(recorrido->elemento,almacen,cantIngredientesAlmacen);
    return true;
}

int postresAPreparar(Lista &lista,Ingrediente *almacen,int cantIngredientesAlmacen) {
    NodoLista *recorrido=lista.inicio,*anterior=nullptr;
    int contador=0;
    while (recorrido!=nullptr and contador<3){
        if (esPosiblePrepararlo(recorrido,almacen,cantIngredientesAlmacen)) {
             if (anterior==nullptr) {
                 anterior=recorrido;
                 recorrido=recorrido->siguiente;
             }else {
                 NodoLista *nodoAMover = recorrido;
                 recorrido=recorrido->siguiente;
                 anterior->siguiente=recorrido;
                 nodoAMover->siguiente = lista.inicio;
                 lista.inicio = nodoAMover;
             }
             contador++;
        }else {
            anterior=recorrido;
            recorrido=recorrido->siguiente;
        }
    }
    return contador;
}

int main() {
    Lista lista;
    construir(lista);
    insertarEnOrdenPasteleria(lista,
        {"P001","Crema volteada",
            5,{
                {1002,810},
                {1003,990},
                {1101,15},
                {1201,12},
                {1301,400}
            }});
    insertarEnOrdenPasteleria(lista,
        {"P002","Trufas de chocolate",
            3,{
                {1014,330},
                {1701,600},
                {1101,5}
            }});
    insertarEnOrdenPasteleria(lista,
        {"P003","Keke de vainilla",
            5,{
                {1501,200},
                {1301,600},
                {1401,375},
                {1014,250},
                {1101,10}
            }});
    insertarEnOrdenPasteleria(lista,
        {"P004","Profiterol",
            3,{
                {1501,100},
                {1401,125},
                {1201,4}
            }});
    insertarEnOrdenPasteleria(lista,
        {"P005","Alfajores",
            4,{
                {1401,188},
                {1302,40},
                {1501,250},
                {1101,15}
            }});
    insertarEnOrdenPasteleria(lista,
            {"P006","Mousse de limon",
                3,{
                {3001,10},
                {1002,330},
                {1004,270}
            }});

    Ingrediente almacen[]={
        {1401,5000},
        {1501,3500},
        {1201,40},
        {1601,2500},
        {1701,500},
        {1301,3000},
        {1302,1000},
        {1702,900},
        {1001,900},
        {1002,900},
        {1003,900},
        {1004,1800},
        {1101,100},
        {3001,10},
    };
    int cantIngredientesAlmacen=sizeof(almacen)/sizeof(almacen[0]);


    cout<<"Postres listado inicial: "<<endl;
    imprimirPasteleria(lista);

    cout<<endl;
    cout<<"Postres listado final: "<<endl;
    int cantPostresAPreparar=postresAPreparar(lista,almacen,cantIngredientesAlmacen);

    if (cantPostresAPreparar>0) {
        cout<<"Se puede(n) preparar: "<<cantPostresAPreparar<<" postre(s)"<<endl;
    }else {
        cout<<"No se puede preparar ninguno"<<endl;
    }
    imprimirPasteleria(lista);
    return 0;
}
