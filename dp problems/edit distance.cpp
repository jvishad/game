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


void solve() {
    string s1,s2;
    cin>>s1 >> s2;
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j =0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(i==0){
                dp[i][j] = j;
            }
            if(j == 0){
                dp[i][j] = i;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] =  1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
    }
//    for(int i=0;i<=m;i++){
//        for(int j=0;j<=n;j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << dp[m][n] << endl;
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