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
        priority_queue<pair<int, int>> q; //we actually don't need pairs
        ll mypower = 1;
        int power_k = 0;
        int hundles_k = 0;
        for(int i = 1; i <= L; i++){
        	while(power_k < (int)power.size() && power[power_k].first == i){
        		q.push(make_pair(power[power_k].second, power[power_k].first));
        		power_k++;
        	}
    		if(i == L - 1) continue;
    		if(hundles_k < (int)hurdles.size() && hurdles[hundles_k].first == i + 1){
    			int dis = hurdles[hundles_k].second - (i + 1) + 1;
    			//debug(i, dis, mypower, hurdles[i + 1]);
    			if(i + mypower > hurdles[hundles_k].second){
    				i = hurdles[hundles_k].second;
    				hundles_k++;
    				continue;
    			}
    			else{
    				//debug(i + mypower, mypower, dis);
    				bool flag = true;
    				while(i + mypower <= hurdles[hundles_k].second){
    					if(q.empty()){
    						flag = false;
    						break;	
    					}
    					auto takep = q.top();
    					q.pop();
    					ans++;
    					mypower += takep.first;
    					//debug(takep, mypower);
    					//debug(i + mypower, dis);
    				}
    				if(!flag){
    					cout << -1 << '\n';
    					return;
    				}
    				
    				i = hurdles[hundles_k].second;
    			}
    			hundles_k++;
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