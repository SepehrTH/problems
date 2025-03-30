#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;

#define MP make_pair
#define F first
#define S second
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define ms(x,y) memset (x, y, sizeof (x))
#define pb push_back
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define VecPrnt(v) for(auto i: v) cout<<i<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 2e5 + 5 , mod = 1e9 + 7;
int r, g, h, dp[maxn], ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> g;

    while(h * (h + 1) / 2 <= r+g)
        h++;
    h--;
    int sum = h*(h+1)/2;

    dp[0] = 1;
    
    for(int i = 1; i <= h; i++)
        for(int j = min(r,g); j >= i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= mod;
        }

    for (int i=max(0, sum-max(r,g)); i<=min(r,g); i++){
        ans = (ans + dp[i]) % mod;
	}
	prnt(ans);


    return 0;
}
