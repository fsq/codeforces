#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    // fa: father
    // l, r: l/r son
    // rep : #same value
    // cnt : #nodes in this tree
    int val, fa, l, r, rep, cnt;
    Node () {}
    Node (int key): val(key), l(0),r(0),fa(0),rep(1),cnt(1) {}
    Node (int key, int f):val(key),fa(f),rep(1),cnt(1),l(0),r(0) {}
};

vector<int> a, q;
vector<Node> t(1);
int root = 0;

int n, m, k=0;

void push(int x) {
    if (t[x].l) t[t[x].l].fa = x;
    if (t[x].r) t[t[x].r].fa = x;
    // update cnt
    t[x].cnt = (t[x].l ? t[t[x].l].cnt : 0) + 
               (t[x].r ? t[t[x].r].cnt : 0) + t[x].rep;
}

void right_rotate(int y) {
    int x = t[y].l, p = t[y].fa;
    t[x].fa = p;
    if (t[p].l==y) t[p].l = x;
            else   t[p].r = x;
    t[y].l = t[x].r;
    t[x].r = y;
    push(y), push(x);
}

void left_rotate(int y) {
    int x = t[y].r, p = t[y].fa;
    t[x].fa = p;
    if (t[p].l==y) t[p].l = x;
            else   t[p].r = x;
    t[y].r = t[x].l;
    t[x].l = y;
    push(y), push(x);
}

void splay(int x) {
    while (t[x].fa) {
        int p =t[x].fa;
        if (p==root) {
            if (t[p].l==x) right_rotate(p);
                    else   left_rotate(p);
        } else {
            int pp = t[p].fa;
            if (p==t[pp].l) {
                if (x==t[p].l) 
                    right_rotate(pp), right_rotate(p);
                else
                    left_rotate(p), right_rotate(pp);
                
            } else {
                if (x==t[p].r)
                    left_rotate(pp), left_rotate(p);
                else
                    right_rotate(p), left_rotate(pp);
            }
        }
    }
    root = x;
}

void insert(int val) {
    int now = root, p = 0, ind = 0;
    while (now) {
        ++t[now].cnt; // directly add increase counter of current tree
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
    }
    if (ind==0) {
        t.push_back(Node(val, p));
        ind = t.size() - 1;
        if (p!=0) 
            if (val<t[p].val) t[p].l = ind;
                        else  t[p].r = ind;
        else {}
    }
    splay(ind);
}

int query(int k) {
    int now = root;
    while (true) {
        int rl = t[now].l ? t[t[now].l].cnt : 0;
        if (k<=rl) 
            now = t[now].l;
        else if (k<=rl+t[now].rep)
            break;
        else {
            k -= rl + t[now].rep;
            now = t[now].r;
        }
    }
    splay(now);
    return t[now].val;
}

int main() {

    scanf("%d %d", &n, &m);
    for (int j, i=0; i<n; ++i) {
        scanf("%d", &j);
        a.push_back(j);
    }

    for (int j, i=0; i<m; ++i) {
        scanf("%d", &j);
        q.push_back(j);
    }

    reverse(q.begin(), q.end());
    
    t.push_back(Node(INT_MIN));
    for (int i=0; i<=n; ++i) {
        while (!q.empty() && q.back()==i) {
            int ans = query(++k);
            printf("%d\n", ans);
            q.pop_back();
        }
        if (i<n) insert(a[i]);
       
    }
    return 0;
}

