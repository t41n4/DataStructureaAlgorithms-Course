#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
     vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> res;
        vector<int> cnt(101, 0);
        
        for(int i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;
        
        for(int i = 1; i < cnt.size(); i++)
            cnt[i] += cnt[i - 1];
        
        for(int i = 0; i < nums.size(); i++)
        {
           if(nums[i] == 0)
               res.push_back(0);
           else 
               res.push_back(cnt[nums[i] - 1]);
            
        }
        return res;
    }
};


int main() 
{
    Solution A;
    vector<int> X {8,2,2,3,5};
   
    
    A.smallerNumbersThanCurrent(X);

}