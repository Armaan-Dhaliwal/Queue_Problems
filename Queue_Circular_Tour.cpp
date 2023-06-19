//{ Driver Code Starts
#include<iostream>
#include<queue>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
      int tour(petrolPump p[],int n)
    {
       int front=0;
       int balance=0;
       int deficiency=0;
       for(int rear=0;rear<n;rear++){
           balance+=p[rear].petrol;
    
           if(balance-p[rear].distance>=0){
               balance=balance-p[rear].distance;
           }
           
           else{
               deficiency+=balance-p[rear].distance;
               front=rear+1;
               balance=0;
               rear=front-1;
           }
       }
       int result;
       if(balance+deficiency>=0){
           result=front;;
       }
       else{
           result=-1;
       }
       
       return result;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends