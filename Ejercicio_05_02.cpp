// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 2

// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y nos devuelva el país que mayor número de medallas ha ganado

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ATLETAS = 30;
const int MAX_NOMBRE = 40;
const int MAX_PAIS = 25;
const int MAX_DEPORTE = 30;

// Estructura para los datos de una persona
struct Datos {
    char nombre[MAX_NOMBRE];
    char pais[MAX_PAIS];
};
// Estructura para un atleta
struct Atleta {
    char deporte[MAX_DEPORTE];
    Datos datosPersonales;
    int medallas;
};
//Funcion para encontrar el pais con mas medallas
char* encontrarPaisConMasMedallas(Atleta atletas[], int n) {
    char* paisConMasMedallas = NULL;
    int mayorNumeroMedallas = 0;

    for (int i = 0; i < n; i++) {
        if (atletas[i].medallas > mayorNumeroMedallas) {
            mayorNumeroMedallas = atletas[i].medallas;
            paisConMasMedallas = atletas[i].datosPersonales.pais;
        }
    }
    return paisConMasMedallas;
}
int main() {
    int n;
    cout <<"Ingrese el numero de atletas: ";
    cin>> n;
    if (n <= MAX_ATLETAS) {
        Atleta atletas[MAX_ATLETAS];
        for (int i = 0; i < n; i++) {
            cout <<"Atleta #" <<i + 1 <<":" <<endl;
            cout <<"Nombre: ";
            cin>> atletas[i].datosPersonales.nombre;
            cout <<"Pais: ";
            cin>> atletas[i].datosPersonales.pais;
            cout <<"Deporte: ";
            cin >> atletas[i].deporte;
            cout <<"Numero de Medallas: ";
            cin>> atletas[i].medallas;
        }
        //Para encontrar el pais con mas medallas
        char* paisMasMedallas = encontrarPaisConMasMedallas(atletas, n);
        if (paisMasMedallas != NULL) {
            cout <<"**** DATOS DEL ATLETA CON MAYOR NUMERO DE MEDALLAS ****" <<endl;
            cout <<"NOMBRE: " << atletas[n-1].datosPersonales.nombre <<endl;
            cout <<"PAIS: " << atletas[n-1].datosPersonales.pais <<endl;
            cout <<"DEPORTE: " << atletas[n-1].deporte <<endl;
            cout <<"NUMERO DE MEDALLAS: " << atletas[n-1].medallas <<endl;
        } else {
            cout <<"No se ingresaron atletas." <<endl;
        }
    } else {
        cout <<"Se ha excedido el limite de atletas (30)." <<endl;
    }
    return 0;
}

