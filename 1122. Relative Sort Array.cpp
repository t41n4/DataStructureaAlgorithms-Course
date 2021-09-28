#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int dem = 0;
        int add;
        vector<int> res;
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr2[i] == arr1[j])
                {

                    dem++;
                    add = arr2[i];
                    arr1.erase(arr1.begin() + j);
                    j=-1;
                }
            }
            if (dem != 0)
            {
                for (int i = 0; i < dem; i++)
                {
                    res.push_back(add);
                }
                dem = 0;
               
            }
        }
        arr1.sort(arr1.begin(),arr1.end());
         for (int i = 0; i < arr1.size(); i++)
                {
                    res.push_back(arr1[i]);
                }
        return res;
    }
};

int main()
{
    vector<int> arr1 ={28,6,22,8,44,17};
    vector<int> arr2 = {22,28,8,6};
    Solution A;
    A.relativeSortArray(arr1,arr2);
}