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
 
ll udiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll ddiv(ll a, ll b) {
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> c;
	int mmax = -1;
	int q;
	multiset<int> ss;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		c[a[i]]++;
		if(c[a[i]] > mmax){
			mmax = c[a[i]];
			q = a[i];
		}
		mmax = max(mmax, c[a[i]]);
	}
	if(k == n || k >= n - mmax){
		cout << 1 << '\n';
		return;
	}
	int ans = 1;
	for(const auto &x : c){
		if(x.first == q) continue;
		ss.insert(x.second);
	}
	for(const auto &x : ss){
		if(k >= x){
			k -= x;
			continue;
		}
		else{
			k = 0;
			ans++;
		}
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