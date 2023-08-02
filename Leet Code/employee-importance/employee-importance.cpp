/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int total = 0;
        int index = 0;
        int current = 0;
        unordered_map<int, int> map; // 해시맵 사용
        stack<int> s;
        
        for (int i = 0; i < employees.size(); i++) {
            map[employees[i]->id] = i;
        }
        
        s.push(map[id]);
        
        while (s.empty() == NULL) {
            current = s.top();
            total = total + employees[current]->importance;
            s.pop();
            for (int i = 0; i < employees[current]->subordinates.size(); i++) {
                s.push(map[employees[current]->subordinates[i]]);
            }
        }
        
        return total;
    }
};