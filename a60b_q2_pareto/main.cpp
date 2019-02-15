#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int x, y, maxY = 0, count = 0;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    for(auto p: v){
        if(p.second > maxY){
            count++;
            maxY = p.second;
        }
    }
    cout<<count;
    return 0;
}
