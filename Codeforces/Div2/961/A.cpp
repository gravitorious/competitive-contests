//created by gravitorious
#include <bits/stdc++.h>
using namespace std;

#ifdef XOX
#include "/home/nikos/gravitonlib/mydebug/debug.h"
#else
#define debug(...) 21198
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

double int_part(double x, double* intpart){
	//returns the real part
	return modf(x, intpart);
}

ll udiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll ddiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
	vector<int> v(n);
	map<ll, ll> h;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		h[v[i]]++;
	}
	getunique(v);
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	for(int i = 0; i < (int)v.size() - 1; i++){
		ll coins = m;
		ll can_buy = coins / v[i];
		ll ans2 = 0;
		if(h[v[i]] <= can_buy){
			coins -= h[v[i]] * v[i];
			ans2 += h[v[i]] * v[i];
			if(v[i] - v[i + 1] > 1){
				ans = max(ans, ans2);	
				continue;
			}
			can_buy = coins / v[i + 1];
			if(h[v[i + 1]] <= can_buy){
				coins -= h[v[i + 1]] * v[i + 1];
				ans2 += h[v[i + 1]] * v[i + 1];
			}
			else{
				coins -= can_buy * v[i + 1];
				ans2 += can_buy * v[i + 1];
			}
			ans = max(ans, ans2);
		}
		else{
			coins -= can_buy * v[i];
			ans2 += can_buy * v[i];
			ans = max(ans, ans2);
		}
	}
	ll can_buy = m / v[n - 1];
	if(h[v[n - 1]] <= can_buy){
		ans = max(ans, h[v[n - 1]] * v[n - 1]);
	}
	else ans = max(ans, can_buy * v[n - 1]);
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
