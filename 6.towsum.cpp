 
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
    int left =0,right = nums.size()-1,test;
    while(left<right)
    {
        test = nums[left] + nums[right];
        if (test <target) ++left;
        if (test > target) --right;
        
        if(test == target) 
        {
            res.push_back(left);
            res.push_back(right);
            break;
        }
     }
    return res;
    }
};

int main()
{
    vector<int> nums = {3,2,4};
    Solution A;
    for(auto i:A.twoSum(nums,6)) cout << i << " ";
    system("pause");
    
};