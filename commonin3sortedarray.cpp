//find common elements in 3 sorted arrays
#include<bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int i=0;
    int j=0;
    int k=0;
    int n=a.size();
    int l=b.size();
    int m=c.size();
    vector<int>ans;
    while(i<n &&  j<l && k<m){
        if(a[i]==b[j] && a[i]==c[k]){
            if(ans.size()==0 || ans.back()!=a[i])
                ans.push_back(a[i]);
            i++;j++;k++;
        }
        else if((a[i]==b[j] && a[i]>c[k]) || (c[k]<b[j] && c[k]<a[i])){
            k++;
        }
        else if((a[i]==c[k] && a[i]>b[j]) || (b[j]<a[i] && b[j]<c[k])){
            j++;
        }
        else if((c[k]==b[j] && c[k]>a[i]) || (a[i]<b[j] && a[i]<c[k])){
            i++;
        }
        else if(a[i]==b[j] && a[i]<c[k]){
            i++;j++;
        }
        else if(a[i]==c[k] && a[i]<b[j]){
            i++;k++;
        }
        else{
            j++;k++;
        }
    }
    return ans;
}
int main(){
    vector<int>arr1={1,4,5,6};
    vector<int>arr2={3,4,5};
    vector<int>arr3={5,6,7};
vector<int>ans=findCommonElements(arr1,arr2,arr3);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
}