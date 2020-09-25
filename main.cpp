#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstdio>


using namespace std;

struct Uzytkownik
{
    int id;
    string nazwa;
    string haslo;
};

int rejestracja (vector <Uzytkownik> &uzytkownicy, int liczba_uzytkownikow) {
    string nazwa, haslo;
    int id=0;
    cout<<"Podaj nazwe uzytkownika: ";
    cin>>nazwa;
    int i=0;
    while (i<liczba_uzytkownikow) {
        if (uzytkownicy[i].nazwa==nazwa) {
            cout<<"Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>nazwa;
            i=0;
        } else {
            i++;
        }
    }
    cout<<"Podaj haslo: ";
    cin>>haslo;
    id = liczba_uzytkownikow+1;
    uzytkownicy.push_back(Uzytkownik {id,nazwa,haslo});
    fstream plik1;
    plik1.open("uzytkownicy.txt", ios::out | ios::app);
    plik1<<uzytkownicy[liczba_uzytkownikow].id<<"|"<<uzytkownicy[liczba_uzytkownikow].nazwa<<"|"<<uzytkownicy[liczba_uzytkownikow].haslo<<endl;
    plik1.close();
    cout<<"Konto zalozone!";
    Sleep(1000);
    return liczba_uzytkownikow+1;
}

int logowanie (vector <Uzytkownik> &uzytkownicy, int liczba_uzytkownikow)
{
    string nazwa, haslo;
    cout<<"Podaj login: ";
    cin>>nazwa;
    int i=0;
    while(i<liczba_uzytkownikow)
    {
        if (uzytkownicy[i].nazwa==nazwa)
        {
            for (int j=0; j<3; j++)
            {
                cout<<"Podaj haslo. Pozostalo Ci "<<3-j<<"prob: ";
                cin>>haslo;
                if (uzytkownicy[i].haslo==haslo)
                {
                    cout<<"Zalogowales sie pomyslnie";
                    Sleep(2000);
                    return uzytkownicy[i].id;
                }
            }
            cout<<"Podales trzykrotnie niewlasciwe haslo. Odczekaj teraz 2s";
            Sleep(2000);
            return 0;
        }
        i++;
    }
    cout<<"Nie ma takiego uzytkownika";
    Sleep(2000);
    return 0;
}

void zmien_haslo(vector <Uzytkownik> &uzytkownicy, int id_zalogowanego_uzytkownika, int liczba_uzytkownikow) {
    string haslo;
    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    for (int i=0; i<liczba_uzytkownikow; i++) {
        if(uzytkownicy[i].id==id_zalogowanego_uzytkownika) {
            uzytkownicy[i].haslo=haslo;
            fstream plik1;
            plik1.open("uzytkownicy.txt", ios::out);
            for (int j=0; j<liczba_uzytkownikow; j++) {
                plik1<<uzytkownicy[j].id<<"|"<<uzytkownicy[j].nazwa<<"|"<<uzytkownicy[j].haslo<<endl;
            }
            plik1.close();
            cout<<"Haslo pomyslnie zmienione";
            Sleep(1500);
        }

    }

}

struct Przyjaciel {
    int id;
    int id_uzytkownika;
    string imie;
    string nazwisko;
    string nrTelefonu;
    string adres;
    string email;

};

int znajdzMaksymalneIdAdresata ()
{
            fstream plik;
            int licznik=0;
            int maxi_id_adresata=0;
            string linia="";
            string  identyfikator="";
            int id=0;
            plik.open("ksiazkaadresowa.txt", ios::in);
            if (plik.good()==true) {
                while (getline(plik, linia)) {
                    int dlugoscLini=linia.length();
                    for (int i=0; i<dlugoscLini; i++) {
                        if (linia[i]=='|') {
                            licznik++;
                            i++;
                        }
                        if (licznik==0) {
                            identyfikator=identyfikator+linia[i];
                        }
                    }
                    id= (atoi(identyfikator.c_str()));
                    if (maxi_id_adresata<id)
                    {
                        maxi_id_adresata=id;
                    }
                    licznik=0;
                    identyfikator="";
                    id=0;
                }
                return maxi_id_adresata;
            }
            else
            {
                return 0;
            }
            plik.close();
}
int zapisywanie(vector <Przyjaciel> &ksiazkaAdresowa, int liczbaOsob, int id_zalogowanego_uzytkownika) {
    int id_uzytkownika=id_zalogowanego_uzytkownika;
    string imie;
    string nazwisko;
    string nrTelefonu;
    string adres;
    string email;
    fstream plik;
    plik.open("ksiazkaadresowa.txt", ios::out | ios::app);
    cin. ignore();
    cout<<"Podaj imie przyjaciela: ";
    getline (cin, imie);
    cout<<"Podaj nazwisko przyjaciela: ";
    cin>>nazwisko;
    cin.ignore();
    cout<<"Podaj numer telefonu przyjaciela: ";
    getline (cin, nrTelefonu);

    cout<<"Podaj adres przyjaciela: ";
    getline (cin, adres);
    cout<<"Podaj email przyjaciela: ";
    cin>>email;

    int id=znajdzMaksymalneIdAdresata()+1;
    ksiazkaAdresowa.push_back(Przyjaciel {id, id_uzytkownika, imie,nazwisko,nrTelefonu,adres,email});
    plik<<ksiazkaAdresowa[liczbaOsob].id<<"|"<<ksiazkaAdresowa[liczbaOsob].id_uzytkownika<<"|"<<ksiazkaAdresowa[liczbaOsob].imie<<"|"<<ksiazkaAdresowa[liczbaOsob].nazwisko<<"|"<<ksiazkaAdresowa[liczbaOsob].nrTelefonu<<"|"<<ksiazkaAdresowa[liczbaOsob].adres<<"|"<<ksiazkaAdresowa[liczbaOsob].email<<"|"<<endl;
    cout<<endl<<"Przyjaciel zapisany pomyslnie";
    Sleep(2000);
    plik.close();
    return liczbaOsob+1;
}
void wyswietlWszystkichPrzyjaciol(vector <Przyjaciel> ksiazkaAdresowa, int liczbaOsob, int id_zalogowanego_uzytkownika) {
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika) {
            cout<<ksiazkaAdresowa[i].id<<" "<<ksiazkaAdresowa[i].imie<<" "<<ksiazkaAdresowa[i].nazwisko;
            cout<<endl;
        }
    }
    system("pause");
}
void wyswietlIdOrazImieiNazwiskoPrzyjacela (vector <Przyjaciel> ksiazkaAdresowa, int i) {
    cout<<"Id:"<<ksiazkaAdresowa[i].id<<"  "<<"Imie:"<<ksiazkaAdresowa[i].imie<<"  "<<"Nazwisko:"<<ksiazkaAdresowa[i].nazwisko;
    cout<<endl;
}
void wypiszWszystkieDane(vector <Przyjaciel> ksiazkaAdresowa, int i) {
    cout<<"Id:"<<ksiazkaAdresowa[i].id<<endl;
    cout<<"Imie:"<<ksiazkaAdresowa[i].imie<<endl;
    cout<<"Nazwisko:"<<ksiazkaAdresowa[i].nazwisko<<endl;
    cout<<"Nr Telefonu:"<<ksiazkaAdresowa[i].nrTelefonu<<endl;
    cout<<"Adres:"<<ksiazkaAdresowa[i].adres<<endl;
    cout<<"E-mail:"<<ksiazkaAdresowa[i].email<<endl;
    cout<<endl;
}

void wyszukajNaPodstawieImienia(vector <Przyjaciel> ksiazkaAdresowa,int liczbaOsob, int id_zalogowanego_uzytkownika) {
    string imie;
    int id;
    cout<<"Podaj imie: ";
    cin>>imie;
    int licznik=0;
    for (int i=0; i<liczbaOsob; i++) {
            if (ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika && ksiazkaAdresowa[i].imie==imie )
            {
                wyswietlIdOrazImieiNazwiskoPrzyjacela (ksiazkaAdresowa, i);
                licznik++;
            }

    }
    if (licznik==0) {
        cout<<"Nie masz przyjaciol o takim imieniu"<<endl;
        Sleep(2000);
    }
    if (licznik!=0) {
        cout<<"Podaj id osoby, ktorej dane chcesz uzyskac:";
        cin>>id;
        for (int i=0; i<liczbaOsob; i++) {
            if (ksiazkaAdresowa[i].id==id && ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika) {
                wypiszWszystkieDane(ksiazkaAdresowa, i);
                system("pause");
            }
        }
    }


}
void wyszukajNaPodstawieNazwiska(vector <Przyjaciel> ksiazkaAdresowa, int liczbaOsob, int id_zalogowanego_uzytkownika) {
    string nazwisko;
    int id;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    int licznik=0;
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika &&ksiazkaAdresowa[i].nazwisko==nazwisko) {
            wyswietlIdOrazImieiNazwiskoPrzyjacela (ksiazkaAdresowa, i);
            licznik++;
        }

    }
    if (licznik==0) {
        cout<<"Nie masz przyjaciol o takim nazwisku"<<endl;
        Sleep(2000);
    }
    if (licznik!=0) {
        cout<<"Podaj id osoby, ktorej dane chcesz uzyskac:";
        cin>>id;
        for (int i=0; i<liczbaOsob; i++) {
            if (ksiazkaAdresowa[i].id==id && ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika) {
                wypiszWszystkieDane(ksiazkaAdresowa, i);
                system("pause");
            }
        }
    }


}
void zapiszDoPlikuPoUsunieciu(int id)
{
    fstream plik;
    plik.open("ksiazkaadresowa.txt", ios::in);
    fstream plik_Nowy;
    plik_Nowy.open("pliknowy.txt", ios::out);

    string linia;
    string identyfikator, identyfikator_uzytkownika="";
    string imie="";
    string nazwisko="";
    string nrTelefonu="";
    string adres="";
    string email="";
    int dlugoscLini=0;
    int licznik=0;
    int id_uzytkownika=0;
    int idAdresata=0;

    if (plik.good()==true) {
        while (getline(plik, linia)) {
            int dlugoscLini=linia.length();
            for (int i=0; i<dlugoscLini; i++) {
                if (linia[i]=='|') {
                    licznik++;
                    i++;
                }
                if (licznik==0) {
                    identyfikator=identyfikator+linia[i];
                }

                if (licznik==1) {
                    identyfikator_uzytkownika=identyfikator_uzytkownika+linia[i];
                }

                if (licznik==2) {
                    imie=imie+linia[i];
                }
                if (licznik==3) {
                    nazwisko=nazwisko+linia[i];
                }
                if (licznik==4) {
                    nrTelefonu=nrTelefonu+linia[i];
                }
                if (licznik==5) {
                    adres=adres+linia[i];
                }
                if (licznik==6) {
                    email=email+linia[i];
                }
            }
            idAdresata= (atoi(identyfikator.c_str()));
            id_uzytkownika= (atoi(identyfikator_uzytkownika.c_str()));
            if (idAdresata!=id) {

                plik_Nowy<<idAdresata<<"|"<<id_uzytkownika<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<adres<<"|"<<email<<"|"<<endl;
            }
            licznik=0;
            identyfikator="";
            idAdresata=0;
            identyfikator_uzytkownika="";
            imie="";
            nazwisko="";
            nrTelefonu="";
            adres="";
            email="";
        }
    }
    plik.close();
    plik_Nowy.close();
    remove ("ksiazkaadresowa.txt");
    rename("pliknowy.txt", "ksiazkaadresowa.txt");
}
int usunAdresata(vector <Przyjaciel> &ksiazkaAdresowa, int liczbaOsob, int  id_zalogowanego_uzytkownika) {
    for (int i=0; i<liczbaOsob; i++) {
            if (ksiazkaAdresowa[i].id_uzytkownika == id_zalogowanego_uzytkownika)
            {
                cout<<ksiazkaAdresowa[i].id<<" "<<ksiazkaAdresowa[i].imie<<" "<<ksiazkaAdresowa[i].nazwisko;
                cout<<endl;
            }
    }
    cout<<"Podaj id osoby, ktorej dane chcesz usunac:";
    int id, licznik=0;
    char potwierdzenie;
    cin>>id;
    for (vector<Przyjaciel>::iterator itr = ksiazkaAdresowa.begin(), koniec=ksiazkaAdresowa.end(); itr != koniec; ++itr) {
        if (itr->id==id && itr->id_uzytkownika==id_zalogowanego_uzytkownika) {
            licznik++;
            cout<<"Czy na pewno mam usunac tego uzytkownika <t/n>: ";
            cin>>potwierdzenie;
            if (potwierdzenie=='t') {
                ksiazkaAdresowa.erase(itr);
                zapiszDoPlikuPoUsunieciu(id);
                cout<<endl<<"Przyjaciel usuniety pomyslnie";
                Sleep(1000);
                return liczbaOsob-1;
            } else {
                cout<<"Powrot do menu glownego"<<endl;
                Sleep (1000);
                return liczbaOsob;
            }
        }
    }
    if (licznik==0) {
        cout<<"Podales niepoprawne id. Wracam do menu glownego"<<endl;
        Sleep(1000);
        return liczbaOsob;
    }
}


void wyswietlPodemenuEdycyjne ();

void  zapiszDoPlikuPoEdycji(vector <Przyjaciel> ksiazkaAdresowa, int id) {
    fstream plik;
    plik.open("ksiazkaadresowa.txt", ios::in);
    fstream plik_Nowy;
    plik_Nowy.open("pliknowy.txt", ios::out);

    string linia;
    string identyfikator, identyfikator_uzytkownika="";
    string imie="";
    string nazwisko="";
    string nrTelefonu="";
    string adres="";
    string email="";
    int dlugoscLini=0;
    int licznik=0;
    int id_uzytkownika=0;
    int idAdresata=0;

    if (plik.good()==true) {
        while (getline(plik, linia)) {
            int dlugoscLini=linia.length();
            for (int i=0; i<dlugoscLini; i++) {
                if (linia[i]=='|') {
                    licznik++;
                    i++;
                }
                if (licznik==0) {
                    identyfikator=identyfikator+linia[i];
                }
                if (licznik==1) {
                    identyfikator_uzytkownika=identyfikator_uzytkownika+linia[i];
                }
                if (licznik==2) {
                    imie=imie+linia[i];
                }
                if (licznik==3) {
                    nazwisko=nazwisko+linia[i];
                }
                if (licznik==4) {
                    nrTelefonu=nrTelefonu+linia[i];
                }
                if (licznik==5) {
                    adres=adres+linia[i];
                }
                if (licznik==6) {
                    email=email+linia[i];
                }
            }
            idAdresata= (atoi(identyfikator.c_str()));
            id_uzytkownika= (atoi(identyfikator_uzytkownika.c_str()));
            if (idAdresata!=id) {

                plik_Nowy<<idAdresata<<"|"<<id_uzytkownika<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<adres<<"|"<<email<<"|"<<endl;
            } else {
                for (int i=0; i<ksiazkaAdresowa.size(); i++) {
                    if (ksiazkaAdresowa[i].id==id) {
                        idAdresata=ksiazkaAdresowa[i].id;
                        id_uzytkownika=ksiazkaAdresowa[i].id_uzytkownika;
                        imie=ksiazkaAdresowa[i].imie;
                        nazwisko=ksiazkaAdresowa[i].nazwisko;
                        nrTelefonu=ksiazkaAdresowa[i].nrTelefonu;
                        adres=ksiazkaAdresowa[i].adres;
                        email= ksiazkaAdresowa[i].email;
                    }
                }
                plik_Nowy<<idAdresata<<"|"<<id_uzytkownika<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<adres<<"|"<<email<<"|"<<endl;
            }
            licznik=0;
            identyfikator="";
            idAdresata=0;
            identyfikator_uzytkownika="";
            imie="";
            nazwisko="";
            nrTelefonu="";
            adres="";
            email="";
        }
    }
    plik.close();
    plik_Nowy.close();
    remove ("ksiazkaadresowa.txt");
    rename("pliknowy.txt", "ksiazkaadresowa.txt");
}
void edytujAdresata(vector <Przyjaciel> &ksiazkaAdresowa, int liczbaOsob, int id_zalogowanego_uzytkownika) {
    int id;
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika) {
            cout<<ksiazkaAdresowa[i].id<<" "<<ksiazkaAdresowa[i].imie<<" "<<ksiazkaAdresowa[i].nazwisko;
            cout<<endl;
        }
    }
    cout<<"Podaj id adresata, ktorego dane chcesz edytowac: ";
    cin>>id;
    char numerDanej=0;
    string imie, nazwisko, numerTelefonu, adres, email;
    int licznik=0;
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].id==id && ksiazkaAdresowa[i].id_uzytkownika==id_zalogowanego_uzytkownika ) {
            wyswietlPodemenuEdycyjne();
            licznik++;
            cout<<"Podaj, ktora dana chcesz edytowac: ";
            cin>>numerDanej;
            switch (numerDanej) {
            case '1': {
                cin. ignore();
                cout<<"Podaj nowe imie: ";
                getline (cin, imie);
                ksiazkaAdresowa[i]. imie = imie;
                cout<<endl<<"Imie zmienione pomyslnie";
            }
            break;
            case '2': {
                cin. ignore();
                cout<<"Podaj nowe nazwisko: ";
                cin>>nazwisko;
                ksiazkaAdresowa[i]. nazwisko = nazwisko;
                cout<<endl<<"Dana zmieniona pomyslnie";
            }
            break;
            case '3': {
                cin. ignore();
                cout<<"Podaj nowy numer telefonu: ";
                getline (cin, numerTelefonu);
                ksiazkaAdresowa[i]. nrTelefonu= numerTelefonu;
                cout<<endl<<"Dana zmieniona pomyslnie";
            }
            break;
            case '4': {
                cout<<"Podaj nowy adres: ";
                cin. ignore();
                getline (cin, adres);
                ksiazkaAdresowa[i]. adres= adres;
                cout<<endl<<"Dana zmieniona pomyslnie";
            }
            break;
            case '5': {
                cout<<"Podaj nowy email: ";
                cin>>email;
                ksiazkaAdresowa[i]. email= email;
                cout<<endl<<"Dana zmieniona pomyslnie";

            }
            break;
            case '6': {
                cout<<"Powrot do menu za 1 sekunde ";
                Sleep(1000);
            }
            break;

            }
            zapiszDoPlikuPoEdycji(ksiazkaAdresowa, id);
            Sleep(1000);

        }

    }
    if (licznik==0) {
        cout<<"Uzytkownik o takim id nie istnieje";
        Sleep(1000);
    }
}
void wyswietlPodemenuEdycyjne () {
    cout<<endl;
    cout<<"1 - imie"<<endl;
    cout<<"2 - nazwisko"<<endl;
    cout<<"3 - numer telefonu"<<endl;
    cout<<"4 - adres"<<endl;
    cout<<"5 - email"<<endl;
    cout<<"6 - powrot do menu"<<endl;
}


int main() {
    int liczba_uzytkownikow=0;
    int id_zalogowanego_uzytkownika=0;
    char wybor;
    vector <Uzytkownik> uzytkownicy;

    fstream plik1;
    plik1.open("uzytkownicy.txt", ios::in);
    int id=0;
    string nazwa="", haslo="";
    string linia1;
    int licznik1=0;
    string identyfikator1="";

    if (plik1.good()==true) {
        while (getline(plik1, linia1)) {
            int dlLini=linia1.length();
            for (int i=0; i<dlLini; i++) {
                if (linia1[i]=='|') {
                    licznik1++;
                    i++;
                }
                if (licznik1==0) {
                    identyfikator1=identyfikator1+linia1[i];
                }

                if (licznik1==1) {
                    nazwa=nazwa+linia1[i];
                }
                if (licznik1==2) {
                    haslo=haslo+linia1[i];
                }
            }
            id= (atoi(identyfikator1.c_str()));
            uzytkownicy.push_back(Uzytkownik{id, nazwa, haslo});
            licznik1=0;
            identyfikator1="";
            nazwa="";
            haslo="";
            liczba_uzytkownikow++;
        }
    }


    int liczbaOsob=0;
    vector <Przyjaciel> ksiazkaAdresowa;
    string linia;
    string identyfikator, identyfikator_uzytkownika="";
    string imie="";
    string nazwisko="";
    string nrTelefonu="";
    string adres="";
    string email="";
    int dlugoscLini=0;
    int licznik=0;
    int id_uzytkownika=0;



    while (1) {
        if (id_zalogowanego_uzytkownika==0) {
            system ("cls");
            cout<<"1. Rejestracja"<<endl;
            cout<<"2. Logowanie"<<endl;
            cout<<"9. Koniec pracy"<<endl;
            cin>>wybor;
            switch (wybor) {
            case '1': {
                liczba_uzytkownikow=rejestracja (uzytkownicy, liczba_uzytkownikow);
            }
            break;
            case '2': {
                id_zalogowanego_uzytkownika= logowanie(uzytkownicy, liczba_uzytkownikow);
            }
            break;
            case '9': {
                exit(0);
            }
            break;
            }
        } else {

            fstream plik;
            ksiazkaAdresowa.clear();
            liczbaOsob=0;
            licznik=0;
            plik.open("ksiazkaadresowa.txt", ios::in);
            if (plik.good()==true) {
                while (getline(plik, linia)) {
                    int dlugoscLini=linia.length();
                    for (int i=0; i<dlugoscLini; i++) {
                        if (linia[i]=='|') {
                            licznik++;
                            i++;
                        }
                        if (licznik==0) {
                            identyfikator=identyfikator+linia[i];
                        }
                        if (licznik==1) {
                            identyfikator_uzytkownika=identyfikator_uzytkownika+linia[i];
                        }
                        if (licznik==2) {
                            imie=imie+linia[i];
                        }
                        if (licznik==3) {
                            nazwisko=nazwisko+linia[i];
                        }
                        if (licznik==4) {
                            nrTelefonu=nrTelefonu+linia[i];
                        }
                        if (licznik==5) {
                            adres=adres+linia[i];
                        }
                        if (licznik==6) {
                            email=email+linia[i];
                        }
                    }
                    id= (atoi(identyfikator.c_str()));
                    id_uzytkownika= (atoi(identyfikator_uzytkownika.c_str()));
                    if (id_uzytkownika==id_zalogowanego_uzytkownika) {

                        ksiazkaAdresowa.push_back(Przyjaciel{id, id_uzytkownika, imie, nazwisko, nrTelefonu, adres, email});
                        liczbaOsob++;
                    }
                    licznik=0;
                    identyfikator="";
                    id=0;
                    identyfikator_uzytkownika="";
                    imie="";
                    nazwisko="";
                    nrTelefonu="";
                    adres="";
                    email="";
                }
            }
            plik.close();

            system ("cls");
            cout<<"MENU programu"<<endl;
            cout<<"1. Zapisywanie"<<endl;
            cout<<"2. Wyszukaj przyjaciol na podstawie imienia"<<endl;
            cout<<"3. Wyszukaj przyjaciol na podstawie nazwiska"<<endl;
            cout<<"4. Wyswietl wszystkich moich przyjaciol"<<endl;
            cout<<"5. Usun adresata"<<endl;
            cout<<"6. Edytuj adresata"<<endl;
            cout<<"7. Zmiana hasla"<<endl;
            cout<<"8. Wylogowanie"<<endl;

            cout<<"Wybierz odpowiednia cyfre aby wskazac co mam zrobic: ";
            cin>>wybor;

            switch (wybor) {
            case '1': {
                liczbaOsob=zapisywanie(ksiazkaAdresowa, liczbaOsob, id_zalogowanego_uzytkownika);
            }
            break;
            case '2': {
                wyszukajNaPodstawieImienia(ksiazkaAdresowa, liczbaOsob, id_zalogowanego_uzytkownika );
            }
            break;
            case '3': {
                wyszukajNaPodstawieNazwiska(ksiazkaAdresowa, liczbaOsob, id_zalogowanego_uzytkownika );
            }
            break;
            case '4': {
                wyswietlWszystkichPrzyjaciol(ksiazkaAdresowa, liczbaOsob, id_zalogowanego_uzytkownika);
            }
            break;
            case '5': {
                liczbaOsob=usunAdresata(ksiazkaAdresowa, liczbaOsob, id_zalogowanego_uzytkownika);
            }
            break;
            case '6': {
                edytujAdresata(ksiazkaAdresowa, liczbaOsob, id_zalogowanego_uzytkownika );
            }
            break;
            case '7': {
                zmien_haslo(uzytkownicy, id_zalogowanego_uzytkownika, liczba_uzytkownikow);
            }
            break;
            case '8': {
                id_zalogowanego_uzytkownika=0;
            }
            break;

            }


        }
    }

    plik1.close();
    return 0;
}
