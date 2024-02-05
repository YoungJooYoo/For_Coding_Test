class BrowserHistory {
public:
    BrowserHistory(const string& homepage) 
    {
        mHistory.push_back(homepage); // 홈페이지를 최초 페이지로 추가
    }
    
    void visit(const string& url) 
    {
        ++index; // 현재 위치를 한 칸 앞으로 이동
        if (index < mHistory.size()) {
            mHistory[index] = url; // 현재 위치에 url 할당
            mHistory.resize(index + 1); // 벡터의 크기를 현재 위치 이후로 조정
        } 
        else {
            mHistory.push_back(url); // 현재 위치가 벡터의 크기를 초과하면 url 추가
        }
    }
    
    string back(const int steps) 
    {
        index -= steps; // 인덱스를 steps만큼 뒤로 이동
        if (index < 0) index = 0; // 인덱스가 범위를 벗어나면 0으로 설정
        return mHistory[index]; // 변경된 위치의 페이지 반환
    }
    
    string forward(const int steps) 
    {
        index += steps; // 인덱스를 steps만큼 앞으로 이동
        if (index >= mHistory.size()) index = mHistory.size() - 1; // 인덱스가 범위를 벗어나면 마지막으로 설정
        return mHistory[index]; // 변경된 위치의 페이지 반환
    }
private:
    vector<string> mHistory;
    int index = 0; // 현재 위치를 추적하는 인덱스
};

// https://leetcode.com/problems/design-browser-history/
