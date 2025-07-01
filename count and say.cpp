#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string check(int n, string s) {
        if (n == 1) {
            return "1";
        }

        string tmp = check(n - 1, s);
        string ans = "";

        int m = tmp.size();
        int i = 0;
        while (i < m) {
            char c = tmp[i];
            int count = 0;
            while (i < m && tmp[i] == c) {
                count++;
                i++;
            }
            ans += to_string(count);
            ans += c;
        }

        return ans;
    }

    string countAndSay(int n) {
        return check(n, "");
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    string result = sol.countAndSay(n);
    cout << "The " << n << "th term in the Count and Say sequence is: " << result << endl;

    return 0;
}
