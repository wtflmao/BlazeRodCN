#include <iostream>
using namespace std;
int inf=0x3f3f3f3f,e[27][27],sum,book[28],dis[28],MIN,u,v,cnt;
int prim(int n)
{
  for(int i=1;i<=n;i++)dis[i]=e[1][i];
  for(int i=1;i<=n;i++)book[i]=0;
  sum=0;cnt=1;
  book[1]=1;
  while(cnt<n)
  {
  	MIN=inf;
  	for(int j=1;j<=n;j++)
	  if(book[j]==0&&dis[j]<MIN)
	  {
	    MIN=dis[j];
		u=j;
      }
    book[u]=1;cnt++;sum+=dis[u];
    for(int v=1;v<=n;v++)
      if(book[v]==0&&dis[v]>e[u][v])
	    dis[v]=e[u][v];
  }
}
int main(void)
{
  int ch;cin>>ch;
  while(ch!=0)
  {
  	int n,q;char k,p;
    for(int i=1;i<=ch;i++)
	  for(int j=1;j<=ch;j++)
	    if(i!=j)e[i][j]=inf;
		else e[i][j]=0;
  	for(int j=1;j<ch;j++)
  	{
  	  cin>>k>>n;
  	  for(int i=1;i<=n;i++)
  	  {
		cin>>p>>q;
		e[j][p-64]=q;
		e[p-64][j]=q;
	  }
    }
    prim(ch);
    cout<<sum<<endl;
    cin>>ch;
  }
  return 0;
}
