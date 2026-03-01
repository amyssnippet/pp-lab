#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks[5];
    float total;
    float percentage;
    char grade;
};

void calculateTotalAndPercent(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = (s->total / 500.0) * 100.0;
}

char calculateGrade(float percentage) {
    if (percentage >= 90.0) {
        return 'A';
    } else if (percentage >= 75.0) {
        return 'B';
    } else if (percentage >= 50.0) {
        return 'C';
    } else if (percentage >= 35.0) {
        return 'D';
    } else {
        return 'F';
    }
}

void displayStudent(struct Student s) {
    printf("\n Student Result \n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Total Marks: %.2f / 500\n", s.total);
    printf("Percentage: %.2f%%\n", s.percentage);
    printf("Grade: %c\n", s.grade);
}

int main() {
    struct Student std;

    printf("Enter Student Name: ");
    scanf(" %[^\n]", std.name); 

    printf("Enter Roll Number: ");
    scanf("%d", &std.rollNumber);

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &std.marks[i]);
    }

    calculateTotalAndPercent(&std); std.grade = calculateGrade(std.percentage);
    displayStudent(std);

    return 0;
}