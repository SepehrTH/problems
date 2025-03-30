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

int ans = 0;
string s;
vector<char> v;

int check(char t)
{
    if((t == '>' || t == ')' || t == '}' || t == ']') && (v[v.size()-1] == '<' || v[v.size()-1] == '(' || v[v.size()-1] == '{' || v[v.size()-1] == '['))
    {
        if(t==char(v.back()+1) || t==char(v.back()+2))
            return 0;
        else
        {
            // debug(t, char(v.back()+2));
            return 1;
        }
    }
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    v.pb(s[0]);
    for(int i = 1; i < s.size(); i++)
    {
        int tmp = check(s[i]);
        if(tmp != -1)
        {
            v.pop_back();
            ans+=tmp;
        }
        else    v.pb(s[i]);
    }
    if(!v.empty())
        prnt("Impossible");
    else
        prnt(ans);


    return 0;
}
