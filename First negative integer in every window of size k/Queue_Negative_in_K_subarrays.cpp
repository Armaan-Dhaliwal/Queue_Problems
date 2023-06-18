#include<queue>
#include<iostream>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        queue<long long int> q;
        vector<long long int> res(N-K+1);

        for(int i=0;i<N-K+1;i++){
            cout<<"In iteration: "<<i<<endl;
                for(int j=i;j<K+i;j++){
                    q.push(A[j]);
                }
                
                while(!q.empty()){
                    cout<<"q.front() is: "<<q.front()<<endl;
                    if(q.front()<0){
                        res[i]=q.front();
                        break;
                    }
                    q.pop();
                }
                while(!q.empty()){
                     q.pop();
                }
        }
        return res;
        
    }