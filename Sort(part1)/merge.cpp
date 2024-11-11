static void merge(T* left, T* middle, T* right){
    /*TODO*/
T* arr = left;
    int l = 0, m = middle - left, r = right - left;
    //! Kích thước mảng con thứ nhất
    int n1 = m - l + 1; 
    //! Kích thước mảng con thứ hai
    int n2 = r - m; 
  
    // Create temp arrays 
    //! Tạo mảng tạm thời  
    int L[n1], R[n2]; 
  
    //* Copy data to temp arrays L[] and R[]  
 //! Sao chép dữ liệu vào mảng tạm thời L[] và R[]
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r] 
      int i = 0;
    //* Initial index of second subarray 

    int j = 0;  
      
    //* Initial index of merged subarray 
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    //* Copy the remaining elements of 
    //* L[], if there are any  
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    printArray(left,right);
}
static void mergeSort(T* start, T* end){
    /*TODO*/
       if(start < end){
       T* mid = (end - start) / 2 + start;
       mergeSort(start, mid);
       mergeSort(mid+1,end);
       merge(start, mid, end);
   }
}