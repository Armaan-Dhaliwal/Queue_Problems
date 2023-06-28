#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class MyStack {
public:
    queue <int>q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);    
    }
    
    int pop() {

        if(q1.size()==1){
            int temp=q1.front();
            q1.pop();
            return temp;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp=q1.front();
        q1.pop();

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        //int temp=q1.front();
        return temp;
    }
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp=q1.front();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */