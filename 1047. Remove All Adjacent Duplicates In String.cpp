#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{

public:
    string removeDuplicates(string S)
    {
        string res;
        for (int i = 0; i < S.size(); i++)
        {
            if (res.empty() == false && res.back() == S[i])
            {
                res.pop_back();
            }
            else
                res.push_back(S[i]);
        }

        return res;
    }
};
int main()
{
    Solution B;
    string s = "abbbabaaa";
    B.removeDuplicates(s);
    system("pause");
}
