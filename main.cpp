#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef ld COMPTYPE;
typedef complex<COMPTYPE> point;
 
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIOS(fn) freopen(fn".in", "r", stdin); freopen(fn".out", "w", stdout);
#define PI 3.14159265358979323846264338327950288419716939937510
#define xx real()
#define yy imag()
#define ff first
#define ss second
#define nl "\n"
#define bl " "
#define pb push_back

template<typename T>
bool chmax(T& val, T nval) { if(val < nval) {val=nval; return true;} return false;}
template<typename T>
bool chmin(T& val, T nval) { if(val > nval) {val=nval; return true;} return false;}

void DEBUGOUT() { cerr << '\n'; }
template<typename Head, typename... Tail>
void DEBUGOUT(Head H, Tail... T) { cerr << ' ' << H; DEBUGOUT(T...); }
#define DEBUG(...) cerr << "(" << #__VA_ARGS__ << "):";  DEBUGOUT(__VA_ARGS__)

void WRITEIN() { return; }
template<typename Head, typename... Tail>
void WRITEIN(Head& H, Tail&... T) { cin >> H; WRITEIN(T...); }
#define win(...) WRITEIN(__VA_ARGS__);

void WRITEOUT() { return; }
template<typename Head, typename... Tail>
void WRITEOUT(Head&& H, Tail&&... T) { cout << H; WRITEOUT(T...); }
#define wout(...) WRITEOUT(__VA_ARGS__);

string s[8];
int p[8];

int32_t main() {
	IOS;

	int minv,maxv;
	int currv;
	int n,k;
	int ans = 1e9;
	win(n,k);

	for(int i = 0; i < n; i++)
		win(s[i]);

	iota(p, p+k, 0);

	do {
		currv = 0;
		for(int j = 0; j < k; j++) {
			currv *= 10;
			currv += s[0][p[j]]-'0';
		}
		maxv = minv = currv;
		for(int i = 1; i < n; i++) {
			currv = 0;
			for(int j = 0; j < k; j++) {
				currv *= 10;
				currv += s[i][p[j]]-'0';
			}
			chmax(maxv,currv);
			chmin(minv,currv);
		}
		chmin(ans, maxv-minv);
	} while(next_permutation(p,p+k));

	wout(ans,nl);
}
