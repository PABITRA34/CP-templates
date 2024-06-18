ll seg[1000001];
 ll lazy[1000001];
 
void build(ll idx, ll low, ll hi,vector<ll>&arr){
     if(low==hi){
        seg[idx]=arr[low];
        return;
     }
 
     ll mid= low + (hi-low)/2;
     build(2*idx+1,low,mid,arr);
     build(2*idx+2,mid+1,hi,arr);
 
     seg[idx]= max(seg[2*idx+1] , seg[2*idx+2]);
}
 
ll query(ll idx,ll low, ll hi, ll l , ll r,vector<ll>&arr){
   //no overlap
//    lr lo hi  or lo hi lr
     if(r<low || l>hi) return INT_MIN;
 
     // complete overlap
    //  l lo hi r
      if(low>=l && hi<=r){
        return seg[idx];
     }
//    partial overlap
    ll  mid= low+(hi-low)/2;
    // ll mid= (low+hi)/2;
    ll left= query(2*idx+1,low,mid,l,r,arr);
    ll right= query(2*idx+2,mid+1,hi,l ,r, arr);
    return max(left , right);
}
 
void update(ll idx, ll lo, ll hi, ll i, ll val,vector<ll>&arr){
    if(lo==hi){
        seg[idx]=val;
        return;
    }
 
    ll mid= lo +(hi-lo)/2;
    if(i<=mid) update(2*idx+1,lo,mid,i,val,arr);
    else update(2*idx+2,mid+1,hi,i,val,arr);
 
    seg[idx]= max(seg[2*idx+1],seg[2*idx+2]);
 
 
}
