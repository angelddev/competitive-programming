#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int kmall[100], mxall[100], kmcv[100], mxcv[100];

    for (int i = 0; i < N; i++) {
        cin >> kmall[i] >> mxall[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> kmcv[i] >> mxcv[i];
    }

    int roadSpeed[100], bessieSpeed[100];

    int idx = 0, pos = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < kmall[i]; j++) {
            roadSpeed[pos++] = mxall[i];
        }
    }

    pos = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < kmcv[i]; j++) {
            bessieSpeed[pos++] = mxcv[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        ans = max(ans, bessieSpeed[i] - roadSpeed[i]);
    }

    cout << ans << "\n";
    return 0;
}
