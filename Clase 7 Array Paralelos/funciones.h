#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void inicializarAlumnos(int estado[], int tam, int valorLibre);
int buscarLibre(int estado[], int tam, int valorLibre);
int cargarAlumno(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorLibre, int valorOcupado);
void mostrarAlumnos(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado);
float calcularPromedio(int nota1, int nota2);

int modificarAlumno(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado);
int eliminarAlumno(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorLibre, int valorOcupado);

void ordenarAlumnosPorNombre(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado);



#endif // FUNCIONES_H_INCLUDED
