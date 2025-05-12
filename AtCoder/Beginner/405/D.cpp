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

const int inf = int(1e9) + 5;
 
void solve(){
    int h, w;
    cin >> h >> w;
    vector<string> t(h);
    vector<pair<int, int>> exits;
    for(int i = 0; i < h; i++) cin >> t[i];
	vector<vector<int>> d(h, vector<int>(w, inf));
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		if(t[i][j] == 'E'){
    			exits.emplace_back(make_pair(i, j));
    			d[i][j] = 0;
    		}
    	}
    }
   	auto lim = [&](int i, int j) -> bool{
   		if(i < 0 || i >= h || j < 0 || j >= w){
    		return false;	
    	}
    	else{
    		if(t[i][j] == '#') return false;	
    		else return true;
    	}
   	};
    vector<vector<bool>> visited(h, vector<bool>(w));
    queue<pair<int, pair<int, int>>> q;
    for(int i = 0; i < (int)exits.size(); i++){
    	q.push({0, {exits[i].first, exits[i].second}});	
    	visited[exits[i].first][exits[i].second] = true;
    }
    while(!q.empty()){
    	auto k = q.front(); q.pop();
    	int w = k.first; int ii = k.second.first, jj = k.second.second;
    	if(lim(ii - 1, jj) && !visited[ii - 1][jj]){
    		visited[ii - 1][jj] = true;
    		t[ii - 1][jj] = 'v';
    		d[ii - 1][jj] = d[ii][jj] + 1;
    		q.push({d[ii - 1][jj], {ii - 1, jj}});
    	}
    	if(lim(ii, jj - 1) && !visited[ii][jj - 1]){
    		visited[ii][jj - 1] = true;
    		t[ii][jj - 1] = '>';
    		d[ii][jj - 1] = d[ii][jj] + 1;
    		q.push({d[ii][jj - 1], {ii, jj - 1}});
    	}
    	if(lim(ii + 1, jj) && !visited[ii + 1][jj]){
    		visited[ii + 1][jj] = true;
    		t[ii + 1][jj] = '^';
    		d[ii + 1][jj] = d[ii][jj] + 1;
    		q.push({d[ii + 1][jj], {ii + 1, jj}});
    	}
    	if(lim(ii, jj + 1) && !visited[ii][jj + 1]){
    		visited[ii][jj + 1] = true;
    		t[ii][jj + 1] = '<';
    		d[ii][jj + 1] = d[ii][jj] + 1;
    		q.push({d[ii][jj + 1], {ii, jj + 1}});
    	}
    	
    }
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		cout << t[i][j];
    	}
    	cout << '\n';
    }
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}
