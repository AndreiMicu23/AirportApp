#include <iostream>
#include<stdio.h>
#include <string.h>
#include <cstring>
using namespace std;
class Zboruri
{
public:
    int zi;
    int luna;
    int an;
    int nr_unic_zbor;
    int ora_plecare;
    int minut_plecare;
    int ora_sosire;
    int minut_sosire;
    string aeroport_plecare;
    string oras_plecare;
    string aeroport_destinatie;
    string oras_destinatie;
    int nr_locuri;
    void adaugare_zbor(int a, int b, int c, int d, int e, int f, int g, int h, string s1, string s2, string s3, string s4, int nr)
    {
        if (e > 23 || e < 0)
            throw "\nOra de plecare incorecta\n";
        if (f > 59 || f < 0)
            throw "Minut de plecare incorect\n";
        if (g > 23 || g < 0)
            throw "\nOra de sosire incorecta\n";
        if (h > 59 || h < 0)
            throw "\nMinut de sosire incorect\n";
        if (d < 2020)
            throw "\nData in trecut\n";
        if (d == 2020 && c < 12)
            throw "\nData in trecut\n";
        if (d == 2020 && c == 12 && b < 7)
            throw "\nData in trecut\n";
        //presupunem ca incepem de pe 7 decembrie
        if (c > 12 || c < 1)
            throw "\nLuna incorecta\n";
        if (d < 2020 || d>2022)
            throw "\nAn indisponibil\n";
        if (c == 2 && b > 28)
            throw "\nZi incorecta\n";
        if (c == 4 || c == 6 || c == 9 || c == 11)
            if (b > 30)
                throw "\nZi incorecta\n";
        if (c == 1 || c == 3 || c == 5 || c == 7 || c == 8 || c == 10 || c == 12)
            if (b > 31)
                throw "\nZi incorecta\n";
        if (s1 == s3)
            throw "\nAeroport plecare e acelasi cu aeroport sosire\n";
        if (s2 == s4)
            throw "\nOras plecare e acelasi cu oras sosire\n";

        int i;
        for (i = 0;i < s1.length();i++)
        {
            if (isalpha(s1[i]) == 0 && s1[i] != 95)
                throw "Aeroportul de plecare contine numere sau caractere dubioase!\n";
        }
        for (i = 0;i < s2.length();i++)
        {
            if (isalpha(s2[i]) == 0 && s2[i] != 95)
                throw "Orasul de plecare contine numere sau caractere dubioase!\n";
        }
        for (i = 0;i < s3.length();i++)
        {
            if (isalpha(s3[i]) == 0 && s3[i] != 95)
                throw "Aeroportul destinatie contine numere sau caractere dubioase!\n";
        }
        for (i = 0;i < s4.length();i++)
        {
            if (isalpha(s4[i]) == 0 && s4[i] != 95)
                throw "Orasul destinatie contine numere sau caractere dubioase!\n";
        }
        this->nr_unic_zbor = a;
        this->zi = b;
        this->luna = c;
        this->an = d;
        this->ora_plecare = e;
        this->minut_plecare = f;
        this->ora_sosire = g;
        this->minut_sosire = h;
        this->aeroport_plecare = s1;
        this->oras_plecare = s2;
        this->aeroport_destinatie = s3;
        this->oras_destinatie = s4;
        this->nr_locuri = nr;
    }
    int stergere_zbor(Zboruri v[], int nr_zb, int pozitie)
    {
        if (pozitie > nr_zb || pozitie <= 0)
            throw "Zborul NU exista!\n";
        int i, j;
        for (i = 0; i < nr_zb; i++)
            if (i == pozitie - 1)
            {
                for (j = i;j < nr_zb - 1;j++)
                {
                    v[j] = v[j + 1];
                }
                break;
            }
        return nr_zb - 1;
    }
    int rezervare_zbor(Zboruri v[], int pozitie, int nr_zb, int rezervari)
    {
        if (pozitie > nr_zb)
            throw "Zborul NU exista!\n";
        if (rezervari > 6)
            throw "NU se pot rezerva mai mult de 6 locuri\n";
        v[pozitie].nr_locuri -= rezervari;
    }
    int cautare_zbor(Zboruri v[], string s1, string s2, string s3, string s4, int numar)
    {
        int i = 0;
        for (i = 0; i < numar; i++)
        {
            if (v[i].aeroport_plecare == s1 && v[i].oras_plecare == s2 && v[i].aeroport_destinatie == s3 && v[i].oras_destinatie == s4)
            {
                cout << "Zborul exista, are numarul de zbor " << i + 1 << endl;
                return 1;
            }
        }
        throw "Zborul NU exista!\n";
    }
};
int exista(Zboruri z[], int b, int c, int d, int e, int f, int g, int h, string s1, string s2, string s3, string s4, int nr, int nr_zb)
{
    int i;
    for (i = 0; i < nr_zb; i++)
    {
        if (b == z[i].zi)
            if (c == z[i].luna)
                if (d == z[i].an)
                    if (e == z[i].ora_plecare)
                        if (f == z[i].minut_plecare)
                            if (g == z[i].ora_sosire)
                                if (h == z[i].minut_sosire)
                                    if (s1 == z[i].aeroport_plecare)
                                        if (s2 == z[i].oras_plecare)
                                            if (s3 == z[i].aeroport_destinatie)
                                                if (s4 == z[i].oras_destinatie)
                                                    if (nr == z[i].nr_locuri)
                                                        throw "Zborul exista DEJA!\n";
    }
    return 0;
}
class Operator
{
public:
    string id;
    string parola;

    int logare(Operator v[], string x, string y, int i)
    {
        int j = 0;
        while (j < i)
        {
            if (v[j].id == x && v[j].parola == y)
            {
                cout << "Conectare reusita.\n";
                return 1;
            }
            j += 1;
        }
        throw "ID sau parola gresita!\n";
    }
};
class Utilizator
{
public:
    string id;
    string parola;
    int logare(Utilizator v[], string x, string y, int i)
    {
        int j = 0;
        while (j < i)
        {
            if (v[j].id == x && v[j].parola == y)
            {
                cout << "Conectare reusita.\n";
                return 1;
            }
            j += 1;
        }
        throw "ID sau parola gresita!\n";
    }
};
void afisare_zbor(Zboruri z)
{
    /*cout << "Nr zbor: " << z.nr_unic_zbor << "\n";
    cout << "Zi: " << z.zi << "\n";
    cout << "Luna:  " << z.luna << "\n";
    cout << "An:  " << z.an << "\n";
    cout << "Ora plecare:  " << z.ora_plecare << "\n";
    cout << "Minut plecare: " << z.minut_plecare << "\n";
    cout << "Ora sosire: " << z.ora_sosire << "\n";
    cout << "Minut sosire: " << z.minut_sosire << "\n";
    cout << "Aeroport plecare: " << z.aeroport_plecare << "\n";
    cout << "Oras plecare: " << z.oras_plecare << "\n";
    cout << "Aeroport sosire: " << z.aeroport_destinatie << "\n";
    cout << "Oras sosire: " << z.oras_destinatie << "\n";
    cout << "Numar locuri: " << z.nr_locuri << "\n";*/
    cout << z.nr_unic_zbor << ")";
    cout << z.zi << ", ";
    cout << z.luna << ", ";
    cout << z.an << ", ";
    cout << z.ora_plecare << ", ";
    cout << z.minut_plecare << ", ";
    cout << z.ora_sosire << ", ";
    cout << z.minut_sosire << ", ";
    cout << z.aeroport_plecare << ", ";
    cout << z.oras_plecare << ", ";
    cout << z.aeroport_destinatie << ", ";
    cout << z.oras_destinatie << ", ";
    cout << z.nr_locuri;
}
int creare_cont(string nume, string parola1, string parola2)
{
    int i;
    int poz1 = 0, poz2 = 0;
    int numar_arond = 0;//nr de @-uri
    //pozitiile unde se gasesc @ si .
    if (nume.length() < 8)
        throw "Numele dvs este prea scurt!";
    for (i = 0;i < nume.length();i++)
    {
        if (nume[i] == '@')
        {
            poz1 = i;
            numar_arond++;
        }
        if (nume[i] == '.')
            poz2 = i;
    }
    if (poz1 == 0 || poz2 == 0)
        throw "Format email gresit!\n";
    //daca pozitia @ e mai mare decat cea mai mare pozitie unde se gaseste punct inseamna ca e gresit
    if (poz2 < poz1)
        throw "Format email gresit!\n";
    if (numar_arond != 1)
        throw "Numele trebuie sa aiba doar un @!\n";
    if (parola1.length() < 8)
        throw "Parola prea scurta(are mai putin de 8 caractere)!\n";
    if (parola1 != parola2)
        throw "Parolele NU se potrivesc!\n";
    int literamica = 0, literamare = 0, numar = 0, caracter_special = 0;
    int contuar = 0;
    for (i = 0;i < parola1.length();i++)
    {
        if (islower(parola1[i]))
            literamica = 1;
        if (isupper(parola1[i]))
            literamare = 1;
        if (isdigit(parola1[i]))
            numar = 1;
        if (!isalpha(parola1[i]) && !isdigit(parola1[i]))
            caracter_special = 1;
    }
    if (literamica == 1 && literamare == 1 && numar == 1 && caracter_special == 1)
    {
        cout << "Cont creat!\n";
        contuar = 1;
    }
    if (contuar == 1)
        return 1;
    throw "Parola nu contine toate tipurile de caractere: litera mica, litera mare, numar si caracter special!\n";
}
int main()
{
    Operator o[10];
    Utilizator u[10];
    o[0].id = "andrei@gmail.com";
    o[0].parola = "mereMere23";
    o[1].id = "ana@mmere.ro";
    o[1].parola = "Asdfasdf12";
    o[2].id = "florentinn@yahoo.com";
    o[2].parola = "B24asdf1";
    u[0].id = "iuliaa0909@yahoo.com";
    u[0].parola = "AI27asdf";
    u[1].id = "bogdan12333@yahoo.ro";
    u[1].parola = "17Zxcv17";
    Zboruri v[10];
    int nro = 3;
    int nru = 2;
    /*am scris cu underline pentru ca  nu citeste cum trebuie
    campurile vectorului daca le scriu cu space.*/
    v[0].nr_unic_zbor = 1;
    v[0].zi = 25;
    v[0].luna = 3;
    v[0].an = 2021;
    v[0].ora_plecare = 9;
    v[0].minut_plecare = 0;
    v[0].ora_sosire = 12;
    v[0].minut_sosire = 0;
    v[0].aeroport_plecare = "Aeroport_Henri_Coanda";
    v[0].oras_plecare = "Bucuresti";
    v[0].aeroport_destinatie = "Aeroport_Hamburg";
    v[0].oras_destinatie = "Hamburg";
    v[0].nr_locuri = 200;
    v[1].nr_unic_zbor = 2;
    v[1].zi = 21;
    v[1].luna = 2;
    v[1].an = 2022;
    v[1].ora_plecare = 12;
    v[1].minut_plecare = 3;
    v[1].ora_sosire = 22;
    v[1].minut_sosire = 9;
    v[1].aeroport_plecare = "Aeroport_Aurel_Vlaicu";
    v[1].oras_plecare = "Bucuresti";
    v[1].aeroport_destinatie = "Aeroport_John_F_Kennedy";
    v[1].oras_destinatie = "New_York";
    v[1].nr_locuri = 231;
    v[2].nr_unic_zbor = 3;
    v[2].zi = 29;
    v[2].luna = 12;
    v[2].an = 2020;
    v[2].ora_plecare = 7;
    v[2].minut_plecare = 42;
    v[2].ora_sosire = 8;
    v[2].minut_sosire = 57;
    v[2].aeroport_plecare = "Aeroport_Henri_Coanda";
    v[2].oras_plecare = "Bucuresti";
    v[2].aeroport_destinatie = "Aeroport_Charles_de_Gaulle";
    v[2].oras_destinatie = "Paris";
    v[2].nr_locuri = 340;
    v[3].nr_unic_zbor = 4;
    v[3].zi = 18;
    v[3].luna = 10;
    v[3].an = 2021;
    v[3].ora_plecare = 20;
    v[3].minut_plecare = 1;
    v[3].ora_sosire = 23;
    v[3].minut_sosire = 7;
    v[3].aeroport_plecare = "Aeroport_Gardermoen";
    v[3].oras_plecare = "Oslo";
    v[3].aeroport_destinatie = "Aeroport_Henri_Coanda";
    v[3].oras_destinatie = "Bucuresti";
    v[3].nr_locuri = 500;
    string om;
    string x, y;
    int nr_zb = 4;
    int i;
    cout << "Introduceti tipul persoanei care se conecteaza:(operator/utilizator): ";
    cin >> om;
    while (om != "operator" && om != "utilizator")
    {
        cout << "FORMAT GRESIT!Va rugam introduceti un statut valabil.\n";
        cin >> om;
    }
    while (om == "operator" || om == "utilizator")
    {
        if (om == "operator")
        {
            try
            {
                cout << "ID:";
                cin >> x;
                cout << "Parola:";
                cin >> y;
                int k = 0;
                int semafor = 0;
                int a1 = 0;
                while (semafor == 0)
                {
                    try
                    {
                        a1 = o[k].logare(o, x, y, nro);
                        if (a1 == 1)
                            semafor = 1;
                    }
                    catch (const char* msg)
                    {
                        cout << msg;
                        cout << "\n" << "ID:";
                        cin >> x;
                        cout << "Parola:";
                        cin >> y;
                    }
                }
                //cat timp nu am iesit din program
                while (1 == 1)
                {
                    char optiune;
                    cout << "Optiuni:\n" << "1.Adaugare zbor\n" << "2.Stergere zbor\n" << "0.Exit\n";
                    cout << "Alegeti optiunea: ";
                    cin >> optiune;
                    while (optiune != '1' && optiune != '2' && optiune != '0')
                    {
                        cout << "Optiune inexistenta.Alegeti una din optiunile existente.\n";
                        cin >> optiune;
                    }
                    if (optiune == '1')
                    {
                        cout << "\n";
                        for (i = 0; i < nr_zb; i++)
                        {
                            afisare_zbor(v[i]);
                            cout << "\n";
                        }
                        cout << "\n";
                        int zi;
                        cout << "Ziua: ";
                        cin >> zi;
                        int luna;
                        cout << "Luna: ";
                        cin >> luna;
                        int an;
                        cout << "Anul: ";
                        cin >> an;
                        int ora1;
                        cout << "Ora plecare: ";
                        cin >> ora1;
                        int minut1;
                        cout << "Minut plecare: ";
                        cin >> minut1;
                        int ora2;
                        cout << "Ora sosire: ";
                        cin >> ora2;
                        int minut2;
                        cout << "Minut sosire: ";
                        cin >> minut2;
                        string sir1, sir2, sir3, sir4;
                        cout << "Aeroport Plecare: ";
                        cin >> sir1;
                        cout << "Oras plecare: ";
                        cin >> sir2;
                        cout << "Aeroport sosire: ";
                        cin >> sir3;
                        cout << "Oras sosire: ";
                        cin >> sir4;
                        int numar;
                        cout << "Numar locuri: ";
                        cin >> numar;
                        try
                        {
                            try
                            {
                                int ert = exista(v, zi, luna, an, ora1, minut1, ora2, minut2, sir1, sir2, sir3, sir4, numar, i);
                                v[nr_zb].adaugare_zbor(nr_zb + 1, zi, luna, an, ora1, minut1, ora2, minut2, sir1, sir2, sir3, sir4, numar);
                                nr_zb++;
                                cout << nr_zb;
                            }
                            catch (const char* msg)
                            {
                                cout << msg;
                            }
                        }
                        catch (const char* msg)
                        {
                            cout << msg;
                        }
                        cout << "\n";
                        for (i = 0; i < nr_zb; i++)
                        {
                            afisare_zbor(v[i]);
                            cout << "\n";
                        }
                    }
                    if (optiune == '2')
                    {
                        int prr;
                        cout << "\n";
                        for (i = 0; i < nr_zb; i++)
                        {
                            afisare_zbor(v[i]);
                            cout << "\n";
                        }
                        int pozitie;
                        cout << "Numarul zborului de sters:";
                        cin >> pozitie;
                        try
                        {
                            prr = v[i].stergere_zbor(v, nr_zb, pozitie);
                            //  v[i].stergere_zbor(v, nr_zb);
                            nr_zb--;
                            for (i = 0;i < nr_zb;i++)
                            {
                                v[i].nr_unic_zbor = i + 1;
                            }
                        }
                        catch (const char* msg)
                        {
                            cout << msg;
                        }
                        for (i = 0; i < nr_zb; i++)
                        {
                            afisare_zbor(v[i]);
                            cout << "\n";
                        }
                    }
                    if (optiune == '0')
                    {
                        exit(1);
                    }
                }
            }
            catch (const char* msg)
            {
                cout << msg;
            }
        }
        if (om == "utilizator")
        {
            try
            {
                //cat timp nu am iesit din program
                while (1 == 1)
                {
                    char optiune;
                    cout << "Alegeti optiunea.\n" << "1.Logare\n" << "2.Creare cont\n" << "0.Iesire\n";
                    cin >> optiune;
                    while (optiune != '1' && optiune != '2' && optiune != '0')
                    {
                        cout << "Optiune inexistenta.Alegeti una dintre optiunile existente.\n";
                        cin >> optiune;
                    }
                    if (optiune == '1')
                    {
                        cout << "ID:";
                        cin >> x;
                        cout << "Parola:";
                        cin >> y;
                        int a2;
                        int semafor = 0;
                        int k = 0;
                        while (semafor == 0)
                        {
                            try
                            {
                                a2 = u[k].logare(u, x, y, nru);
                                if (a2 == 1)
                                    semafor = 1;
                            }
                            catch (const char* msg)
                            {
                                cout << msg;
                                cout << "\nID:";
                                cin >> x;
                                cout << "Parola:";
                                cin >> y;
                            }
                        }
                        char opt;
                        cout << "\nAlegeti optiunea\n1.Cautare zbor\n" << "2.Rezervare zbor\n" << "0.Iesire\n";
                        cin >> opt;
                        while (opt != '1' && opt != '2' && opt != '0')
                        {
                            cout << "Optiune inexistenta.Alegeti una dintre optiunile existente.\n";
                            cin >> opt;
                        }
                        if (opt == '1')
                        {
                            //cautare zbor
                            string sirul1, sirul2, sirul3, sirul4;
                            cout << "Aeroportul de unde vreti sa plecati: ";
                            cin >> sirul1;
                            cout << "Orasul de unde vreti sa plecati: ";
                            cin >> sirul2;
                            cout << "Aeroportul unde vreti sa ajungeti: ";
                            cin >> sirul3;
                            cout << "Orasul unde vreti sa ajungeti: ";
                            cin >> sirul4;
                            int i = 0;
                            try
                            {
                                int w = v[i].cautare_zbor(v, sirul1, sirul2, sirul3, sirul4, nr_zb);
                                cout << endl;
                            }
                            catch (const char* msg)
                            {
                                cout << msg;
                            }
                        }
                        if (opt == '2')
                        {
                            for (i = 0; i < nr_zb; i++)
                            {
                                afisare_zbor(v[i]);
                                cout << "\n";
                            }
                            int t;
                            cout << "Nr zborului in care doriti sa va rezervati locuri: ";
                            cin >> t;
                            int rezervari;
                            cout << "Numarul locurilor pe care doriti sa le rezervati: ";
                            cin >> rezervari;
                            try
                            {
                                int q = v[i].rezervare_zbor(v, t - 1, nr_zb, rezervari);
                            }
                            catch (const char* msg)
                            {
                                cout << msg;
                            }
                            for (i = 0; i < nr_zb; i++)
                            {
                                afisare_zbor(v[i]);
                                cout << "\n";
                            }
                            cout << "\n";
                        }
                        if (opt == '0')
                        {
                            exit(1);
                        }
                    }
                    if (optiune == '2')
                    {
                        //creare cont
                        string nume;
                        cout << "ID: ";
                        cin >> nume;
                        string parola1;
                        cout << "Parola: ";
                        cin >> parola1;
                        string parola2;
                        cout << "Repetare parola: ";
                        cin >> parola2;
                        int h;
                        int semafor = 0;
                        while (semafor == 0)
                        {
                            try
                            {

                                h = creare_cont(nume, parola1, parola2);
                                if (h == 1)
                                {
                                    u[nru].id = nume;
                                    u[nru].parola = parola1;
                                    nru++;
                                    semafor = 1;
                                }
                            }
                            catch (const char* msg)
                            {
                                cout << msg;
                                cout << "ID: ";
                                cin >> nume;
                                cout << "Parola: ";
                                cin >> parola1;
                                cout << "Repetare parola: ";
                                cin >> parola2;
                            }
                        }
                    }
                    if (optiune == '0')
                    {
                        exit(1);
                    }
                }
            }
            catch (const char* msg)
            {
                cout << msg;
            }
        }
    }
}