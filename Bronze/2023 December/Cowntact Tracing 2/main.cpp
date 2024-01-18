#include <bits/stdc++.h> 
using namespace std;

vector<int> arr;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    string str; cin >> str;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(str[i] == '1') cnt += 1;
        else if(cnt > 0){
            arr.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt > 0) arr.push_back(cnt);

    if(arr.empty()){
        cout << 0;
        return 0;
    }

    int max_day = 1e9;
    for(int i = 1; i < arr.size() - 1; i++){
        max_day = min(max_day, (arr[i] - 1) / 2);
    }
    if(str[0] == '1') max_day = min(max_day, arr[0] - 1);
    else max_day = min(max_day, (arr[0] - 1) / 2);

    if(str[N - 1] == '1') max_day = min(max_day, arr.back() - 1);
    else max_day = min(max_day, (arr.back() - 1) / 2);

    int ans = 1e9;
    for(int i = 0; i <= max_day; i++){
        int cnt = 0;

        for(int j = 0; j < arr.size(); j++){
            cnt += arr[j] / (i * 2 + 1) + (arr[j] % (i * 2 + 1) != 0 ? 1 : 0);
        }
        
        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}