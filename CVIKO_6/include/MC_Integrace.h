#ifndef MC_INTEGRACE_H
#define MC_INTEGRACE_H
#include "Shape.h"
#include <random>
#include <fstream>

// Tato trida ma na starosti integraci metodou Monte Carlo
class MC_Integrace
{
    public:
        MC_Integrace(int _n, double a, double b); // Predame pocet nahodnych vystrelu a rozmery ctvercove oblasti
        double vypocet(Shape const& s); // Zde se pocita samotny integral
    protected:
    private:
        std::ofstream vystupni_soubor;
        std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution;
        int n;
        double vol;
};

#endif // MC_INTEGRACE_H
