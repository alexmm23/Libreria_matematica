#pragma once
#include <iostream>
using namespace std;
const double PI = 3.14159;
const double EPSILON = 0.00001;

//Libreria para calcular funciones
double angulos_a_radianes(double angulo) {
	return (angulo * PI) / 180;
}

double potencia(double base, int exp) {
	//si el exponente es 0 o la base es 1, el resultado es directamente 1
	if (exp == 0 || base == 1) { return 1; }

	//si la base es -1, el resultado es 1 o -1, para reflejar esto lo hago:
	//(si el exponente es par exp%2 es 0) 1 - (0)*2 = 1-0 = 1
	//(si el exponente es impar exp%2 es 1) 1 - (1)*2 = 1-2 = -1
	if (base == -1) { return 1 - (exp % 2) * 2; }

	//cargamos el resultado a la base
	double resultado = base;

	//siempre que el exponente sea mayor que 1 seguimos
	while (exp-- > 1) {
		resultado *= base;
	}
	return resultado;
}

long int factorial(int factor) {
	//el factorial de 0 es 1
	if (factor == 0) return 1;

	//cargamos 1 para multiplicar
	long int resultado = 1;

	//hacemos... mientras factor sea mayor que 1
	do {
		resultado *= factor;
	} while (factor-- > 1);

	return resultado;
}

//retornamos como valor positivo siempre (función módulo)
double positivo(double numero) {
	if (numero < 0) return -1 * numero;
	return numero;
}
//taylor para seno, con x en radianes
double seno(double x) {
	//aqui llevaremos la sumatoria
	double resultado = 0;

	//usaremos este valor de control para nuestra precisión 
	double resultado_anterior = 0;

	//este es el variable de la sumatoria
	int sumador = 0;

	//hacemos mientras la diferencia sea menor a la precisión 
	do {
		//almacenamos el resultado anterior
		resultado_anterior = resultado;

		//la serie de taylor
		resultado += potencia(-1, sumador) * potencia(x, 2 * sumador + 1) / factorial(2 * sumador + 1);

		//siempre avanzamos 1
		sumador++;

	} while (positivo(resultado - resultado_anterior) >= EPSILON);

	return resultado;
}

//taylor para coseno, con x en radianes
double coseno(double x) {
	//aqui llevaremos la sumatoria
	double resultado = 0;

	//usaremos este valor de control para nuestra precisión 
	double resultado_anterior = 0;

	//este es el variable de la sumatoria
	int sumador = 0;

	//hacemos mientras la diferencia sea menor a la precisión 
	do {
		//almacenamos el resultado anterior
		resultado_anterior = resultado;

		//la serie de taylor
		resultado += potencia(-1, sumador) * potencia(x, 2 * sumador) / factorial(2 * sumador);

		//siempre avanzamos 1
		sumador++;

	} while (positivo(resultado - resultado_anterior) >= EPSILON);

	return resultado;
}

double tangente(double x) {

	if (x / (PI / 2) == (int)(x / (PI / 2))) {
		cout << "Error: el angulo no debe ser multiplo de 90" << endl;
		return 0;
	}

	//trampa... pero la serie de taylor para tangente es computacionalmente muy pesada
	//este metodo aunque ligeramente menos preciso, resuelve el problema mucho más facil
	return seno(x) / coseno(x);
}