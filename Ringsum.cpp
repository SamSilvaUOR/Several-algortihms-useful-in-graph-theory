#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
int printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j])
            printf(" %d ", arr1[i++]);
        else if(arr2[j] < arr1[i])
                printf(" %d ", arr2[j++]);
            else
            {
                printf(" %d ", arr2[j++]);
                i++;
            }
    }
    while(i < m)
        printf(" %d ", arr1[i++]);
    while(j < n)
        printf(" %d ", arr2[j++]);
}
int printIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr2[j] < arr1[i])
                j++;
            else
            {
                printf(" %d ", arr2[j++]);
                i++;
            }
    }
}
int main()
{
    int m,n,i,j,k;
    cout << "Enter the number of vertices in G1 & G2 : ";
    cin >> m >> n;
    int V1[m], V2[n];
    for(i=0;i<m;i++)
        V1[i] = i;
    for(i=0;i<n;i++)
        V2[i] = i;
    int E1[m][m],E2[n][n],E3[m+n][m+n];
    printf("Enter the adjacency matrix(symmetric) for graph G1:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("E1[%d][%d]=",i,j);
            scanf("%d",&E1[i][j]);
        }
    }
    printf("Enter the adjacency matrix(symmetric) for graph G2:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("E2[%d][%d]=",i,j);
            scanf("%d",&E2[i][j]);
        }
    }
    printf("\nSet of vertices in union of the graphs G1 and G2 is:\n");
    printUnion(V1, V2, m, n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(E1[i][j]>E2[i][j]&& i<m && j<m)
                E3[i][j]=E1[i][j];
            else if(E1[i][j]<E2[i][j]&& i<m && j<m)
                    E3[i][j]=E2[i][j];
                else
                    E3[i][j]=E2[i][j];
        }
    }
    printf("Adjacency matrix of union of graphs G1 and G2 is:\n\t");
    for(i=0;i<n;i++)
        printf("%d\t",i);
    printf("\n\t");
    for(i=0;i<n;i++)
        printf("_______");
    for(i=0;i<n;i++)
    {
        printf("\n%d|\t",i);
        for(j=0;j<n;j++)
            printf("%d\t",E3[i][j]);
    }
    printf("\nSet of vertices in intersection of the graphs G1 and G2 is:\n");
    printIntersection(V1, V2, m, n);
    printf("\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(E1[i][j]>E2[i][j])
                E3[i][j]=E1[i][j];
            else
                E3[i][j]=E2[i][j];
        }
    }
    printf("Adjacency matrix of intersection of graphs G1 and G2 is:\n\t");
    for(i=0;i<m;i++)
        printf("%d\t",i);
    printf("\n\t");
    for(i=0;i<m;i++)
        printf("_______");
    for(i=0;i<m;i++)
    {
        printf("\n%d|\t",i);
        for(j=0;j<m;j++)
            printf("%d\t",E3[i][j]);
    }
    printf("\nSet of vertices in ring sum of the graphs G1 and G2 is:\n");
    printUnion(V1, V2, m, n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(E1[i][j]==E2[i][j]&& i<m && j<m)
                E3[i][j]=0;
            else if(E1[i][j]<E2[i][j]&& i<m && j<m)
                    E3[i][j]=E2[i][j];
            if(E1[i][j]<E2[i][j]&& i<m && j<m)
                E3[i][j]=E1[i][j];
            else
                E3[i][j]=E2[i][j];
        }
    }
    printf("Adjacency matrix of ring sum of graphs G1 and G2 is:\n\t");
    for(i=0;i<n;i++)
        printf("%d\t",i);
    printf("\n\t");
    for(i=0;i<n;i++)
        printf("_______");
    for(i=0;i<n;i++)
    {
        printf("\n%d|\t",i);
        for(j=0;j<n;j++)
            printf("%d\t",E3[i][j]);
    }
    getch();
    return 0;
}
