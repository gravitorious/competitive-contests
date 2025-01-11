////created by gravitorious
#include <bits/stdc++.h>
using namespace std;
 
#ifdef XOX
#include "debug.h"
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
	vector<vector<int>> v(n, vector<int>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> v[i][j];
	int ans = 0;
	for(int i = n - 1; i > 0; i--){
		int mmin = (int)1e6 + 5;
		for(int j = i, k = 0; j < n; j++){
			mmin = min(mmin, v[k][j]);
			k++;
		}
		if(mmin < 0) ans += -1 * mmin;
	}
	int mmin = (int)1e6 + 5;
	for(int i = 0; i < n; i++){
		mmin = min(mmin, v[i][i]);
	}
	if(mmin < 0) ans += -1 * mmin;
	mmin = (int)1e6 + 5;
	for(int i = 1; i < n; i++){
		int mmin = (int)1e6 + 5;
		for(int j = i, k = 0; j < n; j++){
			mmin = min(mmin, v[j][k]);
			k++;
		}
		if(mmin < 0) ans += -1 * mmin;
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
