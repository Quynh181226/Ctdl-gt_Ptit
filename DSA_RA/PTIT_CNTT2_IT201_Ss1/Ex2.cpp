void printDouble(int n) {
    int i=1;
    while(i<n) {
        printf("%d\n",i);
        i*=2;
    }
}
//Time comeplexity
// while log2(n) lần + printf O(1)
//+> O(log n)
