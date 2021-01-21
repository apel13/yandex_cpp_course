//
// Created by apel on 15.01.2021.
//

#ifndef YANDEX_CPP_COURSE_LECTURETITLE_H
#define YANDEX_CPP_COURSE_LECTURETITLE_H

struct Specialization {
    explicit Specialization(string _specialization) {
        specialization = _specialization;
    }

private:
    string specialization;
};

struct Course {
    explicit Course(string _course) {
        course = _course;
    }

    string course;
};

struct Week {
    explicit Week(const string &week) : week(week) {}

    string week;
};

struct LectureTitle {
public:
    LectureTitle(const Specialization &specialization,
                 const Course &course,
                 const Week &week)
            : specialization(specialization.specialization),
            course(course.course), week(week.week) {}


    string specialization;
    string course;
    string week;
};

#endif //YANDEX_CPP_COURSE_LECTURETITLE_H
