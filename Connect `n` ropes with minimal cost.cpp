#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int ans = 0;

    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a + b;
        pq.push(sum);
        ans += sum;
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout << "Minimum cost to connect ropes: " << minCost(arr) << endl;
    return 0;
}
