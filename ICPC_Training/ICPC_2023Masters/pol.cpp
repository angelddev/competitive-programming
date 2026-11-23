#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second 
#define pb push_back
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 



struct pt {
    long long x, y;
    pt() {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}
    pt operator+(const pt &p) const {return pt(x + p.x, y + p.y);}
    pt operator-(const pt &p) const {return pt(x - p.x, y - p.y);}
    ll cross (const pt &p) const {return x * p.y - y * p.x; }
    ll dot(const pt &p) const {return x * p.x + y * p.y; }
    ll cross(const pt &a, const pt &b) const {return (a - *this).cross(b - *this); }
    ll dot(const pt &a, const pt &b) const {return (a - *this).dot(b - *this); }
    ll sqrLen() const {return this-> dot(*this); }
};

bool lexComp(const pt &l, const pt & r){
return l.x < r.x || (l.x == r.x && l.y < r.y);
}

int sgn(ll val) {return val > 0 ? 1 : (val == 0 ? 0 : -1); }

vector<pt> seq;
pt translation;
int n;


bool pointInTriangle(pt a, pt b, pt c, pt point){
    __int128 s1 = abs(a.cross(b, c));
    __int128 s2 = (__int128)abs(point.cross(a, b)) +  (__int128)abs(point.cross(b, c)) + (__int128)abs(point.cross(c, a));
    return s1 == s2;
}

void prepare(vector<pt> &points){
    n = points.size();
    int pos = 0;
    for(int i =1; i< n; i++){
    if(lexComp(points[i], points[pos]))
        pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;
    seq.resize(n);
    for ( int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
        
    if (seq.size() >= 2 && seq[0].cross(seq.back()) < 0) {
        reverse(seq.begin(), seq.end());
    }
    translation = points[0];
}

bool pointInConvexPolygon(pt point){
    point = point - translation;
    if(seq[0].cross(point) != 0 && sgn(seq[0].cross(point)) != sgn(seq[0].cross(seq[n-1]))) return false;
    if(seq[n-1].cross(point) != 0 && sgn(seq[n-1].cross(point)) != sgn(seq[n-1].cross(seq[0]))) return false;
    if(seq[0].cross(point) == 0)
        return seq[0].sqrLen() >= point.sqrLen() && seq[0].dot(point) >= 0; // <--- ¡Vital!

    int l = 0, r = n-1;
    
    while(r -l > 1){
        int mid = (l +r) /2;
        int pos = mid;
        if(seq[pos].cross(point)>=0)
            l = mid;
        else
            r = mid;
    }
    int pos =l;
    return pointInTriangle(seq[pos], seq[pos+1], pt(0, 0), point);
}

void solve(){
    ll d, m, ab, ba;
    bool flag=1;
    pt punto;
    vector<pt> a;
    cin >> d;

    f(i,0,d){
        cin >> ab >> ba;
        pt punto(ab, ba);
        a.pb(punto);
    }

    prepare(a);
    cin >> m;
    f(i,0,m){
        cin >> ab >> ba;
        pt punto(ab, ba);
        if( pointInConvexPolygon(punto) == 0){
            flag=0;
        } 
    }
    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ll t=1; 
    //cin>>t; 
    while(t--){
        solve(); 
    }
}