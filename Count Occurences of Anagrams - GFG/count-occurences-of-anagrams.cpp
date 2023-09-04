//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    bool allzeros(unordered_map<char, int> &m) {
        for (auto it : m) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }

    int search(string pat, string txt) {
        int i = 0;
        int j = 0;
        int k = pat.size();
        int count = 0;
        
        unordered_map<char, int> m_pat; // Frequency map of the pattern

        // Initialize m_pat with the frequency of characters in pat
        for (auto c : pat) {
            m_pat[c]++;
        }

        unordered_map<char, int> m; // Frequency map for the current window

        while (j < txt.size()) {
            // Update the frequency map for the current window
            m[txt[j]]++;

            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                if (m == m_pat) {
                    count++;
                }
                
                // Move the window
                m[txt[i]]--; // Remove the character at the beginning of the window
                if (m[txt[i]] == 0) {
                    m.erase(txt[i]); // Remove if the count becomes 0
                }
                i++;
                j++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends