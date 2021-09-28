#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int a;
    int b;
    cin >> a >> b; cin.ignore();
    int sum1=0;
    int sum2=0;
    for(int i= 1;i<=a/2;i++)
    { 
        if (a%i==0) 
                sum1 += i;
    }
    for(int i= 1;i<=b/2;i++)
     {
        if (b%i==0) sum2 += i;
    }

    if (sum1==a && sum2 == b ) cout << "Amicable" << endl;
     if (sum1==b && sum2 == a ) cout << "Amicable" << endl;
   
    system("pause");
}