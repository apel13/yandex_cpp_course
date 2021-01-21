//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_HOTELSBOOKING_H
#define YANDEX_CPP_COURSE_HOTELSBOOKING_H


class HotelsBooking {
public:
    using HOTEL_NAME = std::string;
    using TIME = int64_t;
    using CLIENT_ID = int;
    using ROOM_COUNT = int;

    void book(TIME &time,
              HOTEL_NAME &hotel_name,
              CLIENT_ID &client_id,
              ROOM_COUNT &room_count) {
        _last_event = time;
        _hotels_info[hotel_name].book(time, client_id, room_count);
    }

    int rooms(const HOTEL_NAME &hotel_name) {
        return _hotels_info[hotel_name].rooms(_last_event);
    }

    int clients(const HOTEL_NAME &hotel_name) {
        return _hotels_info[hotel_name].clients(_last_event);
    }

private:
    struct Event {
        TIME time;
        CLIENT_ID client_id;
        ROOM_COUNT room_count;
    };

    class HotelInfo {
    public:
        void book(TIME &time,
                  CLIENT_ID &client_id,
                  ROOM_COUNT &room_count) {
            _events.push(Event{time, client_id, room_count});
            _rooms += room_count;
            _clients[client_id]++;
        }

        int rooms(const TIME &last_event)  {
            erase_previous(last_event);
            return _rooms;
        }

        int clients(const TIME &last_event)  {
            erase_previous(last_event);
            return _clients.size();
        }

        bool erase_previous(const TIME &time) {
            while (!_events.empty() &&
                   _events.front().time + 86400 <= time) {
                Event top = _events.front();
                _events.pop();
                _rooms -= top.room_count;
                if (--_clients[top.client_id] == 0)
                    _clients.erase(top.client_id);
            }
            return _clients.empty();
        }

    private:
        int _rooms = 0;
        std::queue<Event> _events;
        std::unordered_map<CLIENT_ID, int> _clients;
    };
    TIME _last_event = INT64_MIN;
    std::unordered_map<HOTEL_NAME, HotelInfo> _hotels_info;
};


#endif //YANDEX_CPP_COURSE_HOTELSBOOKING_H
