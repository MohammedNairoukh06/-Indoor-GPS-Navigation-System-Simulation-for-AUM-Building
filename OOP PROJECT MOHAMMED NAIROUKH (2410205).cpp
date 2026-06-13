#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <fstream> // it will read and writh (Both) in the file 
#include <stdexcept> //for out_of_range or runtime_error (Exception Handiling)
using namespace std;
class Course {
private:
    int courseID;
    string courseName;
    int maxEnrollment;
    int currentEnrollment;

public:
    Course()  {
	courseID=0;
	courseName="";
	maxEnrollment=0;
	currentEnrollment=0;
	}

    Course(int id, string name, int maxEn){ 
	courseID=id;
	courseName=name;
	maxEnrollment=maxEn;
	currentEnrollment=0; 
	} 

    void InputInfo() {
        cout<<"Enter course name: ";
		 cin>>courseName;
        cout<<"Enter course ID: "; 
		cin>>courseID;
        cout<<"Enter max enrollment: "; 
		cin>>maxEnrollment;
        cout<<"Enter current enrollment: ";
		 cin>>currentEnrollment;
    }

    void addStudent() {
        if (currentEnrollment >= maxEnrollment)
            throw runtime_error("Course is full");
        currentEnrollment++;
    }

    void removeStudent() {
        if (currentEnrollment>0)
            currentEnrollment--;
        else
            throw runtime_error("No students to remove");
    }

    void displayInfo() const { //virtual
        cout<<"Course Name: "<<courseName<<endl;
        cout<<"Course ID: "<<courseID<<endl;
        cout<<"Max Enrollment: "<<maxEnrollment<<endl;
        cout<<"Current Enrollment: "<<currentEnrollment<<endl;
    }

    string getCourseName() const {
	 return courseName;
	  }
    int getCourseID() const { 
	return courseID;
	 }

    void saveToFile() const {
        ofstream fout("courses.txt", ios::app); //It tells the file stream to add new data at the end of the file,
		                                                                             // and we put the path of the course file
        fout<<courseID<<" "<<courseName<<" "<<maxEnrollment<<" "<<currentEnrollment<<endl;
        fout.close();
    }
};

class Person { //Abstract class
protected:
    string name;
    int id;

public:
    Person():name(""),id(0){}
    Person(string n, int i):name(n),id(i){}
    virtual void displayInfo()=0;
};
class Student : public Person {
private:
    int yearOfStudy;
    string department;
    vector<string> registeredCourses;

public:
    Student():Person(),yearOfStudy(0),department(""){}

    Student(string n,int i,int year,string dept):Person(n, i),yearOfStudy(year),department(dept){}

    void registerCourse(string courseName) { //registerCourse its a vector
        registeredCourses.push_back(courseName);
    }

    void registerCourse(Course &course) {
        try {
            course.addStudent(); //addStudent from  course class (41)
            registeredCourses.push_back(course.getCourseName());
        } catch (out_of_range e) { //runtime_error from #include <stdexcept>
		                             //A type of exception used for errors that occur during program execution
            cerr<<"Registration Error: "<<e.what()<<endl; //it used to output error messages It behaves like cout ,
			                                              //but its meant for errors and diagnostics
        }
    }

    void dropCourse(string courseName) {
        for (size_t i=0;i<registeredCourses.size();++i) {
            if (registeredCourses[i]==courseName) {
                registeredCourses.erase(registeredCourses.begin()+i);  
                return; //The return; statement just means exit the function now its a void function that dosent have a return type .
				        //(exit a void function early)
            }
        }
        throw runtime_error("Cannot drop course: not registered");
    }

    void viewCourses() const {
        cout<<"Registered Courses:"<<endl;
        if (registeredCourses.empty()) {
            cout<<"None"<<endl;
        } else {
            for(size_t i=0;i<registeredCourses.size();i++)
                cout<<"- "<<registeredCourses[i]<<endl;
        }
    }

    void displayInfo() override { //diplayInfo from (abstract class ) 
        cout<<"Student Name: "<<name<<endl;
        cout<<"Student ID: "<< id<<endl;
        cout<<"Year: "<<yearOfStudy<<endl;
        cout<<"Department: "<<department<<endl;
        viewCourses();
    }

    string getName() const { 
	return name;
	 }

    void saveToFile() const {
        ofstream fout("students.txt",ios::app); //ios::app if you want to add something in the file it will take you at the end of the file then you can add everything you want
        fout<<id<<" "<<name<<" "<<yearOfStudy<<" " <<department<<endl;
        for (size_t i = 0;i<registeredCourses.size();++i) {
            fout<<"Course: "<<registeredCourses[i]<<endl;
        }
        fout<<"-----"<<endl;
        fout.close();
    }
};

class Instructor : public Person {
private:
    vector<string> coursesTaught;
    vector<Student*> enrolledStudents;

public:
    Instructor():Person() {}

    Instructor(string n, int i) : Person(n, i) {}

    void addCourse(string courseName) {
        coursesTaught.push_back(courseName);
    }

    void removeCourse(string courseName) {
        for (size_t i = 0;i<coursesTaught.size();++i) {
            if (coursesTaught[i]==courseName){
                coursesTaught.erase(coursesTaught.begin()+i); // erase --> delete the second element 
                return; //Mission complete , exit now but if we use break it will only exit the current loop
            }
        }
        cout<<"Course not found "<<endl;
    }

    void addStudent(Student* student) { 
        enrolledStudents.push_back(student); //(push_back) add at the end  
    }

    void viewEnrolledStudents() const {
        cout<<"Enrolled Students: "<<endl;
        for (size_t i = 0;i<enrolledStudents.size();++i)
            cout<<"- "<<enrolledStudents[i]->getName()<<endl; // (->) notation same as [.] (dot) notation
    }

    void displayInfo() override {
        cout<<"Instructor Name: "<<name<<endl;
        cout<<"Instructor ID: "<<id<<endl;
        cout<<"Courses Taught: "<<endl;
        for (size_t i = 0;i<coursesTaught.size();++i)
            cout<<"- "<<coursesTaught[i]<<endl;
        viewEnrolledStudents();
    }
};

int main() {
    Course c; 
    c.InputInfo();

    string StudentName, dept;
    int StudentId, year;
    cout<<"Enter student name: ";
	cin>>StudentName;
    cout<<"Enter student ID: "; 
	cin>>StudentId;
    cout<<"Enter year of study: "; 
	cin>>year;
    cout<<"Enter department: "; 
	cin>>dept;

    Student student(StudentName, StudentId, year, dept);
    student.registerCourse(c); 

    string InstructorName;
    int InstructorId;
    cout<<"Enter instructor name: "; 
	cin>>InstructorName;
    cout<<"Enter instructor ID: ";
	cin>>InstructorId;
    Instructor instructor(InstructorName, InstructorId);
    instructor.addCourse(c.getCourseName());

    try {
        student.dropCourse("NonexistentCourse");
    } catch (runtime_error& e) {
        cerr<<"Drop Error: "<<e.what()<<endl;
    }

    c.saveToFile();
    student.saveToFile();
    cout<<"---------------------"<<endl;
    cout<<"Course Info : "<<endl;
    c.displayInfo();
    cout<<"---------------------"<<endl;
    cout<<"Student Info : "<<endl;
    student.displayInfo();
    cout<<"---------------------"<<endl;
    cout<<"Instructor Info : "<<endl;
    instructor.displayInfo();

    return 0;
}


