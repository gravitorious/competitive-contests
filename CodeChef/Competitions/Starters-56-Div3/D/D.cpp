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


int calcGCD(vector<int> &v){
	
	int answer = v[0];
	for(int i = 1; i < v.size(); i++){
		answer = __gcd(answer, v[i]);	
	}	
	
	return answer;
}

void solve(){
	
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i];	
	}
	int gcdarray = calcGCD(v);
	//sort(v.begin(), v.end());
	int GK = gcdarray * K;
	//needed to leave the contest
	
	
	
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
