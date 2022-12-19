//created by gravitorious
#include <bits/stdc++.h>
using namespace std;

#ifdef XOX
#include "/home/nikos/mylibs/mydebug/debug.h"
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
	int N, K;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	cin >> K;
	vector<int> B(K);
	for(int i = 0; i < K; i++) cin >> B[i];
		
		
	vector<int> P = A;
	sort(P.begin(), P.end());	
	
	for(int i = 0; i < K; i++){
		P[B[i]-1] = -1;	
	}
		
	for(int i = 0; i < N; i++){
		if(P[A[i]-1] != -1){
			cout << A[i] << " ";
		}	
		
	}	
	cout << endl;
		
}
 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	debug(tc);
	while(tc--) solve();
	
	return 0;
}
