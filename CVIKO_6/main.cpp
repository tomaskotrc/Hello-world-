#include <iostream>
#include <memory>
#include "Shape.h"
#include "MC_Integrace.h"

int main()
{
    // Polymorfni ukazatel, muzeme do nej ukladat libovolne objekty
    // jakekoli tridy odvozene od Shape

    std::shared_ptr<Shape> s;

    int utvar;
    std::cout << "Vyberte druh utvaru (1 - kruh, 2 - kyticka): " << std::endl;
    std::cin >> utvar;

    // Podle uzivatelskeho zadani pripravime vybrany objekt a nasmerujeme na nej ukazatel
    // Parametry funkce make_shared jsou stejne jako parametry konstruktoru naseho objektu
    if (utvar == 1) {
        s = std::make_shared<Circle>(Point(0.0,0.0),1.0);
    }
    else if (utvar == 2) {
        s = std::make_shared<Flower>(Point(0.0,0.0),1.0,4.0);
    }

    // Nyni vypocitame integral metodou Monte Carlo
    const int n_shots = 1000000;
    MC_Integrace integral(n_shots,-1.0,1.0);
    double obsah = integral.vypocet(*s); // Pri predavani objektu musime ukazatel dereferencovat operatorem *
                                         // Jinak by se prekladac snazil predat funkci pouze
                                         // ciselnou hodnotu adresy v pameti

    std::cout << "Provedeno " << n_shots << " iteraci MC metody." << std::endl;
    std::cout << "Obsah utvaru je " << obsah << std::endl;

    return 0;
}
