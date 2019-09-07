#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int menuDeOpciones ();
/** \brief Menu de opciones para la calculadora.
 * \return Opcion elegida.
 */

 float pedirNumero ();
/** \brief Se realiza un scanf que lee datos.
 * \param ()
 * \return El Numero ingresado.
 */

 float sumarDosNumeros (float x, float y);
/** \brief Realizar la suma de dos numeros ingresados.
 * \param Primer numero a sumar.
 * \param Segundo numero a sumar.
 * \return La suma de ambos numeros.
 */

 float restarDosNumeros (float x, float y);
/** \brief Realizar la resta de dos numeros ingresados.
 * \param Primer numero que es al que se le resta.
 * \param Segundo numero que le resta al primer numero.
 * \return La resta entre ambos numeros.
 */

 float dividirDosNumeros (float x, float y);
/** \brief Realizar la division de dos numeros ingresados.
 * \param Primer numero es el dividendo.
 * \param Segundo numero es el divisor.(NO ES VALIDO SI ES 0).
 * \return El resultado de la division.
 */

 float multiplicarDosNumeros (float x, float y);
/** \brief Realizar la multiplicacion de dos numeros ingresados.
 * \param Primer numero que es al que se le multiplica.
 * \param Segundo numero que multiplica al primer numero.
 * \return El producto de la multiplicacion.
 */

 int factorial (int x);
/** \brief Calcular el factorial de un numero.
 * \param Numero ingresado a calcular.
 * \return El factorial del numero ingresado.
 */

 int continuar(void);
/** \brief Se le pregunta al usuario si desea continuar (s ó n).(NO SE PERMITEN OTROS CARACTERES).
 * \param ()
 * \return Si se ingresa "s" devuelve el resultado de la condicion verdadera y si se ingresa "n" devuelve el resultado de la condicion falsa.
 */

#endif // FUNCIONES_H_INCLUDED
