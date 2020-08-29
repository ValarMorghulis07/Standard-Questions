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
 
 // Along with down code it is complete heap sort programme
 /*for(int i=n-1;i>0;i--)
 {
  swap(arr[i],arr[0]);// send largest element to last index then shrink the array
  heapify(arr,i,0);// now heapify the remaining array
 }*/
}
