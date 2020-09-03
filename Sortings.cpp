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

// Quick Sort

int partition (int arr[], int low, int high)
{
 int pivot=arr[high];
 int i=low-1;
 for(int j=low;j<high;j++)
 {
  if(arr[j]<pivot)
  {
   i++;
   swap(arr[i],arr[j]);
  }
 }
 swap(arr[i+1],arr[high]);
 return i+1;
}

void quicksort(int arr[],int low,int high)
{
 if(low<high)
 {
  int pi=partition(arr,low,high);
  quicksort(arr,low,pi-1);
  quicksort(arr,pi+1,high);
 }
}

// Selection sort --> It is both either u bring maximum element int the elast or minimum element int he beginning

void selectionSort(int arr[], int n)
{
   for(int i=0;i<n-1;i++)
   {
    int idx=i;
    for(int j=i+1;j<n;j++)
    {
     if(arr[j]<arr[idx])
      idx=j;
    }
    swap(arr[i],arr[idx]);
   }
}
