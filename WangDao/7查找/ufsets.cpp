#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;
const int SIZE = 100;
int UFSets[SIZE];
void Initial(int S[]) {
    for (int i = 0; i < SIZE; i++) {
        S[i] = -1;
    }
}
int Find(int S[], int x){
    while (S[x]>=0)
        x=S[x];
    return x;
}
void Union(int S[], int Root1, int Root2){
    if (Root1 == Root2)
        return;
    S[Root2]=Root1;
}