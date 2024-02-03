#include <stdio.h>

int add(int s1, int s2, int size, int arr1[][s1], int arr2[][s2])
{
    int arr[3][size];
    int r = 0, check;
    for (int i = 0; i < s1; i++)
    {
        check = 0;
        for (int j = 0; j < s2; j++)
        {
            if (arr1[0][i] == arr2[0][j] && arr1[1][i] == arr2[1][j])
            {
                arr[0][r] = arr1[0][i];
                arr[1][r] = arr1[1][i];
                arr[2][r] = arr1[2][i] + arr2[2][j];
                r++;
                check = 1;
            }
            if (check == 1)
            {
                break;
            }
        }
        if (check == 0)
        {
            arr[0][r] = arr1[0][i];
            arr[1][r] = arr1[1][i];
            arr[2][r] = arr1[2][i];
            r++;
        }
    }
    for (int i = 0; i < s2; i++)
    {
        check = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr2[0][i] == arr[0][j] && arr2[1][i] == arr[1][j])
            {
                check = 1;
            }
        }
        if (check == 0)
        {
            arr[0][r] = arr2[0][i];
            arr[1][r] = arr2[1][i];
            arr[2][r] = arr2[2][i];
            r++;
        }
    }
    printf("Resultant Sparse Matrix Representation : \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] > 9)
                printf("%d ", arr[i][j]);
            else
                printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int sparseMatrix1[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {15, 2, 6, 0, 0}};
    int sparseMatrix2[4][5] =
        {
            {13, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};
    int size = 0, s1 = 0, s2 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix1[i][j] != 0)
                s1++;
            if (sparseMatrix2[i][j] != 0)
                s2++;
            if (sparseMatrix1[i][j] != 0 || sparseMatrix2[i][j] != 0)
                size++;
        }
    }
    int arr1[3][s1], arr2[3][s2], k = 0, k1 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix1[i][j] != 0)
            {
                arr1[0][k] = i;
                arr1[1][k] = j;
                arr1[2][k] = sparseMatrix1[i][j];
                k++;
            }
            if (sparseMatrix2[i][j] != 0)
            {
                arr2[0][k1] = i;
                arr2[1][k1] = j;
                arr2[2][k1] = sparseMatrix2[i][j];
                k1++;
            }
        }
    }
    add(s1,s2,size,arr1,arr2);
    printf("\n");
    
}