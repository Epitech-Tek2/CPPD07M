/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Exam
*/

#ifndef EXAM_HPP_
#define EXAM_HPP_

#include <iostream>
#include <string>
#include <fstream>

class Exam
{
    public:
        Exam(bool *currentCheat);
        ~Exam() = default;
        bool *cur;
        static bool cheat;
        void start(int value);

        void (Exam::*kobayashiMaru)(int value);
        bool isCheating();
};

#endif /* !EXAM_HPP_ */
