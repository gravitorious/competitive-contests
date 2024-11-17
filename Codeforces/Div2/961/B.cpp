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
    	ll n, m;
    	cin >> n >> m;
    	vector<ll> v(n);
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
    		if(v[i] - v[i + 1] > 1){
    			ll can_buy = coins / v[i];
    			if(h[v[i]] <= can_buy){
    				ans = max(ans, h[v[i]] * v[i]);
    			}
    			else ans = max(ans, can_buy * v[i]);
    			continue;
    		}
    		for(ll j = 0; j <= h[v[i + 1]]; j++){
    			ll ss = m - j * (v[i] - 1);
    			if(ss < 0) break;
    			ss /= v[i];
    			if(ss > h[v[i]]){
    				ss = h[v[i]];
    			}
    			ans = max(ans, j * v[i + 1] + ss * (v[i]));
    		}
    	}
    	int size = (int)v.size();
    	ll can_buy = m / v[size - 1];
    	if(h[v[size - 1]] <= can_buy){
    		ans = max(ans, h[v[size - 1]] * v[size - 1]);
    	}
    	else ans = max(ans, can_buy * v[size - 1]);
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