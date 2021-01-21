//
// Created by apel on 17.01.2021.
//

#include "EventComparisonNode.h"

EventComparisonNode::EventComparisonNode(
        const Comparison &comparison, const std::string &value)
        : _comparison(comparison), _value(value) {}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) const {
    if (_comparison == Comparison::Less)
        return event < _value;
    if (_comparison == Comparison::LessOrEqual)
        return event <= _value;
    if (_comparison == Comparison::Greater)
        return event > _value;
    if (_comparison == Comparison::GreaterOrEqual)
        return event >= _value;
    if (_comparison == Comparison::Equal)
        return event == _value;
    if (_comparison == Comparison::NotEqual)
        return event != _value;
    throw std::invalid_argument("");
}
