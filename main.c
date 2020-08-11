/*Segfault happens if comments are removed*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int CROSSED = -1;
const int WHITE = 0;
const int BLACK = 1;

int nonogramField[4][4];

void fieldInit(int nbCol, int nbRow)
{
	/* Initialize the empty nonogram field */
	for(int i = 0; i < nbCol; i++)
	{
		for(int j = 0; j < nbRow; j++)
		{
			nonogramField[i][j] = WHITE;
		}
	}
}

/* Basic Nonogram solving algo */
void basicSolve(int nbRowElem, int nbColElem, int const *const *const cluesRow/*, int const *const *const cluesCol*/)
{	
	/* Trivial solving */
	for(int k = 0; k < nbRowElem; k++)
	{	
		int nbCluesRow = 0;
	
		while(cluesRow[k][nbCluesRow] != -1)
		{
			nbCluesRow++;
		}
		
		if(nbCluesRow == 1)
		{
			if(cluesRow[k][0] == nbRowElem)
			{
				for(int m = 0; m < nbColElem; m++)
				{
					nonogramField[k][m] = BLACK;
				}
			}
			else if(cluesRow[k][0] == 0)
			{
				for(int m = 0; m < nbColElem; m++)
				{
					nonogramField[k][m] = CROSSED;
				}
			}
			else
			{
				if(cluesRow[k][0] / 2 > nbRowElem)
				{
					for(int m = nbRowElem - cluesRow[k][0]; m < cluesRow[k][0]; m++)
					{
						nonogramField[k][m] = BLACK;
					}
				}
			}
		}
	}
	
	/*for(int k = 0; k < nbColElem; k++)
	{	
		int nbCluesCol = 0;
	
		while(cluesCol[nbCluesCol][k] != -1)
		{
			nbCluesCol++;
		}
		
		if(nbCluesCol == 1)
		{
			if(cluesCol[k][0] == nbRowElem)
			{
				for(int m = 0; m < nbColElem; m++)
				{
					nonogramField[m][k] = BLACK;
				}
			}
			else if(cluesCol[k][0] == 0)
			{
				for(int m = 0; m < nbColElem; m++)
				{
					nonogramField[m][k] = CROSSED;
				}
			}
			else
			{
				if(cluesCol[k][0] / 2 > nbRowElem)
				{
					for(int m = nbColElem - cluesCol[k][0]; m < cluesCol[k][0]; m++)
					{
						nonogramField[m][k] = BLACK;
					}
				}
			}
		}
	}*/
	
	printf("Nonogram 4x4 (2, 4, 4, 2) (2, 4, 4, 2)\r\n");
	
	for(int i = 0; i < nbRowElem; i++)
	{
		for(int j = 0; j < nbColElem; j++)
		{
			if(nonogramField[i][j] == WHITE)
			{
				printf("0");
			}
			else if(nonogramField[i][j] == BLACK)
			{
				printf("1");
			}
			else if(nonogramField[i][j] == CROSSED)
			{
				printf("x");
			}
		}
		printf("\r\n");
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{	
	fieldInit(4, 4);

	int cluesa0[2] = {2, -1};
	int cluesa1[2] = {4, -1};

	int *cluesa[4] = {cluesa0, cluesa1, cluesa1, cluesa0};
	int *cluesb[4] = {cluesa0, cluesa1, cluesa1, cluesa0};
	
	basicSolve(4, 4, cluesa/*, cluesb*/);
	
	system("pause");
	return EXIT_SUCCESS;
}
