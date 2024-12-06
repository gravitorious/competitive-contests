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
int n, m;
vector<string> s;
cin >> n >> m;
for(int i = 0; i < n; i++){
	string str;
	cin >> str;
	s.push_back(str);	
}
vector<vector<bool>> check(n, vector<bool>(m));
map<pair<int, int>, bool> path;
auto dfs = [&](auto &&self, int i, int j){
	//debug(i, j);
	if(check[i][j]){
		path[{i, j}] = false;
		return;	
	}
	if(i == 0 && s[i][j] == 'U'){
		path[{i, j}] = false;
		check[i][j] = true;
		return;
	}
	if(j == 0 && s[i][j] == 'L'){
		path[{i, j}] = false;
		check[i][j] = true;
		return;
	}
	if(i == n - 1 && s[i][j] == 'D'){
		path[{i, j}] = false;
		check[i][j] = true;
		return;
	}
	if(j == m - 1 && s[i][j] == 'R'){
		path[{i, j}] = false;
		check[i][j] = true;
		return;
	}
	if(s[i][j] == '?'){
		return;	
	}
	int first, second;
	if(s[i][j] == 'U'){
		first = i - 1;
		second = j;
	}
	else if(s[i][j] == 'D'){
		first = i + 1;
		second = j;
	}
	else if(s[i][j] == 'L'){
		first = i;
		second = j - 1;
	}
	else if(s[i][j] == 'R'){
		first = i;
		second = j + 1;
	}
	if(first < 0 || first == n || second < 0 || second == m){
		path[{i, j}] = false;
		check[i][j] = true; 
		return;
	}
	if(path[{first, second}]){
		return;
	}
	path[{first, second}] = true;
	self(self, first, second);
	if(check[first][second]){
		path[{i, j}] = false;
		check[i][j] = true;
		return;	
	}
};
for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
		if(!check[i][j] && s[i][j] != '?'){
			path[{i, j}] = true;
			dfs(dfs, i, j);
		}
		//if(check[i][j]) path.clear();
	}	
}
for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
		if(s[i][j] == '?'){
			if(j - 1 >= 0 && !check[i][j - 1]){
					continue;
			}
			else if(i - 1 >= 0 && !check[i - 1][j]){
				continue;
			}
			else if(i + 1 <= n - 1 && !check[i + 1][j]){
				continue;
			}
			else if(j + 1 <= m - 1 && !check[i][j + 1]){
				continue;
			}
			else{
				check[i][j] = true;
			}
		}
	}	
}
int ans = n * m;
for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
		if(check[i][j]) --ans;
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

/*
UDU??UU?DD?URDRDU?UUUDDU?RURDRURDR?UDUUU?UUUU?RUD?DUUDUUURD?R??RDDDUDDU?UDDRUDDRRURDUUD?DR?URDDUD?DU
UUD?UUDDDU?U?UUUU?RRU?DUUUUUUDUDR?UDD?RDDRURUUDU???UR?DUR?U?U?UDDDU?RUR?R?UUUDRUUUDR?U?DUR?DU?RD?RUR
R?DUDDUU?UURURDUR?UDUUUU?DURURUR?DR?UUU?U?RRUD?RUU?RUURDRU?UDUDRDDUUU?D?U?UUDDR?U??UU?UUDURD?RRUUURR
R?RUR?U??RDRDRUD?UR?RD???UUU?RU?U??RUDRD??DDUUUDURDU?UU?UR?U?UURDRRUURUDUU?URRUUUU?RRRURUUUUUURUUDUU
R?DUDDUU?UURURDUR?UDUUUU?DURURUR?DR?UUU?U?RRUD?RUU?RUURDRU?UDUDRDDUUU?D?U?UUDDR?U??UU?UUDURD?RRUUURR
*/