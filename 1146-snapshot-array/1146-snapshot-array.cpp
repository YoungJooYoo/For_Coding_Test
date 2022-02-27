class SnapshotArray {
public:
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        mp[snap_index][index] = val;
        
    }
    
    int snap() {
        snap_index++;
        return snap_index - 1;
    }
    
    int get(int index, int snap_id) {
        for (int i = snap_id; i >= 0; i--) {
            if (mp[i].count(index) == 1)
                return mp[i][index];
        }
        
        return 0;
    }
    
private:
    unordered_map<int, unordered_map<int, int>> mp;
    int snap_index = 0;
};