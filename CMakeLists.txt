cmake_minimum_required(VERSION 3.17)
project(yandex_cpp_course)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(yandex_cpp_course
        main.cpp
        course3/week1/airline_ticket.h course3/week1/Paginator.h utils/LogDuration.h course3/week2/ReadingManager.h course3/week2/HotelsBooking.h course3/week3/ObjectPool.h course3/week3/SimpleVector.h course3/week3/LinkedList.h course3/week4/StackVector.h course3/week4/Translator.h course3/week4/AirportCounter.h course3/week4/Editor.h course3/week4/stats.cpp course3/week4/stats.h course3/week4/http_request.h course3/week5/simple_vector.h course3/final/search_server.cpp course3/final/search_server.h)


