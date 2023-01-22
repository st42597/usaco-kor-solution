#include <bits/stdc++.h> 
using namespace std;

char guess[4][4], ans[4][4];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> guess[i][j];
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> ans[i][j];
    int green = 0, yellow = 0;
    for(char alpha = 'A'; alpha <= 'Z'; alpha++){
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(guess[i][j] == alpha) cnt1++;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(ans[i][j] == alpha) cnt2++;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(ans[i][j] == alpha && guess[i][j] == ans[i][j]) cnt3++;
            }
        }
        cnt4 = min(cnt1, cnt2) - cnt3;
        green += cnt3;
        yellow += cnt4;
    }
    cout << green << "\n" << yellow;

    return 0;
}