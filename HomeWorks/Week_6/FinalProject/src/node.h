//
// Created by Dmitry Morozov on 26/11/22.
//

#ifndef COURSERA_YELLOW_BELT_DEV_NODE_H
#define COURSERA_YELLOW_BELT_DEV_NODE_H

#include "date.h"

#include <map>
#include <set>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};
enum class LogicalOperation {
    Or,
    And
};

class Node {
public:
    [[nodiscard]] virtual bool Evaluate(const Date &date, const std::string &event) const = 0;

    virtual ~Node() = default;
};

class EmptyNode : public Node {
public:
    EmptyNode() noexcept;

    [[nodiscard]] bool Evaluate(const Date &date, const std::string &event) const noexcept override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison &comprs, const Date &date) noexcept;

    [[nodiscard]] bool Evaluate(const Date &date, const std::string &event) const noexcept override;

private:
    const Comparison cmpr;
    const Date dt;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison &comprs, std::string event);

    [[nodiscard]] bool Evaluate(const Date &date, const std::string &event) const noexcept override;

private:
    const Comparison cmpr;
    const std::string evnt;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation &logical_operation,
                         const std::shared_ptr<Node> &lhs,
                         const std::shared_ptr<Node> &rhs) noexcept;

    [[nodiscard]] bool Evaluate(const Date &date, const std::string &event) const override;

private:
    const LogicalOperation lgc_op;
    const std::shared_ptr<Node> lhs_node;
    const std::shared_ptr<Node> rhs_node;
};


#endif //COURSERA_YELLOW_BELT_DEV_NODE_H
