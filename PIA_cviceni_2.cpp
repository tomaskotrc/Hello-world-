#include <iostream>
#include <fstream>
using namespace std;

int main()  {
int c, d, e ; string a, b; // retezec textu
cout <<"Zadejte Vase krestni jmeno a prijmeni s mezerou:  ";
cin >> a >> b;
cout << "Zadejte Vas vek: ";
cin >> c;
if (c <= 0 || c >= 150 ){
do { cout << "Vas vek musi byt cele cislo v rozmezi od 0 do 150 let. Zkuste to znova. ";
cin >> c;
}
while (c <= 0 || c >= 150 );
}
cout << "Zadejte Vasi vysku v centimetrech: ";
cin >> d;
if (d <= 0.0 || d >= 250.0 ){
do { cout << "Vase vyska se musi nachazet v rozmezi od 0 do 250 cm. Zkuste to znova. ";
cin >> d;
}
while (d <= 0.0 || d >= 250.0 );
}
cout << "Zadejte cislo pro Vase nejvyse dosazene vzdelani:\n0  zakladni skola \n1  stredni skola \n2 vysoka skola         ";
cin >> e;
if (e != 0 && e != 1 && e != 2 ){
do { cout << "Nevhodny vyber. Zvolte jednu z nabizenych moznosti ";
cin >> e;
}
while (e != 0 && e != 1 && e != 2 );
}

cout << "\nProfil uchazece o zamestnani: \nJmeno a prijmeni: " << a << " " << b << endl << "Vek: " << c << endl << "Vyska(cm): " << d << endl << "Nejvyssi dosazene vzdelani: ";
if (e == 0) {
        cout << "zakladni skola";
}
else if (e == 1) {
        cout << "stredni skola";
}
else {
        cout << "vysoka skola";
}

fstream PIA_cviceni_2("uzivatel.txt", ios::out);
    PIA_cviceni_2 << "Jmeno a prijemni:" << a << " " << b << "\nVek:" << c << "let" << "\nVyska:" << d << "cm" << "\nDosazene vzdelani:" << e << "\n\n";
PIA_cviceni_2.close();

return 0;

}
