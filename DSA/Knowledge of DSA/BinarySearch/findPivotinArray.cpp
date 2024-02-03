//I/P arr = {1,2,3,7,9} sorted
//rotated by 2
// {7,9,1,2,3} rotated 

//pivot give index of minimum element as sorted so rotated about it 

int getPivot(int * arr,int n) {
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start < end){
        if(arr[mid] >= arr[0]){// it is in 7 or 9 so send to right of it 
            start = mid +1;
        }
        else{//it is in 2 or 3 send to left
            end = mid; //not mid -1 as can skip  like peak
        }
        mid = start + (end-start)/2;
    }    
        return start;
}