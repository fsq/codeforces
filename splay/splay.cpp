#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val, fa, l, r, rep;
    Node(int key):val(key),fa(0),l(0),r(0),rep(1) {}
    Node(int key, int f):val(key),fa(f),l(0),r(0),rep(1) {}
};

vector<Node> t;
int root = 0;

void push(int i) {
    if (t[i].l) t[t[i].l].fa = i;
    if (t[i].r) t[t[i].r].fa = i;
}

int right_rotate(int i) {
    int x = t[i].l;
    int p = t[i].fa;
    t[x].fa = p;
    if (p!=0)
        if (t[p].l==i) t[p].l = x;
                else   t[p].r = x;
    t[i].l = t[x].r;
    t[x].r = i;
    push(x), push(i);
    return x;
}

int left_rotate(int i) {
    int x = t[i].r;
    int p = t[i].fa;
    t[x].fa = p;
    if (p!=0)
        if (t[p].l==i) t[p].l = x;
                else   t[p].r = x;
    t[i].r = t[x].l;
    t[x].l = i;
    push(x), push(i);
    return x;
}

void splay(int x) {
    if (x==0) return;
    while (t[x].fa) {
        int p = t[x].fa;
        if (p==root)
            if (x==t[p].l) right_rotate(p);
                      else left_rotate(p);
        else {
            int pp = t[p].fa;;
            if (t[pp].l == p) {
                if (t[p].l == x) {
                    right_rotate(pp);
                    right_rotate(p);
                } else {
                    left_rotate(p);
                    right_rotate(pp);
                }
            } else {
                if (t[p].r == x) {
                    left_rotate(pp);
                    left_rotate(p);
                } else {
                    right_rotate(p);
                    left_rotate(pp);
                }
            }
        }
    }
    root = x;
}

void insert(int val) {
    int now = root, p = 0, ind = 0;
    while (now) 
        if (val==t[now].val) {
            ++t[now].rep;
            ind = now;
            break;
        } else if (val<t[now].val) {
            p = now;
            now = t[now].l;
        } else {
            p = now;
            now = t[now].r;
        }
    
    if (!ind) {
        t.push_back(Node(val, p));
        ind = t.size() - 1;
        if (p!=0)      
            if (val<t[p].val) t[p].l = ind;
                        else  t[p].r = ind;
    }
    splay(ind);
}

int find(int val) {
    int now = root, ind = 0;
    while (now) 
        if (t[now].val==val) {
            ind = now;
            break;
        } else
            now = (val<t[now].val) ? t[now].l : t[now].r;
    splay(ind);
    return ind;
}

int main() {
    t.push_back(Node(INT_MIN));

    unordered_set<int> st;
    int MAXN = 1000000;
    for (int i=0; i<100000; ++i) {
        int x = rand() % MAXN;
        st.insert(x);
        insert(x);
    }

    for (int i=0; i<MAXN; ++i)
        if (st.find(i)==st.end() != find(i)==0)
            cout << i << endl;



  
    return 0;
}