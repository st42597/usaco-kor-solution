#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        string str; cin >> str;
        int min_diff = 1e9;
        for(int i = 1; i < str.length() - 1; i++){
            int diff = 0;
            if(str[i] == 'O'){
                if(str[i - 1] != 'M') diff++;
                if(str[i + 1] != 'O') diff++;
            }else diff = 1e9;
            min_diff = min(min_diff, diff);
        }
        if(min_diff == 1e9) cout << -1 << "\n";
        else cout << min_diff + str.length() - 3 << "\n";
    }

    return 0;
}