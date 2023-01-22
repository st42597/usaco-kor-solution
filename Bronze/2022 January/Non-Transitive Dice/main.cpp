#include <bits/stdc++.h>
using namespace std;

int arr[3][4];

bool simulate(){
    int cnt[3][3] = {0};
    for(int a = 0; a < 3; a++){
        for(int b = a + 1; b < 3; b++){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(arr[a][i] > arr[b][j]) cnt[a][b]++;
                    if(arr[a][i] < arr[b][j]) cnt[b][a]++;
                }
            }
        }
    }
    bool flag = false;
    if(cnt[0][1] > cnt[1][0] && cnt[0][2] < cnt[2][0] && cnt[1][2] > cnt[2][1]) flag = true;
    if(cnt[0][1] < cnt[1][0] && cnt[0][2] > cnt[2][0] && cnt[1][2] < cnt[2][1]) flag = true;
    return flag;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 2; j++) for(int k = 0; k < 4; k++) cin >> arr[j][k];
        bool flag = false;
        for(int a = 1; a <= 10; a++){
            for(int b = a; b <= 10; b++){
                for(int c = b; c <= 10; c++){
                    for(int d = c; d <= 10; d++){
                        arr[2][0] = a;
                        arr[2][1] = b;
                        arr[2][2] = c;
                        arr[2][3] = d;
                        if(simulate()) flag = true;
                    }
                }
            }
        }
        cout << ((flag) ? "yes" : "no") << "\n";
    }

    return 0;
}