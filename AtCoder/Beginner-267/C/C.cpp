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
	
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;
	vector<long long> A(N);
	vector<long long> sums(N+1);
	sums[0] = 0;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		sums[i+1] = sums[i] + A[i];
	}
	//for(const auto &x : sums) cout << x << " ";
    //  cout << endl;
	
	ll mmax = (long long) -1e18-1;
	ll sum = 0;
	ll prev_sum;
	vector<long long> fsums(N-M+1);
	
	for(int i = 0; i < M; i++){
		sum+= A[i] * (i+1);
	}
	prev_sum = sum;
	mmax = max(mmax, sum);
	fsums[0] = sum;
	
	
	for(int i = 1; i <= N-M; i++){
		ll psum = prev_sum - (sums[i+(M-1)] - sums[i-1]);
		psum += A[i+(M-1)] * M;
		fsums[i] = psum;
		mmax = max(mmax, psum);	
		//cout << prev_sum << endl;
		prev_sum = psum;
	}
	
	ll ppmax = -1e18-1;
	for(int i = 0; i < N-M+1; i++){
		
		ppmax = max(ppmax, fsums[i]);	
	}
	
	
	
	cout << ppmax << endl;
	//cout << mmax << "\n";

	return 0;
}
