#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
#define mod 1000000007
using namespace std;

const ll INF = 1e9;
const ll MOD = 1e9 +7;

ll t, n, m, k, a, b; 

struct ArrStruct{
    ll arr[4][4];
    ArrStruct(){
        memset(arr, 0, sizeof(arr));
    }
ArrStruct operator* (ArrStruct& other){
    ArrStruct m = ArrStruct();
    for(int i = 0; i< 4; i++){
        for(int j = 0; j< 4;j++){
            for(int g = 0;g <4;g++){
                m.arr[i][j] = (m.arr[i][j] + ((arr[i][g]* other.arr[g][j])%mod))%mod;
            }
        }
    }
    return m;
}
};

ArrStruct expo(ArrStruct& var, ll ex) {
    ArrStruct m = ArrStruct();
    for(int i = 0 ; i<4; i++){
        m.arr[i][i] = 1;
    }

    while (ex > 0){
        if(ex & 1)
            m=m* var;
    var = var*var;
    ex = (ex>>1);
    }return m;
}

void solve(){
    ll n;
    cin >> n;
    vll base = {1, 2, 3};
    if(n<4){
        cout << base[n-1];
        return;
    }
    ArrStruct a = ArrStruct();
    a.arr[0][0] = 3;
    a.arr[0][1] = 2;
    a.arr[0][2] = 1;
    a.arr[0][3] = 3;
    a.arr[1][0] = 1;
    a.arr[2][1] = 1;
    a.arr[3][3] = 1;
    
    ArrStruct resul = expo(a,n-2);
    ll t = 3*resul.arr[0][0];
    t = (t+2*resul.arr[0][1])%mod;
    t = (t+resul.arr[0][2])%mod;
    t = (t+resul.arr[0][3])%mod;

    cout << t;

            
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    t=1; 
    while(t--){
        solve(); 
    }
}