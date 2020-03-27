#include <bits/stdc++.h>

//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define INF 0x3F3F3F3F

using namespace std;
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const ll mod = 998244353;
const int phash = 3;
const ll modhash = 1000000000000000003;

string s[1005];
vector <int> posrow[1005][26],poscolumn[1005][26];
int p[1005][1005];
int pcolor[1000025];

int unite(int x)
{
    if (x==pcolor[x]) return x;
    else pcolor[x] = unite(pcolor[x]);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    for (int i=0;i<n;i++)
        cin >> s[i];

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            posrow[i][s[i][j]-'a'].push_back(j);
            poscolumn[j][s[i][j]-'a'].push_back(i);
        }


    int color = 1;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<26;k++)
        {
            if (posrow[i][k].size()<=2)
                for (int j:posrow[i][k])
                    p[i][j]=color++;
            if (posrow[i][k].size()==3)
            {
                p[i][posrow[i][k][0]] = p[i][posrow[i][k][2]] = color;
                p[i][posrow[i][k][1]] = color++;
            }

            if (posrow[i][k].size()==3)
            {
                for (int j:posrow[i][k])
                    p[i][j] = color;
                color++;
            }
        }
    }

    for (int i=0;i<m;i++)
    {
        for (int k=0;k<26;k++)
        {
            if (poscolumn[i][k].size()<=2)
            {
               for (int j:poscolumn[i][k])
                    if (p[j][i]==0)
                        p[j][i] = color++;
            }

            if (poscolumn[i][k].size()==3)
            {
                int x=poscolumn[i][k][0],y=poscolumn[i][k][2];
                if (p[x][i])
                {
                    if (p[y][i])
                    {
                        unite(p[x][i],p[y][i])
                    }
                    else p[y][i]=p[x][i];
                }
                else if (p[y][i])
                {
                    if (p[x][i])
                    {
                        unite(p[x][i],p[y][i])
                    }
                    else p[x][i]=p[y][i];
                }
                else
                {
                    p[x][i] = p[y][i] = color;
                }


            }

            if (poscolumn[i][k].size()==3)
            {

            }
        }
    }

}
