//
// Created by apel on 17.01.2021.
//

#include "DateComparisonNode.h"

DateComparisonNode::DateComparisonNode(const Comparison &comparison, const Date &date)
        : _comparison(comparison), _date(date) {}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &string) const {
    if (_comparison == Comparison::Less)
        return date < _date;
    if (_comparison == Comparison::LessOrEqual)
        return date <= _date;
    if (_comparison == Comparison::Greater)
        return date > _date;
    if (_comparison == Comparison::GreaterOrEqual)
        return date >= _date;
    if (_comparison == Comparison::Equal)
        return date == _date;
    if (_comparison == Comparison::NotEqual)
        return date != _date;
    throw std::invalid_argument("");
}
