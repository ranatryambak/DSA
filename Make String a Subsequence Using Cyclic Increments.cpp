#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = 0;
        int m = str2.size();
        for (auto it : str1) {
            if (n < m && (str2[n] - it + 26) % 26 <= 1) {
                n++;
            }
        }
        return n == m;
    }
};

int main() {
    string str1 = "abcde";
    string str2 = "acf";

    Solution sol;
    bool result = sol.canMakeSubsequence(str1, str2);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
