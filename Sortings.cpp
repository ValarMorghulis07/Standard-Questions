// Merge sort

void merge(int arr[], int l, int m, int r)
{
 int n1=m-l+1,n2=r-m;
 int L[n1],R[n2];
 for(int i=0;i<n1;i++)
  L[i]=arr[i+l];
 for(int i=0;i<n2;i++)
  R[i]=arr[m+1+i];
 int p=0,q=0,k=l;
 while(p<n1 && q<n2)
 {
  if(L[p]<=R[q])
  {
   arr[k++]=L[p];
   p++;
  }
  else
  {
    arr[k++]=R[q];
    q++;
  }
 }
 while(p<n1)
  arr[k++]=L[p++];
 while(q<n2)
  arr[k++]=R[q++];

}

void mergsort(int arr[],int l,int r)
{
 if(l<r)
 {
  int mid=(l+r)>>1;
  mergesort(arr,l,mid);
  mergesort(arr,mid+1,r);
  merge(arr,l,mid,r);
 }
}
