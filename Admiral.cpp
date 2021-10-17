/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Admiral
*/

#include "Admiral.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
    _name = name;
    movePtr = &Federation::Starfleet::Ship::move;
    firePtr = &Federation::Starfleet::Ship::fire;
    std::cout << "Admiral " + _name + " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{

}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship,
Destination d)
{
    return (ship->*movePtr)(d);
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship,
Borg::Ship *target)
{
    std::cout << "On order from Admiral " << _name << ":" << std::endl;
    (ship->*firePtr)(target);
}