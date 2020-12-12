#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
    int n,m;
    cin>>n>>m;
//    for(int i=0;i<n+1;i++){
//        for(int j=0;j<m+1;j++){
//            dp[i][j] = 0;
//        }
//    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dp[i][j];
        }
    }

    for(int c = n-1;c>= 0; c--){
        for(int r = 0;r<m;r++){

//            towards right
              int right = (c == n-1)? 0: dp[r][c+1];
//              towards rightdown
              int rightdown = (r == n-1 || c == n-1)? 0:dp[r+1][c+1];
//              towards rightup
              int rightup = (r == 0 || c == n-1) ? 0: dp[r-1][c+1];

              dp[r][c] = dp[r][c] + max(right,max(rightup,rightdown));
        }
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        ans = max(ans,dp[i][0]);
    }
    cout<<ans<< endl;
    return 0;
}