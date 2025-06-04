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
 
/**
  * Description: modular arithmetic operations
  * Source:
  * KACTL
  * https://codeforces.com/blog/entry/63903
  * https://codeforces.com/contest/1261/submission/65632855 (tourist)
  * https://codeforces.com/contest/1264/submission/66344993 (ksun)
  * also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp
  * (ecnerwal) Verification: https://open.kattis.com/problems/modulararithmetic
  */
 const int MOD = (int)998244353;
 template <int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; }  // primitive root for FFT
    int v;
    explicit operator int() const {
        return v;
    }  // explicit -> don't silently convert to int
    mint() : v(0) {}
    mint(ll _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }
    bool operator==(const mint &o) const { return v == o.v; }
    friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
    friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
  
    mint &operator+=(const mint &o) {
        if ((v += o.v) >= MOD) v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &o) {
        if ((v -= o.v) < 0) v += MOD;
        return *this;
    }
    mint &operator*=(const mint &o) {
        v = int((ll)v * o.v % MOD);
        return *this;
    }
    mint &operator/=(const mint &o) { return (*this) *= inv(o); }
    friend mint pow1(mint a, ll p) {
        mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1) ans *= a;
        return ans;
    }
    friend mint inv(const mint &a) {
        assert(a.v != 0);
        return pow1(a, MOD - 2);
    }
  
    mint operator-() const { return mint(-v); }
    mint &operator++() { return *this += 1; }
    mint &operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
    friend std::ostream &operator <<(std::ostream &os, const mint &m){ 
        os << m.v; return os;
    } 
 };
 
 using mi = mint<MOD, 5>;  // 5 is primitive root for both common mods
  
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int j = 0; j < n; j++) cin >> q[j];
    vector<int> pmax(n), qmax(n), ppos(n), qpos(n);
    int apmax = -1, appos, aqmax = -1, aqpos;
    for(int i = 0; i < n; i++){
        if(p[i] > apmax){
            apmax = p[i];
            appos = i;
        }
        pmax[i] = apmax;
        ppos[i] = appos;
        
        if(q[i] > aqmax){
            aqmax = q[i];
            aqpos = i;
        }
        qmax[i] = aqmax;
        qpos[i] = aqpos;        
    }
    vector<mi> r(n);
    for(int i = 0; i < n; i++){
        //mi sum1 = pow1(mi(2), pmax[i]) + pow1(mi(2), q[i - ppos[i]]);
        //mi sum2 = pow1(mi(2), qmax[i]) + pow1(mi(2), p[i - qpos[i]]);
        mi ans;
        if(pmax[i] > qmax[i]){
            ans = pow1(mi(2), pmax[i]) + pow1(mi(2), q[i - ppos[i]]);
        }
        else if(pmax[i] < qmax[i]){
            ans = pow1(mi(2), qmax[i]) + pow1(mi(2), p[i - qpos[i]]);
        }
        else{
            ans = pow1(mi(2), qmax[i]) + pow1(mi(2), max(p[i - qpos[i]], q[i - ppos[i]])); 
        }
        r[i] = ans;
    }
    for(const auto &x : r) cout << x << ' ';
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
