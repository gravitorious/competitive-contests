///created by gravitorious
#include <bits/stdc++.h>
using namespace std;
 
#ifdef XOX
#include "debug.h"
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
    vector<array<int, 3>> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];   
    }
    vector<int> fib(n);
    fib[0] = 1, fib[1] = 2;
    for(int i = 2; i < n; i++) fib[i] = fib[i - 1] + fib[i - 2];
    vector<bool> ans(m);
    int k = 0;
    for(const auto &b : v){
        vector<int> p;
        p.push_back(b[0]); 
        p.push_back(b[1]);
        p.push_back(b[2]);
        sort(p.begin(), p.end());
        if(p[2] >= fib[n - 1] + fib[n - 2] && p[1] >= fib[n - 1] && p[0] >= fib[n - 1]){
            ans[k] = 1;
        }
        k++;
    }
    for(const auto &x : ans) cout << x;
    cout << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}