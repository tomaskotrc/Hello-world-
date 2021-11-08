#include "MC_Integrace.h"
#include <fstream>


using namespace std;

MC_Integrace::MC_Integrace(int _n, double a, double b) :n(_n), distribution(a,b),vystupni_soubor("kyticka.txt")
{
    vol = (b-a)*(b-a);
}

double MC_Integrace::vypocet(Shape const& s) {
    int n_trefy = 0;

    for (int i=0;i<n;++i) {
        Point shot = Point(distribution(generator),distribution(generator));
        if (s.is_inside(shot))

         if (n_trefy %100==0) {
         vystupni_soubor<<shot.x<<" "<<shot.y;
         vystupni_soubor<<"\n" ;
         }

n_trefy++;


    }
    return vol*double(n_trefy)/double(n);

}
