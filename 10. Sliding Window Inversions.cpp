#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define Bismillah() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<long long> vll ;
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

void IcpcDhakaRegionalist2025(){

    long long n , k ; cin >> n >> k ; vector<long long> vec(n) ;
    for(long long i = 0 ; i < n ; i++) cin >> vec[i] ;

    ordered_set<pair<long long,long long>> osat ; long long inversionCount = 0 ;

    for(long long i = 0 ; i < n ; i++){

        long long inv = ( osat.size() - osat.order_of_key({vec[i],i}) ) ;
        inversionCount += inv ;
        osat.insert({vec[i],i}) ;

        if(i-k+1>=0){
            cout << inversionCount << gap ;
            inversionCount -= (osat.order_of_key({vec[i-k+1],i-k+1})) ;
            osat.erase({vec[i-k+1],(i-k+1)}) ;
        }

    }

}


int main(){
    Bismillah() ;

    int testcase = 1 ;

    //cin >> testcase ;

    for(int tc = 1 ; tc <= testcase ; tc++){
        //cout << "Case " << tc << ": " ;
        IcpcDhakaRegionalist2025() ;
    }

    return 0 ;
}
