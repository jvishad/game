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
//solved using left right strategy which give same ans as in the ohter trick.
//which is cut strategy bcz we can mathematically prove that both are same by meaning
int dp[10001] = {0};

void solve() {
    int n;
    cin>>n;
    int price[n+1];
    price[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = 0;
    }
    dp[0] = 0;
    dp[1] = price[1];
    for(int i=2;i<=n;i++){
        dp[i] = price[i];
        int li = 1;
        int ri = i-1;
        while(li <= ri){
            dp[i] = max(dp[i],dp[li] + dp[ri]);

            li++;
            ri--;
        }
    }

    cout <<  dp[n] << endl;
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

//input -
//8
//1 5 8 9 10 17 17 20

//output - 22