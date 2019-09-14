// A Dynamic Programming based solution that uses 
// table C[][] to calculate the Binomial Coefficient 
#include<bits/stdc++.h> 
#define ll long long
using namespace std; 

// Prototype of a utility function that 
// returns minimum of two llegers 
ll min(ll a, ll b); 

// Returns value of Binomial Coefficient C(n, k) 
ll binomialCoeff(ll n, ll k) 
{ 
	ll C[n + 1][k + 1]; 
	ll i, j; 

	// Caculate value of Binomial Coefficient 
	// in bottom up manner 
	for (i = 0; i <= n; i++) 
	{ 
		for (j = 0; j <= min(i, k); j++) 
		{ 
			// Base Cases 
			if (j == 0 || j == i) 
				C[i][j] = 1; 

			// Calculate value using previously 
			// stored values 
			else
				C[i][j] = C[i - 1][j - 1] + 
						C[i - 1][j]; 
		} 
	} 

	return C[n][k]; 
} 

// A utility function to return 
// minimum of two llegers 
ll min(ll a, ll b) 
{ 
	return (a < b) ? a : b; 
} 

// Driver Code 
int main() 
{ 
	ll t;
	cin>>t;
	while(t--){
		ll n,r;
		cin>>n>>r;
		cout << "Value of C[" << n << "]["<< r << "] is " << binomialCoeff(n, r); 
	}
} 

// This code is contributed by Shivi_Aggarwal 

