#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
static int generarId(void);

int emp_initEmployee(Employee* pEmployee,int len)
{
    int i;
    if(pEmployee!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pEmployee[i].idEmployee=-1;
            pEmployee[i].isEmpty=1;
        }
    }
    return 0;
}

int emp_findFree(Employee* pEmployee, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmployee[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int emp_addEmp(Employee* pEmployee,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[51];
    char bufferLastName[51];
    char bufferSector[20];
    char bufferSalary[20];
    float auxSalary;
    int auxSector;
    int retorno=-1;
    if((pEmployee!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        if(((getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries)==0)&&
            (getStringLetras(bufferLastName,"\nIngrese Apellido: ",msgE,tries)==0)))
        {
            if((getStringNumerosFloat(bufferSalary,"\nIngrese Salario: ",msgE,tries)==0)
                &&(getStringNumeros(bufferSector,"\nIngrese su Sector: ",msgE,tries)==0))
            {
                auxSalary=atof(bufferSalary);
                auxSector=atoi(bufferSector);
                strncpy(pEmployee[pIndex].name,bufferName,sizeof(bufferName));
                strncpy(pEmployee[pIndex].lastName,bufferLastName,sizeof(bufferLastName));
                pEmployee[pIndex].salary=auxSalary;
                pEmployee[pIndex].sector=auxSector;
                pEmployee[pIndex].idEmployee=generarId();
                pEmployee[pIndex].isEmpty=0;
                retorno=0;
            }
        }
    }
    return retorno;
}

int emp_findEmpById(Employee* pEmployee, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmployee[i].idEmployee==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
int emp_removeEmployee(Employee* pEmployee, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pEmployee!=NULL && len>0)
    {
        auxID=emp_getID(pEmployee,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=emp_findEmpById(pEmployee,len,auxID);
            if(posOfID!=-1)
            {
               pEmployee[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int emp_alter(Employee* pEmployee, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[51];
    char bufferLastName[51];
    char bufferSector[20];
    char bufferSalary[20];
    float auxSalary;
    int auxSector;
    int retorno=-1;

    if((pEmployee!=NULL)&&(len>0))
    {
        auxID=emp_getID(pEmployee,len,msgE,tries);
        if(auxID>=0)
        {
            posOfID=emp_findEmpById(pEmployee,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=5)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Apellido\n");
                    printf("3- Modificar Salario\n");
                    printf("4- Modificar Sector\n");
                    printf("5- Atras (Menu Principal)\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,5,tries);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE,tries))
                            {
                                strncpy(pEmployee[posOfID].name,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!getStringLetras(bufferLastName,"\nIngrese NUEVO Apellido: ",msgE,tries))
                            {
                                strncpy(pEmployee[posOfID].lastName,bufferLastName,sizeof(bufferLastName));
                                retorno=0;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(!getStringNumeros(bufferSalary,"\nIngrese NUEVO Salario: ",msgE,tries))
                            {
                                auxSalary=atof(bufferSalary);
                                pEmployee[posOfID].salary=auxSalary;
                                retorno=0;
                            }
                            break;
                        }
                        case 4:
                        {
                            if(!getStringNumeros(bufferSector,"\nIngrese NUEVO Sector: ",msgE,tries))
                            {
                                auxSector=atoi(bufferSector);
                                pEmployee[posOfID].sector=auxSector;
                                retorno=0;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}

int emp_getID (Employee* pEmployee,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pEmployee!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

int emp_printEmployee(Employee* pEmployee,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pEmployee[i].isEmpty!=1)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n-------",
                   pEmployee[i].idEmployee,pEmployee[i].name,pEmployee[i].lastName,pEmployee[i].salary,pEmployee[i].sector);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int emp_orderByID(Employee* pEmployee, int len)
{
    int i;
    int j;
    Employee buffer;
    for(i=0;i<len-1;i++)
    {
        if(pEmployee[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pEmployee[j].isEmpty==1)
            {
                continue;
            }
            if(pEmployee[i].idEmployee>pEmployee[j].idEmployee)
            {
                buffer=pEmployee[i];
                pEmployee[i]=pEmployee[j];
                pEmployee[j]=buffer;
            }
        }
    }
    return 0;
}

int sortEmployeesBySector(Employee* pEmployee, int len)
{

    Employee aux;

    int i,j;
    for(i=0; i<len-1; i++)
    {
    for(j=i+1; j<len; j++)
    {
    if(pEmployee[i].sector>pEmployee[j].sector)
        {
        aux = pEmployee[j];
        pEmployee[j] = pEmployee[i];
        pEmployee[i] = aux;
    }
    if (pEmployee[i].sector == pEmployee[j].sector)
        {

    if( strcmp(pEmployee[i].lastName , pEmployee[j].lastName)>0 )
        {
            aux = pEmployee[j];
    pEmployee[j] = pEmployee[i];
    pEmployee[i] = aux;
    }
    }
}
}
    return 0;
}
int sortEmployees(Employee* list, int len, int order)
{
    int returnAux=-1;
    int i;
    Employee buffer;
    int flagSwap;

    if(list!=NULL && len>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < len-1; i++)
            {
                if( ((strcmp(list[i].lastName,list[i+1].lastName) < 0) && order) ||  //1 descendente
                    ((strcmp(list[i].lastName,list[i+1].lastName) > 0) && !order) )  //0ascendente
                {
                    flagSwap=1;
                    buffer = list[i];
                    list[i] = list[i+1];
                    list[i+1] = buffer;
                }
                else if(strcmp(list[i].lastName,list[i+1].lastName) == 0)
                {
                    if( ((list[i].sector < list[i+1].sector) && order) ||
                        ((list[i].sector > list[i+1].sector) && !order) )
                    {
                        flagSwap=1;
                        buffer = list[i];
                        list[i] = list[i+1];
                        list[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        returnAux=0;
    }
    return returnAux;
}
int reportEmployee(Employee* list, int len)
{
    int returnAux =-1;
    int option=0;
    int auxOrder;

    if(list!=NULL && len >0)
    {
        if(len==0)
        {
            printf("\nNo hay Empleados en la lista!\n");
        }
        else
        {
            do
            {
                printf("\n---------INFORMAR---------");
                getIntInRange(&option,"\n1. Listado Ordenado por Apellido y Salario\n2. Total y Promedio de salarios"
                            "\n3.Menu anterior\n","\nError\n",1,3,3);
                switch(option)
                {
                case 1:
                    printf("\n------ORDENAR-----\n");
                    if(!getIntInRange(&auxOrder,"0.Ascendente\n1.Descendente\n","\nError\n",0,1,3))
                    {
                        sortEmployees(list,len,auxOrder);
                        emp_printEmployee(list,len);
                    }
                    break;
                case 2:
                    printSalary(list,len);
                    break;
                }
            }while(option!=3);
        }
    }
    return returnAux;
}
int printSalary(Employee* pEmployee ,int len)
{
    float TotalSalaries , averageSalary = 0;
    int overAverage = 0 , activeEmployees = 0 , i;

    for (i=0;i<len;i++){
        if (pEmployee[i].isEmpty == 0){
            activeEmployees ++;
            TotalSalaries = TotalSalaries + pEmployee[i].salary;
        }
    }

    averageSalary = (TotalSalaries / activeEmployees)  ;

    for(i=0;i<len;i++){

        if (pEmployee[i].salary > averageSalary && pEmployee[i].isEmpty == 0){
            overAverage++;
        }
    }
    printf("\nSuma de todos los salarios: %.2f \nSalario promedio: %.2f \nCantidad de empleados por encima del promedio:%d\n",TotalSalaries,averageSalary,overAverage);
     return 0;
    }

static int generarId(void)
{
    static int idEmpl=0;
    return idEmpl++;
}

