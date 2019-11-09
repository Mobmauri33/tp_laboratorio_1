#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "LinkedList.h"
#include "utn_strings.h"
#include "Controller.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* retorno = NULL;
    Employee* pAuxEmployee;

    if( id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL)
    {        pAuxEmployee = employee_new();
        if(pAuxEmployee != NULL)
        {
            if( !employee_setNombre(pAuxEmployee,nombre) &&
                !employee_setHorasTrabajadasStr(pAuxEmployee,horasTrabajadas) &&
                !employee_setIdStr(pAuxEmployee,id) &&
                !employee_setSueldoStr(pAuxEmployee,sueldo))
            {
                retorno = pAuxEmployee;
            }
            else
            {
                employee_delete(pAuxEmployee);
            }
        }
    }
    return retorno;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
    return;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int employee_setIdStr(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !isValidNumber(id))
    {
        retorno = employee_setId(this,atoi(id));
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getIdStr(Employee* this, char* id)
{
    int retorno = -1;
    int buffer;
    if(this != NULL && id != NULL)
    {
        employee_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}



int employee_setNombre(Employee* this,char* nombre)
{
    int retorno =-1;
    if(this != NULL && isLetter(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno =-1;
    if(this!=NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno =-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno =-1;
    if(this!=NULL && horasTrabajadas!=NULL && isValidNumber(horasTrabajadas))
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno =-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadasStr(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    int buffer;
    if(this != NULL && horasTrabajadas != NULL)
    {
        employee_getHorasTrabajadas(this,&buffer);
        sprintf(horasTrabajadas,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno =-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno =-1;
    if(this!=NULL && sueldo!=NULL && isValidNumber(sueldo))
    {
        retorno = employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno =-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldoStr(Employee* this, char* sueldo)
{
    int retorno = -1;
    int buffer;
    if(this!=NULL && sueldo!=NULL)
    {
        employee_getSueldo(this,&buffer);
        sprintf(sueldo,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int employee_ordenar(void* employee1, void* employee2)
{
    int retorno =-1;
    char bufferA[128];
    char bufferB[128];
    if(employee1!=NULL && employee2!=NULL)
    {
        employee_getNombre((Employee*)employee1,bufferA);
        employee_getNombre((Employee*)employee2,bufferB);
        retorno = strcmp(bufferA,bufferB);
    }
    return retorno;
}

int employee_ordenamientoNombre(void* this1, void* this2)
{
    int retorno=-1;

    char bufferI[128];
    char bufferJ[128];

    if(this1!=NULL && this2!=NULL)
    {
        employee_getNombre((Employee*)this1,bufferI);
        employee_getNombre((Employee*)this2,bufferJ);
        retorno = strcmp(bufferI,bufferJ);
    }
    return retorno;
}

int employee_ordenamientoId(void* this1, void* this2)
{
    int retorno =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getId((Employee*)this1,&bufferI);
        employee_getId((Employee*)this2,&bufferJ);
        if(bufferI>bufferJ)
            retorno=1;
        if(bufferI<bufferJ)
            retorno=-1;
        if(bufferI==bufferJ)
            retorno=0;
    }
    return retorno;
}

int employee_ordenamientoHorasTrabajadas(void* this1, void* this2)
{
    int retorno =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getHorasTrabajadas((Employee*)this1,&bufferI);
        employee_getHorasTrabajadas((Employee*)this2,&bufferJ);
        if(bufferI>bufferJ)
            retorno=1;
        if(bufferI<bufferJ)
            retorno=-1;
        if(bufferI==bufferJ)
            retorno=0;
    }
    return retorno;
}

int employee_ordenamientoSueldo(void* this1, void* this2)
{
    int retorno =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getSueldo((Employee*)this1,&bufferI);
        employee_getSueldo((Employee*)this2,&bufferJ);
        if(bufferI>bufferJ)
            retorno=1;
        if(bufferI<bufferJ)
            retorno=-1;
        if(bufferI==bufferJ)
            retorno=0;
    }
    return retorno;
}
