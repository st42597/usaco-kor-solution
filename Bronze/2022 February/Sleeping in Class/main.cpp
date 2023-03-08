#include <bits/stdc++.h>
using namespace std;

int arr[100003], psum[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            psum[i] = psum[i - 1] + arr[i];
        }
        if(psum[N] == 0){
            cout << 0;
            continue;
        }
        for(int i = 1; i <= N; i++){
            if(psum[i] == 0 || psum[N] % psum[i]) continue;
            int num = psum[i];
            int j;
            for(j = 1; j <= N; j++){
                if(psum[j] == num) num += psum[i];
                if(psum[j] > num) break;
            }
            if(j > N){
                cout << N - psum[N] / psum[i] << "\n";
                break;
            }
        }
    }

    return 0;
}
