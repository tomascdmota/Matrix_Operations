#pragma warning(disable:4996)
#define _USE_MATH_DEFINES
#include "Matrix.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>


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
	elems = new float*[nLines*nLines];

	for (int i = 0; i < nLines; ++i)
	{
		elems[i] = new float[nCols];
		for (int j = 0; j < nCols; ++j)
		{
			elems[i][j] = 0;
		}
	}
};


	Matrix::Matrix() {
		Create(0, 0);
	}

	Matrix::Matrix(const Matrix& m1) {
	}

	Matrix::Matrix(int lines, int cols) {
		Create(lines, cols);
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
		Matrix m1;
		m1 = *this;
		Delete();
		Matrix(m1.nLines, m2.nCols);
		for (int i = 0; i < m1.nLines; i++) {
			for (int j = 0; j < m2.nCols; j++) {
				for (int k = 0; k < m1.nCols; k++) {
					elems[i][j] += m1.elems[i][j] * m2.elems[k][j];
				}
			}
		} return *this;
	}

	const Matrix & Matrix::operator+=(int k)
	{
		Matrix m1;
		for (int i = 0; i < nLines; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				elems[i][j] = m1.elems[i][j] + k;
			}
		} return *this;
	}


	Matrix Matrix::operator+ (const Matrix& m1) {
		if (nLines == m1.nLines && nCols == m1.nCols) {
			for (int i = 0; i < nLines; i++) {
				for (int j = 0; j < nCols; j++) {
					elems[i][j] += m1.elems[i][j];
				}
			}
		}return m1;
	}



	const Matrix & Matrix::operator*=(int k)
	{

		Matrix m1;
		for (int i = 0; i < nLines; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				elems[i][j] = m1.elems[i][j] * k;
			}
		} return *this;
	}

	void Matrix::Transpose() {

	}

	bool Matrix::ReadFromFile(char* file_name) {
		FILE *pfile = fopen(file_name, "r"); // Abre o ficheiro texto em modo leitura
		int lines, cols;
		if (pfile == NULL) {
			printf("Error opening the file");
			return 0;
		}

		Delete();
			//Leitura da 1 linha
			fscanf_s(pfile, "%d %d", &lines, &cols);
			Create(lines, cols);
			printf("Numero de linhas: %d \t\t numero de colunas: %d \n", lines, cols);

			/*for (int i = 1; i < nLinhas; i++) {
				fscanf_s(pfile, "%g", &elems[i]);
				printf("\t%g", elems[i]);
				for (int j = i; j <= cols; ++j) {
					printf("\n");
				}
				
			};*/
			for (int i = 0; i < nLines; i++) {
				for (int j = 0; j < nCols; j++) {
					fscanf_s(pfile, " %f", &elems[i][j]);
				}
			}
			
	}

	bool Matrix::SaveToFile(char* file_name) {
		Matrix ma, mb(2,2), mc;
		char file[] = "matriz_produto.txt";
		ma.ReadFromFile(file_name);
		mb.ReadFromFile(file_name);
		if (ma.CanMultiply(&mb)) {
			mc = ma * mb;
			mc.SaveToFile(file);
		}
		return file_name;
	}

	void Matrix::Output(void) {
		
		for (int i = 0; i < nLines; ++i) {
			for (int j = 0; j < nCols; ++j) {
				printf("%0.01f\t", elems[i][j]);
			}
		} printf("\n");
	}

	Matrix Matrix::GetLU()
	{
		return Matrix();
	}


	int main() {
		Matrix m1 = Matrix::Matrix();
		Matrix::Matrix(); // Constroi a matriz inicial a abre o ficheiro de txt;
		Matrix::Matrix(m1);
		char file_name[] = {"C:/Users/tomas/Desktop/PC/matriz.txt" };
		char file_name2[] = { "C:/Users/tomas/Desktop/PC/matriz2.txt" };
		Matrix ma, mb, mc;
		ma.ReadFromFile(file_name);
		mb.ReadFromFile(file_name2);
		ma.Output();
		mb.Output();

		if(ma.CanAdd(&mb)) {
			mc = ma + mb;
			printf("A soma das matrizes e = \n");
			mc.Output();
		}
		else {
			printf(" Nao e possivel somar as duas\n");
		};


		if (ma.CanMultiply(&mb)) {
			mc = ma * mb;
			printf(" O produto das duas matrizes e = \n");
			mc.Output();
		}
		else {
			printf("Nao e possivel multiplicar as duas matrizes! \n");
		}
		
	}