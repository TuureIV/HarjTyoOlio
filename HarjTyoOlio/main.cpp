/* Tässä ohjelmassa luodaan Luokka eläin ja leikitään niillä.
 * Loppujenlopuksi, tällä koodilla, ei ole juurikaan mitään syöttöarvoja, mutta kaikenkaikkiaan se toimii kuten pitää
*/
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector> //käytetään säiliöluokkaa vector

using namespace std;

// Luodaan yliluokka, jolla on vain yksi suojattu string. Se on dna, joka sitoo koko eläinkunnan yhteen.
// Jos halutaan luoda lisää DNA:ta ja halutaan lisätä aminohappojonoon kirjaimia, tulee uusi kirjain lisätä merkkijonon alkuun.

class Fauna
{
protected:
    string dna="TACGCACGAATT"; //Tässä on pätkä keksityn geenin DNA aminohappojonosta.

    string dnakaanto() //käännetään aminohapot
    {
     reverse(dna.begin(), dna.end());
     return dna;
    }
};

/*Aliluokka
 * Kehityksessä on päästy siihen pisteeseen, että DNA:sta on poikinut ihmisiä, jotka antavat muille DNA-möykyille myös irrelevantteja
 * ominaisuuksia, kuten nimen.
 */

class Elain: public Fauna
{
// Annetaan yksityinen tunnus eläimelle, joka on suosikki
private:
    string status="Suosikki";

public:
    string nimi;
    string ika;
    string vari;
    //Luodaan yksinkertainen jäsenfunktio, jolla voidaan kutsua eläintä suosikiksi
    string get_status()
    {
        return status;
    }
    string givelife()
    {return dna;
    }
    string dnareverse()
    {
     return dnakaanto();

    }

    //Tradaa, tässä esittelen operaattorin ylikuormituksen
    int x,y;
    bool operator == (Elain paikka)
    {
        if(x==paikka.x && y==paikka.y)
        {
            return true;
        }
        return false;
    }
};

     // tehdään tarkastus, onko eläimellä sama nimi ja ikä. Täässä esimerkissä ei saa olla, vaikka olisikin eri eläin.
     int add_elain_if_not_exists(vector<Elain> &elaimet, Elain elain)
     {
         for (int i = 0; i<elaimet.size(); i++) //luodaan for looppi
         {
             if(elaimet[i].nimi==elain.nimi)
             {
             return i; //jos eläinten ikä ja nimi on sama, lopetetaan. Osoittaa sisällä olevan eläimen indexin
             }
         }
         elaimet.push_back(elain); //jos matchia ei löydy, päästetään eläin läpi
         return elaimet.size()-1; //nähdään vektorin indexi, eli osoittaa uuden eläimen indeksin
     }

int main()
{
    //Lisätään muuttujat

    vector<Elain>elaimet;

    //Lisättään olioita

    Elain koira, kissa, kani, virtahepo;

    koira.nimi="Musti";
    koira.ika= "3";
    koira.vari="Ruskea";
    koira.get_status();                 //joku on saanut erityiskohtelua

    kissa.nimi="Kehra";
    kissa.ika= "3";
    kissa.vari="keltainen";

    kani.nimi="Porro";
    kani.ika= "2";
    kani.vari="musta";

    //vielä viimehetkellä lisäsin interaktiivisuutta koodiin

    cout<< "Anna virtahevolle nimi (Musti), tai joku muu ja paina enter. " <<endl;
  
    cin >> virtahepo.nimi;

    virtahepo.ika="3";
    virtahepo.vari="harmaa";
    virtahepo.givelife();
    virtahepo.dnareverse();

    elaimet.push_back (koira);
    elaimet.push_back (kissa);
    elaimet.push_back (kani);

    //testataan virtahevon sopivuutta vektroiin.

    cout << add_elain_if_not_exists(elaimet, virtahepo) <<endl;

    //Tulostetaan, mikäli uusi tulokas machaa

    if (koira.nimi==virtahepo.nimi)
    {cout <<"Nimi tasmaa koiran kanssa, virtahepoa ei lisata stringiin"<< endl;
    }

    //Tulostetaan salaisuuksia

    cout<< "Koiralla "<<koira.nimi<< " on status "<< koira.get_status() <<endl;
    cout<< "Pala yliluokan aminohappokoodia: " <<endl;
    cout<<virtahepo.givelife()<<endl;
    cout<<virtahepo.dnareverse()<<endl;
    cout<<"Ja alapuolella juoste valmiina ottamaan lisaa kirjaimia"<< endl;


    return 0;

}
