// This code is using the most powerful tool called Ordered Set .

void IcpcDhakaRegionalist2025(){
    ll n , k ; cin >> n >> k ; vll vec(n) ; tamjid(n) cin >> vec[i] ;
    ordered_set<pair<ll,ll>> osat ; ll lptr = 0 ; ll rptr = 0 ;
    while(rptr-lptr<k) osat.insert({vec[rptr],rptr++}) ;
    while(rptr<n){
        cout << osat.find_by_order((k-1)/2)->F << gap ;
        osat.erase(osat.find({vec[lptr],lptr++})) ;
        osat.insert({vec[rptr],rptr++}) ;
    }
    cout << osat.find_by_order((k-1)/2)->F << sesh ;
}


// This code doesn't use ordered set , rather than it uses two multiset and balance between them .

void IcpcDhakaRegionalist2025(){
    ll n , k ; cin >> n >> k ; vll vec(n) ; tamjid(n) cin >> vec[i] ;
    multiset<ll> small , large ;
    for(int i = 0 ; i < n ; i++){
        if(small.empty()){
            small.insert(vec[i]) ;
        }else if(*small.rbegin()<vec[i]){
            large.insert(vec[i]) ;
        }else{
            small.insert(vec[i]) ;
        }

        if(len(small)>len(large)+1){
            large.insert(*small.rbegin()) ; small.erase(prev(small.end())); ;
        }

        if(len(large)>len(small)){
            small.insert(*large.begin()) ; large.erase(large.begin()); ;
        }

        if(i+1>=k){
            cout << *small.rbegin() << gap ;
            if(small.find(vec[i-k+1]) != small.end()) small.erase(small.find(vec[i-k+1])) ;
            else large.erase(large.find(vec[i-k+1]));
        }

        if(len(small)>len(large)+1){
            large.insert(*small.rbegin()) ; small.erase(prev(small.end())); ;
        }

        if(len(large)>len(small)){
            small.insert(*large.begin()) ; large.erase(large.begin()); ;
        }

    }
}
