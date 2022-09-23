class Solution {
    public int findPeakElement(int[] arr) {
        if(arr.length==1) {
            return 0;
        }
        int n=arr.length;
        for(int i=0;i<arr.length;i++) {
            if(i==0 && arr[i]>=arr[i+1]) {
                return i;
            }
            else if(i==n-1 && arr[i]>=arr[i-1]) {
               return i;
            }
            else if(arr[i]>=arr[i+1] && arr[i]>=arr[i-1]){
               return i;
            }
        }
        return -1;
    }
}