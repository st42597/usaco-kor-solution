#include <bits/stdc++.h>
using namespace std;

bool isUsed[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> A(N), B(N);
    for(int &in : A) cin >> in;
    for(int &in : B) cin >> in;
    int pos = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        while(isUsed[A[pos]]) pos++;
        if(B[i] != A[pos]) cnt++;
        isUsed[B[i]] = true;
    }
    cout << cnt;

    return 0;
}