#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//void qsort(int a[],int n,sizeof(int),compare);
int compare(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
main()
{
    int n,k,t=0;
    cin>>n>>k;
    int a[n];
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    qsort(a,n,sizeof(int),compare);
    for(i=n-1;i>=0;i-=k)
        t+=a[i];
    cout<<t;

}
