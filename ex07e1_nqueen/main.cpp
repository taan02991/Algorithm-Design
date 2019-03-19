#include <iostream>
#include <vector>

using namespace std;

int n;

bool valid(int i, int j, vector<pair<int, int>> pos){
    for(auto p: pos){
        int dx = p.first - i, dy = p.second - j;
        if(abs(dx) == abs(dy)) return false;
        if(i == p.first) return false;
        if(j == p.second) return false;
    }
    return true;
}

int Q(vector<pair<int, int>> pos, int row){
    if(row == n) return 1;
    int count = 0;
    for(int col = 0; col < n; col++){
        if(valid(row, col, pos)){
            pos.push_back({row, col});
            count += Q(pos, row + 1);
            pos.erase(pos.end()-1);
        }
    }
    return count;
}

int main()
{
    cin>>n;
    vector<pair<int, int>> pos;
    cout<<Q(pos, 0);
    return 0;
}
