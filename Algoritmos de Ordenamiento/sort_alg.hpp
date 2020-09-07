#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Sort{
protected:
    vector<T> mergedVector;
public:

    /*
    Selection Sort:
    Find the minimum element in all of the array,
    and then place it at the beginning, repeating 
    the process until the end.
    */
    void selectionSort(vector<T> arraySort_){
        int arraySize = arraySort_.size();
        for(size_t i=0;i<arraySize;i++){
            //find minimum element
            int min = i;
            for(size_t j=i+1;j<arraySize;j++){
                if(arraySort_[j]<arraySort_[min]){
                    min = j;
                }
                //swap element with first element
                float temp=arraySort_[min];
                arraySort_[min]=arraySort_[i];
                arraySort_[i]=temp;
            }
        }
    }

    /*
    Bubble Sort:
    Compare two elements at the same time and 
    swap positions if the second element is 
    bigger than the first one.
    */
    void bubbleSort(vector<T> arraySort_){
        int arraySize = arraySort_.size();
        for(size_t i=0;i<arraySize-1;i++){
            for(size_t j=0;j<arraySize-i-1;j++){
                //comparison to check if swap is made
                if(arraySort_[j]>arraySort_[j+1]){
                    //swap values
                    float temp=arraySort_[j];
                    arraySort_[j]=arraySort_[j+1];
                    arraySort_[j+1]=temp;
                }
            }
        }
    }

    /*
    Insertion Sort:
    Take a selected value from an array, and put it 
    into a second array in a sorted manner, looking 
    for a value that's higher or the beginning if 
    none is found.
    */
    void insertionSort(vector<T> arraySort_){
        int arraySize = arraySort_.size();
        for(size_t i=1;i<arraySize;i++){
            float comparisonNum = arraySort_[i];
            int j = i-1;
            //move element that is higher than comparisonNum one more position in the array
            while(j>=0 && arraySort_[j]>comparisonNum){
                arraySort_[j+1] = arraySort_[j];
                j = j-1;
            }
            arraySort_[j+1] = comparisonNum;
        }
    }
    
    /*
    Merge Sort:
    Take an element of an array into a smaller array, and then
    merge them together in a sorted manner, looking for an 
    element of lower value.
    */
    void merge(vector<T> arraySort_,int left,int middle,int right){
        int i,j,k; 
        int n1 = middle - left + 1; 
        int n2 = right - middle; 
    
        //temporary arrays
        float leftTemp[n1],rightTemp[n2]; 
    
        //create copies to temporary arrays
        for(i=0;i<n1;i++){
            leftTemp[i] = arraySort_[left + i];
        }
        for(j=0;j<n2;j++){
            rightTemp[j] = arraySort_[middle + 1 + j];
        } 
    
        //first index of first subarray
        i = 0;
        //first index of second subarray
        j = 0;
        //first index of merged subarray
        k = left;
        
        //merge temporary arrays into array
        while(i < n1 && j < n2) { 
            if(leftTemp[i] <= rightTemp[j]){ 
                arraySort_[k] = leftTemp[i]; 
                i++;
            } 
            else{ 
                arraySort_[k] = rightTemp[j]; 
                j++; 
            }
            k++; 
        } 

        //create copies of temporary left array
        while(i<n1){ 
            arraySort_[k] = leftTemp[i]; 
            i++; 
            k++; 
        } 

        //create copies of temporary right arrays
        while(j < n2){ 
            arraySort_[k] = rightTemp[j]; 
            j++;
            k++;
        }
    }
    void mergeSort(Sort s_,vector<T> arraySort_,int left,int right){
        if(left<right){
            int middle = left+(right-left)/2; 
    
            //used to sort first and second halves
            mergeSort(s_,arraySort_, left, middle); 
            mergeSort(s_,arraySort_, middle + 1, right); 
    
            s_.merge(arraySort_, left, middle, right); 
        }
    }

    /*
    Quick Sort:
    Use a "pivot" element from an array used to compare.
    Then, use pointers on both sides of the array, if values 
    on the left are lower, continue until a higher value, 
    and viceversa for the right side, then continue
    until both pointers are on the pivot, and continue 
    to change pivots until a sorted array is obtained.
    */
    T partitionPoint(vector<T> arraySort_,int low,int high){
        float pivotPoint = arraySort_[high];
        //point of smaller element
        int i = (low-1);

        for(size_t j = low;j<=high-1;j++){
            if(arraySort_[j]<pivotPoint){
                //increase position of smaller element used for swap
                i++;
                float temp1 = arraySort_[i];
                arraySort_[i] = arraySort_[j];
                arraySort_[j] = temp1;
            }
        }
        float temp2 = arraySort_[i+1];
        arraySort_[i+1] = arraySort_[high];
        arraySort_[high] = temp2;
        //return partition value used in quick sort
        return i+1;
    }
    void quickSort(Sort s_,vector<T> arraySort_,int low,int high){
        if(low<high){
            int partitionValue = s_.partitionPoint(arraySort_,low,high);
            //sort both elements before and after the partition value
            quickSort(s_,arraySort_,low,partitionValue-1);
            quickSort(s_,arraySort_,partitionValue+1,high);
        }
    }

};