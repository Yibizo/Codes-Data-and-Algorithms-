#include "sort_alg.hpp"
#include "mytimer.h"

/*
template <typename T>
void print_vector(vector<T> arr, int N = 10)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
*/

template <typename T>
void compare_vectors(vector<T> a, vector<T> b, string message = "")
{
    cout << message << ": ";
    // check if equal
    if (a == b)
        cout << "Correct Implementation" << endl;
    else
        cout << "Incorrect Implementation" << endl;
}

int main(){
    Sort<float> s;

    int count;
    cout << "Enter array size: ";
    cin >> count;

    // generate a random vector array of float of size count
    vector<float> arraySort;
    srand((unsigned int)time(NULL));
    for(size_t i = 0; i < count; i++){
        arraySort.push_back((float)rand() / RAND_MAX);
    }

    vector<float> arr1(arraySort);
    vector<float> arr2(arraySort);
    vector<float> arr3(arraySort);
    vector<float> arr4(arraySort);
    vector<float> arr5(arraySort);

    /*
    for(size_t i=0;i<count;i++){
        cout << arraySort[i] << ", ";
    }
    cout << endl;
    */

    DECLARE_TIMING(t1);
    START_TIMING(t1);
    s.selectionSort(arr1);
    STOP_TIMING(t1);
    compare_vectors(arraySort, arr1, "Selection sort");
    SHOW_TIMING(t1, "Selection Sort");

    DECLARE_TIMING(t2);
    START_TIMING(t2);
    s.bubbleSort(arr2);
    STOP_TIMING(t2);
    compare_vectors(arraySort, arr2, "Bubble sort");
    SHOW_TIMING(t2, "Bubble Sort");

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    s.insertionSort(arr3);
    STOP_TIMING(t3);
    compare_vectors(arraySort, arr3, "Compare sort");
    SHOW_TIMING(t3, "Insertion Sort");

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    s.mergeSort(s,arr4,0,arr4.size()-1);
    STOP_TIMING(t4);
    compare_vectors(arraySort, arr4, "Merge sort");
    SHOW_TIMING(t4, "Merge Sort");

    DECLARE_TIMING(t5);
    START_TIMING(t5);
    s.quickSort(s,arr5,0,arr5.size()-1);
    STOP_TIMING(t5);
    compare_vectors(arraySort, arr5, "Quick sort");
    SHOW_TIMING(t5, "Quick Sort");
}