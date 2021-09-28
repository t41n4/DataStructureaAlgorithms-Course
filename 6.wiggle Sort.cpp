#include <iostream>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int n = nums.size(), k = n - 1;
        int i = n / 2, j = n - i;
        int index = 1;
        while(i--) {
            nums[index] = temp[k--];
            index += 2;
        }
        index = 0;
        while(j--) {
            nums[index] = temp[k--];
            index += 2;
        }
    }
};

int main()
{
    vector<int> nums = {1,3,2,2,3,1};
    nums.wiggleSort
}