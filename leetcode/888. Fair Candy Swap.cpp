class Solution 
{
public:
    vector<int> fairCandySwap(const vector<int>& aliceSizes, const vector<int>& bobSizes) 
    {
        const int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        const int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        const int target = (sumAlice - sumBob) / 2;
        
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        vector<int> result;
        
        for (const int& x : aliceSizes) 
        {
            if (bobSet.count(x - target)) 
            {
                result = {x, x - target};
                break;
            }
        }
        
        return result;
    }
};


/*

앨리스와 밥은 서로 다른 총 개수의 사탕을 가지고 있습니다. aliceSizes와 bobSizes라는 두 개의 정수 배열이 주어집니다. aliceSizes[i]는 앨리스가 가진 i번째 사탕 상자의 사탕 개수이고, bobSizes[j]는 밥이 가진 j번째 사탕 상자의 사탕 개수입니다.
그들은 친구이므로 서로 한 개의 사탕 상자를 교환하여 교환 후 둘 다 동일한 총 사탕 개수를 가지길 원합니다. 한 사람이 가진 총 사탕 개수는 그 사람이 가진 모든 상자의 사탕 개수의 합입니다.
answer은 앨리스가 교환해야 하는 상자의 사탕 개수, answer은 밥이 교환해야 하는 상자의 사탕 개수인 정수 배열 answer를 반환하세요. 여러 가지 답이 있는 경우 아무 것이나 반환할 수 있습니다. 최소한 하나의 답이 존재한다는 것이 보장됩니다.
문제 풀이 방향:
앨리스와 밥의 총 사탕 개수를 계산합니다.
총 사탕 개수의 차이를 계산하고 2로 나눕니다. 이 값이 교환해야 하는 사탕 개수 차이입니다.
앨리스의 각 사탕 상자에 대해, 밥의 사탕 상자 중에서 교환 후 총 사탕 개수가 같아지는 상자가 있는지 확인합니다.
그런 상자를 찾으면 해당 상자의 사탕 개수를 반환합니다.
이 문제는 두 배열을 탐색하며 적절한 교환 상자를 찾는 방식으로 해결할 수 있습니다. 시간 복잡도는 O(m*n)이며, m과 n은 각각 aliceSizes와 bobSizes의 길이입니다. 공간 복잡도는 O(n)입니다(bobSizes를 집합으로 변환하는 경우).
*/

// https://leetcode.com/problems/fair-candy-swap/description/
