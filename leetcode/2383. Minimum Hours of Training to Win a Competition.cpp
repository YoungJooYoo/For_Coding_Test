class Solution 
{
public:
    int minNumberOfHours(const int initialEnergy, const int initialExperience, const vector<int>& energy, const vector<int>& experience) 
    {
        const int TOTAL_ENERGY = accumulate(energy.begin(), energy.end(), 0);
        const size_t LENGTH = energy.size();

        int hours = max(0, TOTAL_ENERGY - initialEnergy + 1);
        int currentExperience = initialExperience ;

        for (size_t i = 0; i < LENGTH; ++i) 
        {
            if (currentExperience <= experience[i]) 
            {
                hours += (experience[i] - currentExperience + 1);
                currentExperience = experience[i] + 1;
            }
            currentExperience += experience[i];
        }

        return hours;
    }
};

// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/

/*
문제 설명 (Korean Translation)
당신은 대회에 참가하게 되었고, 초기 에너지(initialEnergy)와 초기 경험치(initialExperience)를 나타내는 두 개의 양의 정수와, 
두 개의 0-인덱스 정수 배열인 에너지(energy)와 경험치(experience)가 주어집니다. 두 배열의 길이는 n입니다.

당신은 순서대로 n명의 상대와 맞서 싸워야 합니다.
 i번째 상대의 에너지와 경험치는 각각 energy[i]와 experience[i]로 나타냅니다. 
 상대를 물리치기 위해서는 상대보다 에너지와 경험치가 모두 더 높아야 하며, 
 그렇게 하면 다음 상대와 싸울 수 있습니다.

i번째 상대를 물리치면 당신의 경험치는 experience[i]만큼 증가하지만, 
에너지는 energy[i]만큼 감소합니다.

경쟁을 시작하기 전에, 당신은 몇 시간 동안 훈련할 수 있습니다. 
훈련을 할 때마다 당신은 초기 경험치를 1만큼 증가시키거나 초기 에너지를 1만큼 증가시킬 수 있습니다.

모든 n명의 상대를 물리치기 위해 필요한 최소 훈련 시간을 반환하세요.

예제
예제 1:

입력: initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
출력: 8
설명:
초기 에너지를 11까지 6시간 동안 훈련하고, 경험치를 5까지 2시간 동안 훈련합니다.
상대들을 다음 순서대로 만나게 됩니다:
0번째 상대를 이겨서 에너지는 11 - 1 = 10이 되고, 경험치는 5 + 2 = 7이 됩니다.
1번째 상대를 이겨서 에너지는 10 - 4 = 6이 되고, 경험치는 7 + 6 = 13이 됩니다.
2번째 상대를 이겨서 에너지는 6 - 3 = 3이 되고, 경험치는 13 + 3 = 16이 됩니다.
3번째 상대를 이겨서 에너지는 3 - 2 = 1이 되고, 경험치는 16 + 1 = 17이 됩니다.
총 6 + 2 = 8시간의 훈련이 필요합니다.
예제 2:

입력: initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
출력: 0
설명: 추가 훈련 없이 대회를 이길 수 있으므로 0을 반환합니다.
제약 조건
n == energy.length == experience.length
1 <= n <= 100
1 <= initialEnergy, initialExperience, energy[i], experience[i] <= 100
문제 풀이 방법
이 문제는 간단한 시뮬레이션 문제입니다. 각 상대를 물리치기 위해 필요한 에너지와 경험치를 계산하면서, 부족한 경우 필요한 만큼 훈련 시간을 추가해 나가면 됩니다.

초기 에너지를 모두 사용할 수 있도록 계산합니다.
각 상대를 차례로 만나면서, 현재 에너지와 경험치가 상대보다 적으면, 필요한 만큼 훈련 시간을 추가합니다.
모든 상대를 이기기 위해 필요한 총 훈련 시간을 계산하여 반환합니다.

*/
