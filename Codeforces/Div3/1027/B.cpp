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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int non = 0, is = 0;
    int t = n - 1;
    int onespairs = 0, zerospairs = 0;
    for(int i = 0; i < n / 2; i++){
    	if(s[i] != s[t - i]) non++;
    	else is++;
    	if(s[i] == s[t - i] && s[i] == '0') zerospairs++;
    	if(s[i] == s[t - i] && s[i] == '1') onespairs++;
    } 
    if(is == k){
    	cout << "YES\n";
    	return;	
    }
    if(k > is){
    	while(non > 0){
    		non -= 2;
    		if(non < 0) break;
    		is += 2;
    		if(is == k) break;
    	}
    	if(is == k){
    		cout << "YES\n";
    		return;	
    	}
    	else{
    		cout << "NO\n";
    		return;	
    	}
    }
    else{
    	while(onespairs > 0 && zerospairs > 0){
    		onespairs--;
    		zerospairs--;
    		is -= 2;	
  			if(is == k) break;
    	}
    	if(is == k){
    		cout << "YES\n";
    		return;	
    	}
    	else{
    		cout << "NO\n";
    		return;	
    	}
    }
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
