//https://leetcode.com/problems/add-to-array-form-of-integer/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       
       int carry = 0;
       int i = num.size() -1;
       while(k>0 || i>=0){//if k khatam ho gaya but i bacha hai aur uske ander carry le jana hai uske liye
           if(i<0){
               break;
           }
           int digit = k%10;
           k = k/10;
           num[i] = num[i] + digit + carry;
            carry = 0;
           if(num[i]>9){
               int temp = num[i]%10;
               carry = num[i]/10;

               num[i] = temp;
           } 

           i--;

       }
        if(k != 0 || carry != 0){//i phele hi khatam and carry ya k bacha hai
            while(k>0 || carry != 0){
               int digit = k%10+carry;
               carry =0;
                k = k/10;
                if(digit>9){
                    int temp= digit%10;
                    digit = digit/10;
                    carry =  digit;
                    num.insert(num.begin(),temp);
                }
                else{
                    num.insert(num.begin(),digit);
                }
                

           }
        }
    //    if(k!=0){
    //        while(k>0){
    //            int digit = k%10;
    //             k = k/10;
    //             num.insert(num.begin(),digit);
    //        }
    //    }

    //    if(carry != 0){
    //        num.insert(num.begin(), carry);
    //    }

       return num;
    }
       
};
/*
num =
[9,9,9,9,9,9,9,9,9,9]
k =
1

num =
[2,1,3]
k =
1815

num =
[7]
k =
993
*/

int main(){
    
    return 0;
}


/*
string s = "";

        for(int i = 0;i<num.size();i++){
            s.push_back(num[i] + '0')
        }

    number = stoi(s);

can use stoi to convert string to int


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        long long number = 0;
        string s = "";

        for(int i = 0;i<num.size();i++){
            s.push_back(num[i] + '0');
        }

        number = stoi(s);

        number += k;

       string st = to_string(number);
        vector<int> ans;
       for(int i = 0;i<st.size();i++){
           ans.push_back(st[i] - '0');
       }
       return ans;
    }
};

failed [9,9,9,9,9,9,9,9,9,9] stoi out of range
*/


//https://www.codingninjas.com/studio/problems/sum-of-two-arrays_893186

#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    while(i>=0 && j >= 0){
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    //first case arr a badha tha

    while(i>=0){
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    //second case
    while(j>=0){
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }

    //third case carry left

    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}