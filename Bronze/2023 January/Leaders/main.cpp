#include <bits/stdc++.h>
using namespace std;

int arr[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    string str; cin >> str;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0, add = 1;
    for(int i = 0; i < N; i++){
        if(str[i] == 'G'){
            for(int j = N - 1; j >= 0; j--){
                if(str[j] == 'G'){
                    if(j < arr[i]){
                        for(int k = 0; k < i; k++){
                            if(str[k] == 'H' && i < arr[k]) ans++;
                        }
                    }else{
                        add = 0;
                    }
                    break;
                }
            }
            break;
        }
    }
    for(int i = 0; i < N; i++){
        if(str[i] == 'H'){
            for(int j = N - 1; j >= 0; j--){
                if(str[j] == 'H'){
                    if(j < arr[i]){
                        for(int k = 0; k < i; k++){
                            if(str[k] == 'G' && i < arr[k]) ans++;
                        }
                    }else{
                        add = 0;
                    }
                    break;
                }
            }
            break;
        }
    }
    cout << ans + add;

    return 0;
}