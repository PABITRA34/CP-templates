//AlgoBot
// One based indexing
const int N = 1e5 + 5, MOD = 1e9 + 7;
ll inp[N];
struct Segment_Tree{
    ll ST[N],lazy[N];
    void propagate(ll SI,ll b,ll e){
        if(lazy[SI]!=0){
            ST[SI]+=lazy[SI];
            if(b!=e){
                lazy[2*SI]+=lazy[SI];
                lazy[2*SI+1]+=lazy[SI];
            }
            lazy[SI]=0;
        }
        return;
    }
    void build(ll SI,ll b,ll e){
        if(b==e){
            ST[SI]=0;
            return;
        }
        ll left=2*SI;
        ll right=left+1;
        ll mid=(b+e)/2;
        build(left,b,mid);
        build(right,mid+1,e);
        ST[SI]=ST[left]+ST[right];
    }
    // increament by val
    void update(ll SI,ll b,ll e,ll l,ll r,ll val){
        if(b>r || e<l){
            return;
        }
        if(b>=l && e<=r){
            ST[SI]+=val;
            return;
        }
        ll left=2*SI;
        ll right=left+1;
        ll mid=(b+e)/2;
        update(left,b,mid,l,r,val);
        update(right,mid+1,e,l,r,val);
        ST[SI]=ST[left]+ST[right];
    }
    ll query(ll SI,ll b,ll e,ll l,ll r){
        if(b>r || e<l){
            return 0;
        }
        if(b>=l && e<=r){
            return ST[SI];
        }
        ll left=2*SI;
        ll right=left+1;
        ll mid=(b+e)/2;
        ll L=query(left,b,mid,l,r);
        ll R=query(right,mid+1,e,l,r);
        return L+R;
    }
}tr;

//
/*
void solve()
{
    
    ll n; cin>>n;     
    
    STree.build(1,1,n); 
    tr.build(1,1,n); 

    vector<ll>a={0,1,2,3,4,5};
    vector<ll>b={0,1,1,1,1,1};
    for(ll i=1;i<=n-1;i++){
      STree.update(1,1,n, i, i, a[i]);
      tr.update(1,1,n, i, i, b[i]);
    }
       
    cout<<tr.query(1,1,n,1,3)<<"\n"; //1
    tr.update(1,1,n, 1, 1, 10);//16
    cout<<tr.query(1,1,n,1,3)<<"\n";   
     
}


*/














//////////////////////////////////////////////////////
//Striver











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
