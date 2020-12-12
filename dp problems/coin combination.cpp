#include <bits/stdc++.h>
#include<math.h>
#include<climits>
#include<queue>
using namespace std;
#define ll long long
#define pb push_back
#define pbb pop_back()
#define mp make_pair
#define pl pair<ll,ll>
#define vl vector<ll>
#define mod 1000000007
#define INF 1000000000

int  dp[1000006] = {0};

void solve()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=x;j++){
            if(j - arr[i] >= 0) {
                dp[j] = (dp[j] + dp[j-arr[i]])%mod;
            }
            dp[j] = dp[j]%mod;
        }
    }
    cout<< dp[x] << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(10);
    int t = 1;
//    cin>>t;
//    int tc = 0;
    while(t--) {
        solve();

    }
}
//those who do not remember past are condemned to repeat it.