#pragma once
#include <stdio.h>

// Interface


// Defini��o da classe Matriz que contem as opera��es
// tipicas de matrizes
class Matrix {

private:
	float **elems;
	int nLines;
	int nCols;
	// Fun��es privadas
	void Delete(); // Apagar a mem�ria din�mica criada para a matriz
	void Create(int lines, int cols); // Criar a mem�ria din�mica e inicializar a matriz

public:
	Matrix(); // Construtor de defeito
	Matrix(const Matrix& m1); // Construtor Copy
	Matrix(int lines, int cols);
	~Matrix(); // Destrutor
	bool CanMultiply(const Matrix* pm);
	bool CanAdd(const Matrix* pm);
	const Matrix& operator = (const Matrix& m1);
	Matrix operator + (const Matrix& m1);
	Matrix operator * (const Matrix& m1);
	const Matrix& operator += (int k); // Soma cada elemento da matriz com o valor k
	const Matrix& operator *= (int k); // Multiplica cada elemento da matriz por k
	void Transpose();
	bool ReadFromFile(char* file_name);
	bool SaveToFile(char* file_name);
	void Output();
	Matrix GetLU();
};