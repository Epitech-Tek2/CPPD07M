/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Federation
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Federation.hpp"

Entity::~Entity()
{

}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _home = _location = EARTH;
    _torpedo = torpedo;
    _photonTorpedo = _torpedo;
    _shield = 100;
    std::cout << "The ship USS " + _name + " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (torpedo)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Entity::checkCore()
{
    if (_core)
        std::cout << "USS " + _name + ": The core is " +
        ((_core->getStability()) ? "stable" : "unstable")
        + " at the time." << std::endl;
}

void Entity::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " + _name + ": The core is set." << std::endl;
}

void Entity::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() + ": I'm glad to be the captain of the USS " + _name + "." << std::endl;
}

WarpSystem::Core *Entity::getCore()
{
    return (_core);
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _shield = 100;
    _home = _location = EARTH;
    _photonTorpedo = _torpedo;
    std::cout << "The independent ship " + _name + " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::checkCore()
{
    if (_core)
        std::cout << _name + ": The core is " +
        ((_core->getStability()) ? "stable" : "unstable")
        + " at the time." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name + ": The core is set." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

Federation::Starfleet::Captain::~Captain()
{

}

int Federation::Starfleet::Captain::getAge()
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " + _name + ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{

}

bool Entity::move(int warp, Destination d)
{
    bool stable = ((getCore()) ? getCore()->isStable() : false);

    if (warp <= _maxWarp && d != _location && stable) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Entity::move(int warp)
{
    return (move(warp, _home));
}

bool Entity::move(Destination d)
{
    return (move(_maxWarp, d));
}

bool Entity::move()
{
    return (move(_maxWarp, _home));
}

int Entity::getShield()
{
    return (_shield);
}

void Entity::setShield(int shield)
{
    _shield = shield;
}

int Entity::getTorpedo()
{
    return (_torpedo);
}

void Entity::setTorpedo(int torpedo)
{
    _torpedo = torpedo;
}

void Entity::fire(Borg::Ship *ship)
{
    return fire(1, ship);
}

void Entity::fire(int torpedo, Borg::Ship *ship)
{
    if (torpedo <= _photonTorpedo) {
        ship->stricken(50 * torpedo);
        _photonTorpedo -= torpedo;
        std::cout << _name + ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    } else if (_photonTorpedo) std::cout << _name + ": No enough torpedoes to fire, " << (_captain ? _captain->getName() : "") << "!" << std::endl;
    else std::cout << _name << ": No more torpedo to fire, " << (_captain ? _captain->getName() : "") << "!" << std::endl;
}

void Entity::stricken(int damage)
{
    _shield -= damage;
    if (_shield < 0) _shield ^= _shield;
}