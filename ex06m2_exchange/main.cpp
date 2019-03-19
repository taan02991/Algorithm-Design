#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    double D[505][505];
    for(int t = 0; t < n; t++){
        int Size;
        cin>>Size;
        for(int i = 0; i < Size; i++){
            for(int j = 0; j < Size; j++){
                scanf("%lf", &D[i][j]);
            }
        }
        for(int k = 1; k < Size; k++){
            for(int i = 0; i < Size; i++){
                for(int j = 0; j < Size; j++){
                    D[i][j] = max(D[i][j], D[i][k]*D[k][j]);
                }
            }
        }
        int check = 0;
        for(int i = 0; i < Size; i++){
            if(D[i][i] > 1){
                check = 1;
                printf("YES\n");
                break;
            }
        }
        if(!check) printf("NO\n");
    }
    return 0;
}
