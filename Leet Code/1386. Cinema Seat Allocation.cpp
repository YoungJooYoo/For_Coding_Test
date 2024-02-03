class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        unordered_map<int, vector<bool>> seatsMap; // 각 행에 대해 예약된 좌석을 추적하는 맵

        // 예약된 좌석 처리, 예약된 행만 짚어 넣는다.
        for (const auto& seat : reservedSeats) {
            const int row = seat[0] - 1; // 행 번호 조정
            const int col = seat[1] - 1; // 열 번호 조정
            if (seatsMap.count(row) == 0) seatsMap[row] = vector<bool>(SEAT_LENGTH, true);  // 해당 행에 대한 벡터가 아직 맵에 없다면, 초기화
            seatsMap[row][col] = false; // 좌석을 예약됨으로 표시
        }

        int result = (n - seatsMap.size()) * 2; // set에 없는 행은, 에약이 없는 자리, 에약이 없는 행을 최대 2팀이 에약 가능하다.
        for (const auto& [row, seats] : seatsMap) {
            result += countFamilies(seats); // 각 행에 앉을 수 있는 최대 가족 수 추가
        }

        return result;
    }

private:
    enum { SEAT_LENGTH = 10,};

    int countFamilies(const vector<bool>& rowSeats) 
    {
        int count = 0;
        
        if (rowSeats[1] && rowSeats[2] && rowSeats[3] && rowSeats[4]) ++count; // 왼쪽 4자리 체크 (2-3-4-5)
        if (rowSeats[5] && rowSeats[6] && rowSeats[7] && rowSeats[8]) ++count; // 오른쪽 4자리 체크 (6-7-8-9)
        if (count == 0 && rowSeats[3] && rowSeats[4] && rowSeats[5] && rowSeats[6]) ++count; // 중앙 4자리 체크 (4-5-6-7), 양쪽이 모두 차지되지 않았을 경우만 가능

        return count;
    }
};

// https://leetcode.com/problems/cinema-seat-allocation/description/
