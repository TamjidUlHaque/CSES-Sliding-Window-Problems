void IcpcDhakaRegionalist2025(){
    ll n , k ; cin >> n >> k ; vll vec(n) ;
    for(int i = 0 ; i < n ; i++) cin >> vec[i] ;
    map<ll,ll> window ;

    for(int i = 0 ; i < n ; i++){
        window[vec[i]]++ ;
        if(i-k+1>=0){
            cout << window.size() ;
            cout << (i == n-1 ? '\n' : ' ') ;
            if(window[vec[i-k+1]]>1){
                window[vec[i-k+1]]-- ;
            }else{
                window.erase(vec[i-k+1]) ;
            }
        }
    }

}
