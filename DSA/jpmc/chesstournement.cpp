#include <bits/stdc++.h>

using namespace std;
// int getPotentialOfWinner(vector<int> potential,long k){
//     long winstreak = 0;
//     int currwin = potential[0];
//     int index = 1;
//     while(winstreak != k){
//         if(currwin > potential[index]){
//             winstreak++;
//         }
//         else {
//             currwin = potential[index];
//             winstreak = 1;
//         }
//         index = (index + 1)%potential.size();
        
//     }
//     return currwin;
// }
int getPotentialOfWinner(vector<int>& potential, long k) {
    long n = potential.size();
    int winStreak = 0;
    int currWin = potential[0];

    for (int i = 1; i < n && winStreak != k; ) {
        if (potential[i] > currWin) {
            currWin = potential[i];
            winStreak = 1;
        } else {
            winStreak++;
        }
        i = (i + 1)%potential.size();
    }

    return currWin;
}
int main(){
    vector<int> potential = {3,2,1,4};
    long k = 3;

    cout<<getPotentialOfWinner(potential,k);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int getpotential(vector<int> &p, long k)
// {
//     deque<int> q(p.begin(), p.end());
//     long wins = 0;
//     int winner = 0;
//     while (wins < k)
//     {
//         int one = q.front();
//         q.pop_front();
//         int two = q.front();
//         q.pop_front();
//         if (one < two)
//         {
//             q.push_back(one);
//             q.push_front(two);
//             wins = 1;
//             winner = two;
//         }
//         else
//         {
//             q.push_back(two);
//             q.push_front(one);
//             wins++;
//         }
//     }
//     return winner;
// }

// int main() {
//     vector<int> v{3,1,2,4};
//     cout << getpotential(v, 2) << endl;
// }