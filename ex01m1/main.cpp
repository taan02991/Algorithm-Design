#include <iostream>

using namespace std;

void tiling(int n, int i, int j, int x, int y){
    if(n == 2){
        if(i == x && j == y) cout<<"0 ";
        else if(i == x+1 && j == y) cout<<"1 ";
        else if(i == x && j == y+1) cout<<"2 ";
        else if(i == x+1 && j == y+1) cout<<"3 ";
        cout<<x<<" "<<y<<"\n";
        return;
    }
    if(i < x + n/2 && j < y + n/2){
        tiling(n/2, i, j, x, y);
        tiling(n/2, x + n/2, y + n/2 -1, x + n/2, y);
        tiling(n/2, x + n/2 - 1, y + n/2, x, y + n/2);
        tiling(n/2, x + n/2, y + n/2, x + n/2, y +n/2);
        cout<<"0 ";
    }
    else if(i >= x + n/2 && j < y + n/2){
        tiling(n/2, x + n/2 - 1, y + n/2 - 1, x, y);
        tiling(n/2, i, j, x + n/2, y);
        tiling(n/2, x + n/2 - 1, y + n/2, x, y + n/2);
        tiling(n/2, x + n/2, y + n/2, x + n/2, y +n/2);
        cout<<"1 ";
    }
    else if(i < x + n/2 && j >= y + n/2){
        tiling(n/2, x + n/2 - 1, y + n/2 - 1, x, y);
        tiling(n/2, x + n/2, y + n/2 -1, x + n/2, y);
        tiling(n/2, i, j, x, y + n/2);
        tiling(n/2, x + n/2, y + n/2, x + n/2, y +n/2);
        cout<<"2 ";
    }
    else if(i >= x + n/2 && j >= y + n/2){
        tiling(n/2, x + n/2 - 1, y + n/2 - 1, x, y);
        tiling(n/2, x + n/2, y + n/2 -1, x + n/2, y);
        tiling(n/2, x + n/2 - 1, y + n/2, x, y + n/2);
        tiling(n/2, i, j, x + n/2, y +n/2);
        cout<<"3 ";
    }
    cout<<x + n/2 - 1<<" "<<y + n/2 -1<<"\n";
}

int main()
{
    int n, i, j;
    cin>>n>>i>>j;
    cout<<(n*n - 1)/3<<"\n";
    tiling(n, i, j, 0, 0);
}
