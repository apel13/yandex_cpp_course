//
// Created by apel on 15.01.2021.
//

#ifndef YANDEX_CPP_COURSE_MATRIX_H
#define YANDEX_CPP_COURSE_MATRIX_H

class Matrix {
public:
    Matrix()
            : _rows(0), _cols(0) {}

    Matrix(int rows, int cols) {
        Reset(rows, cols);
    }

    void Reset(int rows, int cols) {
        if (rows < 0)
            throw out_of_range("num_rows must be >= 0");

        if (cols < 0)
            throw out_of_range("num_columns must be >= 0");

        if (rows == 0 || cols == 0)
            rows = cols = 0;
        _rows = rows;
        _cols = cols;
        _elements.assign(rows, vector<int>(cols));
    }

    int &At(int row, int column) {
        return _elements.at(row).at(column);
    }

    int At(int row, int column) const {
        return _elements.at(row).at(column);
    }

    int GetNumRows() const {
        return _rows;
    }

    int GetNumColumns() const {
        return _cols;
    }

private:
    int _rows, _cols;
    vector<vector<int>> _elements;
};

bool operator==(const Matrix &one, const Matrix &two) {
    if (one.GetNumRows() != two.GetNumRows() ||
        one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }
    for (int row = 0; row < one.GetNumRows(); ++row)
        for (int column = 0; column < one.GetNumColumns(); ++column)
            if (one.At(row, column) != two.At(row, column))
                return false;
    return true;
}

Matrix operator+(const Matrix &one, const Matrix &two) {
    if (one.GetNumRows() != two.GetNumRows())
        throw invalid_argument("Mismatched number of rows");
    if (one.GetNumColumns() != two.GetNumColumns())
        throw invalid_argument("Mismatched number of columns");

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row)
        for (int column = 0; column < result.GetNumColumns(); ++column)
            result.At(row, column) = one.At(row, column) + two.At(row, column);
    return result;
}

istream &operator>>(istream &is, Matrix &matrix) {
    int num_rows, num_columns;
    is >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row)
        for (int column = 0; column < num_columns; ++column)
            is >> matrix.At(row, column);

    return is;
}

ostream &operator<<(ostream &os, const Matrix &matrix) {
    os << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0)
                os << " ";
            os << matrix.At(row, column);
        }
        os << endl;
    }
    return os;
}

#endif //YANDEX_CPP_COURSE_MATRIX_H
