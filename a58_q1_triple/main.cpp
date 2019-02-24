#include <iostream>

using namespace std;

int main()
{
    int n, m, q, pairSum;
    cin>>n>>m;
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &q);
        bool check = false;
        for(int j = 0; j < n; j++){
            pairSum = q - arr[j];
            int select1 = j+1, select2 = n-1;
            while(select1 < select2){
                if(arr[select1] + arr[select2] > pairSum) select2--;
                else if(arr[select1] + arr[select2] < pairSum) select1++;
                else{
                    printf("YES\n");
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        if(!check) printf("NO\n");
    }
    return 0;
}
