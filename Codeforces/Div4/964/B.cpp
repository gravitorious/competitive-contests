////created by gravitorious
#include <bits/stdc++.h>
using namespace std;
 
#ifdef XOX
#include "/home/nikos/gravitonlib/mydebug/debug.h"
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
 
void solve(int n, int m){
	vector<vector<int>> v(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		--a, --b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	vector<bool> visited(n);
	vector<int> parent(n, -1), low(n, (int)1e9), preorder(n);
	iota(low.begin(), low.end(), 0);
	int clock = 0;
	vector<bool> isCut(n);
	int root_child = 0;
	int current_root = -1;
	auto dfs = [&](auto &&self, int u, int p) -> void {
		visited[u] = true;
		preorder[u] = clock++;
		for(const auto &x : v[u]){
			if(!visited[x]){
				if(u == current_root) root_child++;
				parent[x] = u;
				self(self, x, u);
				if(low[u] > low[x]) low[u] = low[x];
				if(low[x] >= preorder[u]) isCut[u] = true;
			}
			else if(x != p){
				if(low[u] > preorder[x]) low[u] = preorder[x]; 
			}	
		}
	};
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			current_root = i;
			dfs(dfs, i, -1);
			isCut[i] = 0;
			int count = 0;
			for(const auto &x : v[i]){
				if(parent[x] == i) count++;
			}
			int ans = 0;
			if(root_child >= 2) ans++;
			for(int i = 1; i < n; i++){
				if(isCut[i]) ans++;
			}
			cout << ans << '\n';
		}
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	while(1){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		solve(n, m);
	}
	return 0;
}
