//
// Created by apel on 20.01.2021.
//

#ifndef YANDEX_CPP_COURSE_AIRPORTCOUNTER_H
#define YANDEX_CPP_COURSE_AIRPORTCOUNTER_H

#include <array>

template<typename TAirport>
class AirportCounter {
public:
    static constexpr size_t _number_of_airports =
            static_cast<uint32_t>(TAirport::Last_);

    using ContainerType = std::array<std::uint32_t, _number_of_airports>;
    using Item = pair<TAirport, std::size_t>;
    using Items = std::array<Item, _number_of_airports>;


    AirportCounter() {
        _airports_counts.fill(0);
    }

    template<typename TIterator>
    AirportCounter(TIterator begin, TIterator end) {
        _airports_counts.fill(0);
        for (auto it = begin; it != end; ++it) {
            ++_airports_counts[
                    static_cast<uint32_t>(*it)
            ];
        }
    }

    size_t Get(TAirport airport) const {
        return _airports_counts[
                static_cast<uint32_t>(airport)
        ];
    }

    void Insert(TAirport airport) {
        ++_airports_counts[
                static_cast<uint32_t>(airport)
        ];
    }

    void EraseOne(TAirport airport) {
        --_airports_counts[
                static_cast<uint32_t>(airport)
        ];
    }

    void EraseAll(TAirport airport) {
        _airports_counts[
                static_cast<uint32_t>(airport)
        ] = 0;
    }

    Items GetItems() const {
        Items _items;
        for (int i = 0; i < _number_of_airports; ++i) {
            _items[i] = std::make_pair(static_cast<TAirport>(i),
                                       _airports_counts[i]);
        }
        return _items;
    }

private:
    ContainerType _airports_counts;
};


#endif //YANDEX_CPP_COURSE_AIRPORTCOUNTER_H
