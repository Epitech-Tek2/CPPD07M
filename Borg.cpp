/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    _weaponFrequency = weaponFrequency;
    _repair = repair;
    _side = 3000;
    _maxWarp = 9;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

bool Borg::Ship::isStable()
{
    return ((getCore()->isStable()) ? true : false);
}

int Borg::Ship::getSide()
{
    return (_side);
}

void Borg::Ship::checkCore()
{
    if (_core)
        std::cout << ((_core->getStability()) ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

int Borg::Ship::getWeaponFrequency()
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int weaponFrequency)
{
    _weaponFrequency = weaponFrequency;
}

short Borg::Ship::getRepair()
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::stricken(int damage)
{
    _shield <<= damage;
    if (_shield < 0) _shield ^= _shield;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *ship)
{
    ship->stricken(_weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *ship)
{
    ship->stricken(_weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (_repair > 0) {
        _repair--;
        _shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else std::cout << "Energy cells depleted, shield weakening." << std::endl;
}