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

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */