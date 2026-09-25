void IcpcDhakaRegionalist2025(){
    ll n , k ; cin >> n >> k ;
    ll x , a , b , c ; cin >> x >> a >> b >> c ;

    vector<long long> vec ; vec.pb(x) ;
    while(vec.size() != n) vec.pb((a*vec.back()+b)%c) ;

    ll ans = 0 ; deque<ll> window ;

    for(int i = 0 ; i < n ; i++){

        while(!window.empty() and vec[window.back()] >= vec[i]){
            window.pop_back() ;
        }

        window.push_back(i) ;

        if(i-k+1 > window.front()) window.pop_front() ;

        if(i-k+1>=0){
            ans ^= vec[window.front()] ;
        }

    }

    cout << ans << sesh ;
}
