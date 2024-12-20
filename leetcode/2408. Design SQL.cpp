class SQL 
{
public:
    SQL(const vector<string>& names, const vector<int>& columns)
    : mID(INIT_VALUE)
    {
        
    }
    
    void insertRow(const string& name, const vector<string>& row) 
    {
        mTable[name].push_back(row);
        ++mID;
    }
    
    void deleteRow(const string& name, const int rowId) 
    {
    
    }
    
    string selectCell(const string name, const int rowId, const int columnId)
    {
        assert(rowId - 1 >= 0 && columnId - 1 >= 0);
        return mTable[name][rowId - 1][columnId - 1];
    }

private:
    unordered_map<string, vector<vector<string>>> mTable;
    size_t mID;

    enum { INIT_VALUE = 1 };
};

// https://leetcode.com/problems/design-sql/description/
