#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    Student(string studentName, int studentRoll, float studentMarks) {
        name = studentName;
        rollNumber = studentRoll;
        marks = studentMarks;
        cout << "Constructor called: Memory allocated and details initialized for " << name << ".\n";
    }

    void displayDetails() {
        cout << "\n Student Details \n";
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Marks: " << marks << "%\n";
    }
    ~Student() {
        cout << "Destructor called: Memory freed and object destroyed for " << name << ".\n";
    }
};

int main() {
    cout << "Starting Program Execution...\n\n";
    {
        Student student1("John Doe", 101, 89.5);
        student1.displayDetails();
        
    }

    cout << "Program Execution Completed.\n";

    return 0;
}