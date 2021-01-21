//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_INOTIFIER_H
#define YANDEX_CPP_COURSE_INOTIFIER_H

#include <utility>

void SendSms(const string &number, const string &message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string &email, const string &message) {
    cout << "Send '" << message << "' to e-mail " << email << endl;
}


class INotifier {
public:
    virtual void Notify(const string &message) const = 0;
};

class SmsNotifier : public INotifier {
public:
    explicit SmsNotifier(string phone)
            : phone_(std::move(phone)) {}

    void Notify(const string &message) const override {
        SendSms(phone_, message);
    }

private:
    string phone_;
};

class EmailNotifier : public INotifier {
public:
    explicit EmailNotifier(string email)
            : email_(std::move(email)) {}

    void Notify(const string &message) const override {
        SendEmail(email_, message);
    }

private:
    string email_;
};


#endif //YANDEX_CPP_COURSE_INOTIFIER_H
