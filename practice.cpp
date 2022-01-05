#include<bits/stdc++.h> 
using namespace std;    
#define ll long long    
#define pb push_back    	
#define S second            
#define F first         	
#define for1(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define precise(x) fixed << setprecision(x) 
#define mod 1000000007  	
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{	
    return (a.second < b.second);
}	
ll int a[5001];
ll int b[5001];	
ll int dp[5001][5001];
ll f(int i,int j){
    if(i>j){
        return dp[i][j]=0;
    }
    else if(j==i){
        return dp[i][j]=a[i]*b[i];
    }
    else if(j-1==i){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
        return dp[i][j]=a[i]*b[j] + a[j]*b[i];}
    }
    else{
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else {
            if(dp[i+1][j-1]!=-1){
               return dp[i][j]=dp[i+1][j-1] + a[i]*b[j] + a[j]*b[i];
            }
            else{
                 return dp[i][j]=f(i+1,j-1) + a[i]*b[j] + a[j]*b[i];
            }
        }
       
    }
}
void solve()
{
    ll int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    a[0]=0;
    b[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    ll int sum[n+1];
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1] + a[i]*b[i];
    }
    ll b;ll max1=sum[n];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
          b=f(i,j) + sum[i-1] + sum[n]-sum[j];
          //cout<<b<<" "<<i<<" "<<j<<endl;
          if(b>max1){
              max1=b;
          }   
        }
    }
    cout<<max1<<endl;
}
int main()
{
    fast;
    
        solve();
    
}
