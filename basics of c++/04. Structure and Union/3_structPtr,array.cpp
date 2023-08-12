//Pointer to structure

#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};

int main(){
    point p={10,20};
    point *ptr = &p;//ptr to a structure holds address of variable p
    cout<<ptr ->x<<" ";//for access member using ptr use ->
    ptr -> x = 30;//went to address of x and modified it 
    cout<<p.x;    
    return 0;
}

//Array of structure

#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};

int main(){
    point arr[5];//has 5 elements all of point datatype
    for(int i =0;i<5;i++){
        arr[i].x = i;
        arr[i].y = i*10;
        
    }
    for(int i =0;i<5;i++){
        cout<<arr[i].x<<" ";
        cout<<arr[i].y<<endl;
        
    }   
    return 0;
}

//other method to access array
//point p =arr[0];
//cout<<p.x<<" "<<p.y<<" ";


//passing structure as argument to function

#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};
void print(point p){//like any other datatype int same point written here
    cout<<p.x<<" "<<p.y<<endl;
}
int main(){
    point p = {10,20};
    print(p);//call by value so send a copy

    return 0;
}

//for call by pointer

#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};
void print1(point *p2){//like any other datatype int same point written here
    cout<<p2->x<<" "<<p2->y<<endl;
    p2-> x = 5;
}
int main(){
    point p2 = {10,20};
    print1(&p2);//call by value so send a copy
    cout<<p2.x;
    return 0;
}
//if too many members in a structure and pass it to a function by call by value send copy size big so use reference
//call by reference
#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};
void print2(point &p1){//like any other datatype int same point written here//if want that not send a copy but also cant change value of members use const
    cout<<p1.x<<" "<<p1.y<<endl;
    p1.x = 5;
}
int main(){
    point p1 = {10,20};
    print2(p1);//call by value so send a copy
    cout<<p1.x;
    return 0;
}