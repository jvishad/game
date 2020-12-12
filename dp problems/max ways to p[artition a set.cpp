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

//long long dp[1000006];

void solve()
{
    long long n;
    cin>>n;
    int dp[n+1][n+1];
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int k =1;k<=i;k++){
            if(k == 1){
                dp[i][k] = 1;
            }
            if(i == k){
                dp[i][k] = 1;
            }
            else {
                dp[i][k] = (dp[i - 1][k] * k) + (dp[i - 1][k - 1]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[n][i];
    }
    cout<< ans<< endl;
}
//k*S(n, k) + S(n, k-1)
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(10);
    int t = 1;
     cin>>t;
//    int tc = 0;
    while(t--) {
        solve();
    }
}
//those who do not remember past are condemned to repeat it.