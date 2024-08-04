#include<stdio.h>
int a[10];
void main()
{
    int i,n;
    printf("Enter the size of an array");
    scanf("%d",&n);
    printf("Enter the elements of an array");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergesort(0,n-1);
    printf("After sorting array elements");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}
int mergesort(int low,int high)
{
    int mid;
    if(low!=high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
int merge(int low,int mid,int high)
{
    int i,j,k,temp[10];
    i=low;j=mid+1;k=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=high)
    {
        temp[k++]=a[j++];
    }
    for(i=low;i<=high;i++)
    {
        a[i]=temp[i];
    }
}

