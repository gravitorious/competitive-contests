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
    int a; ll n;
    cin >> a >> n;
    string s = to_string(n);
    
    auto checkA = [&](ll x) -> bool{
    	string s = "";
    	while(x > 0){
    		s.push_back(char((x % a) + '0'));
      		x /= a;
   		}
   		string rs = s;
   		reverse(rs.begin(), rs.end());
   		if(s == rs) return true;
   		return false;
    };
    ll sum = 0;
    auto gen = [&](int l) -> void{
    	if(l % 2 == 0){
    		int h = l / 2;
    		ll low = 1;
    		for(int i = 2; i <= h; i++) low *= 10;
    		for(ll i = low; i <= low * 10 - 1; i++){
    			string s1 = to_string(i);
    			string s2 = s1; 
    			reverse(s2.begin(), s2.end());
    			string s = s1 + s2;
    			ll x = stoll(s);
    			if(x > n) return;
    			bool flag = checkA(x);
    			if(flag){ sum += x; }
    		}
    	}
    	else{
    		if(l == 1){
    			for(int i = 1; i <= 9; i++){
    				if(i > n) break;
    				bool flag = checkA(i);
    				if(flag){ sum += i; }
    			}
    			return;	
    		}
    		int h = l / 2;
    		ll low = 1;
    		for(int i = 2; i <= h; i++) low *= 10;
    		for(ll i = low; i <= low * 10 - 1; i++){
    			string s1 = to_string(i);
    			string s2 = s1; 
    			reverse(s2.begin(), s2.end());
    			for(int j = 0; j <= 9; j++){
    				string s = s1 + to_string(j) + s2;
    				ll x = stoll(s);
    				if(x > n) return;
    				bool flag = checkA(x);
    				if(flag){ sum += x; }
    			}
    		}
    	}
    };
    for(int l = 1; l <= (int)s.size(); l++){
    	gen(l);
    }
    cout << sum;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
