#include <bits/stdc++.h>
using namespace std;

//SELECTION SORT

void selection_sort(vector<int>&arr,int n){
    for(int i = 0; i < n; i++){
        int mn = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[mn]){
                mn = j;
            }
        }
        swap(arr[i],arr[mn]);
    }
}

//BUBBLE SORT

void bubble_sort(vector<int>&arr,int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j],arr[j + 1]);
            }
        }
    }
}

//INSERTION SORT

//13,46,24,52,20,9 -> 13,46,24,52,20,9 -> 13,24,46,52,20,9 -> 13,24,46,52,20,9 -> 13,20,24,46,52,9 -> 9,13,20,24,46,52
//^                      ^                      ^                      ^                      ^                     ^

void insertion_sort(vector<int>&arr,int n){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 and arr[j - 1] > arr[j]){
            swap(arr[j - 1],arr[j]);
            j--;
        }
    }
}

// MERGE SORT
vector<int>temp;
void mergeSort(vector<int>&arr,int low,int high){
    if(low + 1 >= high)return;
    int mid = (low + high)/2;
    int i = low, j = high, k = low;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid,high);
    
    while(i < mid or j < end){
        if(j >= end or (i < mid and arr[i] < arr[j])){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    for(int i = low; i < high; i++){
        arr[i] = temp[i];
    }
}

//QUICK SORT

int partition(vector<int>&arr,int low,int high){
    int pivot = arr[low];
    int i = low, j = high;
    
    while(i < j){
        while(arr[i] <= pivot and i < high)i++;
        while(arr[j] > pivot and j > low)j--;
        if(i < j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[high]);
    return j;
}

void quickSort(vector<int>&arr,int low,int high){
    if(lo < hi){
        int pIndex = partition(arr,low,high);
        quickSort(arr,low,pIndex - 1);
        quickSort(arr,pIndex + 1,high);
    }
}

// Moore's Algorithm

int majority(vector<int>&nums){
    int n = nums.size();
    int ele;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            ele = nums[i];
            cnt = 1;
        }
        else if(ele == nums[i])cnt++;
        else cnt--;
    }
    // then count the number of ele if it is greater than half of n then well and good
}

int main() {
    int x=10;
    int y=25;
    int z=x+y;

    cout<<"Sum of x+y = " << z;
}