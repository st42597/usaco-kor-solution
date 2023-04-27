#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

void fastio(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}

int n;
ll m[305], v[305][305];

int main(){
    fastio();
    cin >> n;
    for(int i=1 ; i<=n ; i++) for(int j=i ; j<=n ; j++) cin >> v[i][j];
    ll mx, mn;
    for(int j=2 ; j<=n ; j++){
        bool tf=true;
        m[j]=m[j-1]-v[j-1][j];
        mn=m[j], mx=m[j];
        for(int i=j ; i>=1 ; i--){
        mx=max(mx,m[i]);
        mn=min(mn,m[i]);
        if(mx-mn!=v[i][j]){
            tf=false;
            break;
        }
        }
        if(tf) continue;
        m[j]=m[j-1]+v[j-1][j];
    }
    for(int i=1 ; i<=n ; i++) cout << m[i] << ' ';
    return 0;
}