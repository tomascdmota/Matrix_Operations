#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Matrix.h"
#include <stdlib.h>


int main() {
    Matrix ma, mb, mc;
    int k;
    char file_name[] = { "C:/Users/tomas/Desktop/PC/matriz.txt" };
    char file_name2[] = { "C:/Users/tomas/Desktop/PC/matriz2.txt" };
    ma.ReadFromFile(file_name);
    mb.ReadFromFile(file_name2);
    ma.SaveToFile(file_name);
    mb.SaveToFile(file_name2);
    printf("Matriz a: \n");
    ma.Output();
    printf("\n");
    printf("\nMatriz b: \n");
    mb.Output();
    printf("\n\n\n");

    if (ma.CanAdd(&mb)) {
        printf("Adicao das matrizes: \n\n");
        mc = ma + mb;
        printf("\n");
        printf("A soma das matrizes e: \n");
        mc.Output();
        printf("\nindique um valor k:  ");
        scanf("%d", &k);
        printf("\n");
        printf("Soma da matriz ma com o valor k (transposta): \n");
        ma += k;
        printf("\n");
        ma.Transpose();
        ma.Output();
        printf("\n\n\n");
    }
    else {
        printf(" Nao e possivel somar as duas\n");
    }


    if (ma.CanMultiply(&mb)) {
        printf("Mutltiplicação das matrizes\n\n");
       
        mc = ma * mb;
        printf(" O produto das duas matrizes e: \n\n");
        mc.Output();
        printf("indique um valor de k:  ");
        scanf("%d", &k);
        printf("Soma da matriz ma com o valor k: \n");
        ma += k;
        ma.Output();
        printf("\n transposta:");
        ma.Transpose();
        ma.Output();
    }
    else {
        printf("Nao e possivel multiplicar as duas matrizes! \n");
        printf("decomposição: ");
        mb = mc.GetLU();
        mb.Output();
        printf("\n");
    }
    printf("\nValor da decomposicao da matriz: \n\n");
    ma.GetLU();
    printf("\n\n\n\n\n");
    // TODO dar delete aos dados de ma e voltar a ler.
    ma.ReadFromFile(file_name);
    ma.SaveToFile(file_name);
    ma.Output();
    ma.GetDeterminant();
    printf("\n\n\n\n");
    ma.GetInverse();

}