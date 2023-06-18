//{ Driver Code Starts
#include<iostream>
#include<queue>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string output="";
		    queue<char> q;
		    vector<int> aux(26,0);
		    
		    for(int i=0;i<A.size();i++){
		        if(i==0){
		            q.push(A[i]);
		            aux[A[i]-97]=1;
		            output+=A[i];
		        }
		        
		        else{
		            
		            if(aux[A[i]-97]==1){
		                int count=q.size();
		                while(count>0){
		                    if(q.front()==A[i]){
		                        q.pop();
		                        count--;
		                    }
		                    else{
		                        char temp=q.front();
		                        q.pop();
		                        q.push(temp);
		                        count--;
		                    }
		                }
		                if(q.empty()){
		                    output+='#';
		                }
		                else
		                {output+=q.front();}
		            }
		            else if(aux[A[i]-97]==0){
		                q.push(A[i]);
		                aux[A[i]-97]=1;
		                output+=q.front();
		            }

    		        else if(q.front()==A[i]){
    		            q.pop();
    		            if(q.empty()){
    		               output+='#';
    		            }
    		            output+=q.front();
    		        }
    		        
    		        else if(q.empty()){
    		            q.push(A[i]);
    		            aux[A[i]-97]=1;
    		            output+=A[i];
    		        }
                    else{
                        output+=q.front();
                    }		            
		        }
                // cout<<"Output at iteration "<<i<<" is "<<output<<endl;
                // cout<<"q.front() is "<<q.front()<<endl;
		    }
		    return output;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends