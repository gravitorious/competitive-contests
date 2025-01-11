////created by gravitorious
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
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll total = 0;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	total += a[i];
    }
   	sort(a.begin(), a.end());
   	ll ans = 0;
   	for(int i = 0; i < n; i++){
   		ll more = total - a[i];
   		if(more < x) continue;
   		ll left, right;
   		if(more < y) left = 0;
   		else left = more - y;
   		right = more - x;
   		auto low = lower_bound(a.begin(), a.begin() + i + 1, left);
   		if(low == a.begin() + i + 1) continue;
   		auto up = upper_bound(a.begin(), a.begin() + i + 1, right);
   		if(up == a.begin() + i + 1) --up;
   		ans += (up - a.begin()) - (low - a.begin());
   	}
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