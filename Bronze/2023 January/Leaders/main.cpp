#include <bits/stdc++.h>
using namespace std;

int arr[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    string str; cin >> str;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int lg = -1, rg, lh = -1, rh;
    for(int i = 0; i < N; i++){
        if(str[i] == 'G'){
            if(lg == -1) lg = i;
            rg = i;
        }
        if(str[i] == 'H'){
            if(lh == -1) lh = i;
            rh = i;
        }
    }
    int ans = 0;
    if(lg < lh){
        if(arr[lh] > rh){
            for(int i = 0; i < lh; i++){
                if(i == 0 && arr[0] > rg) ans++;
                else if(arr[i] > lh) ans++;
            }
        }
    }else{
        if(arr[lg] > rg){
            for(int i = 0; i < lg; i++){
                if(i == 0 && arr[0] > rh) ans++;
                else if(arr[i] > lg) ans++;
            }
        }
    }
    cout << ans;

    return 0;
}