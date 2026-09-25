void IcpcDhakaRegionalist2025(){
    ll n , k ; cin >> n >> k ; ll sum = 0 ;
    ll x , a , b , c ; cin >> x >> a >> b >> c ;
    vll vec ; vec.pb(x) ; ll curSum = 0 ;
    for(int i = 1 ; i < n ; i++){
        vec.pb((vec.back()*a + b)%c) ;
    }
    ll idx = 0 ;
    for(int i = 0 ; i < n ; i++){
        curSum += vec[i] ;
        if((i+1)>=k){
            sum = (sum ^ curSum) ;
            curSum -= vec[idx++] ;
        }
    }
    cout << sum << sesh ;
}
