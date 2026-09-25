#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define Bismillah() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define infinity LLONG_MAX
#define aura LLONG_MIN
#define F first
#define S second
#define sesh '\n'
#define gap ' '

#define len(x) int((x).size())
#define all(n) n.begin(), n.end()
#define nsort(v) sort(v.begin(),v.end());
#define rsort(v) sort(v.rbegin(),v.rend());
#define flip(v) reverse(v.begin(),v.end());

#define Sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define Boro(vec) *(max_element(vec.begin(),vec.end()))
#define Chuto(vec) *(min_element(vec.begin(),vec.end()))
#define minidx(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxidx(a)    ( max_element((a).begin(), (a).end()) - (a).begin())

multiset<pair<ll,ll>> ms1, ms2;
ll left_sum = 0, right_sum = 0;
ll left_Multiset_Size = 0;

void rebalance() {
    while ((ll)ms1.size() > left_Multiset_Size) {
        auto it = prev(ms1.end());
        left_sum -= it->F;
        right_sum += it->F;
        ms2.insert(*it);
        ms1.erase(it);
    }
    while ((ll)ms1.size() < left_Multiset_Size && !ms2.empty()) {
        auto it = ms2.begin();
        right_sum -= it->F;
        left_sum += it->F;
        ms1.insert(*it);
        ms2.erase(it);
    }
    if (!ms1.empty() && !ms2.empty()) {
        auto itL = prev(ms1.end());
        auto itR = ms2.begin();
        if (itL->F > itR->F) {
            pair<ll,ll> a = *itL, b = *itR;
            left_sum -= a.F; right_sum -= b.F;
            left_sum += b.F; right_sum += a.F;
            ms1.erase(itL); ms2.erase(itR);
            ms1.insert(b);  ms2.insert(a);
        }
    }
}

void insert_pair(pair<ll,ll> p) {
    if (ms1.empty()) {
        ms1.insert(p);
        left_sum += p.F;
    } else {
        auto itL = prev(ms1.end());
        if (p.F <= itL->F) {
            ms1.insert(p);
            left_sum += p.F;
        } else {
            ms2.insert(p);
            right_sum += p.F;
        }
    }
    rebalance();
}

void erase_pair(pair<ll,ll> p) {
    auto it1 = ms1.find(p);
    if (it1 != ms1.end()) {
        left_sum -= it1->F;
        ms1.erase(it1);
    } else {
        auto it2 = ms2.find(p);
        if (it2 != ms2.end()) {
            right_sum -= it2->F;
            ms2.erase(it2);
        }
    }
    rebalance();
}

ll current_median() {
    return ms1.empty() ? 0 : (*prev(ms1.end())).F;
}

void IcpcDhakaRegionalist2025() {
    ll n , k ; cin >> n >> k ; vll vec(n) ;
    for (ll i = 0; i < n; i++) cin >> vec[i];

    left_Multiset_Size = (k + 1) / 2;

    for (ll i = 0; i < n; i++) {
        insert_pair({vec[i], i});

        if (i - k + 1 >= 0) {
            ll med = current_median();
            ll left_cnt = (ll)ms1.size();
            ll right_cnt = (ll)ms2.size();

            ll cost = left_cnt * med - left_sum + right_sum - right_cnt * med;
            cout << cost << gap;

            erase_pair({vec[i - k + 1], i - k + 1});
        }
    }
}

int main() {
    Bismillah();
    int testcase = 1;
    // cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        // cout << "Case " << tc << ": ";
        IcpcDhakaRegionalist2025();
    }
    return 0;
}
Share code to others
