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

int query(int l, int r){
	cout << '?' << l << ' ' << r;
	cout << endl;	
	int ans;
	cin >> ans;
	return ans;
}

 
void solve(){
    int n;
    cin >> n;
    int ans;
    int prev = query(1, n);
    vector<int> p;
    for(int i = 1; i <= n - 2; i++){
    	ans = query(1, n - (i + 1) + 1);
    	if(ans == 0){
    		cout << "! IMPOSSIBLE\n";
    		return;	
    	}
    	if(prev == ans){
    		p.push_back(0);
    	}
    	else{
    		p.push_back(1);
    		prev = ans;
    	}
    	debug(p);
    }
   	if(prev == ans){
		p.push_back(1);
	}
	else p.push_back(0);
	debug(p);
	reverse(p.begin(), p.end());
	for(int i = 0; i < n; i++) cout << p[i] << ' ';
	cout << endl;
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
