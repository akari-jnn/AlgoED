---------- ElementoListaCircular.h ----------

#ifndef LISTAS_ELEMENTOLISTACIRCULAR_H
#define LISTAS_ELEMENTOLISTACIRCULAR_H

struct ElementoListaCircular {
    int node_id;
    bool is_active;
};

#endif //LISTAS_ELEMENTOLISTACIRCULAR_H


---------- NodoListaCircular.h ----------

#ifndef LISTAS_NODOLISTACIRCULAR_H
#define LISTAS_NODOLISTACIRCULAR_H

struct NodoListaCircular {
    ElementoListaCircular elemento;
    NodoListaCircular *next;
    NodoListaCircular *skip_next;
};

#endif //LISTAS_NODOLISTACIRCULAR_H


---------- ListaCircular.h ----------

#ifndef LISTAS_LISTACIRCULAR_H
#define LISTAS_LISTACIRCULAR_H
#include "NodoListaCircular.h"

struct ListaCircular {
    NodoListaCircular *fin;
    int longitud;
};

#endif //LISTAS_LISTACIRCULAR_H

    
---------- funcionesListaCircular.h ----------

#ifndef LISTAS_FUNCIONESLISTACIRCULAR_H
#define LISTAS_FUNCIONESLISTACIRCULAR_H

void construirLC(ListaCircular &lista);
bool esListaVaciaLC(const ListaCircular & lista);
void agregar_nodo(ListaCircular & lista, const ElementoListaCircular &ele);
void calcular_skip_next(ListaCircular &lista);
void desactivar_nodo(ListaCircular &lista,int node_id);
void auto_healing(ListaCircular &lista);
void destruirLC(ListaCircular &lista);
void imprimirLC(const ListaCircular & lista);

#endif //LISTAS_FUNCIONESLISTACIRCULAR_H


---------- funcionesListaCircular.cpp ----------

#include <iostream>

#include "ElementoListaCircular.h"
#include "NodoListaCircular.h"
#include "ListaCircular.h"
#include "funcionesListaCircular.h"
using namespace std;

void construirLC(ListaCircular &lista) {
    lista.fin=nullptr;
    lista.longitud=0;
}

bool esListaVaciaLC(const ListaCircular &lista) {
    return lista.fin == nullptr;
}

void agregar_nodo(ListaCircular &lista, const ElementoListaCircular &ele) {
    NodoListaCircular *nuevo = new NodoListaCircular;
    nuevo->elemento=ele;
    nuevo->next=nullptr;
    nuevo->skip_next=nullptr;
    if (lista.fin == nullptr) {
        lista.fin = nuevo;
        nuevo->next = nuevo;
    }else {
        nuevo->next=lista.fin->next;
        lista.fin->next = nuevo;
        lista.fin = nuevo;
    }
    lista.longitud++;
}

void calcular_skip_next(ListaCircular &lista) {
    NodoListaCircular * recorrido = lista.fin->next;
    while (true) {
        recorrido->skip_next=recorrido->next->next;
        recorrido = recorrido->next;
        if (recorrido == lista.fin->next) break;
    }
}

void desactivar_nodo(ListaCircular &lista,int node_id) {
    NodoListaCircular * recorrido = lista.fin->next;
    while (true) {
        if (recorrido->elemento.node_id == node_id) {
            recorrido->elemento.is_active = false;
            break;
        }
        recorrido = recorrido->next;
        if (recorrido == lista.fin->next) break;
    }
}

void auto_healing(ListaCircular &lista) {
    NodoListaCircular * recorrido_1= lista.fin->next;
    NodoListaCircular *primerActivo=nullptr;
    while (true) {
        if (recorrido_1->elemento.is_active) {
            primerActivo=recorrido_1;
            break;
        }
        recorrido_1 = recorrido_1->next;
        if (recorrido_1 == lista.fin->next) break;
    }
    if (primerActivo == nullptr) {
        destruirLC(lista);
    }else {
        NodoListaCircular *anterior=primerActivo;
        NodoListaCircular *recorrido_2=primerActivo->next;
        NodoListaCircular *nodoAEliminar;
        while (true) {
            if (not recorrido_2->elemento.is_active) {
                nodoAEliminar=recorrido_2;
                anterior->next=recorrido_2->next;
                recorrido_2=recorrido_2->next;
                delete nodoAEliminar;
                lista.longitud--;
            }else {
                anterior=recorrido_2;
                recorrido_2 = recorrido_2->next;
            }
            if (recorrido_2 == primerActivo) {
                lista.fin=anterior;
                break;
            }
        }
        calcular_skip_next(lista);
    }
}

void destruirLC(ListaCircular &lista) {
    NodoListaCircular * recorrido = lista.fin->next;
    while (true) {
        NodoListaCircular * NodoListaAEliminar = recorrido;
        if (recorrido == lista.fin) {
            delete NodoListaAEliminar;
            break;
        }
        recorrido = recorrido->next;
        delete NodoListaAEliminar;
    }
    lista.fin = nullptr;
    lista.longitud = 0;
}

void imprimirLC(const ListaCircular & lista) {
    if (esListaVaciaLC(lista)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        cout<<"Anillo ("<<lista.longitud<<" nodos):"<<endl;
        NodoListaCircular * recorrido = lista.fin->next;
        while (true) {
            cout<<"Nodo "<<recorrido->elemento.node_id<<" [";
            if (recorrido->elemento.is_active) {
                cout<<"ACTIVO";
            }else {
                cout<<"CAIDO ";
            }
            cout<<"] siguiente="<<recorrido->next->elemento.node_id
                <<" skip_next=";
            if (recorrido->skip_next!=nullptr) {
                cout<<recorrido->skip_next->elemento.node_id;
            }else {
                cout<<"No registrado";
            }
            cout<<endl;
            recorrido = recorrido->next;
            if (recorrido == lista.fin->next) break;
        }
    }
}


---------- main.cpp ----------

#include <iostream>
#include "BibliotecaListaCircular/ElementoListaCircular.h"
#include "BibliotecaListaCircular/ListaCircular.h"
#include "BibliotecaListaCircular/funcionesListaCircular.h"
using namespace std;

int main() {
    int N;
    //Ingresa el 5
    cout<<"Ingrese N: ";
    cin>>N;

    ListaCircular lista;
    construirLC(lista);

    //Insertar nodos
    for (int i=1; i<=N; i++) {
        agregar_nodo(lista,{10*i,true});
    }
    calcular_skip_next(lista);

    cout<<"=== Estado inicial ==="<<endl;
    imprimirLC(lista);
    cout<<endl;

    cout<<">>> Nodo 20 cae <<<"<<endl<<endl;
    desactivar_nodo(lista,20);
    cout<<">>> Nodo 30 cae <<<"<<endl<<endl;
    desactivar_nodo(lista,30);

    cout<<"=== Estado antes de auto_healing ==="<<endl;
    imprimirLC(lista);
    cout<<endl;

    auto_healing(lista);

    cout<<"=== Estado despues de auto_healing ==="<<endl;
    imprimirLC(lista);
    cout<<endl;

    return 0;
}
