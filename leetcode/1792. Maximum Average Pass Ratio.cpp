class Solution 
{
public:
    double maxAverageRatio(const vector<vector<int>>& classes, int extraStudents) 
    {
        const auto profit = [](const int pass, const int total) -> double const
        {
            const double currProfit = static_cast<double>(pass) / total;
            const double nextProfit = static_cast<double>(pass + 1) / (total + 1);
            return nextProfit - currProfit;
        };

        priority_queue<pair<double, pair<int, int>>> pq; // 우선순위 큐: 증가율이 가장 큰 클래스를 선택

        // 각 클래스의 초기 증가율 계산
        for (const auto& cls : classes) 
        {
            const int pass = cls[0];
            const int total = cls[1];
            pq.push({profit(pass, total), {pass, total}});
        }

        // 추가 학생 배치
        while (extraStudents > 0) 
        {
            const auto [gain, cls] = pq.top();
            pq.pop();
            int pass = cls.first;
            int total = cls.second;

            ++pass; // 학생 1명 추가
            ++total;

            // 업데이트된 클래스 다시 삽입
            pq.push({profit(pass, total), {pass, total}});
            --extraStudents;
        }

        // 최종 평균 계산
        double maxAvg = 0.0;
        while (!pq.empty()) 
        {
            const auto [gain, cls] = pq.top();
            pq.pop();
            const int pass = cls.first;
            const int total = cls.second;
            maxAvg += static_cast<double>(pass) / total;
        }

        return maxAvg / classes.size();
    }
};

// https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15
/*

문제 번역: 1792. 최대 평균 합격 비율 (Maximum Average Pass Ratio)

문제 설명

한 학교에는 여러 반이 있으며, 각 반은 학생들이 응시하는 기말시험을 진행합니다. 2차원 정수 배열 classes가 주어지며, classes[i] = [passi, totali]는 다음을 의미합니다:
	•	totali: i번째 반의 총 학생 수.
	•	passi: i번째 반에서 시험에 합격한 학생 수.

또한, 추가로 extraStudents명의 학생이 주어지며, 이 학생들은 어느 반에 배정되든 시험에 무조건 합격하는 우수 학생들입니다.

이제, extraStudents명을 적절히 배치하여 모든 반의 평균 합격 비율을 최대화하려고 합니다.
	•	한 반의 합격 비율은 해당 반에서 합격한 학생 수를 총 학생 수로 나눈 값입니다.
	•	평균 합격 비율은 모든 반의 합격 비율의 합을 반의 개수로 나눈 값입니다.

추가 학생을 각 반에 배치하여 가능한 가장 큰 평균 합격 비율을 반환하세요. 답은 10^-5 이내의 오차 범위에서 허용됩니다.

입력 및 출력 형식

입력:
	•	classes: 2D 정수 배열, 각 원소는 [passi, totali].
	•	extraStudents: 추가로 배치할 수 있는 학생 수.

출력:
	•	가능한 가장 큰 평균 합격 비율을 소수점 이하 5자리까지 반환.

예제

예제 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333

설명:
추가 학생 2명을 첫 번째 반에 배치하면 다음과 같은 상태가 됩니다:
	•	첫 번째 반: 합격 비율 = ￼
	•	두 번째 반: 합격 비율 = ￼
	•	세 번째 반: 합격 비율 = ￼

평균 합격 비율:
￼.

예제 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485

설명:
적절히 학생들을 배치하면 최대 평균 합격 비율은 ￼.

제약 조건
	1.	￼
	2.	￼
	3.	￼

문제를 쉽게 설명하기
	1.	각 반에는 합격한 학생의 비율이 있습니다.
예를 들어, [2, 4]라면 합격 비율은 ￼입니다.
	2.	추가 학생을 배치하여 합격 비율을 최대화하려고 합니다.
각 추가 학생은 합격 비율을 높이기 위해 사용됩니다.
	3.	모든 반의 합격 비율의 평균을 계산하여 이를 최대화하는 것이 목표입니다.
단, 모든 반에 추가 학생을 배치할 필요는 없습니다.
	4.	답은 소수점 이하 5자리까지 정확히 반환해야 합니다.

문제 풀이 전략
	1.	합격 비율 증가량 계산
	•	각 반에 학생을 추가했을 때 합격 비율이 얼마나 증가하는지 계산합니다.
예를 들어, [2, 4]에 학생 1명을 추가하면:
	•	기존 합격 비율: ￼
	•	추가 후 합격 비율: ￼
	•	증가량: ￼
	2.	우선순위 큐 사용
	•	합격 비율 증가량이 가장 큰 반에 추가 학생을 배치합니다.
	•	우선순위 큐(최대 힙)를 사용하여 매번 가장 큰 증가량을 가지는 반을 선택합니다.
	3.	반복 작업
	•	추가 학생이 모두 소진될 때까지 위 과정을 반복합니다.
	4.	평균 계산
	•	모든 반의 합격 비율을 더해 평균을 계산합니다.

*/
