// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 3

// Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del Multicine.
//Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de autos. Piso 1 – 50 autos. Piso 2 – 40 autos. Piso 3 – 30 autos. Piso 4 – 45 autos
//El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas, automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del auto

#include <iostream>
#include <string>
using namespace std;

struct Vehiculo {
    string tipo;
    string marca;
    string modelo;
    string color;
};

// Estructura para representar un piso de estacionamiento
struct Piso {
    int capacidad;
    int cantidadEstacionados;
    int vagonetas;
    int camionetas;
    int automoviles;
    int minivans;
    int motocicletas;
    Vehiculo vehiculos[200]; // Cantidad maxima de autos en el piso
};

// Funcion para ingresar un vehiculo
void ingresarVehiculo(Piso& piso, int& cantidadEstacionados) {
    if (piso.cantidadEstacionados < piso.capacidad) {
        cout <<"Tipo de vehiculo (vagoneta, camioneta, automovil, minivan, motocicleta): ";
        cin>> piso.vehiculos[piso.cantidadEstacionados].tipo;
        cout <<"Marca del vehiculo: ";
        cin>> piso.vehiculos[piso.cantidadEstacionados].marca;
        cout <<"Modelo del vehiculo: ";
        cin>> piso.vehiculos[piso.cantidadEstacionados].modelo;
        cout <<"Color del vehiculo: ";
        cin>> piso.vehiculos[piso.cantidadEstacionados].color;

        piso.cantidadEstacionados++;

        // Actualiza el contador por tipo de vehiculo
        if (piso.vehiculos[piso.cantidadEstacionados - 1].tipo == "vagoneta") {
            piso.vagonetas++;
        } else if (piso.vehiculos[piso.cantidadEstacionados - 1].tipo == "camioneta") {
            piso.camionetas++;
        } else if (piso.vehiculos[piso.cantidadEstacionados - 1].tipo == "automovil") {
            piso.automoviles++;
        } else if (piso.vehiculos[piso.cantidadEstacionados - 1].tipo == "minivan") {
            piso.minivans++;
        } else if (piso.vehiculos[piso.cantidadEstacionados - 1].tipo == "motocicleta") {
            piso.motocicletas++;
        }

        cout <<"Vehiculo estacionado en el piso " <<piso.capacidad - piso.cantidadEstacionados + 1 <<endl;
        cantidadEstacionados++;
    } else {
        cout <<"El estacionamiento en este piso esta lleno." <<endl;
    }
}
// Funcion para mostrar informacion del piso
void mostrarInfoPiso(const Piso& piso, int numeroPiso) {
    cout <<"Piso " <<numeroPiso <<": " <<piso.cantidadEstacionados <<" vehiculos estacionados" <<endl;
    cout <<"Vagonetas: " <<piso.vagonetas <<endl;
    cout <<"Camionetas: " <<piso.camionetas <<endl;
    cout <<"Automoviles: " <<piso.automoviles <<endl;
    cout <<"Minivans: " <<piso.minivans <<endl;
    cout <<"Motocicletas: " <<piso.motocicletas <<endl;
}
// Funcion principal
int main() {
    int cantidadEstacionados = 0;
    Piso pisos[4] = {
        {50, 0, 0, 0, 0, 0, 0},
        {40, 0, 0, 0, 0, 0, 0},
        {30, 0, 0, 0, 0, 0, 0},
        {45, 0, 0, 0, 0, 0, 0}
    };
    int opcion;
    do {
        cout <<"Menu de opciones:" <<endl;
        cout <<"1. Ingresar vehiculo" <<endl;
        cout <<"2. Mostrar informacion de pisos" <<endl;
        cout <<"0. Salir" <<endl;
        cout <<"Ingrese una opcion: ";
        cin>> opcion;

        switch (opcion) {
            case 1:
                int numeroPiso;
                cout <<"Ingrese el numero de piso (1-4): ";
                cin>> numeroPiso;
                if (numeroPiso >= 1 && numeroPiso <= 4) {
                    ingresarVehiculo(pisos[numeroPiso - 1], cantidadEstacionados);
                } else {
                    cout <<"Numero de piso invalido." << endl;
                }
                break;
            case 2:
                for (int i = 0; i < 4; i++) {
                    mostrarInfoPiso(pisos[i], i + 1);
                }
                cout <<"Total vehiculos estacionados: " <<cantidadEstacionados <<endl;
                break;
            case 0:
                cout <<"Saliendo del programa." <<endl;
                break;
            default:
                cout <<"Opción invalida." <<endl;
                break;
        }
    } while (opcion != 0);
    return 0;
}

