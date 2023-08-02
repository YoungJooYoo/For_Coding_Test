class TimeMap 
{
public:
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) 
    {
        auto itr = mp[key].upper_bound(timestamp);
        
        if (itr == mp[key].begin()) // begin하고 같으면 존재하지 않음
        {
            return "";
        }
        
        itr--;

        int time = itr->first; // mp[key] 접근 후 map에 관련 itr이므로 first는 time
        
        return mp[key][time];
    }
    
private :
    unordered_map<string, map<int, string>> mp;
};