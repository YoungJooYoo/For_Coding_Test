class StockPrice {
public:
    StockPrice() : last_timestamp(0),
                   last_price(0)
    {
    }
    
    void update(int timestamp, int price) 
    {
        auto it = m.find(timestamp);
        if (it != end(m))
            prices.erase(prices.find(it->second));
        prices.insert(price);
        m[timestamp] = price;
        if (timestamp >= last_timestamp) {
            last_timestamp = timestamp;
            last_price = price;
        }
    }
    
    int current() 
    {
        return last_price;
    }
    
    int maximum() 
    {
        return *rbegin(prices);
    }
    
    int minimum() 
    {
        return *begin(prices);
    }
    
private:
    unordered_map<int, int> m;
    multiset<int> prices;
    int last_timestamp;
    int last_price; 
};