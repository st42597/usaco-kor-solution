#include <bits/stdc++.h>
using namespace std;

int K;
char canvas[23][23], new_canvas[23][23], stamp[23][23], rotate_stamp[23][23];

void rotate(int n){
    int x = 0, y = 0;
    switch(n){
        case 0:
            for(int a = 0; a < K; a++){
                for(int b = 0; b < K; b++){
                    rotate_stamp[x][y++] = stamp[a][b];
                }
                x++;
                y = 0;
            }
            break;
        case 1:
            for(int b = 0; b < K; b++){
                for(int a = K - 1; a >= 0; a--){
                    rotate_stamp[x][y++] = stamp[a][b];
                }
                x++;
                y = 0;
            }
            break;
        case 2:
            for(int a = K - 1; a >= 0; a--){
                for(int b = K - 1; b >= 0; b--){
                    rotate_stamp[x][y++] = stamp[a][b];
                }
                x++;
                y = 0;
            }
            break;
        case 3:
            for(int b = K - 1; b >= 0; b--){
                for(int a = 0; a < K; a++){
                    rotate_stamp[x][y++] = stamp[a][b];
                }
                x++;
                y = 0;
            }
            break;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> canvas[i][j];
                new_canvas[i][j] = '.';
            }
        }
        cin >> K;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < K; j++){
                cin >> stamp[i][j];
            }
        }

        for(int k = 0; k < 4; k++){
            rotate(k);
            for(int i = 0; i < N - K + 1; i++){
                for(int j = 0; j < N - K + 1; j++){
                    bool flag = true;
                    for(int a = 0; a < K; a++){
                        for(int b = 0; b < K; b++){
                            if(rotate_stamp[a][b] == '*' && canvas[i + a][j + b] == '.'){
                                flag = false;
                            }
                        }
                    }
                    if(flag){
                        for(int a = 0; a < K; a++){
                            for(int b = 0; b < K; b++){
                                if(rotate_stamp[a][b] == '*'){
                                    new_canvas[i + a][j + b] = '*';
                                }
                            }
                        }   
                    }
                }
            }
        }
        bool flag = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(canvas[i][j] != new_canvas[i][j]){
                    flag = false;
                }
            }
        }
        cout << ((flag) ? "YES" : "NO") << "\n";
    }


    return 0;
}
