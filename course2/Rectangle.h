//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_RECTANGLE_H
#define YANDEX_CPP_COURSE_RECTANGLE_H

class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;

    int GetPerimeter() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    int width_, height_;
};

#endif //YANDEX_CPP_COURSE_RECTANGLE_H
