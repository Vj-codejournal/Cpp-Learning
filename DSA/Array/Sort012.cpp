//https://www.codingninjas.com/studio/problems/sort-0-1-2_631055

#include <iostream>

using namespace std;
//part  of two pointer approach
void sort012(int *arr, int n)
{
   int i = 0,j=n-1;
    for(int k =0;k<n;k++){
        if(arr[k] == 0 && arr[i] != 0&& i<k){
            swap(arr[k],arr[i]);
            //if(arr[i] == 0)
            i++;
            if(arr[k] == 2)
            k--;
        }
        else if(arr[i] == 0){
            i++;
        }
        if(arr[k] == 2&& arr[j] != 2&& j>k){
            swap(arr[k],arr[j]);
            //if(arr[j] == 2)
            j--;
            if(arr[k] == 0 )
            k--;
            
        }
        else if(arr[j] == 2 && arr[k] != 2){
            //1 2 2 2 1 1 2 1 1 2 reason to do this 
            j--;

        }
        else if(arr[j] == 2 && arr[k] == 2){
            j--;
            k--;
        }
        


    }
   


}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    sort012(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}


//can use map to calc freq of each then print 0 1 2 according to them in O(N)



// with 0, 1 and 2 in a single pass
#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;

	// Iterate till all the elements
	// are sorted
	while (mid <= hi) {
		switch (a[mid]) {

		// If the element is 0
		case 0:
			swap(a[lo++], a[mid++]);
			break;

		// If the element is 1 .
		case 1:
			mid++;
			break;

		// If the element is 2
		case 2:
			swap(a[mid], a[hi--]);
			break;
		}
	}
}

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
	// Iterate and print every element
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}


int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort012(arr, n);

	printArray(arr, n);

	return 0;
}




void sort012(int arr[], int n)
{
    // Initialisation
    int l=0;
    int r=n-1;
     
    for(int i=0;i<n && i<=r;){
        // current element is 0
        if(arr[i]==0){
            swap(arr[l],arr[i]);
            l++;
            i++;
        }
        // current element is 2
        else if(arr[i]==2){
            swap(arr[i],arr[r]);
            r--;
        }
        // current element is 1
        else{
            i++;
        }
    }
}