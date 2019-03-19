#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    double fTime = 0;
    cin>>n>>m;
    priority_queue<int, vector<int>, greater<int>> task, student;
    for(int i = 0; i < m; i++){
        int t;
        scanf("%d", &t);
        task.push(t);
    }
    for(int i = 0; i < n; i++) student.push(0);
    while(!task.empty()){
        int s, t;
        s = student.top(); student.pop();
        t = task.top(); task.pop();
        fTime += s;
        student.push(s + t);
    }
    while(!student.empty()){
        fTime += student.top(); student.pop();
    }
    printf("%.3f", fTime/m);
    return 0;
}
