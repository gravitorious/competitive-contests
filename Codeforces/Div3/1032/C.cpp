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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    int mmax1 = -1;
    int maxi, maxj;
    vector<pair<int, pair<int, int>>> mmax;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> v[i][j];
    		mmax.push_back({v[i][j], {i, j}});
    	}
    }
    if(n == 1 && m == 1){ cout << v[0][0] - 1 << '\n'; return; }
    if(n == 1){
    	for(int i = 0; i < m; i++) --v[0][i];
    	/*
    	int kk = *max_element(v[0].begin(), v[0].end());
    	for(int i = 0; i < m; i++){
    		if(v[0][i] == kk){
    			--v[0][i];
    			break;
    		}
    	}*/
    	cout << *max_element(v[0].begin(), v[0].end()) << '\n';
    	return;
    }
    if(m == 1){
    	for(int i = 0; i < n; i++) --v[i][0];
    	
    	int kk = -1;
    	for(int i = 0; i < n; i++){
    		if(v[i][0] > kk){
    			kk = v[i][0];
    		}	
    	}
    	/*
    	for(int i = 0; i < n; i++){
    		if(v[i][0] == kk){
    			--v[0][i];
    			break;
    		}
    	}
    	kk = -1;
    	for(int i = 0; i < n; i++){
    		if(v[i][0] > kk){
    			kk = v[i][0];
    		}	
    	}*/
    	cout << kk << '\n';
    	return;
    }
    int si = -1, sj = -1;
    sort(mmax.rbegin(), mmax.rend());
    auto r = mmax[0].second.first, c = mmax[0].second.second;
    bool flagrow = false, flagcol = false;
    for(int i = 1; i < (int)mmax.size(); i++){
    	if(i == 1){
    		auto p = mmax[i];
    		if(p.second.first != r && p.second.second != c){
    			si = p.second.first;
    			sj = p.second.second;
    			break;
    		}
    		else if(p.second.first == r && p.second.second != c){
    			flagrow = true;
    		}
    		else if(p.second.first != r && p.second.second == c){
    			flagcol = true;
    		}
    	}
    	if(flagcol){
    		if(mmax[i].second.second != c){
    			si = mmax[i].second.first, sj = mmax[i].second.second;
    			break;
    		}
    	}
    	else if(flagrow){
    		if(mmax[i].second.first != r){
    			si = mmax[i].second.first, sj = mmax[i].second.second;
    			break;
    		}
    	}
    }
    int maxmin1 = -1, maxmin2 = -1;
    auto t = v;
    for(int i = 0; i < m; i++){
    	//if(i != c) 
    	t[si][i]--;
    }
    for(int i = 0; i < n; i++){
    	if(i != si) t[i][c]--;
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(t[i][j] > maxmin1){
    			maxmin1 = t[i][j];
    		}
    	}
    }
    t = v;
    for(int i = 0; i < m; i++){
    	//if(i != sj) 
    	t[r][i]--;
    }
    for(int i = 0; i < n; i++){
    	if(i != r) t[i][sj]--;
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(t[i][j] > maxmin2){
    			maxmin2 = t[i][j];
    		}
    	}
    }
    cout << min(maxmin1, maxmin2) << '\n';
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