/*               BEST             AVG            WORST
Selection Sort	  Ω(n^2)	        θ(n^2)	          O(n^2)
Bubble Sort	     Ω(n)	          θ(n^2)	          O(n^2)
Insertion Sort  	Ω(n)	          θ(n^2)	          O(n^2)
Heap Sort	       Ω(n log(n))	   θ(n log(n))	     O(n log(n))
Quick Sort	      Ω(n log(n))	   θ(n log(n))	     O(n^2)
Merge Sort	      Ω(n log(n))	   θ(n log(n))	     O(n log(n))
Bucket Sort	     Ω(n+k)	        θ(n+k)	          O(n^2)
Radix Sort	      Ω(nk)	         θ(nk)	           O(nk)
*/


// Merge sort

/*
Time complexity: O(n*logn)
Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation
Stable: Yes
*/

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

/*
Is QuickSort stable?
The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes as comparison parameter.
Is QuickSort In-place?

As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function calls but 
not for manipulating the input.
*/

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

// Selection sort --> It is both either u bring maximum element int the last or minimum element int he beginning

void selectionSort(int arr[], int n) // --> bringing min element at first
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

// Bubble Sort(Repeatedly swapping adjacent elements,sending max element at last in consecutive loops)

/*
Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes
*/

void bubble(int arr[], int i, int n)
{
 bool ff=1;
 for(int i=0;i<n-1;i++)
 {
 for(int j=0;j<n-i-1;j++)
 {
  if(arr[j]>arr[j+1])
   swap(arr[j],arr[j+1]),ff=0;
 }
  if(ff)
    break;
 }
}

// Insertion Sort-->Values from the unsorted part are picked and placed at the correct position in the sorted part, Just like Cards

/*
Time Complexity: O(n*2)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes (It means does not require extra space)
Stable: Yes
*/

void insert(int arr[], int i)
{
 for(int i=1;i<n;i++)
 {
 int temp=arr[i];
 int j=i-1;
 while(j>=0 && arr[j]>temp)
 {
  arr[j+1]=arr[j];
  j--;
 }
 arr[j+1]=temp;
 }
}

// Heap Sort

/*
Heap sort is an in-place algorithm.
Its typical implementation is not stable, but can be made stable.
*/

void heapify(int arr[], int n, int i) // log(n)
{
 int largest=i;
 int l=2*i+1;
 int r=2*i+2;
 if(l<n && arr[l]>arr[largest])
  largest=l;
 if(r<n && arr[r]>arr[largest])
  largest=r;
 if(i!=largest)
 {
  swap(arr[i],arr[largest]);
  heapify(arr,n,largest);
 }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  // O(n)
{ 
 for(int i=n/2-1;i>=0;i--)// build the heap;
  heapify(arr,n,i);
 for(int i=n-1;i>0;i--)
 {
  swap(arr[i],arr[0]);// send largest element to last index then shrink the array
  heapify(arr,i,0);// now heapify the remaining array
 }
}

// Quick select--> Quickselect is a selection algorithm to find the k-th smallest element in an unordered list


ll partition(ll a[],ll l,ll r)
{
 ll pivot=a[r],i=l;
 for(ll j=l;j<r;j++)
 {
  if(a[j]<=pivot)
  {
   swap(a[i],a[j]);
   i++;
  }
 }
 swap(a[i],a[r]);
 return i;
}
ll doit(ll a[],ll l,ll r,ll k)
{
 if(k>0 && k<=r-l+1)
 {
  ll idx=partition(a,l,r);
  if(idx-l==k-1)
   return a[idx];
  else if(idx-l>k-1)
   return doit(a,l,idx-1,k);
  else
   return doit(a,idx+1,r,k-idx-1+l);
 }
 return -1;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
 ll n,k;
 cin>>n>>k;
 ll a[n];
 rep(i,0,n)
  cin>>a[i];
 cout<<doit(a,0,n-1,k)<<"\n";
 }
 return 0;
}


