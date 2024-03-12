#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int q, int r, int link[])
{
    int i = q, j = r, k = 0;

    while (i && j)
    {
        if (a[i] < a[j])
        {
            link[k] = i;
            k = i;
            i = link[i];
        }
        else
        {
            link[k] = j;
            k = j;
            j = link[j];
        }
    }
    if (!i)
    {
        link[k] = j;
    }
    else
    {
        link[k] = i;
    }
    return (link[0]);
}

int mergeS(int a[], int s, int e, int link[])
{
    if (s >= e)
    {
        return s;
    }
    int m = s + (e - s) / 2;

    int q = mergeS(a, s, m, link);

    int r = mergeS(a, m + 1, e, link);

    return merge(a, q, r, link);
}

int main()
{
    int a[5] = {-1, 5, 3, 9, 7};
    int link[5] = {0, 0, 0, 0, 0};

    int l = mergeS(a, 1, 4, link);

    int k = 0;
    cout<<"Array after sorting is : ";
    for (int i = 1; i < 5; i++)
    {
        cout << a[link[k]] << " ";
        k = link[k];
    }
}