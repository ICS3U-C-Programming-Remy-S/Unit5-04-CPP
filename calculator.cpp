// Copyright (c) 2023 Remy Skelton All rights reserved.
//
// Created by: Remy Skelton
// Date: Dec, 4, 2023
// This program will ask user for 2 numbers
// and a operation and it will find the result
// of the two numbers to the operation

#include <iostream>
#include <string>
#include <cmath>

float calculate(char sign, float first_number, float second_number) {
    // Statements for each operation
    if (sign == '+') {
        return first_number + second_number;
    } else if (sign == '-') {
        return first_number - second_number;
    } else if (sign == '*') {
        return first_number * second_number;
    } else if (sign == '/') {
        return first_number / second_number;
    } else if (sign == '%') {
        return fmod(first_number, second_number);
    } else {
        std::cout << "The operation entered is invalid." << std::endl;
    }
}

int main() {
    // declare variables
    std::string user_num1_str, user_num2_str, user_operation_str;

    // Get numbers and operation and display message to user
    std::cout << "This program will ask for 2 numbers" << std::endl;
    std::cout << "and an operation and find the result" << std::endl;
    std::cout << "of the two numbers to the operation." << std::endl;
    std::cout << "Please enter your first number: ";
    std::cin >> user_num1_str;
    std::cout << "Please enter your second number: ";
    std::cin >> user_num2_str;
    std::cout << "Please enter the operation you want done: ";
    std::cin >> user_operation_str;

    // Convert numbers and operation
    try {
        float user_num1_float = std::stof(user_num1_str);
        float user_num2_float = std::stof(user_num2_str);
        char user_operation_char = user_operation_str[0];

        // Call function and store the result
        float result =
        calculate(user_operation_char, user_num1_float, user_num2_float);

        // Check if the input is valid
        if (user_operation_char == '%' &&
        (user_num2_float == 0 || user_num1_float == 0)) {
            std::cout << "You can't find the remainder using 0" << std::endl;
        } else if (user_operation_char == '/' &&
        (user_num2_float == 0 || user_num1_float == 0)) {
            std::cout << "You can't divide using 0" << std::endl;
        } else {
            std::cout << user_num1_float << " " << user_operation_char
            << " " << user_num2_float << " = " << result << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << user_num1_str << ", " << user_operation_str <<
        ", " << user_num2_str << " are not valid numbers and/or operations"
        << std::endl;
    }
    return 0;
}
