#include<iostream>
#include<queue>
using namespace std;
class NQueue{
public:
    int *arr;
    int *front;
    int *rear;
    int freespot;
    int *next;

    NQueue(int n, int s){
        freespot =0;
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        
        for(int i=0;i<n;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        for(int i=0;i<s-1;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    void enqueue(int x, int m){
        if(freespot==-1){
            cout<<"overflow"<<endl;
            return;
        }
        int index=freespot;
        freespot = next[index];
        arr[index]=x;
        if(front[m-1]==-1){
            front[m-1]=index;
        }
        else{
            next[rear[m-1]]=index;
        }
        next[index]=-1;
        rear[m-1]=index;
        return;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){

        if(front[m-1]==-1){
            return -1;
        }

        int index = front[m-1];
        front[m-1] = next[index];
        int ele=arr[index];
        next[index]=freespot;
        freespot= index;

        return ele;
    }
};

int main() {

    NQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}