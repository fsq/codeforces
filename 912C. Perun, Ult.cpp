#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

using POSTYPE = vector<multiset<pair<long long,int>>::iterator>;

long long bounty, damage, increase;
long long stable, max_prof;
vector<vector<long long>> monsters;

long long update(multiset<pair<long long, int>>& st, POSTYPE& pos, vector<vector<long long>>& events) {
    long long time = 0;
    if (!events.empty()) time = events.back()[0];
    while (!events.empty() && (st.empty() || events.back()[0]<=st.begin()->first)) {
        int ind = events.back()[1];
        long long start = events.back()[0], health = events.back()[2];
        long long prof_now = (st.size()+stable)*(bounty + (start-1)*increase);
        max_prof = max(max_prof, prof_now);

        if (pos[ind]!=st.end()) {
            st.erase(pos[ind]);
            pos[ind] = st.end();
        }
        if (monsters[ind][2]>0) 
            if (health<=damage) 
                pos[ind] = st.insert({start+(damage-health)/monsters[ind][2], ind});
            else {}
        else {
            if (monsters[ind][1]<=damage && health>damage)
                --stable;
            else if (monsters[ind][1]>damage && health<=damage)
                ++stable;
            monsters[ind][1] = health;
            time = events.back()[0];
        }
        events.pop_back();
    }
    return st.empty() ? time : st.begin()->first;
} 

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    cin >> bounty >> increase >> damage;

    monsters = {{}};
    bool INF = false;
    {
        long long max_health, start_health, regen;
        for (int i=1; i<=n; ++i) {
            cin >> max_health >> start_health >> regen;
            if (max_health<=damage && increase>0) {
                INF = true;
                break;
            }
            monsters.push_back({max_health, start_health, regen});
        }
    }

    if (!INF) {
        vector<vector<long long>> events;
        {
            long long time, enemy, health;
            for (int i=0; i<m; ++i) {
                cin >> time >> enemy >> health;
                events.push_back({time, enemy, health});
            }
            sort(events.begin(), events.end(), greater<vector<long long>>());
        }

        max_prof = 0;
        stable = 0;
        multiset<pair<long long, int>> st;
        POSTYPE pos(n+1, st.end());
        for (int i=1; i<=n; ++i)
            if (monsters[i][1]<=damage) 
                if (monsters[i][2]>0)
                    pos[i] = st.insert({(damage-monsters[i][1])/monsters[i][2], i});
                else 
                    ++stable;
        max_prof = stable;

        while (!(st.empty() && events.empty())) {
            long long time = update(st, pos, events);
            long long prof_now = (st.size()+stable)*(bounty + time*increase);

            max_prof = max<long long>(max_prof, prof_now);
            while (!st.empty() && st.begin()->first==time) {
                pos[st.begin()->second] = st.end();
                st.erase(st.begin());
            }
        }

        cout << (stable==n && increase>0? -1 : max_prof) << endl;
            
    } else 
        cout << -1 << endl;
    return 0;
        
}