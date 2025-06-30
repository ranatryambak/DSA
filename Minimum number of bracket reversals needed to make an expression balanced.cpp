#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int cnt = 0;
        for (char it : s) {
            if (it == '(') {
                open++;
            } else {
                if (open == 0) {
                    cnt++;
                } else {
                    open--;
                }
            }
        }
        return open + cnt;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the parentheses string: ";
    cin >> s;

    int result = sol.minAddToMakeValid(s);
    cout << "Minimum insertions needed to make the string valid: " << result << endl;

    return 0;
}
