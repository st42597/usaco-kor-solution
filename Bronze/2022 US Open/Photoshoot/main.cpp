#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    string str; cin >> str;
    int ans = 0, t = 0;
    for(int i = N - 2; i >= 0; i -= 2){
        if(str.substr(i, 2) == "GH" && t == 0){
            ans++;
            t ^= 1;
        }else if(str.substr(i, 2) == "HG" && t == 1){
            ans++;
            t ^= 1;
        }
    }
    cout << ans;

    return 0;
}
