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


 
bool emptycolumn(vector<int> &v){
	
	for(const auto &x : v){
		if(x == '1') return false;	
	}
	return true;
} 
 
 
 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	string s;
	cin >> s;
	vector<vector<int>> v(7);
	v[0].push_back(s[6]);
	v[1].push_back(s[3]);
	v[2].push_back(s[1]);
	v[2].push_back(s[7]);
	v[3].push_back(s[0]);
	v[3].push_back(s[4]);
	v[4].push_back(s[2]);
	v[4].push_back(s[8]);
	v[5].push_back(s[5]);
	v[6].push_back(s[9]);
	
	
	
	int size = 10;
		
	if(s[0] == '0'){
		for(int i = 0; i <= 4; i++){
			if(emptycolumn(v[i]) == true){
				continue;	
			}
			
			for(int j = i + 2; j < 7; j++){
				if(emptycolumn(v[j]) == true){
					continue;	
				}
				int result = false;
				
				//if(!emptycolumn(v[i]) && !(emptycolumn(v[j]))){
				if(!(emptycolumn(v[j]))){
					int flag = false;
					
					for(int k = i+1; k < j; k++){
						result = emptycolumn(v[k]);	
						if(result == true){
							cout << "Yes" << endl;
							return 0;	
						}
						
					}
				}	
			}
		}	
		cout << "No" << endl;
	}
	else{
		cout << "No" << endl;	
	}
	
	
	
	
	
	return 0;
}
