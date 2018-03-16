#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
#define cind(x) scanf("%d", &x)
#define cindln(x) scanf("%d\n", &x)
#define cinc(x) scanf("%c", &x)

using namespace std;

const int MAXQ = 1e5 + 7;

// without undo operations

class Query {
public:
    char t;
    string a;
    int x;
    Query(){}
    Query(char c, int p):
        t(c), x(p) {}
    Query(char c, string name):
        t(c), a(name) {}
    Query(char c, string name, int p):
        t(c), a(name), x(p) {}
};

class Node {
public:
    int cnt, l, r;
    int s[2];
    Node() {
        cnt = s[0] = s[1] = 0;
    }
};

int Q;

vector<Query> query(1);
vector<int> xs(1);
Node t[MAXQ<<2];
unordered_map<string, int> task;
int link[MAXQ];

inline int get_mid(int l,int r) { return (l+r)>>1; }

void refresh(int node) {
    t[node].cnt = t[t[node].s[0]].cnt + t[t[node].s[1]].cnt;
}

void build(int node, int l, int r) {
    t[node].l = l, t[node].r = r;

    if (l!=r) {
        t[node].s[0] = node << 1;
        t[node].s[1] = node << 1 | 1;
        build(t[node].s[0], l, (l+r)>>1);
        build(t[node].s[1], ((l+r)>>1) + 1, r);
    }
}

void read_in() {
    char c;

    for (int x,q=1; q<=Q; ++q) {
        cinc(c);
        for (char t='1'; t!=' '; cinc(t));
        if (c=='u') {  //undo
            cind(x);
            query.emplace_back('u',  x);
        } else {
            string name;
            char t;
            for (cinc(t); isalpha(t); cinc(t)) 
                name.push_back(t);
            
            if (c=='q' || c=='r')  
                query.emplace_back(c, name);
            else { // set
                cindln(x);
                query.emplace_back(c, name, x);
                xs.push_back(x);
            }
        }
    }

    sort(xs.begin()+1, xs.end());
    xs.resize(unique(xs.begin()+1, xs.end()) - xs.begin()); // distinct
    if (!xs.empty()) build(1, 1, xs.size());
}

void update(int node, int pos, int delta) {
    Node& n = t[node];
    if (n.l==n.r)
        n.cnt += delta;
    else {
        update(t[node].s[pos>get_mid(n.l, n.r)], pos, delta);
        refresh(node);
    }
}

int dfs(int node, int p) {
    Node& n = t[node];
    // printf("%d %d %d %d %d\n", node, n.l, n.r, n.cnt, p);
    if (n.l>=p) return 0;
    if (n.r<p) return n.cnt;
    return dfs(n.s[0], p) + dfs(n.s[1], p);
}

int main() {
    cindln(Q);

    read_in();

    for (int q=1; q<=Q; ++q) {
        Query& qr = query[q];
        // printf("%c\n", qr.t);
        // cout << qr.a << endl;
        if (qr.t=='s') {
            int pos = lower_bound(xs.begin()+1, xs.end(), qr.x) - xs.begin();
            auto it = task.find(qr.a);
            if (it==task.end()) {
                task[qr.a] = qr.x;
                update(1, pos, 1);
            } else {
                int prepos = lower_bound(xs.begin()+1, xs.end(), it->second) 
                                - xs.begin();
                it->second = qr.x;
                update(1, prepos, -1);
                update(1, pos, 1);
            }
        } else if (qr.t=='r') {
            auto it = task.find(qr.a);
            if (it!=task.end()) {
                int pos = lower_bound(xs.begin()+1, xs.end(), it->second) 
                                - xs.begin();
                task.erase(it);
                update(1, pos, -1);
            }
        } else if (qr.t=='q') {
            auto it = task.find(qr.a);
            if (it==task.end()) {
                printf("%d\n", -1);
            } else {
                int pos = lower_bound(xs.begin()+1, xs.end(), it->second) 
                                - xs.begin();   
                printf("%d\n", dfs(1, pos));
            }
            fflush(stdout);
        } else {
            // int now = q-1, pre = now - qr.x - 1;
            // while (now!=pre) 
            //     if (query[now].t=='s')
        }
    }

    return 0;
}