#include <iostream>

using namespace std;


void S(int x, int y, int c, int r, int n){
    int mx = c + n/2, my = r + n/2;
    if(n == 1) return;
//    S(x, y, c, r, n/2);
//    S(x, y, c + n/2, r, n/2);
//    S(x, y, c, r + n/2, n/2);
//    S(x, y, c + n/2, r + n/2, n/2);
//
//    S(mx - 1, my - 1, c, r, n/2);
//    S(mx, my - 1, c + n/2, r, n/2);
//    S(mx - 1, my, c, r + n/2, n/2);
//    S(mx, my, c + n/2, r + n/2, n/2);
    else{
        if(x < mx && y < my){
            S(x, y, c, r, n/2);
            S(mx, my - 1, c + n/2, r, n/2);
            S(mx - 1, my, c, r + n/2, n/2);
            S(mx, my, c + n/2, r + n/2, n/2);
            printf("%d %d %d\n", 0, mx-1, my-1);
        }
        else if(x >= mx && y < my){
            S(x, y, c + n/2, r, n/2);
            S(mx - 1, my - 1, c, r, n/2);
            S(mx - 1, my, c, r + n/2, n/2);
            S(mx, my, c + n/2, r + n/2, n/2);
            printf("%d %d %d\n", 1, mx-1, my-1);
        }
        else if(x < mx && y >= my){
            S(mx - 1, my - 1, c, r, n/2);
            S(mx, my - 1, c + n/2, r, n/2);
            S(x, y, c, r + n/2, n/2);
            S(mx, my, c + n/2, r + n/2, n/2);
            printf("%d %d %d\n", 2, mx-1, my-1);
        }
        else{
            S(x, y, c + n/2, r + n/2, n/2);
            S(mx - 1, my - 1, c, r, n/2);
            S(mx, my - 1, c + n/2, r, n/2);
            S(mx - 1, my, c, r + n/2, n/2);
            printf("%d %d %d\n", 3, mx-1, my-1);
        }
    }
}

int main(){
    int x, y, n;
    cin>>n>>x>>y;
    cout<<(n*n-1)/3<<endl;
    S(x, y, 0, 0, n);
}
