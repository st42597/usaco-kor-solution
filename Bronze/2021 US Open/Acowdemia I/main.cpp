#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L; cin >> N >> L;
    for(int i = 0; i < N; i++){
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), greater<>());
    int i, cnt = 0;
    for(i = 0; i < N; i++){
        if(i == 0 || arr[i - 1] != arr[i]){
            cnt = 1;
        }else{
            cnt++;
        }
        if(arr[i] == i && cnt > L) break;
        else if(arr[i] < i) break;
    }
    cout << i;
    
    return 0;
}