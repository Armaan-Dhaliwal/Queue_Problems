#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;

    Node(int data){
        next=NULL;
        this->data = data;
    }
};

class Queue{
    public:
    Node* rear;
    Node* front;

    Queue(){
        rear=NULL;
        front=NULL;
    }

    void enQueue(int data){
        Node *tempNode  = new Node(data); 
        if(rear==NULL || front==NULL){
            rear=tempNode;
            front = tempNode;
        }

        else{
            rear->next=tempNode;
            rear=rear->next;
        }

    }
    
    int deQueue(){
        if(front==NULL){
            rear=NULL;
            return -1;
        }

        int val = front->data;
        front=front->next;;
        return val;
    }
};

int main(){
    Queue q;
    q.enQueue(4);
    q.enQueue(3);
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;    
    cout<<q.deQueue()<<endl;
    q.enQueue(2);
    q.enQueue(1);
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
}