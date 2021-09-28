#include<iostream>

using namespace std;

int main()
{
    int A[] = {5,8,8,9,6,2,5,8,6,4,5,2,3};
    int i=0,n=13;
    int x = 10;
    A[n]=x;
    while (A[i]!=x)
     i++;
       
    if(i<sizeof(A)+1) cout << i;
    else cout << -1;
system("pause");
    
}