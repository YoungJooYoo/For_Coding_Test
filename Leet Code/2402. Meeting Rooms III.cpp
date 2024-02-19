class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<int> roomCount(n, 0); // 각 방에서 열린 회의 수
        set<int> availableRooms; // 사용 가능한 방
        // 사용 중인 방과 사용 가능 시간 관리를 위한 우선순위 큐
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> busyRooms;
        
        sort(meetings.begin(), meetings.end()); // 회의 시작 시간에 따라 정렬

        // 모든 방을 사용 가능한 상태로 초기화
        for (int i = 0; i < n; ++i) {
            availableRooms.insert(i);
        }

        for (const auto& meeting : meetings) {
            long long int start = meeting[0];
            long long int end = meeting[1];

            // 사용 가능한 방을 업데이트
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                availableRooms.insert(room);
            }

            // 사용 가능한 방이 없는 경우, 가장 일찍 끝나는 회의가 끝날 때까지 기다림
            if (availableRooms.empty()) {
                auto p = busyRooms.top(); busyRooms.pop();
                const long long int duration = end - start;
                start = p.first;
                end = start + duration;
                availableRooms.insert(p.second);
            }

            // 사용 가능한 가장 낮은 번호의 방 선택
            const auto& it = availableRooms.begin(); 
            roomCount[*it]++;
            busyRooms.push({end, *it});
            availableRooms.erase(it);
        }

        // 가장 많은 회의를 개최한 방 찾기
        int maxMeetings = 0;
        int roomWithMaxMeetings = 0;
        for (int i = 0; i < n; ++i) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                roomWithMaxMeetings = i;
            }
        }

        return roomWithMaxMeetings;
    }
};

// https://leetcode.com/problems/meeting-rooms-iii/

/*

### 한국어 번역

2402. 회의실 III
난이도: 어려움
주제: [정보 없음]
회사: [정보 없음]
힌트: [정보 없음]

0부터 n - 1까지 번호가 매겨진 n개의 회의실이 있습니다.

2D 정수 배열 meetings가 주어지며, meetings[i] = [starti, endi]는 반닫힌 시간 구간 [starti, endi) 동안 회의가 열릴 예정임을 의미합니다. starti의 모든 값은 고유합니다.

회의는 다음 방식으로 회의실에 배정됩니다:

- 각 회의는 사용되지 않는 가장 낮은 번호의 회의실에서 열립니다.
- 사용 가능한 회의실이 없는 경우, 회의는 회의실이 비워질 때까지 지연됩니다. 지연된 회의는 원래 회의와 동일한 시간 동안 지속되어야 합니다.
- 회의실이 사용되지 않게 되면, 원래 시작 시간이 더 이른 회의가 해당 회의실을 사용해야 합니다.
- 가장 많은 회의를 개최한 회의실의 번호를 반환합니다. 여러 회의실이 있다면, 가장 낮은 번호의 회의실을 반환합니다.

반닫힌 구간 [a, b)는 a와 b 사이의 구간으로 a는 포함하고 b는 포함하지 않습니다.

### 요약

주어진 n개의 회의실에서, 각 회의를 시작 시간에 따라 가능한 가장 낮은 번호의 회의실에 배정하는 문제입니다. 모든 회의실이 사용 중일 때는 회의가 지연되며, 
회의실이 비워지면 원래 시작 시간이 가장 이른 회의부터 회의실을 사용합니다. 가장 많은 회의를 개최한 회의실의 번호를 반환하며, 
동일한 수의 회의를 개최한 회의실이 여러 개 있을 경우 가장 낮은 번호를 반환합니다.

### 문제 풀이 방향

1. **회의 관리**: 회의를 시작 시간에 따라 정렬하고, 각 회의를 처리할 때 사용 가능한 회의실을 찾거나 회의를 지연시킵니다.

2. **회의실 사용 상태 추적**: 회의실별로 현재 사용 중인지 여부와 다음에 사용할 수 있는 시간을 추적합니다.

3. **우선순위 큐 사용**: 회의실이 다음에 사용 가능할 시간을 기준으로 우선순위 큐를 사용하여 관리합니다. 이를 통해 빨리 비워지는 회의실부터 회의를 배정할 수 있습니다.

4. **회의실별 회의 수 기록**: 각 회의실에서 열린 회의 수를 기록합니다. 모든 회의를 처리한 후 가장 많은 회의를 개최한 회의실 번호를 찾아 반환합니다.

이러한 접근 방식을 사용하면 각 회의를 적절한 회의실에 효율적으로 배정하고, 조건에 따라 가장 많은 회의를 개최한 회의실의 번호를 찾을 수 있습니다.
*/
