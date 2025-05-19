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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<ll> p(n - 1, -1);
	int i = 0;
	int k = 0;
	while(k < n && v[k] > v[k + 1]) k++;
	p[0] = 0;
	bool flag = true;
	for(; k < n - 1; k++){
		if(flag && v[k] > v[k + 1]){
			flag = false;
			i++;
			p[i] = 1;	
		}
		else if(flag){ p[i]++; }
		else if(!flag && v[k] < v[k + 1]){
			flag = true;
			i++;
			p[i] = 1;
		}
		else if(!flag) p[i]++;
	}
	
	int j = 1;
	ll ans = 0;
	while(j - 1 < (int)p.size() && p[j] != -1 && p[j + 1] != -1){
		ans += p[j - 1] * p[j + 1];
		j += 2;	
	}
	cout << ans << '\n';
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
