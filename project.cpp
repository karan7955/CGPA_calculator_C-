#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double calculateCGPA(const vector<int> &credits, const vector<double> &gradePoints)
{
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < credits.size(); ++i)
    {
        totalGradePoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }

    return totalGradePoints / totalCredits;
}

int main()
{
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<int> credits(numCourses);
    vector<double> gradePoints(numCourses);
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i)
    {
        cout << "Enter credits for course " << i + 1 << ": ";
        cin >> credits[i];
        cout << "Enter grade points for course " << i + 1 << ": ";
        cin >> gradePoints[i];

        totalGradePoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }

    double cgpa = calculateCGPA(credits, gradePoints);

    cout << "\nCourse Details:\n";
    for (int i = 0; i < numCourses; ++i)
    {
        cout << "Course " << i + 1 << ": Credits = " << credits[i]
             << ", Grade Points = " << gradePoints[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "GPA for the Semester: " << totalGradePoints / totalCredits << endl;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
