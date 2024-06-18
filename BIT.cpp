struct BIT {
    vector<ll> bit;
 
    BIT () {
        //bit.resize(size);
         bit.resize((ll) 6e5);
    }
 
    void update (ll i, ll val) {
        for ( ; i < n; i |= i + 1) {
            bit[i] += val;
        }
    }
 
    void update (ll l, ll r, ll val) {
        update(l, val);
        update(r + 1, -val);
    }
 
    ll get (ll i) {
        ll sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            sum += bit[i];
        return sum;
    }
    ll get(ll l,ll r){
        return(get(r)- get(l-1));
    }
}; 
 