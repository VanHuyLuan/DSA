#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       cout << arr[i] << " ";
   cout << endl;
}

// selection sort
void selecsort(int a[], int n)
{
    int i;
    cout << "Selection Sort: " << endl;
    for(i = 0; i < n ; i++)
    {
        int minx = a[i], k = i;
        for(int j = i +1 ; j < n; j++)
        {
            if(a[j] < minx)
            {
                minx = a[j];
                k = j;
            }
        }
        cout << "Buoc "<<i+1<<": ";
        if(minx != a[i]) swap(a[i], a[k]);
        printArray(a , n);
    }
}

// insertion sort
void insersort(int arr[], int n)
{
   int i, key, j;
   cout << "insertion sort:" << endl;
   for (i = 1; i < n; i++)
   {
       cout << "Buoc " << i << ": ";
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
       printArray(arr , n);
   }
}

// bubble sort
void BubbleSort(int a[], int n){
    int temp; // biến tạm temp
    for (int i = 0; i < n; i++){
	for (int j = 0; j < n - i - 1; j++){
		if (a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
			}
		}
		cout << "Buoc " << i+1 << ": " ;
		printArray(a , n);
	}
}
// merge sort
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

// quick sort
void quickSort(int a[], int l, int r ) {
    if (a == nullptr || r <= l)
        return;

    int pivot = a[r];
    int i = l, j = r;

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    if (l < j) {
        quickSort(a, l, j );
    }

    if (r > i) {
        quickSort(a, i, r );
    }
}

int main()
{
    int n ;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    //selecsort(a , n);
    //insersort(a , n);
    //BubbleSort(a , n);
    mergeSort(a , 0 , n - 1);
    //quickSort(a , 0 , n-1 );
    printArray(a , n);
    return 0;
}
