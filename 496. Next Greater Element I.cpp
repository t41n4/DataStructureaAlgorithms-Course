#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nextGreaterElement;
        int tag = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    for (int z = j; z < nums2.size(); z++)
                    {
                        if (nums2[z] > nums2[j])
                        {
                            tag++;
                            nextGreaterElement.push_back(nums2[z]);
                            break;
                        }
                    }
                }
            }
            if (tag == 0)
                nextGreaterElement.push_back(-1);
            tag = 0;
        }
        for (int i = 0; i < nextGreaterElement.size(); ++i)
        cout << ' ' << nextGreaterElement[i];
            cout << '\n';
        return nextGreaterElement;
    }
};
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 2, 3, 4};

    Solution A;
    A.nextGreaterElement(nums1,nums2);
    
    system("pause");
}
