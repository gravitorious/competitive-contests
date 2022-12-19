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


const int INF = 100;


bool calc(int X, int Y, int Z, int target){
	
	int t1 = 0, t2 = 0, t3 = 0;
	if(X > 0) t1 = 1;
	if(Y > 0) t2 = 1;
	if(Z > 0) t3 = 1;
	if(target <= t1+t2+t3) return true;
	
	vector<int> v;
	v.push_back(X);
	v.push_back(Y);
	v.push_back(Z);
	sort(v.begin(), v.end());
	
	int basics = t1+t2+t3; int second = 0;
	reverse(v.begin(), v.end());
	//while(basics + second < target){
		
	int i = 0;
	int j = 1;
	int k = 2;
	v[i]--;
	v[j]--;
	if(v[i] <= 0 || v[j] <= 0) return false;
	second++;
	if(basics + second == target) return true;
	
	if(v[i] >= v[j]){
		v[i]--;
		v[k]--;
		if(v[i] <= 0 || v[k] <= 0) return false;
		second++;
		if(basics + second == target) return true;	
		v[j]--;
		v[k]--;
		if(v[j] <= 0 || v[k] <= 0) return false;
		second++;
		if(basics + second == target) return true;	
	}
	else{
		v[j]--;
		v[k]--;
		if(v[j] <= 0 || v[k] <= 0) return false;
		second++;
		if(basics + second == target) return true;	
		v[i]--;
		v[k]--;
		if(v[j] <= 0 || v[k] <= 0) return false;
		second++;
		if(basics + second == target) return true;	

	}

	//return true;	
}








void solve(){
	int X,Y,Z;
	cin >> X >> Y >> Z;
	int answer = 0;
	int first = 0;
	int second  = 6;
	while(first <= second){
		
		int mid = (second + first) >> 1;
		if(calc(X,Y,Z, mid)){
			first = mid + 1;
			answer = mid;
		}
		else{
			second = mid - 1;	
		}
	}	
	cout << answer << endl;
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
