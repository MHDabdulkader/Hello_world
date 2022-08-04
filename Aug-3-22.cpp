#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define mod (int)1e9+7
ll POW(ll a,ll b){if(!b) return 1;ll r=POW(a,b/2);if(b%2) return r*r*a;else return r*r;}

bool ok(ll mid, vector<ll> v, ll n){
	ll cnt = 0;
	//cout << mid <<  " \n ";
	for(ll i = 0;i< n; i++){
		ll j = i+1;
		ll d = j*mid;
		//cout << max(0LL, v[i]-d) << " " << d << endl;
		if(max(0LL, v[i]-d) == 0){
			cnt++;
		}
	}
	if(cnt == n)return true;
	else return false;
}
void solve(){
	int tc;
	cin >> tc;
	while(tc--){
		ll n, p;
		cin >> n >> p;
		vector<ll> v;
		ll mx = 0;
		for(ll i = 0; i< n; i++){
			ll num; cin >> num;
			mx = max(mx, num);
			v.push_back(num);
		}
		ll cnt = 0;
		if(p == 0){
			cout << -1 << endl;
		}
		else {
			ll l = 1, r = p;
			ll dx = mx;
			while(dx > 1){
				dx/=p;
				cnt++;
			}
			r = POW(p, cnt);

			while(l+1<r){
				ll m = (l + r) / 2;
				if(ok(m, v, n)){
					r = m;
				}
				else l = m;
			}
			cout << r << endl;
		}
	}
	
}
int main(){
	#ifndef ONLINE_JUDGE 
        freopen("C:/Users/spykey/Documents/output.txt", "w", stdout);
		freopen("C:/Users/spykey/Documents/input.txt", "r", stdin);
    #endif
	
	solve();
}
