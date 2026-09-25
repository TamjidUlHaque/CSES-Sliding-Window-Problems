void IcpcDhakaRegionalist2025(){
    int n , k ; cin >> n >> k ; vector<int> vec(n) ;
    for(int i = 0 ; i < n ; i++) cin >> vec[i] ;

    map<int,int> freq ; map<int,set<int>> memory ;

    for(int i = 0 ; i < n ; i++){
        int oldFreq = freq[vec[i]] ; freq[vec[i]]++ ;

        if(oldFreq){
            memory[oldFreq].erase(vec[i]) ;
        }
        if(memory[oldFreq].empty()){
            memory.erase(oldFreq) ;
        }

        memory[freq[vec[i]]].insert(vec[i]) ;

        if(i-k+1>=0){
            cout << *(memory.rbegin()->second.begin()) << gap ;
            oldFreq = freq[vec[i-k+1]] ; freq[vec[i-k+1]]-- ;
            if(oldFreq){
                memory[oldFreq].erase(vec[i-k+1]) ;
            }
            if(memory[oldFreq].empty()){
                memory.erase(oldFreq) ;
            }
            if(oldFreq>1){
                memory[freq[vec[i-k+1]]].insert(vec[i-k+1]) ;
            }
        }
    }
}
