#include"lib.h"

class Solution {
public:
    #define MAX 26
    int hashfunc(char s)
    {
        return s-'a';
    }
    string reorganizeString(string s) {
        vector<int> Hashtable = vector<int> (MAX);
        for(int i=0;i<s.size();i++)
        {
            Hashtable[hashfunc(s[i])]++;;
        }
    }
};

int main(){
    string X = "aaaaaaaab";
    Solution A;
    A.reorganizeString(X);
}