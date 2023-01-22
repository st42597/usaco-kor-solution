#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        string str; cin >> str;
        vector<char> ans(N);
        fill(ans.begin(), ans.end(), '.');
        int cnt = 0;
        int G = -1, H = -1;
        for(int i = 0; i < N; i++){
            if(str[i] == 'G' && i <= G) continue;
            if(str[i] == 'H' && i <= H) continue;
            for(int j = min(i + K, N - 1); j >= max(i - K, 0); j--){
                if(ans[j] == '.'){
                    ans[j] = str[i];
                    cnt++;
                    if(str[i] == 'G') G = i + K * 2;
                    if(str[i] == 'H') H = i + K * 2;
                    break;
                }
            }
        }
        cout << cnt << "\n";
        for(char out : ans) cout << out;
        cout << "\n";
    }

    return 0;
}