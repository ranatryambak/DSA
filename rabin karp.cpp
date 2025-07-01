#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int mod = 1e6;

    int check(string a, string b) {
        if (a == "" || b == "") return -1;

        int m = b.size();
        int n = a.size();

        int exp = 1;
        for (int i = 0; i < m; i++) {
            exp = (exp * 26) % mod;
        }

        int code = 0;
        for (int i = 0; i < m; i++) {
            code = (code * 26 + b[i]) % mod;
        }

        int wcode = 0;
        for (int i = 0; i < n; i++) {
            wcode = (wcode * 26 + a[i]) % mod;
            if (i < m - 1) continue;
            if (i >= m) wcode = (wcode - (a[i - m] * exp) % mod + mod) % mod;

            if (wcode == code) {
                if (a.substr(i - m + 1, m) == b) {
                    return i - m + 1;
                }
            }
        }

        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;

        int count = 1;
        string tmp = a;

        while (tmp.size() < b.size()) {
            tmp += a;
            count++;
        }

        if (tmp == b) return count;
        if (check(tmp, b) != -1) return count;
        if (check(tmp + a, b) != -1) return count + 1;

        return -1;
    }
};

int main() {
    Solution sol;
    string a, b;

    cout << "Enter string a: ";
    cin >> a;

    cout << "Enter string b: ";
    cin >> b;

    int result = sol.repeatedStringMatch(a, b);
    cout << "Minimum number of repetitions: " << result << endl;

    return 0;
}
