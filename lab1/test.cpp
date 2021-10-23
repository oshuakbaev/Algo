#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(s) (int)s.size()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vvi;


const int mod = 1e9 + 7;
const int N = 100100;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll d = 2; d * d <= n; d++) {
      if (n % d == 0) {
        cout << "composite\n";
        return 0;
      }
    }    
    cout << "prime\n";
    return 0;
}