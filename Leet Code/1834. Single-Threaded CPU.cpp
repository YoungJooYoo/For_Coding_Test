class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i); // Append task index to each task
        }
        sort(begin(tasks), end(tasks)); // Sort tasks by their enqueue time

        int currentTime = 0;
        int taskIndex = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> processingQueue; // Min-heap for processing time and index
        vector<int> processingOrder;

        while (taskIndex < tasks.size()) {
            // Load tasks that are available at currentTime or if the queue is empty
            while (taskIndex < tasks.size() && (tasks[taskIndex][0] <= currentTime || processingQueue.empty())) {
                if (processingQueue.empty() && currentTime < tasks[taskIndex][0]) {
                    currentTime = tasks[taskIndex][0];
                }
                processingQueue.push({tasks[taskIndex][1], tasks[taskIndex][2]});
                taskIndex++;
            }

            // Process the task at the top of the priority queue
            auto [processingTime, originalIndex] = processingQueue.top();
            processingOrder.push_back(originalIndex);
            currentTime += processingTime;
            processingQueue.pop();
        }

        // Process remaining tasks in the priority queue
        while (!processingQueue.empty()) {
            processingOrder.push_back(processingQueue.top().second);
            processingQueue.pop();
        }

        return processingOrder;
    }
};

// https://leetcode.com/problems/single-threaded-cpu/description/

/*

1. 번역:

1834. 단일 스레드 CPU
중간
주제
회사
힌트
2D 정수 배열 tasks를 통해 0부터 n - 1까지 레이블이 지정된 n개의 작업이 주어지며, tasks[i] = [enqueueTimei, processingTimei]는 i번째 작업이 enqueueTimei에 처리를 시작할 수 있고 processingTimei만큼 처리하는 데 걸리는 시간을 의미합니다.

한 번에 하나의 작업만 처리할 수 있는 단일 스레드 CPU가 있으며 다음과 같은 방식으로 작동합니다:

CPU가 유휴 상태이고 처리할 사용 가능한 작업이 없으면 CPU는 유휴 상태로 유지됩니다.
CPU가 유휴 상태이고 사용 가능한 작업이 있으면 CPU는 가장 짧은 처리 시간을 가진 작업을 선택합니다. 여러 작업이 같은 가장 짧은 처리 시간을 가지고 있으면 가장 작은 인덱스를 가진 작업을 선택합니다.
작업이 시작되면 CPU는 작업을 중단하지 않고 전체 작업을 처리합니다.
CPU는 작업을 마친 후 즉시 새 작업을 시작할 수 있습니다.
CPU가 작업을 처리하는 순서를 반환합니다.

예제 1:

입력: tasks = [[1,2],[2,4],[3,2],[4,1]]
출력: [0,2,3,1]
설명: 이벤트는 다음과 같이 진행됩니다:
- 시간 = 1에, 작업 0이 처리 가능합니다. 사용 가능한 작업 = {0}.
- 또한 시간 = 1에, 유휴 CPU가 작업 0을 처리하기 시작합니다. 사용 가능한 작업 = {}.
- 시간 = 2에, 작업 1이 처리 가능합니다. 사용 가능한 작업 = {1}.
- 시간 = 3에, 작업 2가 처리 가능합니다. 사용 가능한 작업 = {1, 2}.
- 또한 시간 = 3에, CPU가 작업 0을 마치고 가장 짧은 작업 2를 처리하기 시작합니다. 사용 가능한 작업 = {1}.
- 시간 = 4에, 작업 3이 처리 가능합니다. 사용 가능한 작업 = {1, 3}.
- 시간 = 5에, CPU가 작업 2를 마치고 가장 짧은 작업 3을 처리하기 시작합니다. 사용 가능한 작업 = {1}.
- 시간 = 6에, CPU가 작업 3을 마치고 작업 1을 처리하기 시작합니다. 사용 가능한 작업 = {}.
- 시간 = 10에, CPU가 작업 1을 마치고 유휴 상태가 됩니다.
예제 2:

입력: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
출력: [4,3,2,0,1]
설명: 이벤트는 다음과 같이 진행됩니다:
- 시간 = 7에, 모든 작업이 사용 가능해집니다. 사용 가능한 작업 = {0,1,2,3,4}.
- 또한 시간 = 7에, 유휴 CPU가 작업 4를 처리하기 시작합니다. 사용 가능한 작업 = {0,1,2,3}.
- 시간 = 9에, CPU가 작업 4를 마치고 작업 3을 처리하기 시작합니다. 사용 가능한 작업 = {0,1,2}.
- 시간 = 13에, CPU가 작업 3을 마치고 작업 2를 처리하기 시작합니다. 사용 가능한 작업 = {0,1}.
- 시간 = 18에, CPU가 작업 2를 마치고 작업 0을 처리하기 시작합니다. 사용 가능한 작업 = {1}.
- 시간 = 28에, CPU가
*/
