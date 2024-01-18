#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

vector<ll> cow;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++){
        int tmp; cin >> tmp;
        cow.push_back(tmp);
    }

    for(int i = 0; i < M; i++){
        ll cane; cin >> cane;
        ll last = 0;
        for(int j = 0; j < N; j++){
            if(cow[j] > last){
                ll tmp = cow[j];
                cow[j] += min(cow[j], cane) - last;
                last = tmp;
            }
            if(last >= cane) break;
        }
    }

    for(int i = 0; i < N; i++){
        cout << cow[i] << "\n";
    }

    return 0;
}