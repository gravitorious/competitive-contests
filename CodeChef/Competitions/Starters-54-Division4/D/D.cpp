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
	int N;
	
	cin >> N;
	
	map<int, vector<int>> m;
	
	for(int i = 0; i < N; i++){
		int f;
		cin >> f;
		for(int j = 0; j < f; j++){
			int p;
			cin >> p;
			if(m.count(i) > 0){
				m[i].push_back(p);	
			}
			else{
				m.insert({i, vector<int>()});
				m[i].push_back(p);
			}
		
		}	
	}
	
	
	for(int i = 0; i < N-1; i++){
		set<int> p;
		
		for(int j = i+1; j < N; j++){
			for(int k = 0; k < m[i].size(); k++){
				p.insert(m[i][k]);	
			}
			for(int k = 0; k < m[j].size(); k++){
				p.insert(m[j][k]);	
			}
			if(p.size() == 5){
				 cout << "YES" << endl;	
				 return;
			}
			p.clear();
		}	
	}
	cout << "NO" << endl;

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
