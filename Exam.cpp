/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Exam
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Exam.hpp"

Exam::Exam(bool *currentCheat) : cur(currentCheat) {}

bool Exam::cheat = false;

void Exam::start(int value)
{
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << value << " Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;
    if (!cheat) std::cout << "This exam is hard... you lost again." << std::endl;
    else std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
}

bool Exam::isCheating()
{
    return (cheat);
}