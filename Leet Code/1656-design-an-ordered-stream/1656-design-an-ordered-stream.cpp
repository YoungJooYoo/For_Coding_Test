class OrderedStream {
public:
    OrderedStream(int n) 
    {
        stream.resize(n);
    }
    
    vector<string> insert(int id, string value) 
    {
        vector<string> result;
        stream[id - 1] = value; // value is stored in the ith position
        
        while (i < stream.size() && stream[i] != "") //stream[i] !="" because an entry is printed only if the entry before it is printed
        {
            result.push_back(stream[i]);
            i++;
        }
        
        return result;
    }
    
private:
    vector<string> stream ; //to get input
    int i = 0;
};