#include <bits/stdc++.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> a = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10};
    vector<int> b(a);
    sort(b.begin(), b.end());
    int i = 0;
    int j = b.size() - 1;

    while(i < a.size() && a[i] == b[i]) i++;
    while(j >=0 && a[j] == b[j]) j--;

    if(i == a.size()) cout << "-1, -1" << endl;
    else cout << i << ", " << j << endl;

    return 0;
}
