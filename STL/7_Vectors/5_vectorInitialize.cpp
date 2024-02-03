#include <iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v1(5);
//to fill in these 5 places have to use fill(v1.begin(),v1.end(),value);
//can't do pushback to fill these it will fill after these 5 spaces and these spaces will be given 0

    v1.push_back(5);    
    v1.push_back(6);    
    v1.push_back(7);    
    v1.push_back(8);

    for(auto x : v1){
        cout<<x<<"*";
    }    
    return 0;
}

// C++ program to create an empty 
// vector and push values one
// by one.
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    // Create an empty vector
    vector<int> vect;
  
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
  
    for (int x : vect)
        cout << x << " ";
  
    return 0;
}


// C++ program to create an empty 
// vector and push values one
// by one.
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    int n = 3;
  
    // Create a vector of size n with
    // all values as 10.
    vector<int> vect(n, 10);
  
    for (int x : vect)
        cout << x << " ";
  
    return 0;
}


// C++ program to initialize 
// a vector like an array.
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    vector<int> vect{ 10, 20, 30 };
  
    for (int x : vect)
        cout << x << " ";
  
    return 0;
}

// C++ program to initialize
// a vector from an array.
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    vector<int> vect(arr, arr + n);
  
    for (int x : vect)
        cout << x << " ";
  
    return 0;
}


// C++ program to initialize a vector from
// another vector.
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    vector<int> vect1{ 10, 20, 30 };
  
    vector<int> vect2(vect1.begin(), vect1.end());
  
    for (int x : vect2)
        cout << x << " ";
  
    return 0;
}

// C++ Program to initialize vector using fill()
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    // creating array with size 10
    vector<int> vect1(10);
  
    // initializing using fill() function
    int value = 5;
    fill(vect1.begin(), vect1.end(), value);
  
    // printing vector
    for (int x : vect1)
        cout << x << " ";
  
    return 0;
}

// C++ program to initialize a 
// vector with consecutive
// numbers
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
  
int main()
{
    // declaring a vector with size 5
    vector<int> vec(5);
  
    // initializing using iota()
    iota(vec.begin(), vec.end(), 1);
  
    // printing the vector
    for (int i = 0; i < 5; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}



#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1;

    cout<<v1[2];//give error not work as no memory exist in 1st place
    return 0;
}