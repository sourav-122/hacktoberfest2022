#include<bits/stdc++.h>
using namespace std;
int medianMatrix(vector<vector<int> > mat,int n,int m)
{
	int mn=INT_MAX,mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(mat[i][0]<mn)
		mn=mat[i][0];
		if(mat[i][m-1]>mx)
		mx=mat[i][m-1];
	}
	int desired=(n*m+1)/2;
	while(mn<mx)
	{
		int mid=mn+(mx-mn)/2;
		int ct=0;
		for(int i=0;i<n;i++)
		ct+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
		if(ct<desired)
		mn=mid+1;
		else
		mx=mid;
	}
	return mn;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > mat;
	for(int i=0;i<n;i++)
	{
		vector<int> t;
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			t.push_back(x);
		}
		mat.push_back(t);
	}
	int ans=medianMatrix(mat,n,m);
	cout<<ans<<endl;
	return 0;
}
