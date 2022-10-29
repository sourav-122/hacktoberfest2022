#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	cout<<"Enter a string\n";
	getline(cin, line);
	int n=line.size();
	int flag = 0;

	for(int i=0; i<n/2; i++)
	{
		if(line[i]!=line[n-1-i])
		{
			flag=1; break;
		}
	}

	if(flag==0) cout<<"\nEntered string is a palindrome";
	else cout<<"\nEntered string is not a palindrome";
}
