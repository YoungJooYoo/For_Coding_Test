class Solution 
{
public:
    int maxStudentsOnBench(const vector<vector<int>>& students) 
    {
        unordered_map<int, set<int>> studentToBench;
        int maxStudentCount = 0;

        assert(MIN_STUDENTS_SIZE<= students.size() && students.size() <= MAX_STUDENTS_SIZE);
        for (const auto& student : students)
        {
            const int student_id = student[0];
            const int bench_id = student[1];
            studentToBench[bench_id].insert(student_id);
            maxStudentCount = max(maxStudentCount, static_cast<int>(studentToBench[bench_id].size()));
            assert(MIN_STUDENT_ID<= student_id && student_id <= MAX_STUDENT_ID);
            assert(MIN_BENCH_ID<= bench_id && bench_id <= MAX_BENCH_ID);
        }

        assert(maxStudentCount >= 0);
        return maxStudentCount;
    }

private:
    enum  
    {
        NO_STUDENT = 0,
        MIN_STUDENTS_SIZE = 0,
        MAX_STUDENTS_SIZE = 100,
        MIN_STUDENT_ID    = 1,
        MAX_STUDENT_ID    = 100,
        MIN_BENCH_ID      = 1,
        MAX_BENCH_ID      = 100
    };
};

// https://leetcode.com/problems/maximum-students-on-a-single-bench/description/

/*
3450. 한 벤치에 앉은 최대 학생 수
Easy

문제 설명:
2차원 정수 배열 students가 주어집니다.
각 원소 **students[i] = [student_id, bench_id]**는 학생 student_id가 벤치 bench_id에 앉아 있음을 나타냅니다.

모든 벤치 중에서 한 벤치에 앉은 유일한 학생들의 수가 최대인 값을 반환하세요.
만약 학생이 한 명도 없다면 0을 반환합니다.

주의:
입력에서 한 학생이 같은 벤치에 여러 번 등장할 수 있으나, 각 벤치에서는 해당 학생을 한 번만 카운트해야 합니다.

예제 1:

lua
복사
Input: students = [[1,2],[2,2],[3,3],[1,3],[2,3]]
Output: 3
설명:

벤치 2에는 학생 1과 2가 있으므로 유일한 학생 수는 2명입니다.
벤치 3에는 학생 1, 2, 3이 있으므로 유일한 학생 수는 3명입니다.
따라서, 한 벤치에 앉은 최대 유일한 학생 수는 3입니다.
예제 2:

lua
복사
Input: students = [[1,1],[2,1],[3,1],[4,2],[5,2]]
Output: 3
설명:

벤치 1에는 학생 1, 2, 3이 있으므로 유일한 학생 수는 3명입니다.
벤치 2에는 학생 4, 5가 있으므로 유일한 학생 수는 2명입니다.
따라서, 한 벤치에 앉은 최대 유일한 학생 수는 3입니다.
예제 3:

lua
복사
Input: students = [[1,1],[1,1]]
Output: 1
설명:

벤치 1에는 학생 1이 있으므로 최대 유일한 학생 수는 1입니다.
예제 4:

makefile
복사
Input: students = []
Output: 0
설명:

학생이 없으므로 0을 반환합니다.
제약 조건:

0 <= students.length <= 100
students[i] = [student_id, bench_id]
1 <= student_id <= 100
1 <= bench_id <= 100

*/
