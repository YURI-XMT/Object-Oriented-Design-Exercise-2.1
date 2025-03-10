#include <iostream>
#include <string>
using namespace std;

class person {
    
protected:
    string name;
    int age;

public:
    string GetName() {
        return name;
    }

    int GetAge() {
        return age;
    }
};

class teacher : private person {

private:

    double salary;

public:

    double GetSalary() {
        return salary;
    }

    string GetTeacherName() {
        return GetName(); 
    }

    int GetTeacherAge() {
        return GetAge();
    }
};

int main() {
    teacher t;

    cout << "Teacher Name: " << t.GetTeacherName() << " ✓" << endl;
    cout << "Teacher Age: " << t.GetTeacherAge() << " ✓" << endl;

    return 0;
}
