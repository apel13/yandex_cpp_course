//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_CONDITION_PARSER_H
#define YANDEX_CPP_COURSE_CONDITION_PARSER_H

#include "Token.h"
#include "comparison.h"
#include "LogicalOperation.h"

#include "../Date/date.h"
#include "../Nodes/node.h"

#include <memory>
#include <iostream>

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();


#endif //YANDEX_CPP_COURSE_CONDITION_PARSER_H
