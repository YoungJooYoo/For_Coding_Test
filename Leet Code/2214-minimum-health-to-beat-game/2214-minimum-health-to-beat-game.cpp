class Solution 
{
public:
    long long minimumHealth(vector<int>& damage, int armor) 
    {
        long long result = 0;
        
        // 오름 차순 정렬
        sort(damage.begin(), damage.end(), [](int i, int j) { return j < i; });
        
        // 정렬 후, 배열의 맨 앞 값이 최대값
        result = damage[0] - armor; // 최대값에서 armor를 빼야 가장 효율적이다.
        result = result < 0 ? 0 : result; // 뺀 값이 음수라면 0, 양수라면 원래 result
        
        // result에 모든 값을 누적
        for (const auto& ele : damage) {
            result += ele; 
        }
        
        // 위애서 damage[0]이 중복으로 더했으니, 한번 뺴주고, + 1 해야 문제 요구사항이 된다.
        return result - damage[0] + 1;
    }
};