#include <iostream>
#include <cmath>
using namespace std;

struct Palabra {
    char palabra[9];
    int cantLetras;
    int control[8];
    int combinaciones;

};

bool pertenecePalabra(char letra,Palabra &p) {
    for (int k = 0; k < p.cantLetras; k++) {
        if (p.palabra[k]==letra and p.control[k] == 0) {
            p.control[k] = 1; // Marcamos la posición de la letra como ocupada
            return true;
        }
    }
    return false;
}

int main() {
    int cantLetrasProducir;
    cout<<"Cantidad de letras a producir:";
    cin>>cantLetrasProducir;
    // 8

    char letrasProducir[10];

    cout<<"Letras a producir:";
    for (int i=0;i<cantLetrasProducir;i++) {
        cin>>letrasProducir[i];
    }
    // G A L A O G L M

    int cantPalabras;
    cout<<"Cantidad de palabras:";
    cin>>cantPalabras;

    // 4

    Palabra palabras[cantPalabras];

    for (int i = 0; i < cantPalabras; i++) {
        cin >> palabras[i].cantLetras >> palabras[i].palabra;
        palabras[i].combinaciones = 0;
        for (int k = 0; k < 8; k++) {
            palabras[i].control[k] = 0;
        }
    }
    // 3 GOL
    // 4 GALA
    // 3 ALA
    // 4 LOMA

    int combinaciones=pow(2,cantLetrasProducir);

    for (int i=0;i<combinaciones;i++) {

        // 1. Contamos cuántas letras activa la combinación actual 'i'
        int letrasEnCombinacion = 0;
        int temp = i;
        while (temp > 0) {
            if (temp % 2 == 1) letrasEnCombinacion++;
            temp /= 2;
        }

        // 2. Comparamos la combinación actual contra CADA palabra
        for (int p = 0; p < cantPalabras; p++) {
            // Solo se evalúa si la cantidad de letras coincide con el tamaño de la palabra
            if (letrasEnCombinacion == palabras[p].cantLetras) {

                // Reiniciamos las marcas de la palabra para esta prueba
                for (int k = 0; k < 8; k++) {
                    palabras[p].control[k] = 0;
                }

                bool esValida = true;
                int combinacionBit = i;

                // Verificamos letra por letra seleccionada
                for (int j = 0; j < cantLetrasProducir; j++) {
                    if (combinacionBit % 2 == 1) {
                        // Si la letra no se encuentra en la palabra o ya se usó, no sirve
                        if (!pertenecePalabra(letrasProducir[j], palabras[p])) {
                            esValida = false;
                            break;
                        }
                    }
                    combinacionBit /= 2;
                }

                // Si todas las letras encajaron 1 a 1, incrementamos combinaciones
                if (esValida) {
                    palabras[p].combinaciones++;
                }
            }
        }
    }

    // --- Salida ---
    cout << endl;
    for (int i = 0; i < cantPalabras; i++) {
        cout << "La palabra " << palabras[i].palabra
             << " tiene " << palabras[i].combinaciones
             << " combinaciones de Letras." << endl;
    }

    return 0;
}
