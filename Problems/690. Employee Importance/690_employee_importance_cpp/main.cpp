#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Employee {
    public:
        int id;
        int importance;
        vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<short, short> employeeIds;

    short i;
    for(i = employees.size() - 1; i > -1; --i) {
        employeeIds[employees[i]->id] = i;
    }

    vector<short> traversal(1, id);
    int importance = 0;

    while(!traversal.empty()) {
        id = employeeIds[traversal.back()];
        traversal.pop_back();

        importance += employees[id]->importance;

        for(i = employees[id]->subordinates.size() - 1; i > -1; --i) {
            traversal.push_back(employees[id]->subordinates[i]);
        }
    }

    return importance;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<Employee*> employees, int id, int expected) {
    cout << "Employees: ";
    for(Employee* employee : employees) {
        cout << "[" << employee->id << ", " << employee->importance << ", " << "[";
        for(int i = 0; i < employee->subordinates.size(); ++i) {
            cout << employee->subordinates[i];
            if(i != employee->subordinates.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << "] ";
    }
    cout << endl;

    cout << "ID: " << id << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getImportance(employees, id) << endl;

    cout << endl;
}

int main() {
    vector<Employee*> employees1 = { new Employee{1, 5, {2, 3}}, new Employee{2, 3, {}}, new Employee{3, 3, {}} };
    test(employees1, 1, 11);

    vector<Employee*> employees2 = { new Employee{1, 2, {5}}, new Employee{5, -3, {}} };
    test(employees2, 5, -3);

    vector<Employee*> employees3 = { new Employee{1, 10, {}} };
    test(employees3, 1, 10);

    vector<Employee*> employees4 = { new Employee{1, 4, {2}}, new Employee{2, 6, {}} };
    test(employees4, 1, 10);

    vector<Employee*> employees5 = { new Employee{1, 5, {2}}, new Employee{2, 3, {3}}, new Employee{3, 2, {}} };
    test(employees5, 1, 10);

    return 0;
}
