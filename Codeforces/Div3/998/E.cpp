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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> F(n);
    vector<vector<int>> G(n);
    for(int i = 0; i < m1; i++){
    	int a, b;
    	cin >> a >> b;
    	--a, --b;
    	F[a].push_back(b);
    	F[b].push_back(a);	
    }
    for(int i = 0; i < m2; i++){
    	int a, b;
    	cin >> a >> b;
    	--a, --b;
    	G[a].push_back(b);
    	G[b].push_back(a);	
    }
    vector<int> compF(n + 1);
    vector<int> compG(n + 1);
    vector<bool> visited1(n + 1), visited2(n + 1);
    
 	auto dfs1 = [&](auto &&self, int u, int c) -> void{
 		for(const auto &x : F[u]){
 			if(!visited1[x]){
 				visited1[x] = true;
 				compF[x] = c;
 				self(self, x, c);
 			}	
 		}
 	};   
    auto dfs2 = [&](auto &&self, int u, int c) -> void{
 		for(const auto &x : G[u]){
 			if(!visited2[x]){
 				visited2[x] = true;
 				compG[x] = c;
 				self(self, x, c);
 			}	
 		}
 	};
 	int k = 0;
 	int cF, cG;
 	for(int i = 0; i < n; i++){
 		if(!visited1[i]){
 			visited1[i] = true;
 			compF[i] = k;
 			dfs1(dfs1, i, k);
 			k++;	
 		}
 	}
 	cF = k;
 	k = 0;
 	for(int i = 0; i < n; i++){
 		if(!visited2[i]){
 			visited2[i] = true;
 			compG[i] = k;
 			dfs2(dfs2, i, k);
 			k++;	
 		}
 	}
 	cG = k;
 	cout << cF - cG << '\n';
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
