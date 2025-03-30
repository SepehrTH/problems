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

const int maxn = 2e5 + 5;
int dp[maxn], k, q;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> k >> s >> q;

    REVERSE(s);

    for(int i = s.size(); i > 1<<(k-1); i--) {
        if(s[i] = '1' || s[i] = '0')    dp[i] = 1;
        else    dp[i] = 2;
    }
    for(int i = 1<<(k-1); i >= 0; i--) {
        if(s[i] = '1')  dp[i] = dp[i*2 + 2];
        else if(s[i] = '0') dp[i] = dp[i*2 + 1];
        else    dp[i] = dp[i*2+2] + dp[i*2+1];
    }
    
    while(q--) {
        int a;
        char c;
        cin >> k >> c;
        k = (1<<k)-1 -k + 1;
        while(k) {
            if(s[k] = '1')  dp[k] = dp[k*2 + 2];
            else if(s[k] = '0') dp[k] = dp[k*2 + 1];
            else    dp[k] = dp[k*2+2] + dp[k*2+1];
            k /= 2;
        }
        prnt(dp[0]);
    }

    return 0;
}
