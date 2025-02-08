class NumberContainers 
{
public:
    NumberContainers() 
    {

    }

    void change(const int index, const int number) 
    {
        if (indexToValue.find(index) != indexToValue.end() && indexToValue[index] != number) 
        {
            const int oldNumber = indexToValue[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty() == true) 
            {
                numberToIndices.erase(oldNumber);
            }
        }
        // 인덱스에 새 값을 저장하고, 해당 값에 대한 인덱스 집합에 추가합니다.
        indexToValue[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(const int number)
    {    
        if (numberToIndices.find(number) == numberToIndices.end() || numberToIndices[number].empty() == true) 
        {
            return NOT_FOUND;
        }
        
        return *numberToIndices[number].begin();
    }

private:
    unordered_map<int, int> indexToValue; 
    unordered_map<int, set<int>> numberToIndices;
    
    enum 
    {
        NOT_FOUND = -1
    };
};



// https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08
