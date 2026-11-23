#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
    int k, a;
    cin >> k >> a;

    if(a%2){
        for(int i=0; i<a; i++){
            cout << k << ' ';
        }
        cout << endl;
        return;
    }


    int temp = k, msb=0;
    while(temp>0){
        temp >>= 1; 
        msb++;
    }
    
   int nmx = 0, nmn = 0;
    bool found = false;
    int high_bit = 1;
    while (high_bit * 2 <= k) 
        high_bit *= 2;


    nmx = high_bit;

    nmn = k ^ high_bit;


    for (int i = high_bit / 2; i >= 1; i /= 2) {

        if ((nmx + i) <= k && (nmn + i) <= k) {
            if (!(k & i)) {
                nmx |= i;
                nmn |= i;
            }
        }
    }
    
    cout << nmx << ' ' << nmn << ' ';
    for(int i=0; i<a-2; i++){
        cout << k << ' ';
    }
    cout << endl;



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}