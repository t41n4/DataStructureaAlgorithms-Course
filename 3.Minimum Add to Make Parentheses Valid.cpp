#include <stack>
#include <iostream>
using namespace std;

int main()
{
    string S = "(((";
    stack<char> A;
    int res = 0;
    A.push('x');
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
            A.push(S[i]);
        else if (S[i] == ')' && A.top() == '(')
        {
            if (A.empty() == false)
                A.pop();
        }
        else
            res++;
    }
    cout << res+A.size()-1;
    system("pause");
}
