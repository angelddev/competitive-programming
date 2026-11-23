#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    ll a, b, c;
    ll rollbacks = 0;
    __int128 sum = 0;
    __int128 mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        sum += (__int128)a * (b - 1);
        if (sum >= x) {
            for (int j = i + 1; j < n; j++) {
                cin >> a >> b >> c;
            }
            cout << 0 << '\n';
            return;
        }

        mx = max(mx, (__int128)a * b - (__int128)c);
    }

    if (mx <= 0) {
        cout << -1 << '\n';
        return;
    }

    __int128 need = (__int128)x - sum;
    rollbacks = (ll)((need + mx - 1) / mx);

    cout << rollbacks << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
