//created by gravitorious
#include <bits/stdc++.h>
using namespace std;

#ifdef XOX
#include "/home/nikos/libraries-cp/mydebug/debug.h"
#else
#define debug(...) 43
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

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
	int N, Q;
	cin >> N >> Q;
	vector<ll> num(N);
	
	vector<bool> c(N, false);
	
	for(int i = 0; i < N; i++){
		cin >> num[i];
	}
	
	ll mmax = *max_element(num.begin(), num.end());
	int maxbits = (int)log2(mmax) + 1;
	
	vector<vector<ll>> v(61, vector<ll>(N+1));
	
	int b = 59;
	for(int i = 1; i <= 60; i++){
		//debug(i, b);
		for(int j = 1; j <= N; j++){
			if((num[j-1] & (1ll << b))) v[i][j] += (v[i][j-1] + 1);
			else v[i][j] = v[i][j-1];
		}
		b--;
	}
	
	//for(const auto &x : v) debug(x);
	
	for(int i = 0; i < Q; i++){
		int K;
		cin >> K;
		int L1, R1, L2, R2;
		cin >> L1 >> R1 >> L2 >> R2;
		//debug(maxbits);	
		//int search = maxbits - K; //the searching bit
		int fsearch = 60 - K;

		ll first = v[fsearch][R1] - v[fsearch][L1-1];
		ll second = v[fsearch][R2] - v[fsearch][L2-1];
		ll ans = ((R1-L1+1)-first) * second + ((R2-L2+1)-second) * first;
		
		cout << ans << endl;
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
