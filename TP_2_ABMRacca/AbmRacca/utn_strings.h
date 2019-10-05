#ifndef UTN_STRINGS_H_INCLUDED
#define UTN_STRINGS_H_INCLUDED

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return int
 */
int getString(char* pStr, char* msg, char*msgE);
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt (int *pNum, char* msg, char* msgE);
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getFloat (float *pNum, char* msg, char* msgE);

int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE);
int cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras
 */
int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo números
 */
int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo números
 */
int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras y números
 */
int getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos);
int getTelephone (char* pStr, char* msg, char* msgE,int reintentos);
int getDni (char* pStr, char* msg, char* msgE,int reintentos);
int getCuit (char* pStr, char* msg, char* msgE,int reintentos);

int findEmptyPlace (char pArray[][20],int* pIndex,int len);
int findName(char* name, char parray[][20], int len, int* pIndex);
int ordenarArrayMayorMenor (char* pArray, int len,int limit);

int showArrayInt(int* pArray,int len);
int showArrayChar(char* pArray,int len);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int isNumber (char* pStr);
/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int isNumberFloat (char* pStr);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int isLetter (char* pStr);
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int isAlphanumeric (char* pStr);
int isTelephone (char* pStr);
int isDni (char* pStr);
int isCuit (char* pStr);

#endif // UTN_STRINGS_H_INCLUDED
