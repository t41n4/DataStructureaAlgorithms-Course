#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = t.size() - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    s.pop_back();
                    t.erase(t.begin() + j);
                    break;
                }
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};

int main()
{
    Solution A;
    string s = "ccaa";
    string t = "ccac";
    if (A.isAnagram(s, t) == true)
        cout << "true!";
    else
        cout << "false!";
}