#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(ll i=0;i<k;i++){
			char x;
			cin>>x;
		}
		ll arr[n+1] = {0};
		ll a,b,x,y;
		a = k*(26-k)*k;
		b = k*(k-1)*(k-1);
		x = (k-1)*(k-1);
		y = (26-k)*k;
		arr[1] = k;
		arr[2] = k*25;
		arr[3] = a + b;
		for(ll i=4;i<=n;i++){
			if(i%2==0){
				arr[i]=((arr[i-1]%mod)*25)%mod;
			}
			else{
				arr[i]=((a%mod+b%mod)%mod)*((x%mod+y%mod)%mod);
				a = ((a%mod)*(x%mod))%mod + ((a%mod)*(y%mod))%mod;
				b = (b%mod)*(x%mod)%mod + ((b%mod)*(y%mod))%mod;
				a%=mod;
				b%=mod;
			}
		}
		for(ll i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		cout<<arr[n]%mod<<endl;
	}
	return 0;
}
