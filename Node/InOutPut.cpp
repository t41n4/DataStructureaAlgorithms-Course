// Example program
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void Nhap(int* n,int **A){
    cin>>*n;
    *A = (int*)calloc(*n, sizeof(int));
    for (int i = 0; i<*n; i++)  
    cin>>(*A)[i];
}
void Xuat(int n,int A[]){
    for (int i = 0; i<n; i++) 
        cout<<A[i]<<" ";
}
int main()
{
   
    int* A,n;
    Nhap(&n,&A);
    Xuat(n,A);
    system("pause");
    return 0;
}
