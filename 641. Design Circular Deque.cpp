#include<iostream>
#include<vector>
using namespace std;
class MyCircularDeque {
private: vector<int> Data;
            int front;
            int rear;
            int size;
            int storage;
  
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        Data = vector<int>(k);
        front=0;
        rear=-1;
        size=0;
        storage=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
      if (isFull()==false) 
      {     
            
            for(int i=rear+1;i>0;i--)
            {
                Data[i]=Data[i-1];
            }
            Data[0]=value;
            
            front =0;
            rear++;
            size++;
            storage--;
           return true;
      }
          
            return false;
        
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
         if(isFull()==false)
         {   
            rear++;
             Data[rear]=value;
             size++;
             storage--;
              
             return true;
         }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()==false)
         {
          for(int i=0;i<size-1;i++)
          {
              Data[i]=Data[i+1];
          }
          Data[rear]=0;
                front=0;
                rear--;
                size--;
                storage++;
                return true;
         }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()==false)
         {  
             Data[rear]=0;
             rear--;
             size--;
            storage++;
             return true;
         }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
         if(isEmpty()==false)
         {return Data[front]   ;}
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
         if(isEmpty()==false)
         {return Data[rear];}
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {      
        return storage==0; 
    }
};
int main(){
    MyCircularDeque A(15);
    A.insertFront(3);
    A.insertFront(4);
    A.insertLast(1);
    A.insertLast(8);
    A.deleteLast();
    A.insertFront(10);
    A.insertLast(20);
    A.insertFront(50);
    A.deleteFront();
    A.insertLast(2);
    A.insertFront(2);
    A.deleteLast();
    cout <<  A.getRear();
    cout << A.getFront();
    
    system("pause");
        }
