void IcpcDhakaRegionalist2025(){
    ll n , k ; cin >> n >> k ;
    ll x , a , b , c ; cin >> x >> a >> b >> c ;

    vector<long long> vec ; vec.pb(x) ;
    while(vec.size() != n) vec.pb((a*vec.back()+b)%c) ;

    ll ans = 0 , curXor = 0 ;

    for(int i = 0 ; i < n ; i++){

        curXor ^= vec[i] ;

        if(i-k+1>=0){

            ans ^= curXor ; curXor ^= vec[i-k+1] ;

        }

    }

    cout << ans << sesh ;
}
