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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 1e12 + 5;
    int left = 0;
    bool flag = false;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1] && flag == false){
            left = i;
            flag = true;
            continue;   
        }
        else if(a[i] == a[i + 1]) continue;
        else if(a[i] != a[i + 1] && flag == true){
            ans = min(ans, 1LL * a[i] * left + 1LL * a[i] * (n - i - 1));
            flag = false;  
        }
        else{
            ans = min(ans, 1LL * a[i] * i + 1LL * a[i] * (n - i - 1));    
        }
    }
    if(flag == true){
        if(left == 0){
            cout << 0 << '\n';
            return;
        }
        ans = min(ans, 1LL * a[n - 1] * left);
    }
    else{
        ans = min(ans, 1LL * a[n - 1] * (n - 1));  
    }
    cout << ans << '\n';
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