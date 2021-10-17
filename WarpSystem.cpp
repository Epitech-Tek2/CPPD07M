/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-clement.muth
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

bool WarpSystem::QuantumReactor::getStability()
{
    return (_stability);
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (getStability());
}

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{

}

bool WarpSystem::Core::getStability()
{
    return ((_coreReactor) ? _coreReactor->getStability() : false);
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (_coreReactor);
}

bool WarpSystem::Core::isStable()
{
    return (getStability());
}