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


void solve(){
	
    int n, m, L;
    cin >> n >> m >> L;
    int ans = 0;
    vector<pair<int, int>> power;
    vector<pair<int, int>> hurdles;
    //map<int, int> hurdles;
    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	//hurdles[a] = b;
    	hurdles.emplace_back(make_pair(a, b));	
    }
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	//power[a].push_back(b);
    	power.emplace_back(make_pair(a, b));		
    }
    priority_queue<int> q;
    bool flag = false;
    int power_i = 0;
    int mypower = 1;
    for(int i = 0; i < (int)hurdles.size(); i++){
    	int l = hurdles[i].first, r = hurdles[i].second;
    	for(power_i; power_i < (int)power.size(); power_i++){
    		if(power[power_i].first < l){
    			q.push(power[power_i].second);
    		}
    		else break;
    	}
    	while(!q.empty() && mypower	< (r - l + 1 + 1)){
    		mypower += q.top();
    		ans++;
    		q.pop();	
    	}
    	if(q.empty() && mypower	< (r - l + 1 + 1)){
    		cout << -1 << '\n';
    		return;	
    	}
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