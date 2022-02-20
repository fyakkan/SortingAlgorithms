import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String []args) throws IOException{


        long startTime;
        long endTime;
        long totalTime;

        int counter =0;

        ArrayList<String> str = new ArrayList<>();

        String line = "";

        FileReader fr = new FileReader("Query.txt");

        BufferedReader reader = new BufferedReader(fr);

        // For length
        while((line=reader.readLine())!=null){

            counter++;

        }


        Double [] tall = new Double[counter] ;
        int i = 0;


        ///////////////////////////////
        File file=new File("C:\\Users\\Furkan\\Desktop\\Java\\P5\\Query.txt");
        Scanner sc=new Scanner(file);
        while(sc.hasNextLine()){
            String x = sc.nextLine();
            double str1 = Double.parseDouble(x);

            tall[i] = str1;
            i++;

        }

        Double[] forShell = Arrays.copyOf(tall, counter);
        Double[] forInsertionSort = Arrays.copyOf(tall, counter);
        Double[] forQuickSort = Arrays.copyOf(tall, counter);
        Double[] forMergeSort = Arrays.copyOf(tall, counter);
        Double[] forBubbleSort = Arrays.copyOf(tall, counter);


//
        startTime = System.currentTimeMillis();

        SelectionSort(tall);

        endTime   = System.currentTimeMillis();
        totalTime = endTime - startTime;
        System.out.println("Selection : "+totalTime);
//
startTime =0;
endTime=0;
totalTime=0;
        startTime = System.currentTimeMillis();

        ShellSort(forShell);

        endTime   = System.currentTimeMillis();
        totalTime = endTime - startTime;
        System.out.println("ShellSort : "+totalTime);
//
        startTime =0;
        endTime=0;
        totalTime=0;
        startTime = System.currentTimeMillis();

        InsertionSort(forInsertionSort);

        endTime   = System.currentTimeMillis();
        totalTime = endTime - startTime;
        System.out.println("InsertSort : "+totalTime);

//
        startTime =0;
        endTime=0;
        totalTime=0;
        startTime = System.currentTimeMillis();

        quickSort(forQuickSort,0,counter-1);

        endTime   = System.currentTimeMillis();
        totalTime = endTime - startTime;
        System.out.println("QuickSort : "+totalTime);
//
        startTime =0;
        endTime=0;
        totalTime=0;
        startTime = System.currentTimeMillis();

        sort(forMergeSort,0,counter-1);

        endTime   = System.currentTimeMillis();
        totalTime = endTime - startTime;
        System.out.println("MergeSort : "+totalTime);
//
        startTime =0;
        endTime=0;
        totalTime=0;
        startTime = System.currentTimeMillis();

        bubbleSort(forBubbleSort);

        endTime   = System.currentTimeMillis();
        totalTime = endTime - startTime;
        System.out.println("BubbleSort : "+totalTime);

    }
    //Bubble Sort +
    private static void bubbleSort(Double[] arr) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    // swap arr[j+1] and arr[j]
                    Double temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }

    //Selection Sort +
    static void SelectionSort(Double[] arr) {
        int n = arr.length;


        for (int i = 0; i < n - 1; i++) {

            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;


            double temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    //Shell Sort +
    static int ShellSort(Double[] arr)
    {
        int n = arr.length;


        for (int gap = n/2; gap > 0; gap /= 2)
        {

            for (int i = gap; i < n; i += 1)
            {

                Double temp = arr[i];

                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];


                arr[j] = temp;
            }
        }
        return 0;
    }
    //Insert Sort +
    static void InsertionSort(Double[] arr)
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            Double key = arr[i];
            int j = i - 1;


            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }


    //Quick Sort
    static void quickSort(Double[] arr, int low, int high)
    {
        if (low < high)
        {

            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    static int partition(Double[] arr, int low, int high)
    {

        Double pivot = arr[high];


        int i = (low - 1);

        for(int j = low; j <= high - 1; j++)
        {


            if (arr[j] < pivot)
            {

                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }
    static void swap(Double[] arr, int i, int j)
    {
        Double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

//Merge Sort +
    static void merge(Double[] arr, int l, int m, int r)
    {

        int n1 = m - l + 1;
        int n2 = r - m;


        double L[] = new double[n1];
        double R[] = new double[n2];


        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }


        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    static void sort(Double[] arr, int l, int r)
    {
        if (l < r) {

            int m =l+ (r-l)/2;

            sort(arr, l, m);
            sort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }

}
