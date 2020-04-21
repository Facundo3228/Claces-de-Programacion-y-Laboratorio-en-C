/******************************************************************************

                    ARRAY PARALELOS Y SUS FUNCIONES

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define T 10
#define LIBRE 0
#define OCUPADO 1

int main()
{
    int legajo[T]={100,101,102};
    int nota1[T]={5,6,7};
    int nota2[T]={7,4,9};
    float promedio[T]={6,5,8};
    char nombre[T][20]={"Juan", "Ana", "Martin"};
    int estado[T];
    int i;
    int retornoFuncion;
    int opcion;

    inicializarAlumnos(estado, T, LIBRE);

       estado[0]=OCUPADO;
       estado[1]=OCUPADO;
       estado[2]=OCUPADO;
   do
   {
       printf("1. Cargar ALUMNO\n");
       printf("2. Modificar ALUMNO\n");
       printf("3. Eliminar ALUMNO\n");
       printf("4. Ordenar ALUMNOS por NOMBRE\n");
       printf("5. Listar ALUMNOS\n");
       printf("6. Salir\n");
       printf("Elija una opcion: ");
       scanf("%d", &opcion);
       switch(opcion)
       {
           case 1:
              retornoFuncion = cargarAlumno(legajo,nota1,nota2,promedio,nombre,estado,T,LIBRE,OCUPADO);
              switch(retornoFuncion)
               {
                   case 1:
                     printf("Alumno cargado con exito\n");
                   break;
                   case -1:
                     printf("No existe espacio para cargar al alumno\n");
                   break;
               }
            break;
            case 2:
                retornoFuncion = modificarAlumno(legajo, nota1, nota2, promedio, nombre, estado, T, OCUPADO);
                switch(retornoFuncion)
                {
                   case 1:
                     printf("Alumno modificado con exito\n");
                   break;
                   case 0:
                     printf("Alumno no modificado\n");
                   break;
                   case -1:
                     printf("Alumno no encontrado\n");
                   break;
                }
            break;
            case 3:
                retornoFuncion = eliminarAlumno(legajo, nota1, nota2, promedio, nombre, estado, T, LIBRE, OCUPADO);
                switch(retornoFuncion)
                {
                   case 1:
                     printf("Alumno modificado con exito\n");
                   break;
                   case 0:
                     printf("Alumno no modificado\n");
                   break;
                   case -1:
                     printf("Alumno no encontrado\n");
                   break;
                }
            break;
            case 4:
                ordenarAlumnosPorNombre(legajo, nota1, nota2, promedio, nombre, estado, T, OCUPADO);
            break;
            case 5:
                mostrarAlumnos(legajo,nota1,nota2,promedio,nombre,estado,T,OCUPADO);
            break;

       }

   }while(opcion!=6);

    return 0;
}



