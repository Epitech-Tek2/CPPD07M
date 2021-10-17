/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include <iostream>
#include <string>
#include <fstream>

namespace Borg
{
    class Ship;
};

#include "Federation.hpp"
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship : public Entity {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();

            bool isStable();
            int getSide();
            void checkCore();
            void setupCore(WarpSystem::Core *core);
            int getWeaponFrequency();
            short getRepair();

            void setWeaponFrequency(int weaponFrequency);
            void setRepair(short repair);
            void repair();

            void fire(Federation::Starfleet::Ship *ship);
            void fire(Federation::Ship *ship);
            void stricken(int damage);
        private:
            int _side;
            short _repair;
            int _weaponFrequency;

    };
};

#endif /* !BORG_HPP_ */