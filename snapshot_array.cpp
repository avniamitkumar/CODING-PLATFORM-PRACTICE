
#include <bits/stdc++.h>
class SnapshotArray {
public:
   // unordered_map<int,vector<int>>mp;
    vector<map<int,int>> v;
    int snap_id=0;
    SnapshotArray(int length) {
        v.resize(length);
         
        for(auto& it:v){
            it[0]=0;
        }
       // snap_id=0;
    }
    
    
    void set(int index, int val) {
       // arr[index]=val;
       v[index][snap_id]=val;
    }
    
    int snap() {
        // mp.insert({s_id,arr});
        // s_id++;
        // return s_id-1;
        // mp[snap_id] = arr;
         return snap_id++;

        
    }
    
    int get(int index, int snap_id) {
        map<int,int>&m=v[index];
        auto it=m.upper_bound(snap_id);
        return (--it)->second;
    }}
;
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */