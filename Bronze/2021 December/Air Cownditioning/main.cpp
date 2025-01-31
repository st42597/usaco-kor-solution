#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < N; i++) {
        int b; cin >> b;
        B.push_back(b);
    }
    int last = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] - B[i] >= 0) {
            if(last >= 0) {
                if(A[i] - B[i] >= last) {
                    ans += A[i] - B[i] - last;
                }
            }else {
                ans += A[i] - B[i];
            }
            last = A[i] - B[i];
        }else {
            if(last < 0) {
                if(abs(A[i] - B[i]) >= abs(last)) {
                    ans += abs(A[i] - B[i]) - abs(last);
                }
            }else {
                ans += abs(A[i] - B[i]);
            }
            last = A[i] - B[i];
        }
    }
    cout << ans;


    return 0;
}