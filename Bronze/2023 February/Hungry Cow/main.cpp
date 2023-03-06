#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, T; cin >> N >> T;
    ll p = 0, ans = 0;
    for(int i = 0; i < N; i++){
        ll d, b; cin >> d >> b;
        if(T < d) break;
        if(p < d){
            ans += b;
            p = d + b - 1;
        }else{
            ans += b;
            p += b;
        }
        if(T < p){
            ans -= p - T;
            break;
        }
    }
    cout << ans;

    return 0;
}
