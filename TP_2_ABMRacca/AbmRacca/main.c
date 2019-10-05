#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
#define REINTENTOS 3
#define LEN_LISTA 5


int main()
{
    int flag=0;
    int posLibre;
    int opcion=0;
    Employee list[LEN_LISTA];

    emp_initEmployee(list,5);

     flag=1;

    while(opcion!=5)
    {
        getIntInRange(&opcion,"\n1)ALTAS\n2)MODIFICAR\n3)BAJA\n4)INFORMAR\n5)SALIR\n\n    INGRESE OPCION: ","ERROR\n",1,5,3);
        switch(opcion)
        {
            case 1:
            {
                posLibre=emp_findFree(list,LEN_LISTA);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!emp_addEmp(list,LEN_LISTA,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio de ALTA exitosamente!----\n");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA!----\n");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                }
                break;
            }
            case 2:
                {
                if(flag)
                {
                    if(emp_alter(list,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico exitosamente----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(emp_removeEmployee(list,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA se realizo con exito!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 4:
            {
                if(flag)
                {
                    reportEmployee(list,LEN_LISTA);
                    emp_printEmployee(list,LEN_LISTA);
                    printSalary(list, LEN_LISTA);
                }
                break;
            }

}
    }
    return 0;
}
