#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        string res;
        for (int i=0;i<nums.size();i++)
        {
            
            res = res + (to_string(nums[i]));
            
        } 
        return res;
    }
};


int main()
{
    vector<int> arr1 ={28,6,22,8,44,17};
 
    Solution A;
    A.largestNumber(arr1);
}