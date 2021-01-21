//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_LOGICALOPERATIONNODE_H
#define YANDEX_CPP_COURSE_LOGICALOPERATIONNODE_H

#include "../node.h"
#include "../../ExpParser/LogicalOperation.h"

#include <memory>

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation&,
                         std::shared_ptr<Node> left,
                         std::shared_ptr<Node> right);

    bool Evaluate(const Date &date, const std::string &string) const override;

private:
    const LogicalOperation _op;
    std::shared_ptr<Node> _left;
    std::shared_ptr<Node> _right;
};


#endif //YANDEX_CPP_COURSE_LOGICALOPERATIONNODE_H
