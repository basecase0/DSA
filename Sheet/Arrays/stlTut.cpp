#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,string> hmap;
    hmap[13]="harsh";
    hmap[11]="pqr";
    hmap[10]="abc";
    auto got=hmap.find(13);
    // hmap.find(13)
    cout<<got->first;
    cout<<got->second;
    return 0;
}