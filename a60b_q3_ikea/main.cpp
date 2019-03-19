#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> g(n+1);
    int buildOrder[n];
    for(int i = 1; i <= e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[b].push_back(a);
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n; j++){
            int temp;
            scanf("%d", &temp);
            buildOrder[temp] = j;
        }
        int check = 1;
        for(int first = 1; first < g.size(); first++){
            for(auto second: g[first]){
                if(buildOrder[second] > buildOrder[first]){
                    printf("FAIL\n");
                    check = 0;
                    break;
                }
            }
            if(!check) break;
        }
        if(check) printf("SUCCESS\n");
    }
}
