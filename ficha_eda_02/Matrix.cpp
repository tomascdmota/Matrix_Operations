#pragma warning(disable:4996)
#define _USE_MATH_DEFINES
#include "Matrix.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

int main() {
	Matrix m1 = Matrix::Matrix();
	Matrix::Matrix(); // Constroi a matriz inicial a abre o ficheiro de txt;
	Matrix::Matrix(m1);
	
}


	Matrix::Matrix() {
		char file_name[] = { "C:/Users/tomas/Desktop/PC/matriz.txt" };
		ReadFromFile(file_name);
	}

	Matrix::Matrix(const Matrix& m1) {

	}

	Matrix::Matrix(int lines, int cols) {

	}

	Matrix::~Matrix(void) {

	}


	bool Matrix::CanMultiply(const Matrix* pm) {
		return pm;
	}

	bool Matrix::CanAdd(const Matrix* pm) {
		return pm;
	}

	const Matrix& Matrix::operator=(const Matrix& m1) {
		return m1;
	}

	Matrix Matrix::operator*(const Matrix& m1) {
		return m1;
	}


	Matrix Matrix::operator+ (const Matrix& m1) {
		return m1;
	}



	void Matrix::Transpose() {

	}

	bool Matrix::ReadFromFile(char* file_name) {
		FILE* pfile;
		pfile = fopen(file_name, "r"); // Abre o ficheiro texto em modo leitura
		int lines, cols;
		float* elems;
		if (pfile == NULL) {
			printf("Error opening the file");
			exit(0);
		}
		else {
			//Leitura da 1 linha
			fscanf_s(pfile, "%d %d", &lines, &cols);
			printf("Numero de linhas: %d \t\t numero de colunas: %d ", lines, cols);

			elems = new float[lines*lines]; // Cria uma array com o tamanho da matriz
			int nLinhas = (lines * 2) + 1; // Cria uma var com o numero de linhas que e sempre igual ao 
			// primeiro numero do ficheiro (n linhas) x 2 (para fazer o numero de colunas tmb) mais a linha inicial

			printf("\n Valores:");
			for (int i = 1; i < nLinhas; i++) {
				fscanf_s(pfile, "%g", &elems[i]);
				printf("\t\t%g", elems[i]);
				for (int j = i; j < nLinhas; j++) {
					//printf("\n");
				}
				
			};
			printf("\n\n");
		}

	}

	bool Matrix::SaveToFile(char* file_name) {
		return file_name;
	}

	void  Matrix::Output(void) {

	}














