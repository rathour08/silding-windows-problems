//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0;
        int j=0;
        unordered_map<char, int>m;
        int ans=-1;
        while(j<s.size()){
            m[s[j]]++;
            int unicount=m.size();
            if(unicount<k){
                j++;
            }
            else if(unicount==k){
                ans=max(ans,j-i+1);
                j++;
                
                
            }
            else if(unicount>k){
                while(unicount>k){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    
                    i++;
                    unicount=m.size();
                    
                }
                j++;
            }

            
        }
        return ans;
    // your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends