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
    int n;
    int q;
    cin >> n >> q; cin.ignore();
    for(int i = 0;i<n;i++)
    {
      int temp = q;
         for(int j = 0;j<n;j++)
    {
        if(j!= n-1)
        cout << temp <<" ";
        else cout << temp;
        temp++;
    }
        cout <<endl;
        ++q;
    }
    system("pause");

    
}