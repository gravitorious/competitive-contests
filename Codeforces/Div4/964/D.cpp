///created by gravitorious
#include <bits/stdc++.h>
using namespace std;

#ifdef XOX
#include "/home/nikos/gravitonlib/mydebug/debug.h"
#else
#define debug(...) 21198
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

double int_part(double x, double* intpart){
	//returns the real part
	return modf(x, intpart);
}

ll udiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll ddiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

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
	string s, t;
	cin >> s >> t;
	if((int)t.size() > (int)s.size()){
		cout << "NO\n";
		return;
	}
	int start = 0;
	bool flag = false;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == '?'){s[i] = t[start]; start++;}
		else if(s[i] == t[start]) start++;
		if(start == (int)t.size()){
			flag = true;
			break;	
		}
	}
	if(flag){
		cout << "YES\n";
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == '?'){s[i] = 'a';}
		}
		cout << s << '\n';
	}
	else cout << "NO\n";
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
