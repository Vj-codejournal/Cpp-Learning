#include <iostream>

using namespace std;
union Test{
    int x;
    int y;
};

int main(){
    Test t;//in c have to write union here   
    t.x =10;
    cout<<t.x<<" "<<t.y<<endl;
    t.y =20;
    cout<<t.x<<" "<<t.y<<endl;
    cout<<sizeof(t);
    return 0;
}

//application of union 
//type punning

#include <iostream>

using namespace std;
union test{
    int x;
    float y;
};
int main(){
    test t;
    t.y = 1.1;
    cout<<t.x;//we convert one type into other type without typecasting and get internal representation of particualr type in memory .Here 1.1 as t.x print it convert the binary representation of 1.1 in memory to ddecimal and print it
    return 0;
}


#include <iostream>

using namespace std;
union test1{
    int x;
    char bin[4];
};
int main(){
    test1 t;
    t.x =512;
    cout<<(int )t.bin[0]<< " " <<(int )t.bin[1]<< " " <<(int )t.bin[2]<< " " <<(int )t.bin[3]<< " "; 
    return 0;
}

//using annonymous union to use one type for multiple purpose

#include <iostream>

using namespace std;
struct node{
    int data;
    union {//annonymous union no name
        struct{//binary tree node
            node *left, *right;
        };
        struct{//doble linked list node
            node *prev, *next;
        };

    };
};//a node structure tha tcan be used for both doubly linked list and binary tree
int main(){
    
    return 0;
}