class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string, string> cities;

        for (const auto& path : paths) {
            cities[path[0]] = path[1]
        }

        string city = paths[0][0];
        while(cities.find(city) != cities.end()) {
            city = cities[city];
        }

        return city;
    }
};


// https://leetcode.com/problems/destination-city/description/
