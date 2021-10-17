/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

Borg::BorgQueen::BorgQueen()
{
    destroyPtr = &Borg::Ship::fire;
    firePtr = &Borg::Ship::fire;
    movePtr = &Borg::Ship::move;
}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination d)
{
    return (ship->*movePtr)(d);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    (ship->*destroyPtr)(target);
}

void Borg::BorgQueen::fire(Borg::Ship *ship,
Federation::Starfleet::Ship *target)
{
    (ship->*firePtr)(target);
}