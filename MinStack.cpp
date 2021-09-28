#include <iostream>
using namespace std;
#define MAX 100
class MinStack {
    private: 
    int Data[MAX];
        int ntop=0;
public:
    /** initialize your data structure here. */
    MinStack() {
        ntop=0;
    }
    bool isempty(){
        return (ntop==0);
    }
    
    void push(int val) {
                   
           Data[ntop]=val;
            ntop++;
     
    }
    
    void pop() {
        if (isempty()==false)
        {ntop--;}
       
    }
    
    int top() {
        return Data[ntop-1];
    }
    
    int getMin() {
        int MIN=Data[0];
        if (isempty()==false)
        for(int i=0;i<ntop;i++){
            if (Data[i]<MIN) MIN = Data[i];
        }
        cout << MIN;
        return MIN;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){
    MinStack A;
    A.push(-2);
    A.push(0);
    A.push(-3);
    A.getMin();
    A.pop();
    A.top();
    A.getMin();
    system("pause");
}