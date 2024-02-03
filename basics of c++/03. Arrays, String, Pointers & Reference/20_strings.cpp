//c style strings
//stored like continous array so each elemnt next to each other address.it is a character array string 

//c++
#include <iostream>

using namespace std;

int main(){
    string str = "GeeksforGeeks";
    cout<<str<<endl;
    cout<<str.length()<<endl;
    cout<<str[3]<<endl;//it is like a char array so use this to access elements 
    //str.clear() to clear the string
    //str.erase(3,3) from 3rd elemnt erase next 3 element have to include<string>
    //str.insert(2,"lol");
    //int x =786 cout<<to_string(x)+ "2" give 7862
    //to sort a string include<algorithm> use sort(str.begin(),s1.end()) //end give the just next iterator after the string end
    str = str+"xyz";
    cout<<str<<endl;
    cout<<str.substr(1,3)<<endl;//print from 1st to 3rd position in string also position start from 0 so G is at 0.//if write nothing where 3 is print till end
    cout<<str.find("for")<<endl;//tell the position where f start.if did ee then tell about the position that comes first //help find if a given string is present as the sub string in any other string here we checked "for"

    //string comparision
    int res = str.find("eek");
    //find function give index of first occurance of a sub string if present, if substring not present in given string then it return a const string::npos
    if(res == string::npos){
            cout<<"Not Present\n";
    }
    else{
        cout<<"first occurance at index "<<res<<endl;
    }

    string s1 = "abc";
    string s2 = "bcd";//abc  is lexicographically smaller than bcd.lexicographically means dictonary way like geeks anf gfg , g and g same e come before f so geeks lexicographically smaller // also to compare a and A lexicographically see ascii value

    if(s1==s2){//all comparision operator compare both strings character by character
        cout<<"same";
    }
    else if(s1<s2){
        cout<<"smaller";
    }
    else{
        cout<<"Greater";
    }
    cout<<endl;
    string name;
    cout<<"Enter your name:";
    //cin>>name;//but when ther is space in betwn words dont work so use getline function
    getline(cin,name);//takes a string until enter is encountered or if we do getline(cin,name,'&') now it will stop after a & sign
    cout<<"Your name is "<<name<<endl;


    //string traversal

    for(int i=0;i<str.length();i++){
        //char a = str[i] +1; to get next ascii of the each charater of string
        
        cout<<str[i];//like a normal array
    }
    cout<<endl;
    for(char x :str){//can use &x
        cout<<x;//for each loop
    }
    cout<<endl;
    for(auto it= str.begin();it != str.end();it++){//this is like traversing any normal container in c++//can get start iterator with str.begin and similar for end
        cout<<(*it); //value at that iteration//already have address here so can change the value
    }
    
    //to add to a string can do s1= s1 + 'a' or can do s1.push_back('a'); also
    return 0;
}

//here can create an empty string and assign later not in c
//c++ style can convert to c style by c_str function

//strings internal stored in ascii values only