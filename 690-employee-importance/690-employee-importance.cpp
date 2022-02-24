class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) 
	{
        for (const auto& emp : employees) {
			if (emp->id == id) {
				result = result + emp->importance;
				for (const auto& sub_emp_id : emp->subordinates) {
					getImportance(employees, sub_emp_id);
				}
			}
		}

		return result;
    }

private:
	int result = 0;
};