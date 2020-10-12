#include <iostream>

using namespace std;

struct Specialization {
    string specialization;
    explicit Specialization(string specializationName) {specialization = specializationName;}
};
struct Course {
    string course;
    explicit Course(string courseName) {course = courseName;}
};
struct Week {
    string week;
    explicit Week(string weekName) {week = weekName;}
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle (const Specialization& inputSpecialization, const Course& inputCourse, const Week& inputWeek) {
        specialization = inputSpecialization.specialization;
        course = inputCourse.course;
        week = inputWeek.week;
    }
};