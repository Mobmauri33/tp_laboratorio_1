#include <stdio.h>
#include <stdlib.h>
#include "funcionesRacca.h"


int menuDeOpciones ()
{
    int opcion;

    printf("---BIENVENIDO AL MENU---\n");
    printf("1- Ingresar 1er operando (A=x)\n");
    printf("2- Ingresar 2do operando (B=y)\n");
    printf("3- Calcular todas las operaciones\n");
    printf("a) Calcular la suma (A+B)\n");
    printf("b) Calcular la resta (A-B)\n");
    printf("c) Calcular la division (A/B)\n");
    printf("d) Calcular la multiplicacion (A*B)\n");
    printf("e) Calcular el factorial (A!) y (B!)\n");
    printf("4- Informar los resultados\n");
    printf("5- Salir\n");
    printf("\nElegir una opcion (1-5): ");
    scanf("%d",&opcion);
    return opcion;
}
float pedirNumero ()
{
    float numero;
    scanf("%f", &numero);
    return numero;
}

float sumarDosNumeros (float x, float y)
{
    float laSuma;
    laSuma = x + y;
    return laSuma;
}

float restarDosNumeros (float x, float y)
{
    float laResta;
    laResta = x - y;
    return laResta;
}

float dividirDosNumeros (float x, float y)
{
    float laDivision;
    if(y==0)
    {
        printf("Error, no se puede dividir por 0");
    }else{
        laDivision = x / y;
    }
    return laDivision;
}

float multiplicarDosNumeros (float x, float y)
{
    float producto;
    producto = x * y;
    return producto;
}

int factorial (int x)
{
    int factorialX=1;
    int i;
    for (i=1;i<=x;i++)
    {
        factorialX = factorialX *i;
    }
    return factorialX;
}

int continuar(void)
{
    char respuesta;
    printf("Desea volver al menu? Si(s) / NO(n): ");
    scanf(" %c",&respuesta);
    while ( !((respuesta=='s')||(respuesta=='n')) )
        {
            printf ("\nError, ingrese (s/n): ");
            respuesta='s';
            break;
        }
        return (respuesta=='s');
}
