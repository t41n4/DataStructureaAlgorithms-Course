#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char A[1000];
    fgets(A, sizeof(A), stdin);
    for (int i = 0; i < strlen(A); i++)
    {
        printf("%c", A[i]);
        if (A[i] == ' ')
        {
            A[i] ='';
            printf("\n");
        }
    }
    return 0;
}
