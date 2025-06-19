int* mallocArray(int n) {
    int* arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        arr[i]=i; //O(1)
    }
    return arr;
}
//Space complexity
//malloc O(1), arr O(n)
//for O(n) lần
//+> O(n)






