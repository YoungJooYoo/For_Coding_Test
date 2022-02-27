class SnapshotArray {
public:
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        mp[mp_snap_index][index] = val;
    }
    
    int snap() {
        mp_snap_index++; 
        return mp_snap_index - 1;
    }
    
    int get(int index, int snap_id) {
        for (int i = snap_id; i >= 0; i--) {
            if (mp[i].count(index) == 1) // index 존재 유무 확인
                return mp[i][index];
        }
        
        return 0;
    }
    
private:
    unordered_map<int, unordered_map<int, int>> mp; // 변경사항을 저장하기 위한 해시
    int mp_snap_index = 0; // mp 전용 인덱스
};