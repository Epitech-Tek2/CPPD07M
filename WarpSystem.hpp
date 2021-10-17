/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include <iostream>
#include <string>
#include <fstream>

namespace
{
    class QuantumReactor;
    class Core;
}

namespace WarpSystem
{
    class QuantumReactor
    {
        public:
            QuantumReactor();
            ~QuantumReactor();

            void setStability(bool stability);
            bool getStability();
            bool isStable();

        private:
            bool _stability;
    };

    class Core
    {
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();

            QuantumReactor *checkReactor();
            bool getStability();
            bool isStable();


        private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */