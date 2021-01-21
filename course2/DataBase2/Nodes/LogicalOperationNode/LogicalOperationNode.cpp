//
// Created by apel on 17.01.2021.
//

#include "LogicalOperationNode.h"

#include <utility>

LogicalOperationNode::LogicalOperationNode(
        const LogicalOperation &op,
        std::shared_ptr<Node> left,
        std::shared_ptr<Node> right)
        : _op(op)
        , _left(std::move(left))
        , _right(std::move(right)) {}


bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) const {
    if (_op == LogicalOperation::And) {
        return _left->Evaluate(date, event) && _right->Evaluate(date, event);
    } else if (_op == LogicalOperation::Or) {
        return _left->Evaluate(date, event) || _right->Evaluate(date, event);
    }
    throw std::invalid_argument("");
    return false;
}