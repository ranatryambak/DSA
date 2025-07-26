#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int j = 0;
        for(int i = 0; i < n; i++) {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    Solution sol;
    bool result = sol.validateStackSequences(pushed, popped);
    
    cout << (result ? "true" : "false") << endl;

    return 0;
}
