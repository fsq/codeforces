#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 210
inline int read()
{
    int x=0,t=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-'){t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*t;
}
struct Line
{
       int v,next;
}e[10*MAX*MAX];
int h[MAX],cnt=1;
int vis[MAX],dep;
int match[MAX],N,sum=0,a;
inline void Add(int u,int v)
{
       e[cnt]=(Line){v,h[u]};
       h[u]=cnt++;
}
bool DFS(int x)
{
       for(int i=h[x];i;i=e[i].next)
       {
             int v=e[i].v;
             if(vis[v]!=dep)
             {
                   vis[v]=dep;
                   if(!match[v]||DFS(match[v]))
                   {
                        match[v]=x;
                        return true;
                   }
             }
       }
       return false;
}

int main()
{
     int T=read();
     while(T--)
     {
           N=read();
           sum=0;
           cnt=1;
           for(int i=1;i<=N;++i)match[i]=vis[i]=h[i]=0;
           for(int i=1;i<=N;++i)
           {
                 for(int j=1;j<=N;++j)
                 {
                         a=read();
                         if(a)
                            Add(i,j);
                 }
           }

           for(dep=1;dep<=N;++dep)
                  if(DFS(dep))++sum;
           if(sum==N)
                 cout<<"Yes"<<endl;
           else
                 cout<<"No"<<endl;
     }

}