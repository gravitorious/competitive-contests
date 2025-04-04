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
    vector<string> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    vector<int> ans;
    vector<int> pos(n + 1, -1);
    ans.push_back(n);
    pos[n] = 0;
    int q = 0;
    for(int i = n - 2; i >= 0; i--){
    	q++;
    	int mmin = 10000;
    	/*
    	for(int j = i + 1; j < n; j++){
			if(v[i][j] == '1'){
				mmin = j + 1;
				break; 
			}
    	}*/
		for(int k = 0; k < q; k++){
			for(int j = 1; j <= n; j++){
				if(pos[j] == k && v[i][j - 1] == '1'){
					mmin = j;
					break;
				}
			}	
		}    	
    	if(mmin == 10000){
    		pos[i + 1] = n - i - 1;
    		continue;
    	}
    	int p = -1;
    	int k = pos[mmin];
    	for(int j = 1; j <= n; j++){
    		if(pos[j] == -1) continue;
    		if(pos[j] >= k) pos[j]++;
    	}
    	pos[i + 1] = k;
    }
    for(int k = 0; k < n; k++){
    	for(int i = 1; i <= n; i++){
    		if(pos[i] == k){
    			cout << i << ' ';
    			break;
    		}
    	}	
    }
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
