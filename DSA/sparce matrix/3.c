#include <stdio.h>

typedef struct sparseNode
{
    int r;
    int c;
    int data;
} Node;

void add(Node *arr1, Node *arr2, int size, int s1, int s2)
{
    Node arr[size];
    int trv = 0, check;
    for (int i = 0; i < s1; i++)
    {
        check = 1;
        for (int j = 0; j < s2; j++)
        {
            if (arr1[i].r == arr2[j].r && arr1[i].c == arr2[j].c)
            {
                arr[trv].r = arr1[i].r;
                arr[trv].c = arr1[i].c;
                arr[trv].data = arr1[i].data + arr2[j].data;
                trv++;
                check = 0;
                break;
            }
        }
        if (check)
        {
            arr[trv].r = arr1[i].r;
            arr[trv].c = arr1[i].c;
            arr[trv].data = arr1[i].data;
            trv++;
        }
    }

    for (int i = 0; i < s2; i++)
    {
        check = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr2[i].r == arr[j].r && arr2[i].c == arr[j].c)
            {
                check = 1;
                break;
            }
        }
        if (!check)
        {
            arr[trv].r = arr2[i].r;
            arr[trv].c = arr2[i].c;
            arr[trv].data = arr2[i].data;
            trv++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0)
            {
                if (arr[j].r <= 9)
                {
                    printf(" %d ", arr[j].r);
                }
                else
                    printf("%d ", arr[j].r);
            }
            else if (i == 1)
            {
                if (arr[j].c <= 9)
                {
                    printf(" %d ", arr[j].c);
                }
                else
                    printf("%d ", arr[j].c);
            }
            else
            {
                if (arr[j].data <= 9)
                {
                    printf(" %d ", arr[j].data);
                }
                else
                    printf("%d ", arr[j].data);
            }
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

    Node arr1[s1], arr2[s2];
    int trv1 = 0, trv2 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix1[i][j] != 0)
            {
                arr1[trv1].r = i;
                arr1[trv1].c = j;
                arr1[trv1++].data = sparseMatrix1[i][j];
            }
            if (sparseMatrix2[i][j] != 0)
            {
                arr2[trv2].r = i;
                arr2[trv2].c = j;
                arr2[trv2++].data = sparseMatrix2[i][j];
            }
        }
    }
    add(arr1, arr2, size, s1, s2);
    return 0;
}