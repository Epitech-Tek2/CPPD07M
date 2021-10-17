/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>
#include <string>
#include <fstream>

#ifndef _DESTINATION_
#define _DESTINATION_

enum Destination
{
    EARTH,
    VULCAN,
    ROMULUS,
    REMUS,
    UNICOMPLEX,
    JUPITER,
    BABEL
};

#endif

namespace Federation
{
    namespace Starfleet {
        class Ship;
        class Captain;
        class Ensign;
    }
    class Ship;
};
namespace Borg
{
    class Ship;
};

#include "WarpSystem.hpp"

class Entity
{
    public:
        virtual void checkCore();
        virtual void setupCore(WarpSystem::Core *core);
        virtual ~Entity();
        void promote(Federation::Starfleet::Captain *captain);
        WarpSystem::Core *getCore();

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

        virtual void fire(Borg::Ship *ship);
        virtual void fire(int torpedo, Borg::Ship *ship);
        virtual void stricken(int damage);

        int getShield();
        void setShield(int shield);
        int getTorpedo();
        void setTorpedo(int torpedo);
    protected:
        Federation::Starfleet::Captain *_captain;
        Destination _home;
        Destination _location;
        int _length;
        int _width;
        int _torpedo;
        int _shield;
        int _photonTorpedo;
        short _maxWarp;
        std::string _name;
        WarpSystem::Core *_core;
};

#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship : public Entity {
            public:
                Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 0);
                ~Ship();
        };
        class Captain
        {
            public:
                Captain(std::string name);
                ~Captain();

                int getAge();
                std::string getName();
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ensign
        {
            public:
                explicit Ensign(std::string name);
                ~Ensign();
            private:
                std::string _name;
        };
    }
    class Ship : public Entity {
        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void checkCore();
            void setupCore(WarpSystem::Core *core);
    };
};

#endif /* !FEDERATION_HPP_ */