// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 1

// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”. La información con que se cuenta es: nombre, ci, departamento y salario.
//Realizar sun programa en C++ que lea un array de estructura de los datos de N empleados e imprima los siguiente: Empleado con mayor salario. Empleado con menor salario. Promedio salarial
//Promedio por departamento. Departamento con mayor salario en promedio. Departamento con menor salario en promedio

#include <iostream>
#include <string>
using namespace std;
struct Empleado {
    string nombre;
    int ci;
    string departamento;
    double salario;
};

void leerEmpleado(Empleado& emp) {
    cout <<"Nombre: ";
    cin>> emp.nombre;
    cout <<"CI: ";
    cin>> emp.ci;
    cout <<"Departamento: ";
    cin>> emp.departamento;
    cout <<"Salario: ";
    cin>> emp.salario;
}
// Funcion para encontrar al empleado con el mayor salario
Empleado encontrarMayorSalario(const Empleado empleados[], int n) {
    Empleado mayorSalario = empleados[0];
    for (int i = 1; i < n; i++) {
        if (empleados[i].salario > mayorSalario.salario) {
            mayorSalario = empleados[i];
        }
    }
    return mayorSalario;
}
// Funcion para encontrar al empleado con el menor salario
Empleado encontrarMenorSalario(const Empleado empleados[], int n) {
    Empleado menorSalario = empleados[0];
    for (int i = 1; i < n; i++) {
        if (empleados[i].salario < menorSalario.salario) {
            menorSalario = empleados[i];
        }
    }
    return menorSalario;
}
// Funcion para calcular el promedio salarial
double calcularPromedioSalarial(const Empleado empleados[], int n) {
    double sumaSalarios = 0.0;
    for (int i = 0; i < n; i++) {
        sumaSalarios += empleados[i].salario;
    }
    return sumaSalarios / n;
}
// Funcion para calcular el promedio salarial por departamento
double calcularPromedioSalarialPorDepartamento(const Empleado empleados[], int n, const string& departamento) {
    double sumaSalarios = 0.0;
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (empleados[i].departamento == departamento) {
            sumaSalarios += empleados[i].salario;
            contador++;
        }
    }
    return (contador > 0) ? (sumaSalarios / contador) : 0.0;
}
// Funcion para encontrar el departamento con el mayor salario promedio
string encontrarDepartamentoMayorPromedio(const Empleado empleados[], int n) {
    string departamentoMayorPromedio = "";
    double mayorPromedio = 0.0;
    for (int i = 0; i < n; i++) {
        string departamentoActual = empleados[i].departamento;
        double promedioActual = calcularPromedioSalarialPorDepartamento(empleados, n, departamentoActual);
        if (promedioActual > mayorPromedio) {
            mayorPromedio = promedioActual;
            departamentoMayorPromedio = departamentoActual;
        }
    }
    return departamentoMayorPromedio;
}
// Funcion para encontrar el departamento con el menor salario promedio
string encontrarDepartamentoMenorPromedio(const Empleado empleados[], int n) {
    string departamentoMenorPromedio = "";
    double menorPromedio = calcularPromedioSalarialPorDepartamento(empleados, n, empleados[0].departamento);
    for (int i = 1; i < n; i++) {
        string departamentoActual = empleados[i].departamento;
        double promedioActual = calcularPromedioSalarialPorDepartamento(empleados, n, departamentoActual);
        if (promedioActual < menorPromedio) {
            menorPromedio = promedioActual;
            departamentoMenorPromedio = departamentoActual;
        }
    }
    return departamentoMenorPromedio;
}
int main() {
    int N;
    cout <<"Ingrese la cantidad de empleados: ";
    cin>> N;
    Empleado empleados[N];

    for (int i = 0; i < N; i++) {
        cout <<"Ingrese los datos del empleado #" <<i + 1 <<":" <<endl;
        leerEmpleado(empleados[i]);
    }
    Empleado mayorSalario = encontrarMayorSalario(empleados, N);
    Empleado menorSalario = encontrarMenorSalario(empleados, N);
    double promedioSalarial = calcularPromedioSalarial(empleados, N);
    string departamentoMayorPromedio = encontrarDepartamentoMayorPromedio(empleados, N);
    string departamentoMenorPromedio = encontrarDepartamentoMenorPromedio(empleados, N);
    
    cout <<"Empleado con mayor salario: " <<mayorSalario.nombre <<" (CI: " << mayorSalario.ci << ")" << endl;
    cout <<"Empleado con menor salario: " <<menorSalario.nombre <<" (CI: " << menorSalario.ci << ")" << endl;
    cout <<"Promedio salarial: " <<promedioSalarial <<endl;
    cout <<"Departamento con mayor salario promedio: " <<departamentoMayorPromedio <<endl;
    cout <<"Departamento con menor salario promedio: " <<departamentoMenorPromedio <<endl;
    return 0;
}

