#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector <pair<ll,ll> > p;
		ll x[n],b[n];
		for(ll i=0;i<n;i++){
			cin>>x[i];
		}
		for(ll i=0;i<n;i++){
			cin>>b[i];
		}
		for(ll i=0;i<n;i++){
			p.push_back(make_pair(b[i],x[i]));
		}
		sort(p.begin() , p.end());
		sort(b,b+n);
		if(n!=1){
			vector <ll> v;
			for(ll i=0;i<n;i++){
				v.push_back(p[i].second);
			}

			ll diff[n]={0};
			for(ll i=1;i<n;i++){
				diff[i-1]=abs(v[i]-v[i-1]);
				diff[i-1]%=mod;
			}
			ll arr[n]={0};
			for(ll i=n-2;i>=0;i--){
				arr[i] = diff[i]%mod+arr[i+1]%mod;
			}
			
			for(ll i=0;i<n;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			ll sum[n]={0};
			for(ll i=n-2;i>=0;i--){
				sum[i] = (arr[i]%mod+sum[i+1]%mod)%mod;
				sum[i]%=mod;
			}
			
			for(ll i=0;i<n;i++){
				cout<<sum[i]<<" ";
			}
			cout<<endl;
			ll ans = 0;
			for(ll i=n-1;i>=1;i--){
				ll temp = ((sum[0]-sum[i])%mod - ((i * arr[i]%mod))%mod)*(b[i])%mod ;
				temp%=mod;
				ans+= temp;
				ans%=mod;
			}
			cout<<ans%mod<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}
