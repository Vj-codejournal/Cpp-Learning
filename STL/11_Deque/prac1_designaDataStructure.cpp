/*
create a data structure to perform operations in O(1)
insertMin(x) - assume inserted item smaller then all present items so come at begin of queue
insertMax(x) - assume inserted item bigger then all present items so come at end of queue
getMin()
getMax()
extractMin()
extractMax()
and all these get time complexity O(1) as deque
*/

#include <iostream>
#include<deque>
using namespace std;
deque<int> dq;

void insertMin(int x){dq.push_front(x);}
void insertMax(int x){dq.push_back(x);}
void getMin(){dq.front();}
void getMax(){dq.back();}
void ExtractMin(){dq.pop_front();}
void ExtractMax(){dq.pop_back();}
int main(){
    insertMin(5);
    insertMax(10);
    insertMin(3);
    insertMax(15);
    insertMin(2);
    getMin();
    getMax();
    insertMin(1);
    getMin();
    insertMax(20);
    getMax();
    ExtractMin();
    ExtractMax();


    return 0;
}