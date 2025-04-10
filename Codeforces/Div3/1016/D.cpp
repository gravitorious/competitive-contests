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
 
void solve(){
	int n, q;
	cin >> n >> q;
	for(int k = 0; k < q; k++){
		ll numb = 1 << n;
		string s; cin >> s;
		if(s[0] == '<'){
			ll a;
			cin >> a;
			ll z = 1, l = 0, r = 0;
			ll jumb = 1;
			int x = 0, y = 0;
			for(int i = 0; i < n - 1; i++) jumb *= 4;
			for(int i = 0; i < n - 1; i++){
				bool flag = false;
				numb /= 2;
				for(int j = 0; j < 4; j++){
					l = r + 1;
					r = l + jumb - 1;
					if(a >= l && a <= r){
						if(j == 1){
							x += numb;
							y += numb;
						}
						else if(j == 2){
							x += numb;
						}
						else if(j == 3){
							y += numb;
						}
						flag = true;
						r = l - 1;
					}
					if(flag) break;
				}
				jumb /= 4;
			}
			if(n == 1) l = 1;
			//starts from 1
			if(l == a) cout << x + 1 << ' ' << y + 1<< '\n';
			else if(l + 1 == a) cout << x + 2 << ' ' << y + 2 << '\n';
			else if(l + 2 == a) cout << x + 2 << ' ' << y + 1 << '\n';
			else cout << x + 1<< ' ' << y + 2 << '\n';
		}
		else{
			int x, y;
			cin >> x >> y;
			--x, --y;
			ll z = 1, l = 0, r = 0;
			int cx = 0, cy = 0;
			ll jumb = 1;
			for(int i = 0; i < n - 1; i++) jumb *= 4;
			for(int i = 0; i < n - 1; i++){
				bool flag = false;
				numb /= 2;
				int tx = cx, ty = cy;
				for(int j = 0; j < 4; j++){
					l = r + 1;
					r = l + jumb - 1;
					if(j == 1){
						cx += numb;
						cy += numb;
					}
					else if(j == 2){
						cx += numb;
					}
					else if(j == 3){
						cy += numb;
					}
					if(x >= cx && x <= cx + numb - 1 &&
					   y >= cy && y <= cy + numb - 1){
						flag = true;
						r = l - 1;
					}
					else{
						cx = tx, cy = ty;	
					}
					if(flag) break;
				}
				jumb /= 4;
			}
			if(n == 1) l = 1;
			if(cx == x && cy == y){
				cout << l << '\n';	
			}
			else if(x == cx + 1 && y == cy){
				cout << l + 2 << '\n';	
			}
			else if(x == cx && y == cy + 1){
				cout << l + 3 << '\n';	
			}
			else if(x == cx + 1 && y == cy + 1){
				cout << l + 1 << '\n';	
			}
		}
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
