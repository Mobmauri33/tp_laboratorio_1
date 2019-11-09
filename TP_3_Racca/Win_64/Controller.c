#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_strings.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 //FUNCION PARA CARGAR LOS DATOS DE EMPLEADOS DE UN ARCHIVO DE TEXTO
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    //ABRE EL ARCHIVO EN MODO LECTURA
  FILE* pFile = fopen(path, "r");
    int retorno = 0;
    //VALIDO QUE NO SEAN NULL
    if (pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        //GUARDA EL ARCHIVO PARSEADO EN RETORNO
        retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        //IMPRIME ESTE MENSAJE SI NO SE CARGO BIEN
        printf("\n----No se realizo la CARGA de DATOS!----\n");
    }
    //CIERRA EL ARCHIVO
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 //FUNCION PARA CARGAR LOS DATOS DE EMPLEADOS DE UN ARCHIVO BINARIO
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    //ABRE EL ARCHIVO
    pFile=fopen(path,"rb");
    //VALIDO QUE NO SEAN NULL
    if (pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        //GUARDO LOS DATOS PARSEADOS EN RETORNO
        retorno = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }
    //CIERRO EL ARCHIVO
    fclose(pFile);
    return retorno;
}

/** \brief Busca el indice de un ID determinado.
 *
 * \param pArrayListEmployee LinkedList* donde buscar.
 * \param id int ID a buscar.
 * \param index int* Indice del LinkedList donde se encuentra el Id buscado.
 * \return retorno int. (0) si salio todo correctamente. (-1) Si se pasaron parametros nulos o no se encontró.
 */
 //FUNCION QUE BUSCA ID
int controller_findID(LinkedList* pArrayListEmployee,int id,int* index)
{
    Employee* pAux;
    int length = ll_len(pArrayListEmployee);
    int i;
    int retorno = -1;
    int bufferInt;
    //VALIDA QUE NO SEA NULL
    if(pArrayListEmployee != NULL)
    {
        //RECORRE EL ARRAY
        for(i=0;i<length;i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            //LLAMA AL GET ID
            employee_getId(pAux, &bufferInt);
            if(bufferInt == id)
            {
                //LO QUE GUARDE EN EL BUFFER LO GUARDA EN id
                retorno = 0;
                *index = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Devuelve el array mas alto + 1.
 *
 * \param pArrayListEmployee LinkedList* donde buscar.
 * \return maxID int Devuelve el ID mas alto + 1. (-1) si los parametros son nulos o la lista se encuentra vacia.
 */
 //FUNCION QUE BUSCA EN EL ARRAY EL ID MAXIMO
int controller_arrayMaxID(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int longitud;
    int currentID;
    int maxID = -1;
    int i;
    //VALIDO QUE NO SEA NULL
    if(pArrayListEmployee != NULL)
    {
        //LONGITUD DEL ARRAY
        longitud = ll_len(pArrayListEmployee);
        for(i=0;i<longitud;i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            //LLAMA A GET ID
            employee_getId(pAux, &currentID);
            if(currentID > maxID)
            {
                //SE GUARDA EL ID MAXIMO
                maxID = currentID;
            }
        }
    }
    maxID += 1;
    return maxID;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* e_EmpNew = employee_new();
    char* buffer = (char*) malloc(sizeof(char)*128);
    int bufferId;
    char* bufferHoras = (char*) malloc(sizeof(char)*128);
    char* bufferSueldo = (char*) malloc(sizeof(char)*128);
    int retorno = 0;
    if(pArrayListEmployee == NULL || e_EmpNew == NULL)
    {
        retorno = 0;
    }
    else
    {
        getStringLetras(buffer,"\nIngrese Nombre del empleado: ","\nError\n",3);
        getStringNumeros(bufferHoras,"\nIngrese Las Horas Trabajadas: ","\nError\n",3);
        getStringNumeros(bufferSueldo,"\nIngrese El Sueldo: ","\nError\n",3);
        bufferId = ll_len(pArrayListEmployee);
        employee_setId(e_EmpNew,bufferId + 1);
        employee_setNombre(e_EmpNew,buffer);
        employee_setHorasTrabajadas(e_EmpNew,atoi(bufferHoras));
        employee_setSueldo(e_EmpNew,atoi(bufferSueldo));
        if(ll_add(pArrayListEmployee,e_EmpNew)==0)
        {
            retorno = 1;
        }
    }
    free(buffer);
    free(bufferSueldo);
    free(bufferHoras);
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferInt;
    char bufferId[4096];
    int option;
    int index;
    char bufferChar[128];
    Employee* pAux = NULL;
    if(pArrayListEmployee != NULL)
    {
        if(!getStringNumeros(bufferId,"\nIngrese id del empleado:","\nError\n",3))
        {
            if(!controller_findID(pArrayListEmployee,atoi(bufferId),&index))
            {
                pAux = ll_get(pArrayListEmployee, index);
                if(!getIntInRange(&option,"\n1) Modificar Nombre\n2) Modificar Horas Trabajadas\n3) Modificar sueldo\n", "\nError: Opcion invalida. Ingresela nuevamente: ",1,4,3))
                {
                    switch(option)
                    {
                        case 1:
                            if(!getStringLetras(bufferChar,"\nIngrese el nombre: ","\nError: Nombre invalido. Ingreselo nuevamente:",3))
                            {
                                employee_setNombre(pAux, bufferChar);
                                retorno = 1;
                            }
                            break;
                        case 2:
                            if(!getInt(&bufferInt,"\nIngrese las horas trabajadas: ","\nError: Horas invalidas. Ingreselo nuevamente: "))
                            {
                                employee_setHorasTrabajadas(pAux, bufferInt);
                                retorno = 1;
                            }
                            break;
                        case 3:
                            if(!getInt(&bufferInt,"\nIngrese el sueldo: ", "\nError: Sueldo invalido. Ingreselo nuevamente: "))
                            {
                                employee_setSueldo(pAux, bufferInt);
                                retorno = 1;
                            }
                            break;
                        default:
                            printf("Opcion invalida.");
                            break;
                    }
                }
            }
        }else
        {
            return retorno;
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
   int retorno=-1;
    char idBuscado[4096];
    int index;

       if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
        {
            if( !getStringNumeros(idBuscado,"\nIngrese id del empleado que desea ELIMINAR:","\nError\n",3) &&
                !controller_findID(pArrayListEmployee,atoi(idBuscado),&index))
            {
                retorno=ll_remove(pArrayListEmployee,index);
            }
            else
            {
                printf("\nNo existe el ID\n");
            }
        }
        else
        {
            printf("\nNo hay empleado en la nomina\n");
        }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* auxpEmployee;
    char nombre[4096];
    int id;
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0 )
    {
        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxpEmployee=ll_get(pArrayListEmployee,i);
            employee_getNombre(auxpEmployee,nombre);
            employee_getId(auxpEmployee,&id);
            employee_getHorasTrabajadas(auxpEmployee,&horasTrabajadas);
            employee_getSueldo(auxpEmployee,&sueldo);
            printf("\nId: %d Nombre: %s  HorasTrabajadas: %d Sueldo: %d\n" ,id,nombre,horasTrabajadas,sueldo);
            retorno=0;
        }
    }
    else
    {
        printf("\nNo hay empleados en la nomina\n");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
   int retorno=-1;
   int option;
   int flag = -1;

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
    {
        do{
                getIntInRange(&option,"\n\n*MENU DE ORDENAMIENTO*\n\n1)Ordenar por Nombre ascendente"
                                "\n2)Ordenar por Nombre descendente"
                                "\n3)Ordenar por Id ascendente"
                                "\n4)Ordenar por Id descendente"
                                "\n5)Ordenar por Horas Trabajadas ascendente"
                                "\n6)Ordenar por Horas Trabajadas descendente"
                                "\n7)Ordenar por Sueldo ascendente"
                                "\n8)Ordenar por Sueldo descendente"
                                "\n9)Salir\n\n INGRESE OPCION: ","ERROR\n",1,9,3);
                                system("CLS");
        switch(option)
        {
            case 1:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee, employee_ordenamientoNombre, 1);
                system("Pause");
                system("CLS");
            break;
            case 2:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoNombre,0);
                system("Pause");
                system("CLS");
            break;
            case 3:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoId,1);
                system("Pause");
                system("CLS");
            break;
            case 4:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoId,0);
                system("Pause");
                system("CLS");
            break;
            case 5:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoHorasTrabajadas,1);
                system("Pause");
                system("CLS");
            break;
            case 6:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoHorasTrabajadas,0);
                system("Pause");
                system("CLS");
            break;
            case 7:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoSueldo,1);
                system("Pause");
                system("CLS");
            break;
            case 8:
                printf("\nLA LISTA SE ESTA ORDENANDO POR FAVOR ESPERE :D\n");
                flag=ll_sort(pArrayListEmployee,employee_ordenamientoSueldo,0);
                system("Pause");
                system("CLS");
            break;
        }
        if(flag!=-1)
        {
            printf("\n----Se ORDENO los DATOS exitosamente!----\n");
            retorno =0;
        }
    }
    while(option != 9);
    }
    else
    {
        printf("\n NO hay elementos para ordenar!\n");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int i;
    char id[1024];
    char sueldo[1024];
    char horasTrabajadas[1024];
    char nombre[1024];
    Employee * pEmpleado=NULL;
    FILE* pFile=NULL;
    if(path != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL && pArrayListEmployee !=NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                employee_getIdStr(pEmpleado,id);
                employee_getNombre(pEmpleado,nombre);
                employee_getSueldoStr(pEmpleado,sueldo);
                employee_getHorasTrabajadasStr(pEmpleado,horasTrabajadas);
                fprintf(pFile,"%s,%s,%s,%s\n",id,nombre,horasTrabajadas,sueldo);
            }
        fclose(pFile);
        retorno=0;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"wb");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmployee =(Employee*) ll_get(pArrayListEmployee,i);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        retorno =0;
        fclose(pFile);
    }
    return retorno;
}
