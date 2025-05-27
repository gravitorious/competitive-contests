///created by gravitorious
#include <bits/stdc++.h>
using namespace std;
 
#ifdef XOX
#include "../../../debug.h"
#else
#define debug(...) 77
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
 
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
void chkmax(T &x,T y){
    if(x < y) x = y;
}
 
template <class T>
void chkmin(T &x,T y){
    if(x > y) x = y;
}
 
constexpr int popcnt(int x){
    return __builtin_popcount(x);
}
 
constexpr int ctz(int x){
    return __builtin_ctz(x);
}

constexpr double int_part(double x, double *intpart){ 
	return modf(x, intpart); //returns the real part
}
 
ll ceil_div(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll floor_div(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down
 
long long myRand(long long B) {
	//0 to B-1
	return (unsigned long long)rng() % B;
}
 
int myUniRand(int a, int b){
	//a to b
	uniform_int_distribution<int> distribution(a,b);
	return distribution(rng);
}
 
void solve(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	v.emplace_back(make_pair(a, b));	
    }
    if(n == 1){
   		cout << 1 << '\n';
   		return;	
    }
    if(n == 2){
    	cout << 2 << '\n';
    	return;	
    }
    vector<pair<ll, ll>> xs = v, ys = v;
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end(), [](auto &l, auto &r){
        return l.second < r.second;
    });
    ll minx, maxx, miny, maxy;
    auto calc = [&](int i, int j) -> ll{
        ll minx = xs[0].first, maxx = xs[n - 1].first;
        ll miny = ys[0].second, maxy = ys[n - 1].second;   
        if(i == minx) minx = xs[1].first;
        if(i == maxx) maxx = xs[n - 2].first;
        if(j == miny) miny = ys[1].second;
        if(j == maxy) maxy = ys[n - 2].second;   
        ll area = (maxx - minx + 1) * (maxy - miny + 1);
        if(area < n) area += min((maxx - minx + 1), (maxy - miny + 1));
        return area;
    };
    ll ans = 1e18 + 5;
    ans = min(ans, calc(xs[0].first, xs[0].second));
    ans = min(ans, calc(ys[0].first, ys[0].second));
    ans = min(ans, calc(xs[n - 1].first, xs[n - 1].second));
    ans = min(ans, calc(ys[n - 1].first, ys[n - 1].second));
    cout << ans << '\n';
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	while(tc--) solve();
	return 0;
}
