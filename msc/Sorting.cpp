#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>&arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
    
    for(auto it : arr){
        cout << it << " ";
    }
    cout << "\n";
}

void bubble_sort(vector<int>&arr){
    int n = arr.size();
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j + 1])swap(arr[j + 1],arr[j]);
        }
    }
    for(auto it : arr){
        cout << it << " ";
    }
    cout << "\n";
}

void insertion_sort(vector<int>&arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 and arr[j - 1] > arr[j]){
            swap(arr[j - 1],arr[j]);
            j--;
        }
    }
    for(auto it : arr){
        cout << it << " ";
    }
    cout << "\n";
}

void merge(vector<int>&arr, int low, int mid, int high){
    vector<int>temp;
    int left = low, right = mid + 1;
    
    while(left <= mid and right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int>&arr,int low,int high){
    if(low >= high)return;
    
    int mid = (low + high)/2;
    
    merge_sort(arr,low,mid);
    merge_sort(arr,mid + 1,high);
    merge(arr,low,mid,high);
}

int partition(vector<int>&arr,int low, int high){
    int pivot = arr[low];
    
    int left = low, right = high;
    
    while(left < right){
        while(left < high and arr[left] <= pivot)left++;
        while(right > low and arr[right] > pivot)right--;
        if(left < right)swap(arr[left],arr[right]);
    }
    swap(arr[low],arr[right]);
    return right;
}

void quick_sort(vector<int>&arr,int low,int high){
    if(low >= high)return;
    
    int pivot = partition(arr,low,high);
    quick_sort(arr,low,pivot - 1);
    quick_sort(arr,pivot + 1,high);
    
}

int main() {
    
    vector<int>arr = {3,2,8,5,1,4,23};
    // selection_sort(arr);
    // bubble_sort(arr);
    // insertion_sort(arr);
    // merge_sort(arr,0,arr.size() - 1);
    quick_sort(arr,0,arr.size() - 1);
    for(auto it : arr){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}