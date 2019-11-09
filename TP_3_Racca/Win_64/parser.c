#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char salario[4096];
    int retorno = 0;
    int ok = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = 1;
        do
        {
            Employee* neww = employee_new();
            if(neww != NULL)
            {
                ok = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,salario);
                if(ok == 4)
                {
                    employee_setId(neww, atoi(id));
                    employee_setNombre(neww,nombre);
                    employee_setHorasTrabajadas(neww,atoi(horasTrabajadas));
                    employee_setSueldo(neww,atoi(salario));
                    ll_add(pArrayListEmployee,neww);
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
            else
            {
                retorno = 0;
                break;
            }
        }
        while(!feof(pFile));

        fclose(pFile);
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int estado=1;
    Employee* pEmpleado;

    while(!feof(pFile))
    {
        pEmpleado = employee_new();
        if(fread(pEmpleado,sizeof(Employee),1, pFile)!=0)
        {
            ll_add(pArrayListEmployee,pEmpleado);
            estado=0;
        }
        else
        {
            employee_delete(pEmpleado);
        }
    }
    return estado;
}
