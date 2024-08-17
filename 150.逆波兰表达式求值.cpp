/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        // 存储运算符映射关系
        map<string, int> operator_map;
        operator_map.insert(make_pair<>("+", 1));
        operator_map.insert(make_pair<>("-", 2));
        operator_map.insert(make_pair<>("*", 3));
        operator_map.insert(make_pair<>("/", 4));

        for (int i = 0; i < tokens.size(); i++)
        {
            // 非运算符入栈
            if (!operator_map.count(tokens[i]))
                operands.push(stoi(tokens[i]));
            // 操作符弹出栈运算后入栈
            else
            {
                auto op1 = operands.top();
                operands.pop();
                auto op2 = operands.top();
                operands.pop();
                int res;
                
                switch (operator_map[tokens[i]])
                {
                case 1: // +
                    res = op2 + op1;
                    operands.push(res);
                    break;
                case 2: // -
                    res = op2 - op1;
                    operands.push(res);
                    break;
                case 3: // *
                    res = op2 * op1;
                    operands.push(res);
                    break;
                case 4: // /
                    res = op2 / op1;
                    operands.push(res);
                    break;
                }
            }
        }

        return operands.top();
    }
};
// @lc code=end

