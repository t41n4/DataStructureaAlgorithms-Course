#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> table = vector<int> (26,0);
        int res=0;
        for(auto i:text) table[i-'a']++;    
         int b = 0,a= 0,l= 0,o=0,n=0;
        for(int i=0;i<text.size()+1;i++)
            {
               
                
                if(table[0] > 0) {table[0]--;a++;}
                else if(table[1] > 0)  {table[1]--;b++;} 
                else if(table[11] > 0) {table[11]--;l++;}
                else if(table[13] > 0) {table[13]--;n++;}
                else if(table[14] > 0) {table[14]--;o++;} 
                else if(b>=1&&a>=1&&l>=2&&o>=2&&n>=1) {res++;b--; a--; l-=2; o-=2;n--; } 
                              
             }
        return res;
    }
};
int main()
{
    string text = "loonbalxballpoon";

    Solution A;
    A.maxNumberOfBalloons(text);

    system("pause");
}
