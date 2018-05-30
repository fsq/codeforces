#include <string>
#include <iostream>

using namespace std;

string word, text;

int main() {
    getline(cin, word);
    getline(cin, text);

    for (auto& c : word) c = tolower(c);
    for (auto& c : text) c = tolower(c);
    word = " " + word + " ";
    text = " " + text + " ";

    int first=-1, cnt=0;
    
    for (auto i=0; (i=text.find(word, i))!=string::npos; ++i) {
        ++cnt;
        if (first==-1) first = i;
    }

    if (first==-1)
        printf("-1\n");
    else 
        printf("%d %d\n", cnt, first);

    return 0;
}