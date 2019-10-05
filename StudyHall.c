#include<stdio.h>

void compute(int N[6][6],int Z[6][6])
{
//compute neighbors
	//	 In this it will calculate the all 4 rules which are for the CGOL project

    int i,j;
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)	     	//	If any live cell with fewer than two live neighbours dies, as if by underpopulation.
        								//	If any live cell with more than three live neighbours dies, as if by overpopulation.
        								//	If any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
        {
            N[i][j]=Z[i-1][j-1]+Z[i][j-1]+Z[i+1][j-1]
                    + Z[i-1][j]+Z[i+1][j]
                    + Z[i-1][j+1]+Z[i][j+1]+Z[i+1][j+1];  //	If any live cell with two or three live neighbours lives on to the next generation.
        }
    }

}

void show(int Z[6][6])
{
//this will show the output in 6*6 array
    int i,j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%d ", Z[i][j]);
        }
        printf("\n");
    }

}

// this will calculate if the array have 2 neighbors then cell will dead or if it have 3 then neighbors will alive
// Or if more than 3 neighbors will dead
void iteration(int Z[6][6])
{
    int N[6][6];
    int i,j;
    compute(N,Z);

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if((Z[i][j] == 1)&&(N[i][j] < 2 || N[i][j] > 3))
            {
                Z[i][j] = 0;
            }
            else if((Z[i][j] == 0)&&(N[i][j] == 3))
            {
                Z[i][j] = 1;
            }
        }
    }

}


int main()
{

    /* 2D arraj declaration*/
    int Z[6][6]=
    {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };
    int i;
    printf("Original");
    printf("\n");
    show(Z);

    for(i=0; i<20; i++)					// It will define the number of Generation
    {
    	printf("\nGeneration %d\n", i+1);
    	    printf("\n"); // to print the output
        iteration(Z);
        show(Z);
    }

    return 0;
}
