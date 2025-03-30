#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;

#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define inf 1e9
#define INF 1e16
#define pb push_back
#define MAX 100005
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007LL
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=(b); i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(J,0,v.size()) cout<<v[J]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define EPS 1e-9
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};



bool ok(int q[], int col){
       
       for(int i=0;i<col;i++){ 
         if((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i))) 
         {   return false;
         }
       }
         return true;
    }

    void backtrack(int &col, int m, int n1){
        col--;
    
        if(col==-1){
           cout<<"There are "<<m<<" solutions of "<<n1<<" queens problem."<<endl;
           exit(1);
           }
    }

    
int main()
{     
    int n;
    cout<<"Enter the number of Queens for the solution: ";
    cin>>n;
    cout<<endl;
    int*  q = new int[n];
    int c=1,count=0;
    q[0]=0;
    //delete[]q;
    // from_backtrack keeps track if we need to reset the row to the
    // top of the current colum or not.

    bool from_backtrack=false;
    // The outer loop keep looking for solutions
    // The program terminates from function backtrack
    // when we are forced to backtack into column -1
    while(1){
        while(c<n)
        { //this loop goes across columns
            // if we just returned from backtrack, use current value of row
            // otherwise get ready to start at the top of this column
            if(!from_backtrack) // we did not just return from backtrack
            q[c]=-1;   //check here
            from_backtrack=false;
                while(q[c]<n){ // place queen in this column
                    q[c]++;
                  // if row=8, there is no valid square in this column
                    // so backtrack and continue the loop in the previous column
                    while(q[c]==n)
                    {
                        backtrack(c, count, n);
                        q[c]++;
                    }
                    //if this position is ok, place the queen
                    // and move on (break) to the next column,
                    // otherwise keep looking in this column
                 
                    if(ok(q, c))
                        break;
                                   
            }// while q[c]<8
          c++; // placed ok, move to the next column
     }//while(c<8)
     // one complete solution found, print it.
     //print(q); // board completed, print it out
     count++;
     
     backtrack(c, count, n);
     from_backtrack=true;
    }
           
}
             