#include <iostream>
#include <string>
#include<fstream>
using namespace std;

// ================= STUDENT NODE =================

class Student {
public:
    int id;
    string name;
    string semester;
    Student* next;

    Student(int studentId, string studentName, string studentSemester) {
        id = studentId;
        name = studentName;
        semester = studentSemester;
        next = NULL;
    }
};

// ================= LINKED LIST =================

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = NULL;
    }

    // Add Student
    void addStudent(int id, string name, string semester) {

        Student* newStudent = new Student(id, name, semester);

        if (head == NULL) {
            head = newStudent;
        }
        else {
            Student* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newStudent;
        }

        cout << "\nStudent Added Successfully!\n";
    }

    // Display Students
    void displayStudents() {

        if (head == NULL) {
            cout << "\nNo Students Found!\n";
            return;
        }

        Student* temp = head;

        cout << "\n===== STUDENT RECORDS =====\n";

        while (temp != NULL) {

            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Semester: " << temp->semester << endl;
            cout << "--------------------------\n";

            temp = temp->next;
        }
    }
    
    
    // ================= SEARCH STUDENT =================

    void searchStudent(int searchId) {

        if (head == NULL) {
            cout << "\nNo Students Available!\n";
            return;
        }

        Student* temp = head;
        bool found = false;

        while (temp != NULL) {

            if (temp->id == searchId) {

                cout << "\n===== STUDENT FOUND =====\n";
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Semester: " << temp->semester << endl;

                found = true;
                break;
            }

            temp = temp->next;
        }

        if (!found) {
            cout << "\nStudent Not Found!\n";
        }
    }
};
#include <queue>

// ================= COURSE CLASS =================

class Course {
public:

    string courseName;
    int capacity;
    int enrolledStudents;

    queue<string> waitingList;

    Course(string name, int cap) {
        courseName = name;
        capacity = cap;
        enrolledStudents = 0;
    }

    // Register Student
    void registerStudent(string studentName) {

        if (enrolledStudents < capacity) {

            enrolledStudents++;

            cout << "\nStudent Registered in "
                << courseName << " Successfully!\n";
        }

        else {

            waitingList.push(studentName);

            cout << "\nCourse Full!\n";
            cout << studentName
                << " added to Waiting List.\n";
        }
    }

    // Display Course Info
    void displayCourse() {

        cout << "\n===== COURSE DETAILS =====\n";

        cout << "Course Name: "
            << courseName << endl;

        cout << "Capacity: "
            << capacity << endl;

        cout << "Enrolled Students: "
            << enrolledStudents << endl;

        cout << "Waiting Students: "
            << waitingList.size() << endl;
    }
    // Drop Student
    void dropStudent() {

        if (enrolledStudents > 0) {

            enrolledStudents--;

            cout << "\nStudent Dropped Successfully!\n";

            // Waiting list check
            if (!waitingList.empty()) {

                string nextStudent = waitingList.front();

                waitingList.pop();

                enrolledStudents++;

                cout << nextStudent
                    << " moved from Waiting List to Registered Students.\n";
            }
        }

        else {

            cout << "\nNo Students Enrolled!\n";
        }
    }
    // Generate Report
    void generateReport() {

        cout << "\n===== COURSE REPORT =====\n";

        cout << "Course Name: "
            << courseName << endl;

        cout << "Total Capacity: "
            << capacity << endl;

        cout << "Registered Students: "
            << enrolledStudents << endl;

        cout << "Students in Waiting List: "
            << waitingList.size() << endl;

        int availableSeats = capacity - enrolledStudents;

        cout << "Available Seats: "
            << availableSeats << endl;
    }
};
// ================= TREE NODE =================

class TreeNode {
public:

    string name;

    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) {

        name = value;

        left = NULL;
        right = NULL;
    }
};

// ================= COURSE TREE =================

class UniversityTree {

private:

    TreeNode* root;

public:

    UniversityTree() {

        root = NULL;
    }

    // Create Hierarchy
    void createTree() {

        root = new TreeNode("Computing Faculty");

        root->left = new TreeNode("IT Department");

        root->left->left = new TreeNode("DSA");

        root->left->right = new TreeNode("OOP");
    }

    // Display Tree
    void display(TreeNode* node) {

        if (node == NULL) {
            return;
        }

        cout << node->name << endl;

        display(node->left);

        display(node->right);
    }

    // Show Hierarchy
    void showHierarchy() {

        cout << "\n===== UNIVERSITY HIERARCHY =====\n";

        display(root);
    }
};
#include <map>

class Timetable {

private:
    map<string, string> schedule;

public:

    Timetable() {

        // Sample timetable (you can change)
        schedule["Monday 9-10"] = "DSA";
        schedule["Monday 10-11"] = "OOP";
        schedule["Tuesday 9-10"] = "PF";
        schedule["Tuesday 10-11"] = "ICT";
    }

    void showTimetable() {

        cout << "\n===== WEEKLY TIMETABLE =====\n";

        for (auto item : schedule) {

            cout << item.first
                << "  -->  "
                << item.second << endl;
        }
    }
};
// ================= MAIN FUNCTION =================

int main() {

    StudentList students;
    Timetable tt;
    Course dsa("DSA", 2);
    UniversityTree tree;
    tree.createTree();
    int choice;

    do {

        cout << "\n====== UNIVERSITY SYSTEM ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Register in DSA Course\n";
        cout << "4. View Course Details\n";
        cout << "5. Drop Student From DSA\n";
        cout << "6. Generate Report\n";
        cout << "7. Search Student\n";
        cout << "8. Show Timetable\n";
        cout << "9. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {

            int id;
            string name;
            string semester;

            cout << "\nEnter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Semester: ";
            getline(cin, semester);

            students.addStudent(id, name, semester);

            break;
        }

        case 2:
            students.displayStudents();
            break;

        case 3: {

            string studentName;

            cin.ignore();

            cout << "\nEnter Student Name: ";
            getline(cin, studentName);

            dsa.registerStudent(studentName);

            break;
        }

        case 4:

            dsa.displayCourse();
            break;

        case 5:

            dsa.dropStudent();
            break;

        case 6:

            dsa.generateReport();
            break;

        case 7: {

            int id;

            cout << "\nEnter Student ID to Search: ";
            cin >> id;

            students.searchStudent(id);

            break;
        }

        case 8:

            tt.showTimetable();
            break;


        case 9:

            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}