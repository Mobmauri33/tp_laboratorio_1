#include <stdio.h>
#include <stdlib.h>
#include "funcionesRacca.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1=0;
    float num2=0;
    float laSuma;
    float laResta;
    float laDivision;
    float laMultiplicacion;
    int i;
    int factorialA = 1;
    int factorialB = 1;
    int flag=0;

    while(seguir=='s')
    {
        printf("---BIENVENIDO AL MENU---\n");
        printf("A=%.2f---B=%.2f\n", num1, num2);
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

        if ( opcion < 1 || opcion > 5 ){

                printf("ERROR INGRESE UNA OPCION (1-5)\n");
                system("Pause");
                system("CLS");
        }
        switch(opcion)
        {
            case 1: /*INGRESO EL NUMERO UNO*/
                printf("\nIngrese el primer operando (A): ");
                scanf("%f",&num1);
                system("CLS");
                break;
            case 2: /*INGRESO EL NUMERO DOS*/
                printf("\nIngrese el segundo operando (B): ");
                scanf("%f",&num2);
                system("CLS");
                break;
            case 3: /*CALCULAR TODO*/
                if(num1==0 && num2==0)
                {
                    printf("**Error no se ha ingresado ningun valor**\n");
                    system("Pause");
                    system("CLS");
                break;
                }
                else{
                        if(num1==0 || num2==0)
                        {
                            printf("**Error A y B deben ser diferentes a 0 para poder operar**\n");
                            system("Pause");
                            system("CLS");
                            break;
                        }
                }
                flag=1;
                printf("Se Calcularon todas las operaciones, presione 4 para mostrar los resultados\n");
                laSuma = num1 + num2;
                laResta = num1 - num2;
                if(num2 != 0)
                {
                    laDivision = num1 / num2;
                }else {
                    printf("Error no se puede dividir por cero\n");
                }
                laMultiplicacion = num1 * num2;
                for (i=1;i<=num1;i++)
                {
                    factorialA = factorialA * i;
                }
                for (i=1;i<=num2;i++)
                {
                    factorialB = factorialB *i;
                }
                system("Pause");
                system("CLS");
                break;
            case 4:system("CLS"); /*MOSTRAR LOS RESULTADOS*/
                if(flag==0)
                {
                    printf("**Error, se deben calcular las operaciones antes de mostrar los resultados**\n");
                    system("Pause");
                    system("CLS");
                    break;
                }
                printf("---RESULTADOS---\n");
                printf("A=%.2f---B=%.2f\n", num1, num2);
                //SUMA
                printf("a)La suma de %.2f + %.2f es igual a %.2f\n", num1, num2, laSuma);
                //RESTA
                printf("b)La resta de %.2f - %.2f es igual a %.2f\n", num1, num2, laResta);
                //DIVISION
                if(num2==0)
                {
                    printf("c)No se puede dividir por 0\n");
                }else{
                printf("c)La division de %.2f / %.2f es igual a %.2f\n", num1, num2, laDivision);
                }
                //MULTIPLICACION
                printf("d)La multiplicacion de %.2f * %.2f es igual a %.2f\n", num1, num2, laMultiplicacion);
                //FACTORIALES
                printf("e)El factorial del numero %.2f es %i\n", num1, factorialA);
                printf("e)El factorial del numero %.2f es %i\n", num2, factorialB);
                //PREGUNTA SI QUIERE CONTINUAR
                printf("\nDesea volver al menu? Si(s) / NO(n): ");
                scanf(" %c",&seguir);
                while ( !((seguir=='s')||(seguir=='n')) )
                    {printf ("\nError, ingrese (s/n): ");
                    seguir='s';
                    break;
                }
                system("Pause");
                system("CLS");
                break;
            case 5: /*SALIR*/
                seguir='n';
                system("CLS");
                break;
        }
    }
    return 0;
}
