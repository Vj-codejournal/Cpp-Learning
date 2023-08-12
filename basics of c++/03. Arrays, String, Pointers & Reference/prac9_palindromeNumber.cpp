#include <iostream>

using namespace std;

int main() {
    string n;
    cout<<"Enter the number:";
    getline(cin,n);
    int t=0;

    // for(int i =0 ; n[i] != '\0';i++){// \0 is only in character array char a[] and not in string of c++
    //     a++;
    //     if(n[i]== '\0'){
    //         break;
    //     }
    // }

    int a = n.length();
    for(int i=0;i < (a+1)/2;i++){
        if(n[i]!=n[a-i-1]){
            t=0;
            printf("This is not a palindrome");
            break;
        }
        else{
            t=1;
        }
        
    }
    if (t==1){
        printf("This is a palindrome");
    }
    
    return 0;
}//also work for aabbaa and others



//video code

#include <iostream>

using namespace std;

int main(){
       string s;
       cin >>s;
       int start = 0;
       int end = s.length() - 1;

       while(start<end){
        if(s[start] != s[end]){
            cout<<"No";
            return 0;
        }
        else{
            start++;
            end--;//so reach center and then start>end so stop
        }
       }
    return 0;
}



//c code
/*
#include <stdio.h>

int main() {
    char n[10];
    printf("Enter the number:");
    gets(n);
    int a=0,t=0;

    for(int i =0 ; n[i] != '\0';i++){
        a++;
        if(n[i]== '\0'){
            break;
        }
    }
    for(int i =0;i < (a+1)/2;i++){
        if(n[i]!=n[a-i-1]){
            t=0;
            printf("This is not a palindrome");
            break;
        }
        else{
            t=1;
        }
        
    }
    if (t==1){
        printf("This is a palindrome");
    }
    
    return 0;
}
*/