#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, q;
    string t;

    cin >> n >> q;
    cin >> t;

    bool allA = true;
    for (char c : t)
        if (c == 'B')
            allA = false;

    long long currQuery; 

    for (int i = 0; i < q; i++) {
        cin >> currQuery;

        long long sol = 0;
        int cont = 0;

        if (allA) {
            sol = currQuery;
            currQuery = 0;
            cout << sol << "\n";
            continue;
        }

        while (currQuery > 0) {
            if (cont >= t.size())
                cont = 0;

            if (t[cont] == 'A')
                currQuery--;
            else
                currQuery /= 2;

            cont++;
            sol++;
        }
        cout << sol << "\n";
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
