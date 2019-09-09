#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll countfactors(ll num){
	set <ll> s;
	for(ll i=1;i<=sqrt(num);i++){
		if(num%i==0){
			s.insert(i);
			s.insert(num/i);
		}
	}
	cout<<s.size()<<endl;
	return s.size();
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		ll fx[r-l+1] = {0};
		ll j=0;
		for(ll i=l;i<=r;i++){
			fx[j]=countfactors(i);
			j++;
		}
		
		for(ll i=0;i<r-l+1;i++){
			cout<<fx[i]<<" "<<endl;
		}
	}
}
