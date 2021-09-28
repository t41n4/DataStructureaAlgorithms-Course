#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[0] == '#')
            {
                s.erase(s.begin() + 0);
                i = 0;
            }
            else if (s[i] == '#')
            {
                if (s[0] != '#')
                    s.erase(i - 1, 2);
                i = 0;
            }
        }
for (int i = 0; i < t.size(); i++)
        {
            if (s[0] == '#')
            {
                t.erase(t.begin() + 0);
                i = 0;
            }
            else if (t[i] == '#')
            {
                if (t[0] != '#')
                    t.erase(i - 1, 2);
                i = 0;
            }
        }
        if (s == t)
            return true;
        return false;
    }
};
int main()
{
    Solution A;
    string s = "asasdasd#sa##ssadasd##saas##c", t = "#a#c";
    cout << A.backspaceCompare(s, t);
    system("pause");
}
