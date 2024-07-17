#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

struct Results {
    string set_name;
    vector<string> selected_cards;
};

map<char, int> rank_order = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'1', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
vector<char> suits_order = {'S', 'H', 'D', 'C'};

bool compare_ranks(const string &a, const string &b) {
    return rank_order[a[0]] > rank_order[b[0]];
}

Results findTripleAndPair(unordered_map<char, vector<string>> &rank_map) {
    char triple_rank = '\0', pair_rank = '\0';
    for (auto &entry : rank_map) {
        if (entry.second.size() >= 3 && (!triple_rank || rank_order[entry.first] > rank_order[triple_rank])) {
            pair_rank = triple_rank;
            triple_rank = entry.first;
        } else if (entry.second.size() >= 2 && (!pair_rank || rank_order[entry.first] > rank_order[pair_rank])) {
            pair_rank = entry.first;
        }
    }
    if (triple_rank && pair_rank) {
        vector<string> selected_cards(rank_map[triple_rank].begin(), rank_map[triple_rank].begin() + 3);
        selected_cards.insert(selected_cards.end(), rank_map[pair_rank].begin(), rank_map[pair_rank].begin() + 2);
        return {"a triple and a pair", selected_cards};
    }
    return {"", {}};
}

Results findSuit(unordered_map<char, vector<string>> &suit_map) {
    for (char suit : suits_order) {
        if (suit_map[suit].size() >= 5) {
            return {"suit", vector<string>(suit_map[suit].begin(), suit_map[suit].begin() + 5)};
        }
    }
    return {"", {}};
}

Results findFiveInARow(unordered_map<char, vector<string>> &rank_map) {
    vector<string> sorted_cards;
    for (auto &entry : rank_map) {
        sorted_cards.insert(sorted_cards.end(), entry.second.begin(), entry.second.end());
    }
    sort(sorted_cards.begin(), sorted_cards.end(), compare_ranks);
    vector<string> selected_cards;
    for (int i = 0; i < sorted_cards.size(); ++i) {
        if (i > 0 && rank_order[sorted_cards[i][0]] != rank_order[sorted_cards[i-1][0]] - 1) {
            selected_cards.clear();
        }
        selected_cards.push_back(sorted_cards[i]);
        if (selected_cards.size() == 5) {
            return {"five in a row", selected_cards};
        }
    }
    return {"", {}};
}

Results findTriple(unordered_map<char, vector<string>> &rank_map, vector<string> &cards) {
    // for (auto &entry : rank_map) {
    //     if (entry.second.size() >= 3) {
    //         return {"triple", vector<string>(entry.second.begin(), entry.second.begin() + 3)};
    //     }
    // }
    // return {"", {}};
    if(cards.size() >= 3){
        for(int i = 2; i < cards.size(); i++) {
            if(cards[i][0] == cards[i-1][0] && cards[i][0] == cards[i-2][0]) {
                return {"triple", {cards[i], cards[i-1], cards[i-2]}};
            }
        }
    }
    return {"", {}};
}

Results findPair(unordered_map<char, vector<string>> &rank_map, vector<string> &cards) {
    // for (auto &entry : rank_map) {
    //     if (entry.second.size() >= 2) {
    //         return {"pair", vector<string>(entry.second.begin(), entry.second.begin() + 2)};
    //     }
    // }
    // return {"", {}};
    if(cards.size() >= 2){
        for(int i = 1; i < cards.size(); i++) {
            if(cards[i][0] == cards[i-1][0]) {
                return {"pair", {cards[i], cards[i-1]}};
            }
        }
    }
    return {"", {}};
}

Results findSingleCard(unordered_map<char, vector<string>> &rank_map, vector<string> &cards) {
    // for (auto &entry : rank_map) {
    //     return {"single card", {entry.second[0]}};
    // }
    return {"single card", {cards[0]}};
}

Results solution(vector<string> &cards) {
    sort(cards.begin(), cards.end(), compare_ranks); 
    unordered_map<char, vector<string>> rank_map, suit_map;
    for (const string &card : cards) {
        rank_map[card[0]].push_back(card);
        suit_map[card.back()].push_back(card);
    }

    sort(suit_map['S'].begin(), suit_map['S'].end(), compare_ranks);
    sort(suit_map['H'].begin(), suit_map['H'].end(), compare_ranks);
    sort(suit_map['D'].begin(), suit_map['D'].end(), compare_ranks);
    sort(suit_map['C'].begin(), suit_map['C'].end(), compare_ranks);

    Results result;

    result = findTripleAndPair(rank_map);
    if (result.set_name != "") return result;

    result = findSuit(suit_map);
    if (result.set_name != "") return result;

    result = findFiveInARow(rank_map);
    if (result.set_name != "") return result;

    result = findTriple(rank_map, cards);
    if (result.set_name != "") return result;

    result = findPair(rank_map, cards);
    if (result.set_name != "") return result;

    result = findSingleCard(rank_map, cards);
    return result;
}

int main() {
    vector<string> cards1 = {"10D", "10H", "10C", "2S", "2H", "2D", "JH", "JC"};
    Results res1 = solution(cards1);
    cout << res1.set_name << " ";
    for (const string &card : res1.selected_cards) {
        cout << card << " ";
    }
    cout << endl;

    vector<string> cards2 = {"6H", "7S", "8S", "9S", "10S", "JD", "JC", "KC", "AC"};
    Results res2 = solution(cards2);
    cout << res2.set_name << " ";
    for (const string &card : res2.selected_cards) {
        cout << card << " ";
    }
    cout << endl;
    vector<string> cards3 = {"AS", "10H", "8H", "10S", "8D"};
    Results res3 = solution(cards3);
    cout << res3.set_name << " ";
    for (const string &card : res3.selected_cards) {
        cout << card << " ";
    }
    cout << endl;
    vector<string> cards4 = {"2D","4D","6D","8D", "9D","AC","KC", "QC","JC", "7C"};
    Results res4 = solution(cards4);
    cout << res4.set_name << " ";
    for (const string &card : res4.selected_cards) {
        cout << card << " ";
    }
    cout << endl;
    vector<string> cards5 = {"AS","JS","AH","AD","10D","AC"};
    Results res5 = solution(cards5);
    cout << res5.set_name << " ";
    for (const string &card : res5.selected_cards) {
        cout << card << " ";
    }
    cout << endl;
    vector<string> cards6 = {"2H","4H","7C", "9D","10D", "KS"};
    Results res6 = solution(cards6);
    cout << res6.set_name << " ";
    for (const string &card : res6.selected_cards) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}





#include<bits/stdc++.h>

map<char, int> rOrder = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'1', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
vector<char> sOrder = {'S', 'H', 'D', 'C'};

bool cmp_rank(const string &x, const string &y) {
    return rOrder[x[0]] > rOrder[y[0]];
}

Results findTripleAndPair(unordered_map<char, vector<string>> &rmap) {
    char triple_rank = '\0', pair_rank = '\0';
    for (auto &entry : rmap) {
        if (entry.second.size() >= 3 && (!triple_rank || rOrder[entry.first] > rOrder[triple_rank])) {
            pair_rank = triple_rank;
            triple_rank = entry.first;
        } else if (entry.second.size() >= 2 && (!pair_rank || rOrder[entry.first] > rOrder[pair_rank])) {
            pair_rank = entry.first;
        }
    }
    if (triple_rank && pair_rank) {
        vector<string> selected_cards(rmap[triple_rank].begin(), rmap[triple_rank].begin() + 3);
        selected_cards.insert(selected_cards.end(), rmap[pair_rank].begin(), rmap[pair_rank].begin() + 2);
        return {"a triple and a pair", selected_cards};
    }
    return {"", {}};
}

Results findSuit(unordered_map<char, vector<string>> &smap) {
    for (char suit : sOrder) {
        if (smap[suit].size() >= 5) {
            return {"suit", vector<string>(smap[suit].begin(), smap[suit].begin() + 5)};
        }
    }
    return {"", {}};
}

Results findFiveInARow(unordered_map<char, vector<string>> &rmap) {
    vector<string> sorted_cards;
    for (auto &entry : rmap) {
        sorted_cards.insert(sorted_cards.end(), entry.second.begin(), entry.second.end());
    }
    sort(sorted_cards.begin(), sorted_cards.end(), cmp_rank);
    vector<string> selected_cards;
    for (int i = 0; i < sorted_cards.size(); ++i) {
        if (i > 0 && rOrder[sorted_cards[i][0]] != rOrder[sorted_cards[i-1][0]] - 1) {
            selected_cards.clear();
        }
        selected_cards.push_back(sorted_cards[i]);
        if (selected_cards.size() == 5) {
            return {"five in a row", selected_cards};
        }
    }
    return {"", {}};
}

Results findTriple(unordered_map<char, vector<string>> &rmap, vector<string> &cards) {
    
    if(cards.size() >= 3){
        for(int i = 2; i < cards.size(); i++) {
            if(cards[i][0] == cards[i-1][0] && cards[i][0] == cards[i-2][0]) {
                return {"triple", {cards[i], cards[i-1], cards[i-2]}};
            }
        }
    }
    return {"", {}};
}

Results findPair(unordered_map<char, vector<string>> &rmap, vector<string> &cards) {
   
    if(cards.size() >= 2){
        for(int i = 1; i < cards.size(); i++) {
            if(cards[i][0] == cards[i-1][0]) {
                return {"pair", {cards[i], cards[i-1]}};
            }
        }
    }
    return {"", {}};
}

Results findSingleCard(unordered_map<char, vector<string>> &rmap, vector<string> &cards) {
    
    return {"single card", {cards[0]}};
}

Results solution(vector<string> &cards) {
    sort(cards.begin(), cards.end(), cmp_rank); 
    unordered_map<char, vector<string>> rmap, smap;
    for (const string &card : cards) {
        rmap[card[0]].push_back(card);
        smap[card.back()].push_back(card);
    }

    sort(smap['S'].begin(), smap['S'].end(), cmp_rank);
    sort(smap['H'].begin(), smap['H'].end(), cmp_rank);
    sort(smap['D'].begin(), smap['D'].end(), cmp_rank);
    sort(smap['C'].begin(), smap['C'].end(), cmp_rank);

    Results res;

    res = findTripleAndPair(rmap);
    if (res.set_name != "") return res;

    res = findSuit(smap);
    if (res.set_name != "") return res;

    res = findFiveInARow(rmap);
    if (res.set_name != "") return res;

    res = findTriple(rmap, cards);
    if (res.set_name != "") return res;

    res = findPair(rmap, cards);
    if (res.set_name != "") return res;

    res = findSingleCard(rmap, cards);
    return res;
}