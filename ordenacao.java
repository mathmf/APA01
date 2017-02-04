import java.util.Scanner;

/**
 *
 * @author mathe_000
 */
public class ordenacao {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int i, j,n,temp;
		long startT,endT;
		double total;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] a = new int[n];
        for(i=0;i<n;i++){
            a[i] = sc.nextInt();
        }
        int[] b = new int[n];
        startT = System.currentTimeMillis();
        switch(Integer.parseInt(args[0])){
            case 1://selectionSort
                for (j = 0; j < n-1; j++)
                {
                    int iMin = j;
                    for (i = j+1; i < n; i++){
                        if(a[i] < a[iMin]){
                            iMin = i;
                        }
                    }
                    if(iMin != j)
                    {
                        temp = a[j];
                        a[j] = a[iMin];
                        a[iMin] = temp;
                    }
                }
                break;
                
            case 2: //insertion sort
                      
                for(j = 1;j < n;j++){
                    temp = a[j];
                    for(i = j-1;i>=0 && a[i]>temp;i--){
                        a[i+1] = a[i];
                    }
                    a[i+1] = temp;
                }
                break;
            case 3: // MergeSort
                CopyArray(a,0,n,b);
                Split(b,0,n,a);
                
                break;
            case 4: // QuickSort
                
                QuickSort(a,0,n-1);
                
                break;
            case 5: //HeapSort
                HeapSort(a,n-1);
                break;
        }
		endT = System.currentTimeMillis();
		total = (endT - startT);
		total = total/1000;
        for(i = 0;i<n;i++){
            System.out.println(a[i]);
        }
		System.out.printf("%.2f",total);
    }
    
    public static void Split(int[] b, int iBegin,int iEnd,int[] a){
        int iMiddle;
        if(iEnd - iBegin < 2)
            return;
        
        iMiddle = (iEnd + iBegin)/2;
        Split(a,iBegin,iMiddle,b);
        Split(a,iMiddle,iEnd,b);
        Merge(b,iBegin,iMiddle,iEnd,a);
    }
    
    public static void Merge(int[] a,int iBegin,int iMiddle,int iEnd,int[] b){
        int i = iBegin;
        int j = iMiddle;
        for(int k = iBegin; k < iEnd;k++){
            if(i < iMiddle &&(j>= iEnd || a[i] <= a[j])){
                b[k] = a[i];
                i = i+1;
            }
            else {
                b[k] = a[j];
                j = j +1;
            }
        }
    }
    
    public static void CopyArray(int[] A,int iBegin, int iEnd, int[] B){
        for(int k = iBegin;k< iEnd;k++)
            B[k] = A[k];
    }
    
    public static void QuickSort(int[] arr, int left , int right){
        int index = Part(arr, left, right);
      if (left < index - 1)
            QuickSort(arr, left, index - 1);
      if (index < right)
            QuickSort(arr, index, right);
    }
    
    public static int Part(int[] arr,int left, int right){
        int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
     
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
     
      return i;
    }
    
    public static void maxheap(int[] a, int i, int n){
        int left = 2*i;
        int right = 2*i + 1;
        int largest;
        if(left <=n && a[left] > a[i]){
            largest = left;
        }
        else {
            largest = i;
        }
        if(right <= n && a[right] > a[largest])
            largest = right;
        if(largest != i){
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheap(a, largest, n);
        }
        
    }
    
    public static void buildheap(int a[], int n){
        for(int i = n/2; i >= 0; i--){
            maxheap(a,i,n);
        }
    }
    
    public static void HeapSort(int[] a, int n){
        buildheap(a,n);
        int temp;
        for(int i = n; i>0;i--){
            temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            n = n-1;
            maxheap(a,0,n);
        }
    }
}
