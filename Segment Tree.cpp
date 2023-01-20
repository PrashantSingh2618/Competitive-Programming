class SegTree {
    vector<int>seg ;
    public:
        SegTree(int n){
            seg.resize(4*n+1, INT_MAX);
        }
    
    void build(int low, int high ,vector<int>&arr, int index){
        if(low == high ){
            seg[index] = arr[low];
            return ;
        }
        int mid = (low + high )>>1 ;
        build(low, mid, arr, 2*index + 1);
        build(mid + 1, high, arr, 2*index+2);
        seg[index] = min(seg[2*index+1], seg[2*index+2]);
    }
    int query(int low, int high , int l, int r, int index){
        // no overlap
        if(low > r || high < l)
            return INT_MAX ;
        
        // complete
        if(l <= low && high <=r)
            return seg[index];
        
        int mid = (low + high )>>1 ;
        int left = query(low, mid, l, r, 2*index+1) ;
        int right = query(mid+1,high, l, r, 2*index+2) ;
        return min(left, right) ;
    }
    void update(int low, int high, int index, int updatedIndex, int val, vector<int>&arr){
        if(low == high ){
            seg[index] = val ;
            arr[updatedIndex] = val ;
            return ;
        }
        int mid = (low + high ) >> 1 ;
        if(updatedIndex <= mid)
            update(low , mid , 2*index+1,updatedIndex, val, arr);
        else
            update(mid+1, high, 2*index+2,updatedIndex, val, arr);
        seg[index] = min(seg[2*index+1], seg[2*index+2]) ;
    }
};
