#include <bits/stdc++.h>
using namespace std;

int arr[100003];
bool check[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cnt += arr[i];
    }
    check[N] = true;
    int pos = 0, dir = 1;
    while(cnt--){
        if(pos == 0) dir = 1;
        if(dir == 1){
            if(arr[pos] > 0){
                arr[pos++]--;
                cout << 'R';
            }else{
                if(--arr[--pos] == 0){
                    check[pos] = check[pos + 1];
                }
                dir = -1;
                cout << 'L';
            }
        }else{
            if(arr[pos - 1] > 1){
                arr[--pos]--;
                cout << 'L';
            }else if(arr[pos - 1] == 1 && check[pos]){
                arr[--pos]--;
                check[pos] = check[pos + 1];
                cout << 'L';
            }else{
                arr[pos++]--;
                dir = 1;
                cout << 'R';
            }
        }
    }

    return 0;
}