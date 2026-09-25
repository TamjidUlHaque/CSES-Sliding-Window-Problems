void IcpcDhakaRegionalist2025() {
    ll n , k ; cin >> n >> k ; ll cnt = 0 , current = 0 ;
    ll x , a , b , c ; cin >> x >> a >> b >> c ;
    vll vec(1,x) ; while(vec.size() != n) vec.pb((vec.back()*a+b)%c) ;
    vll prefix(n+5,0) , suffix(n+5,0) ;
    for(int i = 1 ; i <= n ; i++){
        current |= vec[i-1] ; prefix[i] = current ; cnt++ ;
        if(cnt==k){
            cnt = 0 ; current = 0 ;
        }
    }

    cnt = n % k ; current = 0 ; ll answer = 0 ;

    if(cnt==0) cnt = k ;

    for(int i = n ; i >= 1 ; i--){
        current |= vec[i-1] ; suffix[i] = current ; cnt-- ;
        if(cnt==0){
            cnt = k ; current = 0 ;
        }
    }

    for(int i = k ; i <= n ; i++){
        answer ^= (prefix[i] | suffix[i-k+1]) ;
    }

    cout << answer << sesh ;
}
