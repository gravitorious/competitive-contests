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
    cin >> n;
    vector<pair<int, int>> v;
    const int maxN = 400010;
    int count[maxN + 1] = {};
    int check[maxN + 1] = {};
    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;	
    	v.emplace_back(make_pair(a, b));
    	if(a == b){
    		count[a]++;
    		check[a] = 1;
    	}
    }
    int psum[maxN + 1] = {};
    for(int i = 1; i <= 2 * n; i++){
    	psum[i] += psum[i - 1] + check[i];
    }
    vector<bool> ans(n);
    for(int i = 0; i < n; i++){
    	auto k = v[i];
    	if(k.first == k.second && count[k.first] > 1){
    		ans[i] = 0;
    		continue;
    	}
    	else if(k.first == k.second){
    		ans[i] = 1;
    		continue;
    	}
    	if(psum[k.second] - psum[k.first - 1] == k.second - k.first + 1){
    		ans[i] = 0;	
    	}
    	else ans[i] = 1;
    }
    for(const auto &x : ans) cout << x;
    cout << '\n';
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
