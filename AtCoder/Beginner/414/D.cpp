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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<pair<ll, int>> u;
	for(int i = 0; i < n - 1; i++){
		u.emplace_back(v[i + 1] - v[i], i + 1);
	}
	sort(u.rbegin(), u.rend());
	vector<int> nodes; 
	for(int i = 0; i < m - 1; i++){
		nodes.push_back(u[i].second);
	}
	sort(nodes.begin(), nodes.end());
	int j = 1;
	int left = 0, right;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(j <= nodes.size()){
			if(i + 1 == nodes[j - 1]){
				right = i;
				ans += (v[right] - v[left]);
				left = i + 1;
				j++;
			}
		}
		else right = i;
	}
	ans += (v[right] - v[left]);
	cout << ans;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}