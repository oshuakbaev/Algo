#include <iostream>
#include <queue>

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
typedef vector<vector<int> > vvi;


const int mod = 1e9 + 7;
const int N = 100100;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int cnt = 1;
    queue<int> q1;
    queue<int> q2;
    for (int i = 0; i < 5; i++) {
      int x;
      cin >> x;
      q1.push(x);
    }
    for (int i = 0; i < 5; i++) {
      int x;
      cin >> x;
      q2.push(x);
    }
    while (cnt <= 1e6) {
       int a = q1.front(), b = q2.front();
       q1.pop(), q2.pop();
       if (a == 0 && b == 9) {
         q1.push(0);
         q1.push(9);
       }  else if (a == 9 && b == 0) {
         q2.push(9);
         q2.push(0);
       }  else {
         if (a > b) {
           q1.push(a);
           q1.push(b);
         }  else {
           q2.push(a);
           q2.push(b);
         }
       }
       if (sz(q1) == 0) {
         cout << "second" << ' ' << cnt;
         return 0; 
       } 
       if (sz(q2) == 0) {
         cout << "first" << ' ' << cnt;
         return 0;
       }
       cnt++;
    } 
    cout << "botva";
    return 0;
}