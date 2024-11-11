static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T* arr = start;
    int low = 0;
    int high = end-start-1;
    int i=low, j = high+1;
    int pivot = arr[low];
    do{
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i > j) break;
        swap(arr[i],arr[j]);
    }while(i <= j);
    if(i<=j){
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    cout << j << " ";
    return start+j;
}

static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if(start < end){
        T* pivot = Partition(start,end);
        QuickSort(start,pivot);
        QuickSort(pivot+1,end);
    }
}