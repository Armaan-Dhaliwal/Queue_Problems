#include<iostream>
#include<queue>
using namespace std;

int Min_Max_Sum(int *arr,int n,int k){
    deque<int> q_max;
    deque<int> q_min;
    int sum=0;

    for(int i =0;i<k;i++){
        while(!q_max.empty() && arr[i]>=arr[q_max.back()]){
            q_max.pop_back();
        }

        while(!q_min.empty() && arr[i]<=arr[q_min.back()]){
            q_min.pop_back();

        }
        q_max.push_back(i);
        q_min.push_back(i);        
    }
    
    sum+=arr[q_min.front()]+arr[q_max.front()];


    for(int i=k;i<n;i++){
        while(!q_min.empty() && i-q_min.front()>=k){
            q_min.pop_front();  
        }

        while(!q_max.empty() && i-q_max.front()>=k){
                q_max.pop_front();  
        }

        while(!q_max.empty() && arr[i]>=arr[q_max.back()]){
            q_max.pop_back();
        }

        while(!q_min.empty() && arr[i]<=arr[q_min.back()]){
            q_min.pop_back();
        }
        q_max.push_back(i);
        q_min.push_back(i);

        // cout<<"sum is: "<<arr[q_min.front()]+arr[q_max.front()]<<" at "<<i<<endl;
        // cout<<" arr[q_min.front()] is : "<<arr[q_min.front()]<<endl;
        // cout<<" arr[q_max.front()] is : "<<arr[q_max.front()]<<endl;
        sum+=arr[q_min.front()]+arr[q_max.front()];

    }

    return sum;

}

int main(){
    int n,k;
    n=7;
    k=4;
    // cout<<"Enter number of elements: "<<endl;
    // cin>>n;
    // cout<<"Enter windows size: "<<endl;
    // cin>>k;

    //int *arr = new int[n];
    int arr[7]={2,5,-1,7,-3,-1,-2};
    // cout<<"Enter elements of array: "<<endl;
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    int res=Min_Max_Sum(arr,n,k);
    // for(int i=0;i<n-k+1;i++){
    //     cout<<res[i]<<" ";
    //     sum+=res[i];
    // }
    cout<<endl;
    cout<<"Sum is :"<<res<<endl;
}