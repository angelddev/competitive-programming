#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 
ll arr[500006];
ll st[3000006];
ll tg[3000006];


void push(ll node, ll l, ll r){
    tg[2*node] += tg[node];
    tg[2*node+1] += tg[node];   
    ll mid = (l+r)/2;
    st[2*node] +=tg[node];
    st[2*node+1] +=tg[node];
    tg[node] = 0; 
}

void build(ll node, ll l, ll r){
    if(l==r){
        st[node] = arr[l];
        return;
    }
    ll mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    st[node] = min(st[2*node],st[2*node+1]);
}

void update(ll node, ll l, ll r, ll lq, ll rq, ll val){

    if(l>=lq&&r<=rq){
        tg[node]+=val;
        st[node]+=val;
        return;
    }

    if(l>rq||r<lq){
        return;
    }

    push(node, l, r);
    ll mid = (l+r)/2;
    update(2*node, l, mid, lq, rq, val);
    update(2*node+1, mid+1, r, lq, rq, val);
    st[node] = min(st[2*node+1], st[2*node]);
}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st[node];
    }

    if(l>rq||r<lq){
        return INF;
    }

    push(node, l, r);
    ll mid = (l+r)/2;
    return min(query(2*node, l, mid, lq, rq),
    query(2*node+1, mid+1, r, lq, rq));
}


void solve(){

    ll n, m; cin >> n;
    f(i,0,n){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    cin >> m;
    cin.ignore();
    f(i,0,m){
        vll nums;
        string ln;
        getline(cin, ln);
        istringstream iss(ln);
        ll temp;
        while(iss >> temp){
            nums.pb(temp);
        } 
        if(nums.size()==2){
            if(nums[0]>nums[1]){
                cout << min(query(1, 0, n-1, nums[0], n-1),query(1, 0, n-1, 0, nums[1])) << "\n";
            }
            else cout << query(1, 0, n-1, nums[0], nums[1]) << "\n";
        } else {
            if(nums[0]>nums[1]){
                update(1, 0, n-1, nums[0], n-1, nums[2]);
                update(1, 0, n-1, 0, nums[1], nums[2]);
            }
            else update(1, 0, n-1, nums[0], nums[1], nums[2]);
        }
    }
}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}