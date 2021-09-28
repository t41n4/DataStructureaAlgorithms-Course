#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++) // duyệt các phân tử chưa được sort
        {
            int insert = arr[i];  // chọn phần tử insert  là phần tử xét để chèn vào
            int j = i - 1; //  phần tử trước đó
            while (j >= 0 && arr[j] > insert) // đưa phần tử insert đi trong mảng cho đến khi arr[j]<=insert 
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = insert;// chèn phẩn tử vào vị trí hết thoả mãn điều kiện
        }
    }
};

int main()
{
    vector<int> arr ={0,8,5,1,2,78,12,8,9};
   
    Solution A;
    A.sortColors(arr);
}