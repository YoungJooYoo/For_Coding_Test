class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        int result = 0;
        int currBatch;
        
        // boyTypes에 두번쨰 값, 즉 값이 큰 순서대로 정렬한다.
        sort(begin(boxTypes), end(boxTypes), [](const auto& a, const auto& b){return a[1] > b[1];}); 
        //sort(boxTypes.begin(), boxTypes.end(), greater<>());
        
        for (const auto& elem : boxTypes) { // carrying as many larger sized boxes as we can first
            currBatch = min(elem[0], truckSize); // elem[0]을 계속 선택하다. 막판에 truckSize가 elem[0]보다 작을때 truckSize 선택
            truckSize -= currBatch; // truckSize를 감소시키면서,
            result += currBatch * elem[1]; // 문제 조건 (박스 * 유닛)
            if (truckSize == 0) {
                break;
            }
        }
        
        return result;
    }
};
