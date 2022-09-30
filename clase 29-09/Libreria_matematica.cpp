#include <iostream>
#include "trigonometricas.h"

using namespace std;


const int Deg = 180;

class Function {
private:
	
	double angle = 0;

public:
	Function(double);
	double funSin();
	double funCos();
	double funTan();

};
Function::Function(double _angle) {
	angle = _angle;

}
double Function::funSin() {
	double Sin = 0;
	cout.precision(5);
	double rad = angulos_a_radianes(angle);
	Sin = seno(rad);
	return Sin;
}
double Function::funCos() {
	double Cos = 0;
	cout.precision(5);
	double rad = angulos_a_radianes(angle);
	Cos = coseno(rad);
	return Cos;
}
double Function::funTan() {
	double Tan = 0;
	double rad = angulos_a_radianes(angle);
	Tan = tangente(rad);
	return Tan;
}


class Matrix {
private:
	int rows = 0;
	int columns = 0;
	int** Matrixx;

	
public:
	Matrix(int _rows, int _columns) {
		if (_rows < 0 || _columns < 0) {
			cout << "No puedes ingresar valores menores a 0" << endl;
			rows = 0;
			columns = 0;
		}

		rows = _rows;
		columns = _columns;

		Matrixx = new int* [rows];

		for (int i = 0; i < rows; i++) {
			Matrixx[i] = new int[columns];
		}
	};
	
	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] Matrixx[i];
		}
		delete[] Matrixx;
	}
	void mulMatrix(Matrix, Matrix, Matrix);
	void setMatrix();
	/*int getMatrix();*/
	int getRows();
	int getColumns();

};
void Matrix::setMatrix() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Ingrese el valor [" << i << "][" << j << "]" << " de la matriz: ";
			cin >> Matrixx[i][j];
			
		}

	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << Matrixx[i][j] << " ";
		}
		cout << endl;
	}
}
int Matrix::getRows() {
	return rows;
}
int Matrix::getColumns() {
	return columns;
}

void Matrix::mulMatrix(Matrix a, Matrix b, Matrix r) {
	cout << "Filas de la primera matriz " << a.getRows() << " por " << "columnas de la segunda matriz " << b.getColumns() << endl;
	if (a.getColumns() == b.getRows()) {
		//Calcular R = A*B
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < b.getColumns(); j++) {
				r.Matrixx[i][j] = 0;
				for (int k = 0; k < a.getColumns(); k++) {
					r.Matrixx[i][j] += a.Matrixx[i][k] * b.Matrixx[k][j];
				}

			}
		}
		for (int i = 0; i < r.getRows(); i++) {
			for (int j = 0; j < r.getColumns(); j++) {

				cout << r.Matrixx[i][j] << " ";
			}
			cout << endl;
		}
	}

}

int main() {
	int respuesta = 1;
	char answer = ' ';
	char* pointsToanswer = &answer;
	float angleA = 0;
	unsigned int row = 0, column = 0, row2 = 0, column2 = 0;

	while (true) {

		cout << "Seleccione una opcion" << endl;
		cout << "[1] Calcular seno de un angulo" << endl;
		cout << "[2] Calcular coseno de un angulo" << endl;
		cout << "[3] Calcular tangente de un angulo" << endl;
		cout << "[4] Multiplicacion de matrices (A x B)" << endl;
		cout << "[0] Salir" << endl;
		cin >> respuesta;
		system("cls");

		while (respuesta < 0 || respuesta > 4) {
			cout << "Ingrese una opcion valida" << endl;
			cout << "[1] Sin" << endl;
			cout << "[2] Cos" << endl;
			cout << "[3] Tan" << endl;
			cout << "[4] Multiplicacion" << endl;
			cout << "[0] Salir" << endl;
			cin >> respuesta;
			system("cls");
		}
		if (respuesta == 0) {

			break;
		}
		switch (respuesta)
		{
		case 1:
		{
			cout << "Calcular seno de un angulo" << endl;
			cout << "Ingrese un angulo en grados" << endl;
			cin >> angleA;
			Function seno(angleA);
			cout << "El seno del angulo: " << angleA << " es igual a " << seno.funSin() << " grados" << endl;
			break;
		}
		case 2:
		{
			cout << "Calcular coseno de un angulo" << endl;
			cout << "Ingrese un angulo en grados" << endl;
			cin >> angleA;
			Function coseno(angleA);
			cout << coseno.funCos() << endl;
			break;
		}
		case 3:
		{
			cout << "Calcular tangente de un angulo" << endl;
			cout << "Ingrese un angulo en grados" << endl;
			cin >> angleA;
			Function tangente(angleA);
			cout << tangente.funTan() << endl;
			break;
		}
		case 4:
		{
			cout << "---Multiplicacion de matrices ( A x B )---" << endl;
			cout << "---Matriz A---" << endl;
			cout << "Ingrese el numero de filas" << endl;
			cin >> row;
			cout << "Ingrese el numero de columnas" << endl;
			cin >> column;
			system("cls");
			cout << "---Matriz B---" << endl;
			cout << "Ingrese el numero de filas" << endl;
			cin >> row2;
			cout << "Ingrese el numero de columnas" << endl;
			cin >> column2;
			system("cls");
			if (row == column2)
			{
				
				Matrix* matrixA, * matrixB, * matrixR;
				matrixA = new Matrix(row, column);
				matrixB = new Matrix(row2, column2);
				matrixR = new Matrix(row, column2);
				matrixA->setMatrix();
				matrixB->setMatrix();
				matrixR->mulMatrix(*matrixA, *matrixB, *matrixR); //Aqui se me sale el case del bucle pero no entiendo por que?
				delete matrixA;
				delete matrixB;
				delete matrixR;
			}
			else

				cout << "No es posible hacer la multiplicacion de matrices" << endl;

			break;
		}

		}
		cout << "Desea ver el menu de nuevo? [y/n]" << endl;
		cin >> answer;
		system("cls");
		if (*pointsToanswer == 'n' || *pointsToanswer == 'N') {
			break;
		}

	}
}
