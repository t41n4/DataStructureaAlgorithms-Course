#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum=0;
        vector<int>record;
        int previous = 0;
        for(int i=0;i<ops.size();i++)
        {
            if (ops[i]=="C")
            {   
                
                if(record.empty()==false)
                {
                   
                    record.pop_back();                  
                }
            }
                else if (ops[i]=="D")
                {
                    if(record.empty()==false)
                    {
                      record.push_back(2*record[record.size()-1]);
                    }
                  
                    
                }
            else if (ops[i]=="+")
                {
                    if(record.size()>=2)
                    {
                      record.push_back(record[record.size()-1]+record[record.size()-2]);
                    }
                }
            else 
            {
                record.push_back(stoi(ops[i]));
                if(record.size()>=2) previous = record[record.size()-2];
                }                                  
    }
    for (int i=0;i<record.size();i++)
    {
        sum+=record[i];
    }
        return sum;
    }
};

int main(){
   Solution A;
   vector<string> ops = {"5","-2","4","C","D","9","+","+"};
  cout <<  A.calPoints(ops);
    system("pause");
        }
