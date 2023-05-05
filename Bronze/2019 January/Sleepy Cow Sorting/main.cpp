#define _DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define all(x) (x).begin(),(x).end() 
#define sz(x) (x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
const long double pi = acos(-1.0);
const int INF = 1987654321;
const ll LLINF = 4e18;
const double eps = 1e-9;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(){
#ifdef _DEBUG
    freopen ("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif      
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> V(N);
    for(auto &v : V) cin >> v;
    
    int ans = N-1;
    
    for(int i = N-1; i >=1; i--){
        if(V[i-1] < V[i]){
            ans = i-1;
        }
        else{
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}