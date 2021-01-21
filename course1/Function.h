//
// Created by apel on 15.01.2021.
//

#ifndef YANDEX_CPP_COURSE_FUNCTION_H
#define YANDEX_CPP_COURSE_FUNCTION_H

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(double source_value) const {
        if (operation == '+')
            return source_value + value;
        else if (operation == '-')
            return source_value - value;
        else if (operation == '*')
            return source_value * value;
        else
            return source_value / value;
    }

    void Invert() {
        if (operation == '+')
            operation = '-';
        else if (operation == '-')
            operation = '+';
        else if (operation == '*')
            operation = '/';
        else
            operation = '*';
    }

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }

    double Apply(double value) const {
        for (const FunctionPart &part : parts)
            value = part.Apply(value);
        return value;
    }

    void Invert() {
        for (FunctionPart &part : parts)
            part.Invert();
        std::reverse(begin(parts), end(parts));
    }

private:
    vector <FunctionPart> parts;
};

#endif //YANDEX_CPP_COURSE_FUNCTION_H
