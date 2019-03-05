#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 3 //lines
#define N 4 //

void printMatrix(int m, int n,float* matrix) 
{
	int i, j;
    for(i = 0; i < m; i++)
	{
        for(j = 0; j < n; j++)
		{
            printf(" %f\t", *(matrix + (m+1)*i + j));
        }
        printf("\n");
    } 
    printf("\n");
}

void modMatrixLine(int m, int n, float* matrix, float modifier, int indx) // 2 - 1 
{
	int i, j;
	for(j = 0; j < n; j++)
	{
		*(matrix + (m+1)*indx + j) = modifier*(*(matrix + (m+1)*indx + j));
	}
}

void SumMatrixLine(int m, int n, float* matrix, float k1, float k2, int indx1, int indx2) // 2 - 1 
{
	int i, j;
	for(j = 0; j < n; j++)
	{
		*(matrix + (m+1)*indx2 + j) = k2*(*(matrix + (m+1)*indx2 + j)) + k1*(*(matrix + (m+1)*indx1 + j));
	}
}

int main(void) 
{
	int i, j;
	float matrix[M][N] = {0};
	
//	matrix[0][0] = 1; 	matrix[0][1] = 1; 	matrix[0][2] = 2;
//	matrix[1][0] = 2; 	matrix[1][1] = 4; 	matrix[1][2] = 6;

	matrix[0][0] = 0.66; 	matrix[0][1] = -1.44; 	matrix[0][2] = -0.18; 	matrix[0][3] = 1.83; //0.66*x - 1.44*y - 0.18*z = 1.11
	matrix[1][0] = 0.48; 	matrix[1][1] = -0.24; 	matrix[1][2] = 0.37; 	matrix[1][3] = -0.84; //0.48*x - 0.24*y +0.37*z = -0.84
	matrix[2][0] = 0.86; 	matrix[2][1] = 0.43;	matrix[2][2] = 0.64;	matrix[2][3] = 0.64; //0.86*x + 0.43*y + 0.64*z = 0.64
	
	
	printMatrix (M,N,(float*) matrix);
	
	for(j = 0; j < N-1; j++)
	{
		modMatrixLine(M, N, (float*) matrix, 1.0/matrix[j][j], j);
		printMatrix (M,N,(float*) matrix);
		for(i = 0; i < M - 1 - j; i++)
		{
			SumMatrixLine(M, N, (float*) matrix, - matrix[i+1+j][j], 1.0, j, i+1+j);
			printMatrix (M,N,(float*) matrix);
		}
	}
	
	float x[M] = {0};
	
	for(i = (M - 1); i >= 0; i--)
	{
		x[i] = matrix[i][N-1];
	//	printf("%f\n", x[i]);
		for(j = 0; j < N - 2 - i; j++)//j = i; j < N - 2; j++)
		{
			if(i == M-1)
			{
				continue;
			}
		//	printf("%f,  %f\n", x[i+j+1],matrix[i][i+j+1]);
			x[i] = x[i] - x[i+j+1]*matrix[i][i+j+1];
		}
	}	
	
	printf("\n");
	printf("\n");
	printMatrix(1,M,x);

	
	
	return 0;
}



