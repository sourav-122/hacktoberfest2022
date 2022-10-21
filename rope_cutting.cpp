#include<iostream>
using namespace std;

int max_of(int a, int b, int c){
    if(a > b && a > c) return a;
    else if(b > c) return b;
    else return c;
}

int rope_cuts(int n, int a, int b, int c){
    if(n==0) return 0;
    if(n<0) return -1;
    int r1 = rope_cuts(n-a, a, b, c);
    int r2 = rope_cuts(n-b, a, b, c);
    int r3 = rope_cuts(n-c, a, b, c);
    if(r1 == 0) cout << a << " ";
    if(r2 == 0) cout << b << " ";
    if(r3 == 0) cout << c << " ";
    int res = max_of(r1, r2, r3);
    if(res == -1) return -1;

    return res+1;

}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << rope_cuts(n, a, b, c);
    // cout << max_of(30, 10, 40);
    return 0;
}
