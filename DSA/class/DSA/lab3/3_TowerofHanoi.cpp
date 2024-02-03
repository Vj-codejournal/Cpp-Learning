// #include <iostream>

// using namespace std;
// void TOH(int n,char A,char B,char C){
//     if(n>0){
//         TOH(n-1,'A','C','B');
//         cout<<"Move  Disc "<<n<<" from "<<A<<" to "<<C<<endl;
//         TOH(n-1,'B','C','A');
//     }
// }
// int main(){
//     int n;
//     cin>>n;

//     TOH(n,'A','B','C');
//     return 0;
// }


// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod,
				char aux_rod)
{
	if (n == 0) {
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod
		<< " to rod " << to_rod << endl;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
	int N = 3;

	// A, B and C are names of rods
	towerOfHanoi(N, 'A', 'C', 'B');
	return 0;
}

// This is code is contributed by rathbhupendra
