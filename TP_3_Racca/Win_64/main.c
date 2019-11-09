#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_strings.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
            //MENU
            getIntInRange(&option,"\n\n*MENU*\n\n1)Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
                                "\n2)Cargar los datos de los empleados desde el archivo data.bin (modo binario)."
                                "\n3)Alta de empleado"
                                "\n4)Modificar datos de empleado"
                                "\n5)Baja de empleado"
                                "\n6)Listar empleados"
                                "\n7)Ordenar empleados"
                                "\n8)Guardar los datos de los empleados en el archivo data.csv (modo texto)."
                                "\n9)Guardar los datos de los empleados en el archivo data.bin (modo binario)."
                                "\n10)Salir\n\n INGRESE OPCION: ","ERROR\n",1,10,3);
                                system("CLS");
        switch(option)
        {
            case 1://CARGA EL ARCHIVO DE TEXTO
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\n----Se CARGO los DATOS exitosamente!---- %d\n",ll_len(listaEmpleados));
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se realizo la CARGA de DATOS!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            case 2://CARGA EL ARCHIVO BINARIO
                if (!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\n----Se CARGO los DATOS exitosamente!---- %d\n",ll_len(listaEmpleados));
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se realizo la CARGA de DATOS!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            case 3://LLAMA A LA FUNCION DE AGREGAR UN EMPLEADO
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("\n----Se dio ALTA de EMPLEADO exitosamente!----\n");
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se realizo el ALTA de EMPLEADO!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            case 4://LLAMA A LA FUNCION DE EDITAR UN EMPLEADO
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("\n----Se modifico EMPLEADO exitosamente----\n");
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se modifico EMPLEADO!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            case 5://LLAMA A LA FUNCION DE ELIMINAR A UN EMPLEADO
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("\n----La BAJA de EMPLEADO se realizo con exito!----\n");
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se realizo la BAJA de EMPLEADO!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            case 6://LLAMA A LA FUNCION DE LISTAR EMPLEADOS
                if(controller_ListEmployee(listaEmpleados))
                    printf("\nERROR!");
                    system("Pause");
                    system("CLS");
             break;
            case 7:
                if(controller_sortEmployee(listaEmpleados)==-1)
                    printf("\nERROR!");
                    system("Pause");
                    system("CLS");
                break;
            case 8://GUARDA LA LISTA EN UN ARCHIVO DE TEXTO EXTRA CON EXTENSION.BKP
                if(!controller_saveAsText("data.bkp",listaEmpleados))
                {
                    printf("\n----El GUARDADO de DATOS se realizo con exito!----\n");
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se realizo el GUARDADO de DATOS!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            case 9://GUARDA LA LISTA DE UN ARCHIVO BINARIO
            if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\n----El GUARDADO de DATOS se realizo con exito!----\n");
                    system("Pause");
                    system("CLS");
                }
                else
                {
                    printf("\n----No se realizo el GUARDADO de DATOS!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
        }
    }while(option != 10);
    return 0;
}
