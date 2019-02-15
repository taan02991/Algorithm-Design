#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main(){
    map<int, int> count;
    int range[3][3] = {};
    int n, ans = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }
    for(int i = 0; i < count[1]; i++) range[0][arr[i]-1]++;
    for(int i = count[1]; i < count[1] + count[2]; i++) range[1][arr[i]-1]++;
    for(int i = count[1] + count[2]; i < n; i++) range[2][arr[i]-1]++;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(i == j) continue;
            if(range[i][j] != 0){
                int temp = min(range[i][j], range[j][i]);
                ans += temp;
                range[i][i] += temp;
                range[i][j] -= temp;
                range[j][j] += temp;
                range[j][i] -= temp;
                for(int k = 0; k < 3; k++){
                    if(k != i && k != j){
                        int temp = min(range[i][j], range[k][i]);
                        ans += temp;
                        range[i][i] += temp;
                        range[i][j] -= temp;
                        range[k][j] += temp;
                        range[k][i] -= temp;
                    }
                }
            }
        }
    }
    cout<<ans;
}
