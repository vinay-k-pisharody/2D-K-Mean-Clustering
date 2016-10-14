#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

class node
{
public:
    int id;
    float dim1;
    float dim2;
    void setdata(int n,float temp,float temp1)
    {
        id=n;
        dim1=temp;
        dim2=temp1;
    }
    void setdata(float temp,float temp1)
    {
        dim1=temp;
        dim2=temp1;
    }
};

int main()
{
    int n;
    cout<<"\nEnter number of nodes : ";
    cin>>n;
    node ele[n];
    float temp,temp1;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter values for node "<<i+1<<" : "<<endl;
        cout<<"\nEnter dimension 1 : ";
        cin>>temp;
        cout<<"\nEnter dimension 2 : ";
        cin>>temp1;
        ele[i].setdata(i+1,temp,temp1);
    }

    int k;
    cout<<"\nEnter number of clusters : ";
    cin>>k;

    node m[k];
    float dist[k][n];

    for(int i=0;i<k;i++)
    {
        cout<<"\nEnter mean "<<i+1<<" : ";
        cout<<"\nEnter dimension 1 : ";
        cin>>temp;
        cout<<"\nEnter dimension 2 : ";
        cin>>temp1;
        m[i].setdata(temp,temp1);
    }
    cout<<"\n";
start:
    cout<<"\n\nDistances :\n\n\t";
    for(int i=0;i<n;i++)
    {
        cout<<"("<<ele[i].dim1<<","<<ele[i].dim2<<")\t\t";
    }
    cout<<"\n";
    for(int i=0;i<k;i++)
    {
        cout<<"("<<m[i].dim1<<","<<m[i].dim2<<")\t";
        for(int j=0;j<n;j++)
        {
            dist[i][j]=sqrt(pow((m[i].dim1-ele[j].dim1),2)+pow((m[i].dim2-ele[j].dim2),2));
            cout<<dist[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
    //cout<<"\nDistances Calculated";
    int pointers[k];
    for(int i=0;i<k;i++)
    {
        pointers[i]=0;
    }
    //cout<<"\nPointers Initialised";

    node result[k][n];
    for(int i=0;i<n;i++)
    {
        //cout<<"\nelement : "<<ele[i].dim1<<" "<<ele[i].dim2;
        int minindex;
        int min=9999;
        for(int j =0;j<k;j++)
        {

            if(dist[j][i]<min)
            {
                minindex=j;
                min=dist[j][i];
            }
        }
        //cout<<"\nmin : "<<min;
        //cout<<"\nminindex : "<<minindex;
        int temp=pointers[minindex];
        //cout<<"\ntemp : "<<temp;
        result[minindex][temp]=ele[i];
        //cout<<"\nresult[minindex][pointers[minindex]] : "<<result[minindex][temp].dim1<<" "<<result[minindex][temp].dim2;
        pointers[minindex]+=1;
    }
    cout<<"\nClusters :";
    for(int i=0;i<k;i++)
    {
        cout<<"\n\nCluster "<<i+1<<endl;
        for(int j=0;j<pointers[i];j++)
        {
            cout<<result[i][j].id<<" -> "<<"("<<result[i][j].dim1<<" , "<<result[i][j].dim2<<")\t\t";
        }
    }

    cout<<"\n\nMeans : ";
    node mnew[k];
    for(int i=0;i<k;i++)
    {
        int sum1=0,sum2=0;
        for(int j=0;j<pointers[i];j++)
        {
            sum1=sum1+result[i][j].dim1;
            sum2=sum2+result[i][j].dim2;
        }
        mnew[i].dim1=(float)sum1/(pointers[i]);
        mnew[i].dim2=(float)sum2/(pointers[i]);
        cout<<"("<<mnew[i].dim1<<" , "<<mnew[i].dim2<<")\t\t";
    }
    cout<<"\n______________________________________________________________________________________________________________________________________________\n";
    int sumc=0;
    for(int i=0;i<k;i++)
    {
        if(m[i].dim1==mnew[i].dim1)
        {
            sumc++;
        }
    }
    if(sumc==k)
    {
        return 0;
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            m[i]=mnew[i];
        }
        goto start;
    }

    return 0;
}
