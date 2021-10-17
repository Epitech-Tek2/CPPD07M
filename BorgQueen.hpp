/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include <iostream>
#include <string>
#include <fstream>

#include "Federation.hpp"
#include "Borg.hpp"
#include "tests/Dest.hpp"

namespace Borg
{
    class BorgQueen {
            public:
            BorgQueen();
            ~BorgQueen() = default;

            bool move(Borg::Ship *ship, Destination d);
            void destroy(Borg::Ship *ship, Federation::Ship *target);
            void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        public:
            bool (Borg::Ship::*movePtr)(Destination d);
            void (Borg::Ship::*destroyPtr)(Federation::Ship *ship);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *ship);
    };
} // namespace Borg

#endif /* !BORGQUEEN_HPP_ */