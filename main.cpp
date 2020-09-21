#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
//

using namespace std;

struct Przyjaciel {
    int id;
    string imie;
    string nazwisko;
    string nrTelefonu;
    string adres;
    string email;

};
int zapisywanie(vector <Przyjaciel> &ksiazkaAdresowa, int liczbaOsob) {
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
    int maksymalne_id=0;
    for (int i=0; i<liczbaOsob; i++) {
        maksymalne_id=ksiazkaAdresowa[0]. id;
        if (ksiazkaAdresowa[i].id>maksymalne_id) {
            maksymalne_id= ksiazkaAdresowa[i].id;
        }
    }
    int id=maksymalne_id+1;
    ksiazkaAdresowa.push_back(Przyjaciel {id,imie,nazwisko,nrTelefonu,adres,email});
    plik<<ksiazkaAdresowa[liczbaOsob].id<<"|"<<ksiazkaAdresowa[liczbaOsob].imie<<"|"<<ksiazkaAdresowa[liczbaOsob].nazwisko<<"|"<<ksiazkaAdresowa[liczbaOsob].nrTelefonu<<"|"<<ksiazkaAdresowa[liczbaOsob].adres<<"|"<<ksiazkaAdresowa[liczbaOsob].email<<"|"<<endl;
    cout<<endl<<"Przyjaciel zapisany pomyslnie";
    Sleep(2000);
    plik.close();
    return liczbaOsob+1;
}
void wyswietlWszystkichPrzyjaciol(vector <Przyjaciel> ksiazkaAdresowa, int liczbaOsob) {
    for (int i=0; i<liczbaOsob; i++) {
        cout<<ksiazkaAdresowa[i].id<<" "<<ksiazkaAdresowa[i].imie<<" "<<ksiazkaAdresowa[i].nazwisko;
        cout<<endl;
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

void wyszukajNaPodstawieImienia(vector <Przyjaciel> ksiazkaAdresowa,int liczbaOsob) {
    string imie;
    int id;
    cout<<"Podaj imie: ";
    cin>>imie;
    int licznik=0;
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].imie==imie) {
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
            if (ksiazkaAdresowa[i].id==id) {
                wypiszWszystkieDane(ksiazkaAdresowa, i);
                system("pause");
            }
        }
    }


}
void wyszukajNaPodstawieNazwiska(vector <Przyjaciel> ksiazkaAdresowa, int liczbaOsob) {
    string nazwisko;
    int id;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    int licznik=0;
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].nazwisko==nazwisko) {
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
            if (ksiazkaAdresowa[i].id==id) {
                wypiszWszystkieDane(ksiazkaAdresowa, i);
                system("pause");
            }
        }
    }


}
int usunAdresata(vector <Przyjaciel> &ksiazkaAdresowa, int liczbaOsob) {
    for (int i=0; i<liczbaOsob; i++) {
        cout<<ksiazkaAdresowa[i].id<<" "<<ksiazkaAdresowa[i].imie<<" "<<ksiazkaAdresowa[i].nazwisko;
        cout<<endl;
    }
    cout<<"Podaj id osoby, ktorej dane chcesz usunac:";
    int id, licznik=0;
    char potwierdzenie;
    cin>>id;
    for (vector<Przyjaciel>::iterator itr = ksiazkaAdresowa.begin(), koniec=ksiazkaAdresowa.end(); itr != koniec; ++itr) {
        if (itr->id==id) {
            licznik++;
            cout<<"Czy na pewno mam usunac tego uzytkownika <t/n>: ";
            cin>>potwierdzenie;
            if (potwierdzenie=='t') {
                ksiazkaAdresowa.erase(itr);
                fstream plik;
                plik.open("ksiazkaadresowa.txt", ios::out);

                for (int i=0; i<liczbaOsob-1; i++) {
                    plik<<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].nrTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<ksiazkaAdresowa[i].email<<"|"<<endl;

                }
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
void edytujAdresata(vector <Przyjaciel> &ksiazkaAdresowa, int liczbaOsob) {
    int id;
    for (int i=0; i<liczbaOsob; i++) {
        cout<<ksiazkaAdresowa[i].id<<" "<<ksiazkaAdresowa[i].imie<<" "<<ksiazkaAdresowa[i].nazwisko;
        cout<<endl;
    }
    cout<<"Podaj id adresata, ktorego dane chcesz edytowac: ";
    cin>>id;
    char numerDanej=0;
    string imie, nazwisko, numerTelefonu, adres, email;
    int licznik=0;
    for (int i=0; i<liczbaOsob; i++) {
        if (ksiazkaAdresowa[i].id==id) {
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
                cout<<endl<<"Dana zmieniona pomyslnie";
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
            fstream plik;
            plik.open("ksiazkaadresowa.txt", ios::out);
            for (int i=0; i<liczbaOsob; i++) {
                plik<<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].nrTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<ksiazkaAdresowa[i].email<<"|"<<endl;

            }
            plik.close();

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
    int liczbaOsob=0;
    char wybor;
    vector <Przyjaciel> ksiazkaAdresowa;
    fstream plik;
    plik.open("ksiazkaadresowa.txt", ios::in);
    string linia;
    int id;
    string identyfikator="";
    string imie="";
    string nazwisko="";
    string nrTelefonu="";
    string adres="";
    string email="";
    int dlugoscLini=0;
    int licznik=0;

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
                id= (atoi(identyfikator.c_str()));
                if (licznik==1) {
                    imie=imie+linia[i];
                }
                if (licznik==2) {
                    nazwisko=nazwisko+linia[i];
                }
                if (licznik==3) {
                    nrTelefonu=nrTelefonu+linia[i];
                }
                if (licznik==4) {
                    adres=adres+linia[i];
                }
                if (licznik==5) {
                    email=email+linia[i];
                }
            }
            ksiazkaAdresowa.push_back(Przyjaciel{id, imie, nazwisko, nrTelefonu, adres, email});
            liczbaOsob++;
            licznik=0;
            identyfikator="";
            id=0;
            imie="";
            nazwisko="";
            nrTelefonu="";
            adres="";
            email="";
        }
    }


    while (1) {
        system ("cls");
        cout<<"MENU programu"<<endl;
        cout<<"1. Zapisywanie"<<endl;
        cout<<"2. Wyszukaj przyjaciol na podstawie imienia"<<endl;
        cout<<"3. Wyszukaj przyjaciol na podstawie nazwiska"<<endl;
        cout<<"4. Wyswietl wszystkich moich przyjaciol"<<endl;
        cout<<"5. Usun adresata"<<endl;
        cout<<"6. Edytuj adresata"<<endl;
        cout<<"9. Koniec programu"<<endl;
        cout<<"Wybierz odpowiednia cyfre aby wskazac co mam zrobic: ";
        cin>>wybor;

        switch (wybor) {
        case '1': {
            liczbaOsob=zapisywanie(ksiazkaAdresowa, liczbaOsob);
        }
        break;
        case '2': {
            wyszukajNaPodstawieImienia(ksiazkaAdresowa, liczbaOsob);
        }
        break;
        case '3': {
            wyszukajNaPodstawieNazwiska(ksiazkaAdresowa, liczbaOsob);
        }
        break;
        case '4': {
            wyswietlWszystkichPrzyjaciol(ksiazkaAdresowa, liczbaOsob);
        }
        break;
        case '5': {
            liczbaOsob=usunAdresata(ksiazkaAdresowa, liczbaOsob);
        }
        break;
        case '6': {
            edytujAdresata(ksiazkaAdresowa, liczbaOsob);
        }
        break;
        case '9': {
            exit(0);
        }
        break;
        }
    }
    plik.close();
    return 0;
}
