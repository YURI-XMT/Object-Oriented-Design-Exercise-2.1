#include <iostream>
#include <string>
#include <stdexcept>

class person {
protected:
    std::string name;
    int age;

public:
    person(const std::string& n, int a) : name(n), age(a) {
        if (a < 0) throw std::invalid_argument("Age cannot be negative");
    }

    std::string GetName() const {
        return name;
    }

    int GetAge() const {
        return age;
    }
};

class student : public person {
private:
    double Avg;

public:
    student(const std::string& n, int a, double avg) : person(n, a), Avg(avg) {
        if (avg < 0 || avg > 100) throw std::invalid_argument("Average must be between 0 and 100");
    }

    double GetAvg() const {
        return Avg;
    }

    std::string GetStudentName() const {
        return GetName();
    }
};

class teacher : public person {
private:
    double salary;

public:
    teacher(const std::string& n, int a, double sal) : person(n, a), salary(sal) {
        if (sal < 0) throw std::invalid_argument("Salary cannot be negative");
    }

    double GetSalary() const {
        return salary;
    }
};

int main() {
    try {
        student s("Ali", 20, 85.5);
        teacher t("Reza", 35, 5000.0);

        std::cout << "Student Name: " << s.GetStudentName() << ", Age: " << s.GetAge() << ", Avg: " << s.GetAvg() << std::endl;
        std::cout << "Teacher Name: " << t.GetName() << ", Age: " << t.GetAge() << ", Salary: " << t.GetSalary() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
