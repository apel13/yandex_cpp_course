//
// Created by apel on 21.01.2021.
//

#ifndef YANDEX_CPP_COURSE_EDITOR_H
#define YANDEX_CPP_COURSE_EDITOR_H

#include <list>
#include <strstream>

class Editor {
public:
    Editor();
    void Left();
    void Right();
    void Insert(char token);
    void Copy(size_t tokens);
    void Cut(size_t tokens);
    void Paste();
    string GetText() const;

private:
    list<char> _data;
    decltype(_data)::iterator _pos;
    list<char> _buf;

    decltype(_data)::iterator next_with_check(size_t tokens);
};

Editor::Editor()
        : _pos(_data.begin()) {}

void Editor::Left() {
    if (_pos != _data.begin())
        _pos = std::prev(_pos);
}

void Editor::Right() {
    if (_pos != _data.end())
        _pos = std::next(_pos);
}

void Editor::Insert(char token) {
    _data.insert(_pos, token);
}

void Editor::Copy(size_t tokens) {
    _buf.assign(_pos, next_with_check(tokens));
}

void Editor::Cut(size_t tokens) {
    _buf.clear();
    auto _last_pos = next_with_check(tokens);
    _buf.splice(_buf.begin(), _data,  _pos, _last_pos);
    _pos = _last_pos;
}

void Editor::Paste() {
    _data.insert(_pos, _buf.begin(), _buf.end());
}

string Editor::GetText() const {
    stringstream ss;
    for (auto &c : _data)
        ss << c;
    return ss.str();
}

list<char>::iterator Editor::next_with_check(size_t tokens) {
    auto ret = _pos;
    while (ret != _data.end() && tokens--)
        ret = std::next(ret);
    return ret;
}

#endif //YANDEX_CPP_COURSE_EDITOR_H
