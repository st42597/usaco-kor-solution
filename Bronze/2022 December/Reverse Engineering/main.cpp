#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        string str[103];
        int ret[103];
        bool check1[103] = {false};
        bool check2[103] = {false};
        for(int i = 0; i < M; i++) cin >> str[i] >> ret[i];
        for(int t = 0; t < N; t++){
            for(int i = 0; i < N; i++){
                if(check1[i]) continue;
                vector<int> rec[4];
                for(int j = 0; j < M; j++){
                    if(check2[j]) continue;
                    if(str[j][i] == '0'){
                        if(ret[j] == 0) rec[0].push_back(j);
                        else rec[1].push_back(j);
                    }else{
                        if(ret[j] == 0) rec[2].push_back(j);
                        else rec[3].push_back(j);
                    }
                }
                if(rec[0].size() * rec[1].size() == 0){
                    check1[i] = true;
                    if(rec[0].size() > 0){
                        for(int a : rec[0]) check2[a] = true;
                    }else{
                        for(int a : rec[1]) check2[a] = true;
                    }
                    break;
                }else if(rec[2].size() * rec[3].size() == 0){
                    check1[i] = true;
                    if(rec[2].size() > 0){
                        for(int a : rec[2]) check2[a] = true;
                    }else{
                        for(int a : rec[3]) check2[a] = true;
                    }
                    break;
                }
            }
        }
        vector<int> tmp;
        for(int i = 0; i < M; i++){
            if(check2[i]) continue;
            tmp.push_back(ret[i]);
        }
        bool flag = true;
        for(int i = 1; i < tmp.size(); i++){
            if(tmp[i] != tmp[i - 1]){
                flag = false;
                break;
            }
        }
        cout << ((flag) ? "OK" : "LIE") << "\n";
    }

    return 0;
}