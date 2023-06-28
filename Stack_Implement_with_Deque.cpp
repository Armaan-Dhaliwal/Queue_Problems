#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Stack
{
public:
    deque<int> deq;
    Stack()
    {
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        deq.push_back(x);

        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
      if (deq.empty()) {
        return -1;
     }
        int temp = deq.back();
        deq.pop_back();
        return temp;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {   
        
        if(deq.empty()){
            cout<<"deq is empty "<<" top is "<<deq.back()<<endl;
            return -1;
        }
        
        return deq.back();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        if(deq.empty()){
            return true;
        }
        return false;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {   
        int count=0;
        while(!deq.empty()){
            count++;
            deq.pop_back();
        }
        return count;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
}