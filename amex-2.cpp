#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n]={0};
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		
		for(ll i=0;i<n;i++){
			if(arr[i]%2==0){
				while(arr[i]%2!=1){
					arr[i]/=2;
				}
			}
		}
		
		sort(arr,arr+n);
		for(ll i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		
		ll mnans=INT_MAX;
		for(ll i=0;i<n-1;i++){
			ll mn1 = abs(arr[i]-arr[i+1]);
			cout<<"mn1 ->> "<<mn1<<endl;
			ll mn2,mn3;
			ll value = 2*arr[i];
			cout<<"value ->> "<<value<<endl;
			if(value>arr[n-1]){
				mn2 = abs(value-arr[n-1]);
				mn3 = INT_MAX;
			}
			else{
				ll f = i+1;
				ll l = n-1;
				ll ans=0,index=-1;
				while(f<=l){
					cout<<"f ->> "<<f<<endl;
					cout<<"l ->> "<<l<<endl;
					ll m = (f+l)/2;
					cout<<"m ->> "<<m<<endl;
					if(value<arr[m]){
						l = m - 1;
						ans = arr[m];
						index = m;
					}
					else{
						f = m + 1;
					}
				}
				cout<<"Ans BS - >> "<<ans<<endl;
				cout<<"index ->> "<<index<<endl;
				mn2 = abs(value - ans);
				if(index-1 == i){
					mn3 = INT_MAX;
				}
				else{
					mn3 = abs(value - arr[index-1]);
				}
			}
			
			cout<<"mn1 ->> "<<mn1<<endl;
			cout<<"mn2 ->> "<<mn2<<endl;
			cout<<"mn3 ->> "<<mn3<<endl;
			
			ll x = min(mn2 , mn3);
			ll mn = min(mn1 , x);
			mnans = min(mnans , mn);
		}
		cout<<"Final Answer  - > "<<mnans<<endl;
	}
	return 0;
}
