#include <bits/stdc++.h> 
using namespace std;
void deleteMiddle(stack<int>&inputStack, int N){
	stack<int>finalStack;

    int count = 1; 
    int pos;
    if(N%2 == 0)
    pos = (N+1) - ((N+1)/2);//here size is n when actual size of arr is n+1 if arr has 5 element put size = 4 as it is 0 to 4 index
    else
    pos = (N+1) - (((N+1)/2)-1);


    while(!inputStack.empty()){
        if(count == pos){
            inputStack.pop();
        }
        else{
            finalStack.push(inputStack.top());
            inputStack.pop();
        }
        count++;
        
    }
    if(finalStack.empty()){
        cout<<"stack empty"<<endl;
        return;
    }
    while(!finalStack.empty()){
        cout<<finalStack.top();
        cout<<" ";
        finalStack.pop();
    }

    

}

int main(){
    stack<int> inputStack;
    int N;
    int t;
    cin>>t;

    while(t-->0){
        cin>>N;
        int a;
        for(int i = 0;i<N+1;i++){
            cin>>a;
            inputStack.push(a);

        }

        deleteMiddle(inputStack,N);

    }
}


//BABBAR //Recursion approach
//approach

/*
let stack 5 6 7
count =0 size = 3 size /2 = 1 is middle element
go to next recursion 
count =1 size/2 =1 so pop and now backtrack so put 7 back
*/
#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&inputStack,int count , int size){
    //base case
    if(count  == size/2){ //here size is correct if array has 5 element size = 5
        inputStack.pop(); 
        return;
    }
    int num = inputStack.top();//saved the element to insert again at backtracking
    inputStack.pop();
    //recursive call
    solve(inputStack,count+1,size);
    inputStack.push(num);

}
void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;
    solve(inputStack,count,N);

}

int main(){
    stack<int> inputStack;
    int N;
    int t;
    cin>>t;

    while(t-->0){
        cin>>N;
        int a;
        for(int i = 0;i<N;i++){
            cin>>a;
            inputStack.push(a);

        }

        deleteMiddle(inputStack,N);

    }
}