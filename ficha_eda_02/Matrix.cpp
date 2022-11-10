#pragma warning(disable:4996)
#define _USE_MATH_DEFINES
#include "Matrix.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#define MAX_li 50


void Matrix::Delete() {
	if (elems != NULL) {
		for (int i = 0; i < nLines; ++i) {
			delete[] elems[i];
		}
	}
}

void Matrix::Create(int lines, int cols) {
	nLines = lines;
	nCols = cols;
	elems = new float* [nLines];
	for (int i = 0; i < nLines; ++i)
	{
		elems[i] = new float[nCols];
		for (int j = 0; j < nCols; ++j)
		{
			elems[i][j] = 0;
		}
	}
};



Matrix::Matrix(const Matrix& ma) {

	Create(ma.nLines, ma.nCols);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = ma.elems[i][j];
		}
	}
}

Matrix::Matrix(int lines, int cols) {
	Create(lines, cols);
}

Matrix::Matrix()
{
}

Matrix::~Matrix(void) {
	Delete();
}

bool Matrix::CanMultiply(const Matrix* pm) {
	if (nCols == pm->nLines) // verifica se o n colunas e igual ao de linhas
		return true;
	return false;
}

bool Matrix::CanAdd(const Matrix* pm) {
	if (nLines == pm->nLines && nCols == pm->nCols)
		return true;
	return false;
}

const Matrix& Matrix::operator=(const Matrix& m1) {
	Delete(); // Limpa a memoria existente, caso esta exista
	Create(m1.nLines, m1.nCols);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = m1.elems[i][j];
		}
	} return *this;
}

Matrix Matrix::operator*(const Matrix& m2) {
	Matrix result(nLines, nCols);
	Matrix m1(nLines, nCols);
	result.Output();
	m1 = *this;
	m1.Output();
	for (int i = 0; i < result.nLines; i++) {
		for (int j = 0; j < m2.nCols; j++) {
			for (int k = 0; k < result.nCols; k++) {
				result.elems[i][j] += m1.elems[i][k] * m2.elems[k][j];
			}
		}
	} return result;
}

const Matrix& Matrix::operator+=(int k)
{
	Matrix result(nLines, nCols);
	result = *this;

	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = result.elems[i][j] + k; // Error here
		}
	}
	return *this;
}


Matrix Matrix::operator+ (const Matrix& m1) {
	Matrix r(nLines, nCols);
	if (nLines == m1.nLines && nCols == m1.nCols) {
		for (int i = 0; i < nLines; i++) {
			for (int j = 0; j < nCols; j++) {
				r.elems[i][j] = elems[i][j] + m1.elems[i][j];
			}
		}
	}return r;
}



const Matrix& Matrix::operator*=(int k) {
	Matrix m1;
	Matrix r(nLines, nCols);
	if (nLines == m1.nLines && nCols == m1.nCols) {
		for (int i = 0; i < nLines; i++) {
			for (int j = 0; j < nCols; j++) {
				elems[i][j] = m1.elems[i][j] * k;
			}
		}
	}return *this;
}

void Matrix::Transpose() {
	Matrix result(nCols, nLines);
	result = *this;
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nCols; j++) {
			elems[i][j] = result.elems[j][i];
		}
	}
}


bool Matrix::ReadFromFile(char* file_name) {
	FILE* pfile = fopen(file_name, "r"); // Abre o ficheiro texto em modo leitura
	int lines, cols;
	if (pfile == NULL) {
		printf("Error opening the file");
		return 0;
	}

	Delete();
	//Leitura da 1 linha
	fscanf(pfile, "%d %d", &lines, &cols);
	Create(lines, cols);
	printf("Numero de linhas: %d \t\t numero de colunas: %d \n\n", lines, cols);

	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nCols; j++) {
			fscanf(pfile, " %f", &elems[i][j]);
		}
	}

	return true;
}
bool Matrix::SaveToFile(char* file_name) {
	FILE* pfile;
	pfile = fopen(file_name, "w");
	if (pfile == NULL)
	{
		printf("Erro a criar o fichiro\n");
		return false;
	}
	fprintf(pfile, "%d  %d\n", nLines, nCols);
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nCols; j++) {
			fprintf(pfile, "%g\n", elems[i][j]);
		}
	}
	fclose(pfile);
	return true;
}


void Matrix::Output(void) {

	for (int i = 0; i < nLines; ++i) {
		for (int j = 0; j < nCols; ++j) {
			printf("%0.01f\t", elems[i][j], " ");
		}std::cout << std::endl;
	}
}


Matrix Matrix::getLowerTriangle() {
	std::cout << "\n";
	// printing lower triangular matrix
	std::cout << "Lower triangular matrix: \n";
	Matrix ma = *this;
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			if (i < j)
			{
				std::cout << "0" << " ";
			}
			else
				std::cout << elems[i][j] << " ";
		}
		std::cout << std::endl;
	}  return *this;
}

Matrix Matrix::getUpperTriangle() {
	std::cout << "Upper triangular matrix: \n";
	Matrix ma = *this;
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			if (i > j)
			{
				std::cout << "0" << " ";
			}
			else
				std::cout << elems[i][j] << " ";
		}
		std::cout << std::endl;
	}  return *this;
}

Matrix Matrix::GetLU() {

	Matrix U;
	U = *this;
	float f;
	for (int k = 0; k <= nLines - 2; k++)
	{
		for (int i = k + 1; i < nLines; i++) {

			f = U.elems[i][k] / U.elems[k][k];
			for (int j = k + 1; j < nCols; j++)
			{
				U.elems[i][j] = U.elems[i][j] - f * U.elems[k][j];
			}
			U.elems[i][k] = f;
		}
	} 
	return U;
}


float Matrix::GetDeterminant() {

	Matrix ma = *this;
	Matrix mb;
	int determinant = 0;
	mb = ma.getUpperTriangle();

	if (nCols != nLines) {
		return(0);
	}

	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nCols; j++) {
			determinant = determinant + mb.elems[i][j];
		}
	} printf("\n Determinante:\t %d\n", determinant);
	return determinant;
}

Matrix Matrix::GetInverse() {
	Matrix U = GetLU();
	Matrix Y(nLines, nCols);
	Matrix B(nLines, nCols);
	float s, z;
	//float det=GetDeterminante; fazer ciclo if para verificar se det não é zero para fazer a iversa
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nCols; j++) {
			s = 0;
			for (int k = 0; k <= i - 1; k++) {
				s += U.elems[i][k] * Y.elems[k][j];
			}
			if (i == j) {
				Y.elems[i][j] = (1 - s);
			}
			else {
				Y.elems[i][j] = (0 - s);
			}
		}
	}

	for (int i = nLines - 1; i >= 0; i--) {
		for (int n = 0; n < nLines; n++) {
			z = 0;
			for (int k = (i + 1); k < nCols; k++) {
				z += U.elems[i][k] * B.elems[k][n];
			}
			B.elems[i][n] = (Y.elems[i][n] - z) / U.elems[i][i];

		}

	}
	printf("\n\n\n");
	printf("Matriz inversa: \n");
	B.Output();
	return B;
}