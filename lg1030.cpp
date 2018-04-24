#include <vector>
#include <string>
#include <iostream>

using namespace std;

void dfs(string mid, string pst) {
    if (mid.empty())
        return;
    else if (mid.size()==1) 
        printf("%c", mid[0]);
    else {
        char rt = pst.back();
        int pivot = mid.find(rt);

        printf("%c", rt);
        dfs(mid.substr(0, pivot), pst.substr(0, pivot));
        dfs(mid.substr(pivot+1), pst.substr(pivot, pst.size()-pivot-1));
    }
}

int main() {
    string mid, pst;
    cin >> mid >> pst;
    dfs(mid, pst);
    return 0;
}