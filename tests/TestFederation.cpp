/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** tests_ex00
*/

#include <ostream>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Federation.hpp"
#include "../WarpSystem.hpp"
#include "../Borg.hpp"
#include "../Admiral.hpp"
#include "../BorgQueen.hpp"

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

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void call_constructor()
{
    Federation::Starfleet::Ship Ship{10, 10, "ShipName", 10};
}

Test(testShipConstruction, read_all_content, .init=redirect_all_stdout) {
    call_constructor();
    cr_assert_stdout_eq_str("The ship USS ShipName has been finished.\nIt is 10 m in length and 10 m in width.\n""It can go to Warp 10!\n");
}

static void call_allOutput()
{
    Federation::Starfleet::Ship UssKreog(289 , 132 , "Kreog", 6);
    Federation::Ship Independent(150 , 230 , "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Independent.setupCore(&core2);
    Independent.checkCore();
    QR.setStability( false );
    QR2.setStability( false );
    UssKreog.checkCore();
    Independent.checkCore();
}

Test(testAllOutput, read_all_content, .init=redirect_all_stdout) {
    call_allOutput();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\nThe independent ship Greok just finished its construction.\nIt is 150 m in length and 230 m in width.\nUSS Kreog: The core is set.\nUSS Kreog: The core is stable at the time.\nGreok: The core is set.\nGreok: The core is stable at the time.\nUSS Kreog: The core is unstable at the time.\nGreok: The core is unstable at the time.\n");
}

static void callAllOutputEx2()
{
    Federation::Starfleet::Ship UssKreog(289 , 132 , "Kreog", 6);
    Federation::Starfleet::Captain James("James T. Kirk");
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);
    Borg::Ship Cube;
    Cube.setupCore(&core2);
    Cube.checkCore();
}

Test(testAllOutputEx2, read_all_content, .init=redirect_all_stdout) {
    callAllOutputEx2();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\nEnsign Pavel Chekov, awaiting orders.\nUSS Kreog: The core is set.\nUSS Kreog: The core is stable at the time.\nJames T. Kirk: I'm glad to be the captain of the USS Kreog.\nWe are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile.\nEverything is in order.\n");
}

static void callMovemnt()
{
    Federation::Starfleet::Ship UssKreog(289 , 132 , "Kreog", 6);
    Federation::Starfleet::Captain James("James T. Kirk");
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);

    UssKreog.move(VULCAN);
}

Test(testMovemnt, read_all_content, .init=redirect_all_stdout) {
    callMovemnt();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\nUSS Kreog: The core is set.\nUSS Kreog: The core is stable at the time.\nJames T. Kirk: I'm glad to be the captain of the USS Kreog.\n66101\n1\n");
}

static void callMovemntWarp()
{
    Federation::Starfleet::Ship UssKreog(289 , 132 , "Kreog", 6);
    Federation::Starfleet::Captain James("James T. Kirk");
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);
    UssKreog.move(6);
}

Test(testMovemntWarp, read_all_content, .init=redirect_all_stdout) {
    callMovemntWarp();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\nUSS Kreog: The core is set.\nUSS Kreog: The core is stable at the time.\nJames T. Kirk: I'm glad to be the captain of the USS Kreog.\n66001\n1\n");
}

static void callShipWithNoArgument()
{
    Federation::Starfleet::Ship UssKreog;
}

Test(testShipWithNoArgument, read_all_content, .init=redirect_all_stdout) {
    callShipWithNoArgument();
    cr_assert_stdout_eq_str("The ship USS Entreprise has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\n");
}

static void callBorg()
{
    Borg::Ship borgy;
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    borgy.setupCore(&core);
    borgy.checkCore();
}

Test(testBorg, read_all_content, .init=redirect_all_stdout) {
    callBorg();
    cr_assert_stdout_eq_str("We are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile.\nEverything is in order.\n");
}

static void callBorgFire()
{
    Federation::Starfleet::Ship UssKreog(289 , 132 , "Kreog", 6);
    Federation::Ship Kreog(289 , 132 , "Albert");
    Borg::Ship borgy;
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    borgy.setupCore(&core);
    borgy.checkCore();

    borgy.fire(&UssKreog);
    borgy.fire(&Kreog);
}

Test(testBorgFire, read_all_content, .init=redirect_all_stdout) {
    callBorgFire();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\nThe independent ship Albert just finished its construction.\nIt is 289 m in length and 132 m in width.\nWe are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile.\nEverything is in order.\nFiring on target with 20GW frequency.\nFiring on target with 20GW frequency.\n");
}

static void callBorgRepearAndStarfleetShipFire()
{
    Federation::Starfleet::Ship UssKreog(289 , 132 , "Kreog", 6);
    Federation::Ship Kreog(289 , 132 , "Albert");
    Borg::Ship borgy;
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    borgy.setupCore(&core);
    borgy.checkCore();
    Federation::Starfleet::Captain James("James T.Kirk");
    Federation::Starfleet::Captain Albert("Alert T.Kirk");

    UssKreog.promote(&James);
    Kreog.promote(&Albert);
    borgy.fire(&UssKreog);
    borgy.fire(&Kreog);
    UssKreog.fire(&borgy);
    borgy.repair();
}

Test(testBorgRepearAndStarfleetShipFire, read_all_content, .init=redirect_all_stdout) {
    callBorgRepearAndStarfleetShipFire();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is 289 m in length and 132 m in width.\nIt can go to Warp 6!\nThe independent ship Albert just finished its construction.\nIt is 289 m in length and 132 m in width.\nWe are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile.\nEverything is in order.\nJames T.Kirk: I'm glad to be the captain of the USS Kreog.\nAlert T.Kirk: I'm glad to be the captain of the USS Albert.\nFiring on target with 20GW frequency.\nFiring on target with 20GW frequency.\nKreog: No more torpedo to fire, James T.Kirk!\nBegin shield re-initialisation... Done. Awaiting further instructions.\n");
}

static void callBorgNoRepearAndStarfleetShipFire()
{
    Federation::Starfleet::Ship UssKreog(200, 100, "UssKreog", 6, 10);
    Federation::Ship Kreog(289 , 132 , "Albert");
    Borg::Ship borgy(20, 0);
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    borgy.setupCore(&core);
    borgy.checkCore();
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Federation::Starfleet::Captain James("James T.Kirk");
    Federation::Starfleet::Captain Albert("Alert T.Kirk");

    UssKreog.promote(&James);
    Kreog.promote(&Albert);
    borgy.fire(&UssKreog);
    borgy.fire(&Kreog);
    UssKreog.fire(9, &borgy);
    borgy.repair();
}

Test(testBorgNoRepearAndStarfleetShipFire, read_all_content, .init=redirect_all_stdout) {
    callBorgNoRepearAndStarfleetShipFire();
    cr_assert_stdout_eq_str("The ship USS UssKreog has been finished.\nIt is 200 m in length and 100 m in width.\nIt can go to Warp 6!\nWeapons are set: 10 torpedoes ready.\nThe independent ship Albert just finished its construction.\nIt is 289 m in length and 132 m in width.\nWe are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile.\nEverything is in order.\nUSS UssKreog: The core is set.\nUSS UssKreog: The core is stable at the time.\nJames T.Kirk: I'm glad to be the captain of the USS UssKreog.\nAlert T.Kirk: I'm glad to be the captain of the USS Albert.\nFiring on target with 20GW frequency.\nFiring on target with 20GW frequency.\nUssKreog: Firing on target. 1 torpedoes remaining.\nEnergy cells depleted, shield weakening.\n");
}

static void callAdmiralQueen()
{
    Federation::Starfleet::Ship UssKreog(200, 100, "UssKreog", 6, 10);
    Federation::Ship Kreog(289 , 132 , "Albert");
    Federation::Starfleet::Admiral General("General");
    Borg::BorgQueen Queen;
    Borg::Ship borgy(20, 0);
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    borgy.setupCore(&core);
    borgy.checkCore();
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Federation::Starfleet::Captain James("James T.Kirk");
    Federation::Starfleet::Captain Albert("Alert T.Kirk");

    UssKreog.promote(&James);
    Kreog.promote(&Albert);
    General.fire(&UssKreog, &borgy);
    Queen.fire(&borgy, &UssKreog);
}

Test(testAdminalQueen, read_all_content, .init=redirect_all_stdout) {
    callAdmiralQueen();
    cr_assert_stdout_eq_str("The ship USS UssKreog has been finished.\nIt is 200 m in length and 100 m in width.\nIt can go to Warp 6!\nWeapons are set: 10 torpedoes ready.\nThe independent ship Albert just finished its construction.\nIt is 289 m in length and 132 m in width.\nAdmiral General ready for action.\nWe are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile.\nEverything is in order.\nUSS UssKreog: The core is set.\nUSS UssKreog: The core is stable at the time.\nJames T.Kirk: I'm glad to be the captain of the USS UssKreog.\nAlert T.Kirk: I'm glad to be the captain of the USS Albert.\nOn order from Admiral General:\nUssKreog: Firing on target. 9 torpedoes remaining.\nFiring on target with 20GW frequency.\n");
}