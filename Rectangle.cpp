#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	/* to enter the number of times the sides to be checked out*/
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{ 
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		
		/* conditions for quad to be rectangle */
		
		
		if((a==b && d==c) || (a==c && b==d) || (a==d && b==d))
		{
			cout<<"YES";
		}
		else cout<< "NO" << endl;
	}
	
}
