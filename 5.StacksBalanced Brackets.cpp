#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING expression as parameter.
 */
string isBalanced(string expression)
{
    stack<char> res;
    int l = expression.length();
    if (l == 0)
        return "NO";
    if (l % 2 != 0)
        return "NO";
    else
    {
        for (int i = 0; i < l; i++)
        {
            if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            {
                res.push(expression[i]);
            }
            else if (expression[i] == ')' && res.top() != '(')
                return "NO";
            else if (res.top() == '(')
            {
                if (res.size() != 0)
                    res.pop();
            }
            else if (expression[i] == '}' && res.top() != '{')
                return "NO";
            else if (res.top() == '{')
            {
                if (res.size() != 0)
                    res.pop();
            }
            else if (expression[i] == ']' && res.top() != '[')
                return "NO";
            else if (res.top() == '[')
            {
                if (res.size() != 0)
                    res.pop();
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string expression;
        getline(cin, expression);

        string res = isBalanced(expression);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
