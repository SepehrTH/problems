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

const int maxn = 10001;
int t, n, u, q, a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--)
    {
        int val;
        int l = 0, r = 0;
        cin >> n >> u;
        ms(a, 0);
        for(int i = 0; i < u; i++)
        {
            cin >> l >> r >> val;
            a[l] += val;
            a[r+1] -= val;
        }
        for(int tmp = 0, i = 0 ; i < n; i++)
        {
            a[i]+=tmp;
            tmp = a[i];
        }
        cin >> q;
        for(int t, i = 0; i < q; i++)
        {
            cin >> t;
            prnt(a[t]);
        }
    }


    return 0;
}