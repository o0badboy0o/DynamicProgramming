#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

int dp[100][100];

int knapsack(vpii a,int n,int w)
{
    if(n==0 || w==0) return dp[n][w]=0;

    if(a[n].s>w) return dp[n][w]=knapsack(a,n-1,w);

    return dp[n][w]=max( knapsack(a,n-1,w) , a[n].f+knapsack(a,n-1,w-a[n].s) );
}

void solve()
{
    int n,w;
    cin>>n;
    vpii a(n+1);

    for(int i=1;i<=n;i++) cin>>a[i].f;
    for(int i=1;i<=n;i++) cin>>a[i].s;

    cin>>w;

    mem(dp,0);
    cout<<knapsack(a,n,w);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}