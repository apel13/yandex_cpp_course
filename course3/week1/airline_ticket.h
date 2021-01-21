//
// Created by apel on 18.01.2021.
//

#ifndef YANDEX_CPP_COURSE_AIRLINE_TICKET_H
#define YANDEX_CPP_COURSE_AIRLINE_TICKET_H

struct Date {
    int year, month, day;
};

struct Time {
    int hours, minutes;
};

bool operator<(const Date &date1, const Date &date2) {
    return std::make_tuple(date1.year, date1.month, date1.day) <
           std::make_tuple(date2.year, date2.month, date2.day);
}

bool operator==(const Date &date1, const Date &date2) {
    return std::make_tuple(date1.year, date1.month, date1.day) ==
           std::make_tuple(date2.year, date2.month, date2.day);
}

bool operator<(const Time &time1, const Time &time2) {
    return std::make_tuple(time1.hours, time1.minutes) <
           std::make_tuple(time2.hours, time2.minutes);
}

bool operator==(const Time &time1, const Time &time2) {
    return std::make_tuple(time1.hours, time1.minutes) ==
           std::make_tuple(time2.hours, time2.minutes);
}

ostream &operator<<(ostream &os, const Time &time) {
    return os << "";
}

ostream &operator<<(ostream &os, const Date &date) {
    return os << "";
}

istream &operator>>(istream &is, Time &time) {
    is >> time.hours; is.get();
    is >> time.minutes;
    return is;
}

istream &operator>>(istream &is, Date &date) {
    is >> date.year; is.get();
    is >> date.month; is.get();
    is >> date.day;
    return is;
}


struct AirlineTicket {
    string from;
    string to;
    string airline;
    Date departure_date;
    Time departure_time;
    Date arrival_date;
    Time arrival_time;
    uint64_t price;
};

#define SORT_BY(field)                                                 \
    [](const AirlineTicket &lhs, const AirlineTicket &rhs) {     \
        return lhs.field < rhs.field;                                 \
    }



#define UPDATE_FIELD(ticket, field, values) {        \
    auto it = values.find(#field);                   \
    if (it != values.end()) {                        \
        istringstream is(it->second);                       \
        is >> ticket.field;                             \
    }                                                  \
}




#endif //YANDEX_CPP_COURSE_AIRLINE_TICKET_H
