void IcpcDhakaRegionalist2025(){
    int n , k ; cin >> n >> k ; vector<int> vec(n) ;
    for(int i = 0 ; i < n ; i++) cin >> vec[i] ;

    map<int,int> freq ; set<int> mex ;
    for(int i = 0 ; i <= k ; i++) mex.insert(i) ;
    for(int i = 0 ; i < n ; i++){
        freq[vec[i]]++ ; if(mex.count(vec[i])) mex.erase(vec[i]) ;
        if(i-k+1>=0){
            cout << *mex.begin() << gap ;
            if(freq[vec[i-k+1]]>1){
                freq[vec[i-k+1]]-- ;
            }else{
                freq.erase(vec[i-k+1]) ; mex.insert(vec[i-k+1]) ;
            }
        }
    }
}
