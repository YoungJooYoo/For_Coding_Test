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
        
        if (itr == mp[key].begin())
        {
            return "";
        }
        
        itr--;

        int time = itr->first;
        
        return mp[key][time];
    }
    
private :
    unordered_map<string, map<int, string>> mp;
};