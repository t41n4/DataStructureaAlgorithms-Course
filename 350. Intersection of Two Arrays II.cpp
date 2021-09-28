#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> h = vector<int>(max(*max_element(nums1.begin(), nums1.end()), *max_element(nums2.begin(), nums2.end())) + 1, 0);
        vector<int> res;

        for (auto i : nums1)h[i]++;
            

        for (int i = 0; i < nums2.size(); i++)
        {
            if (h[nums2[i]] > 0)
            {
                h[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }

        return res;
    }
};
int main()
{
    vector<int> nums1 = {2, 2};
    vector<int> nums2 = {1, 2, 2, 1};

    Solution A;
    A.intersect(nums1, nums2);

    system("pause");
}
