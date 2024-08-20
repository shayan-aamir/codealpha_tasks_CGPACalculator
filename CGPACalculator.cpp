#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course
{
public:
    string courseName;
    int credits;
    string grade;

    Course(string name, int creds, string grd) : courseName(name), credits(creds), grade(grd) {}
};

class Student
{
    double convertGradeToPoints(string grade)
    {
        if (grade == "A+" || grade == "A")
            return 4.0;
        else if (grade == "A-")
            return 3.67;
        else if (grade == "B+")
            return 3.3;
        else if (grade == "B")
            return 3.0;
        else if (grade == "B-")
            return 2.67;
        else if (grade == "C+")
            return 2.33;
        else if (grade == "C")
            return 2.0;
        else if (grade == "C-")
            return 1.67;
        else if (grade == "D+")
            return 1.33;
        else if (grade == "D")
            return 1.0;
        else if (grade == "F")
            return 0.67;
        else
            return 0.0;
    }

    vector<Course> courses;
    double totalGradePoints = 0;
    int totalCredits = 0;
    double cumulativeSGPA = 0;
    int numSemesters = 0;

public:
    void addCourse(string courseName, int credits, string grade)
    {
        courses.push_back(Course(courseName, credits, grade));
        totalCredits += credits;
        totalGradePoints += (convertGradeToPoints(grade) * credits);
    }

    double calculateSGPA()
    {
        if (totalCredits == 0)
            return 0.0;
        return totalGradePoints / totalCredits;
    }

    void addSGPA(double sgpa)
    {
        cumulativeSGPA += sgpa;
        numSemesters++;
    }

    void displayGrades()
    {
        cout << "Course Grades:" << endl;
        for (const auto &course : courses)
        {
            cout << "Course: " << course.courseName << ", Credits: " << course.credits << ", Grade: " << course.grade << endl;
        }
    }

    double calculateCGPA()
    {
        if (numSemesters == 0)
            return 0.0;
        return cumulativeSGPA / numSemesters;
    }
};

int main()
{
    Student student;
    int numCourses, numSemesters;

    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    for (int sem = 1; sem <= numSemesters; sem++)
    {
        cout << "\nEntering data for Semester " << sem << ":" << endl;
        cout << "Enter the number of courses: ";
        cin >> numCourses;

        for (int i = 0; i < numCourses; i++)
        {
            string courseName;
            int credits;
            string grade;
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, courseName);
            cout << "Enter credits: ";
            cin >> credits;
            cout << "Enter grade (A+/A/A-/B+/B/B-/C+/C/C-/D+/D/F): ";
            cin >> grade;

            student.addCourse(courseName, credits, grade);
        }

        double sgpa = student.calculateSGPA();
        student.addSGPA(sgpa);
        cout << "\nSGPA for Semester " << sem << ": " << sgpa << endl;
    }

    student.displayGrades();
    double cgpa = student.calculateCGPA();
    cout << "\nYour overall CGPA is: " << cgpa << endl;

    return 0;
}
