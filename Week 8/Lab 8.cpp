#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int max_number = root;
    int left_child = (2 * root) + 1;
    int right_child = (2 * root) + 2;

    // if left child is larger than root of the tree
    if (left_child < n && arr[left_child] > arr[max_number]) {
        max_number = left_child;
    }

    // if right child is larger than largest element
    if (right_child < n && arr[right_child] > arr[max_number]) {
        max_number = right_child;
    }

    // if largest element is not root
    if (max_number != root) {
        swap(arr[root], arr[max_number]);
        heapify(arr, n, max_number);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int j = n - 1; j >= 0; j--) {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i) {
       cout << arr[i] << " ";
   }
   cout << "\n";
}

// main program
int main()
{
    int n;
    cout << "Input array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[i] = num;
    }

    cout << "Input array: ";
    displayArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    displayArray(arr, n);
    return 0;
}