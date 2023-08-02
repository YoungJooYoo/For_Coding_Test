class MovingAverage {
public:
    MovingAverage(int size) : max_size(size), sum(0) {}
    
    double next(int val) 
    {
        sum  += val;
        list.push(val);
        int list_size = list.size();
        if (list_size <= max_size) {
            return sum / list_size;
        }
        else { // list_size > max_size, 이 경우 front에서 하나씩 값을 뺀다.
            sum -= list.front(); 
            list.pop();
            return sum / max_size;
        }
    }
    
private:
    queue<int> list;
    const int max_size;
    double sum;
};