//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_EMPTYNODE_H
#define YANDEX_CPP_COURSE_EMPTYNODE_H

#include "../node.h"

class EmptyNode : public Node{
public:
    bool Evaluate(const Date &date, const std::string &string) const override;
};


#endif //YANDEX_CPP_COURSE_EMPTYNODE_H
