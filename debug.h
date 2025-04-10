#include <bits/stdc++.h>
using namespace std;

template<typename T,typename U> ostream& operator<<(ostream& out,const pair<T,U>& p){
	out<<"{" <<p.first<<","<<p.second<<"}";
	return out;
}

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < (int) v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
} 

template<typename T,typename U> ostream& operator<<(ostream& out,const map<T,U>& m){
	out<<"{"; for(const auto &x : m) out<<"[" <<x.first<<","<<x.second<<"]";
	out << "}";
	return out;
}


vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; 
	ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

