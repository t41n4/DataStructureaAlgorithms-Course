#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string temp, res;
        int dem = 0, tag = 0;
        
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '(')
            {
                dem++;
                temp = temp + S[i];
                tag = i;
            }
            else if (S[i] == ')' && temp[tag] == '(')
            {
                dem--;
                temp = temp + S[i];
            }
            if (dem == 0)
            {   if(temp.size()>=2)
                {temp.erase(temp.begin() + 1);
                temp.erase(temp.end() - 1);}
                res = res+temp;
                
                S = S.erase(0,temp.size()+2);
                temp="";
                i=-1;
                tag=0;
            }
        }
        return res;
    }
};
int main()
{
    Solution B;
    string s = "()()";
    B.removeOuterParentheses(s);
    system("pause");
}
