#include <iostream>
#include <algorithm>

using namespace std;

int n, x, y;
vector<pair<int, int>> v(100005);

vector<pair<int, int>> P(int i, int j){
    if(i == j) return {v[i]};
    int mid = (i+j)/2;
    vector<pair<int, int>> pL = P(i, mid);
    vector<pair<int, int>> pR = P(mid + 1, j);
    int MAX_Y = 0;
    for(auto c: pR) MAX_Y = max(MAX_Y, c.second);
    for(auto c: pL){
        if(c.second >= MAX_Y){
            pR.push_back(c);
        }
    }
    return pR;
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        v[i] = {x, y};
    }
    sort(v.begin(), v.begin() + n);
    cout<<P(0, n-1).size()<<endl;
    return 0;
}
