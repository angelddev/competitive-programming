#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int m;
    cin >> m;

    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    long long total_sm = 0;
    for (int i = 0; i < m - 1; i++) {
        total_sm += abs(arr[i] - arr[i + 1]);
    }

    int mx_savings = 0;

    mx_savings = max(abs(arr[0] - arr[1]), abs(arr[m - 1] - arr[m - 2]));

    for (int i = 1; i < m - 1; i++) {
        int current = abs(arr[i - 1] - arr[i]) + abs(arr[i] - arr[i + 1]);
        int skipped = abs(arr[i - 1] - arr[i + 1]);
        mx_savings = max(mx_savings, current - skipped);
    }

    cout << total_sm - mx_savings << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}