#include <iostream>
#include <stack> 
#include <queue>
using namespace std;

class Solution {
 private: 
 stack<char> A;
 queue<char> B;
 public:
    void pushCharacter(char ch) {     
          A.push(ch);   
      }
    void enqueueCharacter(char ch){
        B.push(ch);
    }
    char popCharacter(){
        char temp{} ;
        if(A.empty()==true){
            temp = A.top();
            A.pop();
        } 
        return temp;
    }
    char dequeueCharacter() {
        char temp{} ;
        if(B.empty()==true){
            temp = B.front();
            B.pop();
        } 
        return temp;
    }
    
  
 
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    system("pause");
    return 0;
}