#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/// SELECTION SORT

void selectionSort(int a[],int n){
	 
	 for(int i=0;i<n-1;i++){  
	 	
		int minIndex = i;
		for(int j=i+1;j<n;j++){
			
		
			if(a[j]<a[minIndex]){
				minIndex = j;
			}
		} 
		
		swap(a[minIndex],a[i]);
	 	
	 }
	
}

/// MERGE SORT 

void Merge(int *a,int s, int e){
	int mid = (s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	int temp[100];
	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k]=a[i];
			k++;
			i++;
		}
		else{
			temp[k]=a[j];
			k++;
			j++;
		}
		
	}
	while(i<=mid){
		temp[k]=a[i];
		k++;
		i++;
	}
	
	while(j<=e){
		temp[k]=a[j];
		k++;
		j++;
		
	}
	
	for(int i=s;i<=e;i++){
		a[i] = temp[i];
	}
}
void mergeSort(int a[],int s,int e){
    if(s>=e){
    	return;
	}	

		int mid = (s+e)/2;
	    mergeSort(a,s,mid);
	    mergeSort(a,mid+1,e);
	    Merge(a,s,e);
}


/// Worst Cse Generator for MERGE Sort


int join(int arr[], int left[], int right[],
          int l, int m, int r)
{
    int i; // Used in second loop
    for (i = 0; i <= m - l; i++)
        arr[i] = left[i];
 
    for (int j = 0; j < r - m; j++)
        arr[i + j] = right[j];
}
 
// Function to store alternate elemets in left
// and right subarray
int split(int arr[], int left[], int right[],
          int l, int m, int r)
{
    for (int i = 0; i <= m - l; i++)
        left[i] = arr[i * 2];
 
    for (int i = 0; i < r - m; i++)
        right[i] = arr[i * 2 + 1];
}
 

int worstCase(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
 
        int left[m - l + 1];
        int right[r - m];
        
       split(arr, left, right, l, m, r);
 
        
        worstCase(left, l, m);
        worstCase(right, m + 1, r);
 
        join(arr, left, right, l, m, r);
    }
}

/// Function that checks if the array is Sorted in ascending order or descending order or unsorted

int isSorted(int a[], int n){
	if(n==0||n==1){
		return 1;
	}
	
	else{
		int i;
	for(i=0;i<n-1;i++){
		if(a[i+1]<a[i]){
			break;
		}
	}
	if(i==n-1){
		return 2;   // sorted in ascending order
	}
	for(i=0;i<n-1;i++){
			if(a[i+1]>a[i]){
			return -1;
		}
	}
	if(i==n-1){
		return 3;   // sorted in descending order
	}
}

}

/// Function to find Minimum Element in Array
 
int findMin(int a[],int n){             // complexity is O(n/2)
	int mid = (n/2);
	int min = 100000000;
	int j = mid;
	for(int i=0;i<=mid;i++){

		if(a[i]<min){
			min = a[i];
		}
		if(a[j]<min){
			min = a[j];
		}
	
	j+=1;
}
return min;
}

// Function to Find Maximum Element in an Array

int findMax(int a[],int n){             // complexity is O(n/2)
	int mid = (n/2);
	int max = -100000;
	int j = mid;
	for(int i=0;i<=mid;i++){

		if(a[i]>max){
			max = a[i];
		}
		if(a[j]>max){
			max = a[j];
		}
	
	j+=1;
}
return max;
}

/// Counting Sort

void countingSort(int arr[], int n, int expo)
{
    int output[n]; 
    int i, count[10] = {0};
 
      for (i = 0; i < n; i++)
        count[ (arr[i]/expo)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/expo)%10 ] - 1] = arr[i];
        count[ (arr[i]/expo)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    int m = findMax(arr, n);
 
    for (int expo = 1; m/expo > 0; expo *= 10)
        countingSort(arr, n, expo);
}
 int partition(int *a,int s,int e){
	int i=s-1;
	int j=s;
	int pivot = a[e];
	for(;j<e;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}

/// QUICK Sort
void quickSort(int *a, int s, int e){
	if(s>=e){
		return;
	}
	int p = partition(a,s,e);
	quickSort(a,s,p-1);
	quickSort(a,p+1,e);
	
}
 /// Function to Print Array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


/// Function that uses best Sorting Algo

int konsaSort(int a[], int n){
	int k = findMax(a,n);
    if(isSorted(a,n)==1||isSorted(a,n)==2){
    	print(a,n);
	}	
	
   else if((log(k))<((3.321*n*log(n))/(n+10))){
   	radixsort(a,n);
   }
  else{
  	quickSort(a,0,n-1);
  }
}
 
 // Function which tells which algo to use
int SortName(int a[],int n){
		int k = findMax(a,n);
	if(isSorted(a,n)==1){
		cout<<"The array is already sorted!"<<endl;
	}
	if(isSorted(a,n)==3){
		cout<<"Array is Sorted in Dec Order"<<endl<<"do NOT use Quick Sort, Bubble Sort, Selection Sort";
	}
	if((log(k))>((3.321*n*log(n))/(n+10))){
   	   cout<<"Do NOT use Radix Sort"<<endl;
   }
    if(((findMax(a,n))-findMin(a,n))>(n*(log(n)-1))){
   	cout<<"Do NOT use Counting Sort, Instead use Quick or Merge Sort"<<endl;
   }
   if(((log(k))<((3.321*n*log(n))/(n+10)))){
   	cout<<"Use Radix Sort"<<endl;
   }
   else{
   	cout<<"use any Sorting Function you like";
   }
}

int main(){
	int n=7;
	int a[n]={9,8,7,6,5,1,3};
	int temp[n];
	for(int i=0;i<n;i++){
		temp[i] = a[i];
	}
	cout<<isSorted(a,n);
	cout<<findMin(a,n)<<" "<<findMax(a,n);
	cout<<endl<<endl;


	konsaSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" , ";
	}
	cout<<SortName(a,n)<<endl;
	return 0;
}
