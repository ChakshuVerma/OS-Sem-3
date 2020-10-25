#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
      int c,i,j,k,n,l,m[10],p[10],po[20],flag,z,y,temp,temp1;
      cout<<"-----------------------------------------MEMORY MANAGEMENT------------------------------------------"<<endl<<endl;
      cout<<"Enter number of memory partitions : ";
      cin>>n;
      cout<<endl;
      for(i=1;i<=n;i++)
      {
        cout<<"Memory Size For Partition "<<i<<" :\t";
        cin>>m[i];
        po[i]=i;
      }

      cout<<"\nEnter number of processes : \t";
      cin>>j;
      cout<<endl;
      for(i=1;i<=j;i++)
      {
        cout<<"Memory Size For Process "<<i<<" :\t";
        cin>>p[i];
      }
      cout<<"\n\n1.First fit\n2.Best fit\n3.Worst fit\nEnter your choice:\t";
      cin>>c;
      switch(c)
      {
        case 1:
                for(i=1;i<=j;i++)
                {
                    flag=1;
                    for(k=1;k<=n;k++)
                    {
                        if(p[i]<=m[k])
                        {
                            cout<<"\nProcess "<<i<<" with memory size "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
                            m[k]=m[k]-p[i];
                            break;
                        }
                        else
                        {
                            flag++;
                        }
                    }
                    if(flag>n)
                    {
                        cout<<"\nProcess "<<i<<" with memory size "<<p[i]<<"KB can't be allocated";
                    }
                }
                break;
        case 2:
                for(y=1;y<=n;y++)
                {
                    for(z=y;z<=n;z++)
                    {
                        if(m[y]>m[z])
                        {
                              temp=m[y];
                              m[y]=m[z];
                              m[z]=temp;
                              temp1=po[y];
                              po[y]=po[z];
                              po[z]=temp1;
                        }
                    }
                }
                  for(i=1;i<=j;i++)
                  {
                        flag=1;
                        for(k=1;k<=n;k++)
                        {
                            if(p[i]<=m[k])
                            {
                                cout<<"\nProcess "<<i<<" with memory size "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
                                m[k]=m[k]-p[i];
                                break;
                            }
                            else
                            {
                                flag++;
                            }
                        }
                        if(flag>n)
                        {
                            cout<<"\nProcess "<<i<<" with memory size "<<p[i]<<"KB can't be allocated";
                        }
                }
                break;
          case 3:
                for(y=1;y<=n;y++)
                {
                    for(z=y;z<=n;z++)
                    {
                        if(m[y]<m[z])
                        {
                              temp=m[y];
                              m[y]=m[z];
                              m[z]=temp;
                              temp1=po[y];
                              po[y]=po[z];
                              po[z]=temp1;
                        }
                    }
                }
                for(i=1;i<=j;i++)
                {
                    flag=1;
                    for(k=1;k<=n;k++)
                    {
                        if(p[i]<=m[k])
                        {
                            cout<<"\nProcess "<<i<<" with memory size "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
                            m[k]=m[k]-p[i];
                            break;
                        }
                    else
                        {
                            flag++;
                        }
                    }
                    if(flag>n)
                    {
                        cout<<"\nProcess "<<i<<" with memory size "<<p[i]<<"KB can't be allocated";
                    }
                }
                break;
        default:cout<<"\n\nINVALID INPUT !!!!!!!!!!!!!!! ";
        }
        cout<<endl<<endl;
      return 0;
}
