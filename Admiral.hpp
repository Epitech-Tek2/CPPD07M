/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include <iostream>
#include <string>
#include <fstream>

namespace Federation
{
    namespace Starfleet
    {
        class Admiral;
    } // namespace Starfleet
} // namespace Federation

#include "tests/Dest.hpp"
#include "Borg.hpp"
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral {
            public:
                bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *ship);
            public:
                Admiral(std::string name);
                ~Admiral();

                bool move(Federation::Starfleet::Ship *ship, Destination d);
                void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);

            private:
                std::string _name;
        };
    } // namespace Starfleet
} // namespace Federation

#endif /* !ADMIRAL_HPP_ */