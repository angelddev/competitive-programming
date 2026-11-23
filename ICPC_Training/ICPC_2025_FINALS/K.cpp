#include <bits/stdc++.h>

#define ll long long 
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
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;


void solve(){
 

    ll n, k; cin >> n >> k;

    ll ymin = INF, ymax = -INF, xmin = INF, xmax = -INF;

    vpl cords;
    ll x, y;
    ll h, w;
    f(i,0,n){
        cin >> x >> y;
        xmin=min(x,xmin); xmax=max(x,xmax);
        ymin=min(y,ymin); ymax=max(y,ymax);
        cords.pb({x, y});
    }
    if(n==1) {cout << 1 << "\n"; return;}

    ll ans = h*w, tempAns=0;
    f(i,0,n){
        ll disX, disY;
        disX=min(abs(cords[i].F-xmin), abs(cords[i].F-xmax));
        disY=min(abs(cords[i].S-ymin), abs(cords[i].S-ymax));
        ll temp = 0, act = k;
        if(disX>=disY){
            if(disY>=k){}
            else{
            act-=disY;
            temp = min(act, disX-disY)*h; act-=disX-disY;
            if(act<=0) {}
            else{ temp+=act*h; temp+=act*w; temp+=((disX-disY)+act)*act; }
            }
        } 
        
        else {
            if(disX>=k){}
            else{
                act-=disX;
                temp = min(act, disY-disX)*w; act-=disY-disX;
                if(act<=0) {}
                else {temp+=act*h; temp+=act*w; temp+=((disY-disX)+act)*act;}  
            }
        }
        tempAns=max(tempAns, temp);
    }

    ll kings2;
    ll diff = max(h,w)-min(h,w);
    if(diff>=k){
        kings2= max(h,w)*(min(h,w)+k);
    } else {
        k-=diff; kings2 = (max(h,w)+k/2)*(max(h,w)+k/2+k%2);
    }
    cout << max(ans+tempAns, kings2) << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

