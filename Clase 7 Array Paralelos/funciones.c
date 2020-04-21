#include <stdio.h>
#include <string.h>
#include "funciones.h"

//Funcion de control inicializa el array estado[] en 0 para vacio y 1 para ocupado
void inicializarAlumnos(int estado[], int tam, int valorLibre)
{
    int i;
    for(i=0; i<tam; i++)
    {
        estado[i] = valorLibre;
    }
}

//Funcion de control busca un estado en el array estado[] donde el valor sea 0 para libre
int buscarLibre(int estado[], int tam, int valorLibre)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(estado[i]==valorLibre)
        {
            indice = i;
            break;
        }
    }
    /*
    -1: Si no encontro espacio
    1: si pudo cargar al alumno
    */
    return indice;
}

//Funcion de control que calcula el promedio
float calcularPromedio(int nota1, int nota2)
{
    return (float)(nota1+nota2)/2;
}

//Carga de datos, siempre y cuando la funcion buscarLibre(...) haya encontrado en el array estado[i] un valor != -1 indicando que hay espacio disponible
int cargarAlumno(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorLibre, int valorOcupado)
{
    int indiceEncontrado;
    //buscar una posicion dentro del array estado p/ guardar datos
    indiceEncontrado = buscarLibre(estado, tam, valorLibre);
    if(indiceEncontrado!=-1)//encontro lugar
    {
         //si encuentro lugar, pido los datos del alumno y calcular el promedio
        //cambiar el estado

        printf("Ingrese un legajo: ");
        scanf("%d", &legajo[indiceEncontrado]);

        printf("Ingrese nota 1: ");
        scanf("%d", &nota1[indiceEncontrado]);

        printf("Ingrese nota 2: ");
        scanf("%d", &nota2[indiceEncontrado]);

        /*calcular promedio*/
        promedio[indiceEncontrado] = calcularPromedio(nota1[indiceEncontrado], nota2[indiceEncontrado]);

        printf("Ingrese nombre: ");
        __fpurge(stdin);
        fgets(nombre[indiceEncontrado],20,stdin);
        nombre[indiceEncontrado][strlen(nombre[indiceEncontrado])-1]='\0';

        /*cambiar estado*/
        estado[indiceEncontrado] = valorOcupado;

        indiceEncontrado = 1;
    }
   return indiceEncontrado;
}

//Muestro los datos cargados solo si el array estado[i] se encuentra con valorOcupado = 1
void mostrarAlumnos(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado)
{
    int i;

    printf("\tLegajo-------Nota 1-------Nota 2-----Promedio--------------Nombre\n");
    for(i=0; i<tam; i++)
    {
        if(estado[i]==valorOcupado)
        {
            printf("%12d %12d %12d %12.2f %20s\n", legajo[i], nota1[i], nota2[i], promedio[i], nombre[i]);
        }
    }
}

//Modifico el valor de los datos ingresados siempre i cuando la confirmacion sea 's' (1 si pudo modificar,0 si el usuario cancela la modificacion y -1 si no encontro al alumno)
int modificarAlumno(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado)
{
    char confirmacion;
    int valorRetorno = -1;
    int i;
    int auxLegajo;
    int auxNota1[tam];
    int auxNota2[tam];
    float auxPromedio[tam];
    char auxNombre[tam][20];

    //pedir un legajo
    printf("Ingrese el legajo que esta buscando: ");
    scanf("%d", &auxLegajo);

    printf("\tLegajo-------Nota 1-------Nota 2-----Promedio--------------Nombre\n");
    //buscar el legajo
    for(i=0;i<tam; i++)
    {
        //lo encuentre
        if(estado[i] == valorOcupado && auxLegajo == legajo[i])//encontre al alumno
        {
            //Valor a modificar
            printf("%12d %12d %12d %12.2f %20s\n", legajo[i], nota1[i], nota2[i], promedio[i], nombre[i]);

            if(valorRetorno != valorOcupado)
            {
                //Modifico
                printf("\nIngrese nueva nota 1: ");
                scanf("%d", &auxNota1[i]);
                printf("\nIngrese nueva nota 2: ");
                scanf("%d", &auxNota2[i]);
                auxPromedio[i] = calcularPromedio(auxNota1[i], auxNota2[i]);
                printf("Ingrese nombre: ");
                __fpurge(stdin);
                fgets(auxNombre[i],20,stdin);
                auxNombre[i][strlen(auxNombre[i])-1]='\0';

                //Valor ingresado para confirmar modificacion
                printf("\n\tLegajo-------Nota 1-------Nota 2-----Promedio--------------Nombre\n");
                printf("%12d %12d %12d %12.2f %20s\n", legajo[i], auxNota1[i], auxNota2[i], auxPromedio[i], auxNombre[i]);

                printf("Confirme si desea realizar los cambios s/n:");
                __fpurge(stdin);
                scanf("%c", &confirmacion);

                if(confirmacion == 's')
                {
                    nota1[i] = auxNota1[i];
                    nota2[i] = auxNota2[i];
                    promedio[i] = auxPromedio[i];
                    strcpy(nombre[i], auxNombre[i]);

                    //Valor ya modificar
                    printf("\n\tLegajo-------Nota 1-------Nota 2-----Promedio--------------Nombre\n");
                    printf("%12d %12d %12d %12.2f %20s\n", legajo[i], auxNota1[i], auxNota2[i], auxPromedio[i], auxNombre[i]);

                    valorRetorno = 1;
                    break;
                }
                else
                {
                    auxNota1[i] = nota1[i];
                    auxNota2[i] = nota2[i];
                    auxPromedio[i] = promedio[i];
                    strcpy(auxNombre[i], nombre[i]);

                    //Valor no modificado
                    printf("\n\tLegajo-------Nota 1-------Nota 2-----Promedio--------------Nombre\n");
                    printf("%12d %12d %12d %12.2f %20s\n", legajo[i], nota1[i], nota2[i], promedio[i], nombre[i]);

                    valorRetorno = 0;

                }
                break;
            }
        }else
        {
          //printf("El legajo ingresado no existe.\n");
          valorRetorno = -1;
          break;
        }
    }

    return valorRetorno;
}


int eliminarAlumno(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorLibre ,int valorOcupado)
{

    int i;
    int auxLegajo;
    printf("Ingrese el legajo que quiere eliminar: ");
    scanf("%d", &auxLegajo);

    for(i=0;i<tam; i++)
    {
        if(estado[i] == valorOcupado && auxLegajo == legajo[i])//encontre al alumno
        {

            estado[i]= valorLibre;
            break;
        }
    }

    return 1;
}

void ordenarAlumnosPorNombre(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado)
{
    int i;
    int j;

    char auxString[20];
    int auxInt;
    float auxFloat;

    for(i=0; i<tam-1; i++)
    {
        if(estado[i]!=valorOcupado)
        {
            continue;
        }
        for(j=i+1; j<tam; j++)
        {
             if(estado[j]!=valorOcupado)
             {
                 continue;
             }
            if(strcmp(nombre[i], nombre[j])<0)
            {
                strcpy(auxString, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString);

                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat;


            }
        }
    }
}

//nota:

 /*
            //do
            //{

                //Modifico
                printf("Ingrese nueva nota 1: ");
                scanf("%d", &auxNota1[i]);
                printf("Confirme si desea realizar los cambios s/n:");
                __fpurge(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's')
                {
                  nota1[i] = auxNota1[i];
                  valorRetorno = 1;
                }else
                {
                  auxNota1[i] = nota1[i];
                  valorRetorno = 0;
                }

                printf("Ingrese nueva nota 2: ");
                scanf("%d", &auxNota2[i]);
                printf("Confirme si desea realizar los cambios s/n:");
                __fpurge(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's')
                {
                  nota2[i] = auxNota2[i];
                  valorRetorno = 1;
                }else
                {
                  auxNota2[i] = nota2[i];
                  valorRetorno = 0;
                }


                auxPromedio[i] = calcularPromedio(auxNota1[i], auxNota2[i]);
                promedio[i] = auxPromedio[i];


                printf("Ingrese nombre: ");
                __fpurge(stdin);
                fgets(auxNombre[i],20,stdin);
                auxNombre[i][strlen(auxNombre[i])-1]='\0';
                printf("Confirme si desea realizar los cambios s/n:");
                __fpurge(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's')
                {
                  strcpy(nombre[i], auxNombre[i]);
                  valorRetorno = 1;
                }else
                {
                  strcpy(auxNombre[i], nombre[i]);
                  valorRetorno = 0;
                }

                //Valor a modificar
                printf("\n\tLegajo-------Nota 1-------Nota 2-----Promedio--------------Nombre\n");
                printf("%12d %12d %12d %12.2f %20s\n", legajo[i], nota1[i], nota2[i], promedio[i], nombre[i]);

                /*
                printf("Confirme si desea realizar los cambios s/n:");
                __fpurge(stdin);
                scanf("%c", &confirmacion);
                //valorRetorno = 1;

            }while(confirmacion != 's');
            */
