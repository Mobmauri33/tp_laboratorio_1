#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; ///1vacio - 0ocupado
    int idEmployee; ///clave unica de identidad univoca
}Employee;
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int emp_initEmployee(Employee* pEmployee,int len);
int emp_findFree(Employee* pEmployee, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int emp_addEmp(Employee* pEmployee,int len,int pIndex,char* msgE,int tries);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int emp_findEmpById(Employee* pEmployee, int len, int idE);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int emp_removeEmployee(Employee* pEmployee, int len,char* msgE,int tries);
int emp_alter(Employee* pEmployee, int len,char* msgE,int tries);
int emp_getID (Employee* pEmployee,int len,char* msgE,int tries);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int emp_printEmployee(Employee* pEmployee,int len);
int emp_orderByID(Employee* pEmployee, int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);
int sortEmployeesBySector(Employee * pEmployee, int len);
int reportEmployee(Employee* list, int len);
int printSalary(Employee* pEmployee , int len);
void limpiar (void);

#endif // ASOCIADO_H_INCLUDED

