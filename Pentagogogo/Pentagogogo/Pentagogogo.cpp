#include <iostream>

#include <string>

#define dlugosc_planszy 6
#define wysokosc_planszy 6
using namespace std;

struct gracz //deklaracja struktury
{
    string nazwa_gracza;
    char zeton = ' ';

};
void wczytaj_imiona(string* imie1, string* imie2) { // wczytanie imion graczy, zastapienie domyslnych wartosci
    cout << "Podaj imie gracza 1: ";
    cin >> *imie1;
    cout << endl;
    cout << "Podaj imie gracza 2: ";
    cin >> *imie2;
    cout << endl;

}

void PredefiniownaPlansza(char p[4][9], gracz gracz_przy_ruchu, gracz drugi_gracz) {

    system("cls"); // ustawienie predefiniowanej planszy metodą "na siłe" 
    p[0][1] = gracz_przy_ruchu.zeton;
    p[0][5] = gracz_przy_ruchu.zeton;
    p[1][4] = gracz_przy_ruchu.zeton;
    p[2][3] = gracz_przy_ruchu.zeton;
    p[2][7] = gracz_przy_ruchu.zeton;
    p[3][4] = gracz_przy_ruchu.zeton;
    p[3][7] = gracz_przy_ruchu.zeton;
    p[3][8] = gracz_przy_ruchu.zeton;

    p[0][3] = drugi_gracz.zeton;
    p[0][4] = drugi_gracz.zeton;
    p[0][7] = drugi_gracz.zeton;
    p[1][1] = drugi_gracz.zeton;
    p[1][3] = drugi_gracz.zeton;
    p[2][0] = drugi_gracz.zeton;
    p[2][1] = drugi_gracz.zeton;
    p[2][5] = drugi_gracz.zeton;

}

void ustaw_zeton(char* zeton, char znak) {
    *zeton = znak;
    cout << "ustawiono zeton :)) " << endl;
}
void zmien_zeton(gracz& g1, gracz& g2) {
    cout << "w funkcji zmien znak: " << endl;
    cout << "Wprowadz swoj nowy znak (char)" << endl;
    char nowy_znak;
    while (true) {
        cin >> nowy_znak;
        if ((nowy_znak == g2.zeton) || (nowy_znak == g1.zeton)) { //zeby znaki sie nie powtarzaly...
            cout << "znak zajety przez gracza wybierz nowy znak: ";

        }
        else {
            break;
        }
    }
    ustaw_zeton(&g1.zeton, nowy_znak);

}
void uzupelnij_plansze(char p[4][9], char znak) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            p[i][j] = znak; 
        }
        //uzupelniamy dowolnymi znakami :)
    }

}
void GoraPlanszy() {

    cout << "ÉÍÍÍËÍÍÍËÍÍÍ» ÉÍÍÍËÍÍÍËÍÍÍ»"; // gora planszy
    cout << endl;

}
void SrodekPlanszy() {
    cout << "ĚÍÍÍÎÍÍÍÎÍÍÍą ĚÍÍÍÎÍÍÍÎÍÍÍą";
    cout << endl;
}
void DolPlanszy() {

    cout << "ČÍÍÍĘÍÍÍĘÍÍÍĽ ČÍÍÍĘÍÍÍĘÍÍÍĽ";
    cout << endl;
}

void wypisz_graczy(gracz g1, gracz g2) {

    //wypisywanie graczy ze struktury
    cout << " Nazwa Gracza nr 1 : " << g1.nazwa_gracza;
    cout << " Zeton Gracza: " << g1.zeton;
    cout << "\n Nazwa Gracza nr 2 : " << g2.nazwa_gracza;
    cout << " Zeton Gracza: " << g2.zeton << endl;

}
void wypisz_plansze(char p[4][9], gracz g1, gracz g2) {
    system("cls");
    wypisz_graczy(g1, g2);
    for (int i = 0; i <= 2; i += 2) {   //wypisanie jednego pietra [Q i W]
        GoraPlanszy();  
        for (int z = 0; z < 3; z++) {   //wypisanie pierwszego rzedu pietra
            for (int j = z * 3; j < z * 3 + 3; j++) {   //wypisywanie komórek
                cout << "ş " << p[i][j] << " ";
            }
            cout << "ş ";
            for (int j = z * 3; j < z * 3 + 3; j++) {//wypisywanie komórek
                cout << "ş " << p[i + 1][j] << " ";
            }
            cout << "ş";
            cout << endl;

            if (z != 2) {
                SrodekPlanszy(); //wyswietlenie srodka planszy pomiedzy rzedami 0 i 1 oraz 1 i 2

            }
            else {
                DolPlanszy(); // dla z=2 koniec planszy 
            }

        }

    }

}

void wypisz_pomoc() {
    cout << "q,w,a,s = wybor czesci planszy odpowiednio: lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
    cout << "1..9 = wybor pola na czesci planszy jak na klawiaturze numerycznej tj. 1 to dolne lewe pole" << endl;
    cout << "x, z = obrot odpowiednio : zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek" << endl;
    cout << "p = pauza" << endl;
    cout << "u = undo" << endl;
    cout << "o = wczytanie predefiniowanej planszy" << endl;
    cout << "m = wejscie do opcji" << endl;
    cout << "h = wejscie do opisu programu" << endl;

}
void wykonaj_ruch(gracz& gracz_przy_ruchu, char p[4][9], gracz& drugi_gracz) {
    char wybrany_znak;
    int wybrany_numer;
    cout << "Ruch gracza: " << gracz_przy_ruchu.nazwa_gracza << endl;

    while (true) { //zabezpieczenie przed wybraniem blednego ruchu

        cout << "wybierz cwiartke planszy : (q, w, a, s) h == pomoc c == zmien zeton  o == predefiniowana plansza  p== pauza   :";
        cin >> wybrany_znak;
        if (wybrany_znak == 'h') {
            wypisz_pomoc();
        }
        while (wybrany_znak == 'h') {
            cin >> wybrany_znak;
        }
        if (wybrany_znak == 'c') {
            zmien_zeton(gracz_przy_ruchu, drugi_gracz);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 9; j++) {
                    if ((p[i][j] != gracz_przy_ruchu.zeton) && (p[i][j] != drugi_gracz.zeton) && (p[i][j] != ' ')) {
                        p[i][j] = gracz_przy_ruchu.zeton;

                    }

                }

            }
        }
        while ((wybrany_znak == 'c') || (wybrany_znak == 'h')) {
            cin >> wybrany_znak;
        }
        if (wybrany_znak == 'o')
        {
            char znaczek = ' ';
            uzupelnij_plansze(p, znaczek);
            PredefiniownaPlansza(p, gracz_przy_ruchu, drugi_gracz);
            wypisz_plansze(p, gracz_przy_ruchu, drugi_gracz);
            cout << "ruch gracza: " << gracz_przy_ruchu.nazwa_gracza << "\t";
        }
        while ((wybrany_znak == 'c') || (wybrany_znak == 'h') || (wybrany_znak == 'o'))
        {
            cin >> wybrany_znak;
        }
        if (wybrany_znak == 'p')
        {
            system("cls");
            system("pause");
            wypisz_plansze(p, gracz_przy_ruchu, drugi_gracz);
            wykonaj_ruch(gracz_przy_ruchu, p, drugi_gracz);

        }
        while ((wybrany_znak == 'c') || (wybrany_znak == 'h') || (wybrany_znak == 'o') || (wybrany_znak == 'p'))
        {
            cin >> wybrany_znak;
        }
        if (wybrany_znak == 'q' || wybrany_znak == 'w' || wybrany_znak == 'a' || wybrany_znak == 's') {
            break;
        }
        cout << "\nnieprawidlowa cwiartka! wpisz jeszcze raz..." << endl;
    }
    cout << "wybrana cwiartka " << wybrany_znak << endl;
    while (true) {
        cout << "wybierz numer pola : 1-9 ";//wybor pola na wybranej cwiartce
        cin >> wybrany_numer;
        if (wybrany_numer >= 1 && wybrany_numer <= 9) {
            break;
        }
        cout << "\nnieprawidlowy numer pola! wpisz jeszcze raz..." << endl;
    }
    cout << "wybrana numer " << wybrany_numer << endl; 
    switch (wybrany_znak) { //wybrany znak-1 -> by trafic do odpowiedniej komórki
    case 'q': {
        if (p[0][wybrany_numer - 1] == ' ') {
            p[0][wybrany_numer - 1] = gracz_przy_ruchu.zeton;
            break;
        }
        else {
            cout << "POLE ZAJETE, WYBIERZ INNE DRANIU!" << endl;
            wykonaj_ruch(gracz_przy_ruchu, p, drugi_gracz);
            break;
        }
    }

    case 'w': {
        if (p[1][wybrany_numer - 1] == ' ') {
            p[1][wybrany_numer - 1] = gracz_przy_ruchu.zeton;
            break;
        }
        else {
            cout << "POLE ZAJETE, WYBIERZ INNE DRANIU!" << endl;
            wykonaj_ruch(gracz_przy_ruchu, p, drugi_gracz);
            break;
        }
    }

    case 'a': {
        if (p[2][wybrany_numer - 1] == ' ') {
            p[2][wybrany_numer - 1] = gracz_przy_ruchu.zeton;
            break;
        }
        else {
            cout << "POLE ZAJETE, WYBIERZ INNE DRANIU!" << endl;
            wykonaj_ruch(gracz_przy_ruchu, p, drugi_gracz);
            break;
        }
    }

    case 's': {
        if (p[3][wybrany_numer - 1] == ' ') {
            p[3][wybrany_numer - 1] = gracz_przy_ruchu.zeton;
            break;
        }
        else {
            cout << "POLE ZAJETE, WYBIERZ INNE DRANIU!" << endl;
            wykonaj_ruch(gracz_przy_ruchu, p, drugi_gracz);
            break;
        }
    }

    }

}
void obroc_cwiartke(char c, char k, char p[4][9]) {
    char pomocnicza[9];
    int i; //cwiartka 0,1,2,3
    if (c == 'q') {
        i = 0;
    }
    else if (c == 'w') {
        i = 1;
    }
    else if (c == 'a') {
        i = 2;
    }
    else {
        i = 3;
    }

    for (int o = 0; o < 9; o++) {

        pomocnicza[o] = p[i][o];

    }

    if (k == 'z') { //bardzo skomplikowany algorytm rozpisany na kartce papieru
        p[i][0] = pomocnicza[6];
        p[i][1] = pomocnicza[3];
        p[i][2] = pomocnicza[0];
        p[i][3] = pomocnicza[7];
        p[i][4] = pomocnicza[4];
        p[i][5] = pomocnicza[1];
        p[i][6] = pomocnicza[8];
        p[i][7] = pomocnicza[5];
        p[i][8] = pomocnicza[2];
    }
    else {
        p[i][0] = pomocnicza[2]; //bardzo skomplikowany algorytm rozpisany na kartce papieru
        p[i][1] = pomocnicza[5];
        p[i][2] = pomocnicza[8];
        p[i][3] = pomocnicza[1];
        p[i][4] = pomocnicza[4];
        p[i][5] = pomocnicza[7];
        p[i][6] = pomocnicza[0];
        p[i][7] = pomocnicza[3];
        p[i][8] = pomocnicza[6];

    }

}
void wybierz_cwiartke_doobrotu(char p[4][9]) {
    char wybrana_cwiartka;
    char wybrany_kierunek;
    while (true) {
        cout << "wybierz cwiartke planszy do obrotu : (q, w, a, s) :";
        cin >> wybrana_cwiartka;
        if (wybrana_cwiartka == 'q' || wybrana_cwiartka == 'w' || wybrana_cwiartka == 'a' || wybrana_cwiartka == 's') {
            break;
        }
        cout << "\nnieprawidlowa cwiartka! wpisz jeszcze raz..." << endl;
    }
    while (true) {
        cout << "wybierz kierunek obrotu : z - zgodnie z ruchem wskazowek zegara, x - odwrotnie :";
        cin >> wybrany_kierunek;
        if (wybrany_kierunek == 'z' || wybrany_kierunek == 'x') {
            break;
        }
        cout << "\nnieprawidlowy kierunek! wpisz jeszcze raz..." << endl;
    }
    obroc_cwiartke(wybrana_cwiartka, wybrany_kierunek, p);

}

void sprawdz_remis(char p[4][9], bool* koniec_gry) {
    bool remis = true; //warunek remisu - zajete wszystkie pola
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            if (p[i][j] == ' ') {
                remis = false;
                break;
            }

        }
        if (!remis) {
            break;
        }
    }
    if (remis) {
        cout << "Kto gra na remis... tego nikt nie lubi..." << endl; *koniec_gry = true;
    }

}
void sprawdz_wygrana(char p[4][9], gracz g1, gracz g2, bool* koniec_gry) {
    //sprawdzanie w pionie
    // i to ilosc cwiartek
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if ((p[i][j] == p[i][j + 3]) && (p[i][j] != ' ')) { // warunek wygranej -> nie moze wygrywac spacja 
                if (p[i][j + 3] == p[i][j + 6]) {
                    if (p[i][j + 6] == p[i + 2][j]) {
                        if (p[i][j + 6] == p[i + 2][j]) {
                            if (p[i + 2][j] == p[i + 2][j + 3]) {
                                cout << "wygral gracz " << p[i + 2][j + 3] << endl;
                                *koniec_gry = true;
                                break;
                            }

                        }

                    }

                }

            }
            else if ((p[i + 2][j + 6] == p[i + 2][j + 3]) && (p[i + 2][j + 6] != ' ')) {
                if (p[i][j + 3] == p[i][j + 6]) {
                    if (p[i][j + 6] == p[i + 2][j]) {
                        if (p[i][j + 6] == p[i + 2][j]) {
                            if (p[i + 2][j] == p[i + 2][j + 3]) {
                                cout << "wygral gracz " << p[i + 2][j + 3] << endl;
                                *koniec_gry = true;
                                break;
                            }

                        }

                    }

                }

            }

        }

    }
    //sprawdzanie w poziomie
    // i to ilosc cwiartek

    for (int i = 0; i < 3; i += 2) {
        // 0 i 2
        for (int j = 0; j < 3; j++) {
            if ((p[i][j * 3] == p[i][j * 3 + 1]) && (p[i][j * 3] != ' ')) {
                if (p[i][j * 3 + 1] == p[i][j * 3 + 2]) {
                    if (p[i][j * 3 + 2] == p[i + 1][j * 3]) {
                        if (p[i + 1][j * 3] == p[i + 1][j * 3 + 1]) {
                            cout << "wygral gracz " << p[i + 1][j * 3 + 1] << endl;
                            *koniec_gry = true;
                            break;

                        }

                    }

                }

            }
            else if ((p[i + 1][j * 3 + 2] == p[i + 1][j * 3 + 1]) && (p[i + 1][j * 3 + 2] != ' ')) {
                if (p[i][j * 3 + 1] == p[i][j * 3 + 2]) {
                    if (p[i][j * 3 + 2] == p[i + 1][j * 3]) {
                        if (p[i + 1][j * 3] == p[i + 1][j * 3 + 1]) {
                            cout << "wygral gracz " << p[i + 1][j * 3 + 1] << endl;
                            *koniec_gry = true;
                            break;

                        }

                    }

                }

            }
        }

    }

    //sprawdzanie po przekatnej
    //sprawdzanie po ukosie (najdluzsze przekatne)//
    int i = 0;
    int j = 0;

    if ((p[0][0] == p[0][4]) && (p[0][0] != ' ')) {
        if (p[0][4] == p[0][8]) {
            if (p[0][8] == p[3][0]) {
                if (p[3][0] == p[3][4]) {
                    cout << "wygral gracz " << p[3][4] << endl;
                    *koniec_gry = true;
                }

            }

        }

    }
    else if ((p[3][4] == p[3][8]) && (p[3][4] != ' ')) {
        if (p[0][4] == p[0][8]) {
            if (p[0][8] == p[3][0]) {
                if (p[3][0] == p[3][4]) {
                    cout << "wygral gracz " << p[3][4] << endl;
                    *koniec_gry = true;

                }

            }

        }

    }
    else if ((p[1][2] == p[1][4]) && (p[1][2] != ' ')) {
        if (p[1][4] == p[1][6]) {
            if (p[1][6] == p[2][2]) {
                if (p[2][2] == p[2][4]) {
                    cout << "wygral gracz " << p[2][4] << endl;
                    *koniec_gry = true;

                }

            }

        }

    }
    else if ((p[2][4] == p[2][6]) && (p[2][4] != ' ')) {
        if (p[1][4] == p[1][6]) {
            if (p[1][6] == p[2][2]) {
                if (p[2][2] == p[2][4]) {
                    cout << "wygral gracz " << p[2][4] << endl;
                    *koniec_gry = true;

                }

            }

        }

    }

    // krotsze przekatne
    else if ((p[0][3] == p[0][7]) && (p[0][3] != ' ')) {
        if (p[0][7] == p[2][2]) {
            if (p[2][2] == p[3][3]) {
                if (p[3][3] == p[3][7]) {
                    cout << "wygral gracz " << p[3][7] << endl;
                    *koniec_gry = true;

                }

            }

        }

    }
    else if ((p[0][1] == p[0][5]) && (p[0][1] != ' ')) {
        if (p[0][5] == p[1][6]) {
            if (p[1][6] == p[3][1]) {
                if (p[3][1] == p[3][5]) {
                    cout << "wygral gracz " << p[3][5] << endl;
                    *koniec_gry = true;
                }

            }

        }

    }
    else if ((p[1][1] == p[1][3]) && (p[1][1] != ' ')) {
        if (p[1][3] == p[0][8]) {
            if (p[0][8] == p[2][1]) {
                if (p[2][1] == p[2][3]) {
                    cout << "wygral gracz " << p[2][3] << endl;
                    *koniec_gry = true;

                }

            }

        }

    }
    else if ((p[1][5] == p[1][7]) && (p[1][5] != ' ')) {
        if (p[1][7] == p[3][0]) {
            if (p[3][0] == p[2][5]) {
                if (p[2][5] == p[2][7]) {
                    cout << "wygral gracz " << p[2][5] << endl;
                    *koniec_gry = true;

                }

            }

        }

    }
    //sprawdzanie czy remis

    if (!*koniec_gry) {
        sprawdz_remis(p, koniec_gry);
    }

}

void kolko_i_krzyzyk(char p[4][9], gracz g1, gracz g2, bool* koniec_gry) {
    wczytaj_imiona(&g1.nazwa_gracza, &g2.nazwa_gracza); //wczytanie nazw graczy
    char odpowiedz;
    for (int i = 0; i < 2; i++) {
        cout << "Czy gracz nr " << i + 1 << " chce zmienic zeton?   t/n" << endl;// warunek zmiany zetonu -> powtarzamy petle 2 razy, zmieniamy raz 1 a raz 2 gracza
        cin >> odpowiedz;
        if (odpowiedz == 't') {
            if (i == 0) {
                zmien_zeton(g1, g2);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((p[i][j] != g1.zeton) && (p[i][j] != g2.zeton) && (p[i][j] != ' ')) {  //zastepowanie zetonow juz obecnych na planszy
                            p[i][j] = g1.zeton;

                        }

                    }

                }

            }
            else {

                zmien_zeton(g2, g1);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((p[i][j] != g1.zeton) && (p[i][j] != g2.zeton) && (p[i][j] != ' ')) {
                            p[i][j] = g2.zeton;

                        }

                    }

                }

            }

        }
    }
    uzupelnij_plansze(p, ' '); //uzupelnienie planszy o puste pola w miejscu niewypelnionych znakow
    while (!*koniec_gry) {
        wypisz_plansze(p, g1, g2); // kolejno: wypisanie planszy -> wykonanie ruchu -> aktualizacja planszy (1) -> sprawdzenie warunku wygranej
        wykonaj_ruch(g1, p, g2);
        wypisz_plansze(p, g1, g2);
        sprawdz_wygrana(p, g1, g2, koniec_gry);
        if (*koniec_gry) {
            cout << "Koniec Gry..." << endl;
            break;
        }

        wykonaj_ruch(g2, p, g1);
        wypisz_plansze(p, g1, g2);
        wypisz_plansze(p, g1, g2);
        sprawdz_wygrana(p, g1, g2, koniec_gry);
        if (*koniec_gry) {
            cout << "end game" << endl;
            break;
        }

    }

}

void pentago(char p[4][9], gracz g1, gracz g2, bool* koniec_gry) {
    wczytaj_imiona(&g1.nazwa_gracza, &g2.nazwa_gracza);
    char odpowiedz;
    for (int i = 0; i < 2; i++) {
        cout << "Czy gracz nr " << i + 1 << " chce zmienic zeton?   t/n" << endl; // warunek zmiany zetonu -> powtarzamy petle 2 razy, zmieniamy raz 1 a raz 2 gracza
        cin >> odpowiedz;
        if (odpowiedz == 't') {
            if (i == 0) {
                zmien_zeton(g1, g2);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((p[i][j] != g1.zeton) && (p[i][j] != g2.zeton) && (p[i][j] != ' ')) {
                            p[i][j] = g1.zeton;

                        }

                    }

                }

            }
            else {

                zmien_zeton(g2, g1);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 9; j++) {
                        if ((p[i][j] != g1.zeton) && (p[i][j] != g2.zeton) && (p[i][j] != ' ')) {
                            p[i][j] = g2.zeton;

                        }

                    }

                }

            }

        }
    }
    uzupelnij_plansze(p, ' ');
    while (!*koniec_gry) {          
        wypisz_plansze(p, g1, g2);
        wykonaj_ruch(g1, p, g2);    // kolejno: wypisanie planszy -> wykonanie ruchu -> aktualizacja planszy (1)  -> wykonaniue obrotu -> aktualizacja planszy (2)-> sprawdzenie warunku wygranej
        wypisz_plansze(p, g1, g2);
        wybierz_cwiartke_doobrotu(p);
        wypisz_plansze(p, g1, g2);
        sprawdz_wygrana(p, g1, g2, koniec_gry);
        if (*koniec_gry) {
            cout << "Koniec Gry" << endl;
            break;
        }

        wykonaj_ruch(g2, p, g1);
        wypisz_plansze(p, g1, g2);
        wybierz_cwiartke_doobrotu(p);
        wypisz_plansze(p, g1, g2);
        sprawdz_wygrana(p, g1, g2, koniec_gry);
        if (*koniec_gry) {
            cout << "Koniec Gry" << endl;
            break;
        }

    }

}
void MenuGlowne(const int max_x, const int max_y, char p[4][9], gracz* g1, gracz* g2, bool* koniec_gry) {
    bool wyjdz_z_programu = false;// warunek konca gry ustawiony na false
    while (!wyjdz_z_programu) { // zapetlenie menu

        //char(186); - ║ // char(201) - ╔; // char(204) = ╠ //   char(185) = ╣
        //char(187); - ╗ // char(205) - ═ //   char(202) = ╩ // char(188) = ╝ //char(200) = ╚

        int n = 1;
        // rysowanie menu
        cout << char(201);
        for (int i = 0; i < max_y; i++) {

            cout << char(205);

        }
        cout << char(187);
        cout << endl;
        cout << char(186);
        for (int i = 0; i < (max_y - 18) / 2; i++) {

            cout << " ";
        }
        cout << "Kolko i Krzyzyk(1)";
        for (int i = 0; i < (max_y - 18) / 2; i++) {

            cout << " ";
        }
        cout << " ";
        cout << char(186);
        cout << endl;
        cout << char(186);
        for (int i = 0; i < (max_y - 10) / 2; i++) {

            cout << " ";
        }
        cout << "Pentago(2)";
        for (int i = 0; i < (max_y - 10) / 2; i++) {

            cout << " ";
        }
        cout << " ";
        cout << char(186);
        cout << endl;
        cout << char(186);
        for (int i = 0; i < (max_y - 8) / 2; i++) {

            cout << " ";
        }
        cout << "Pomoc(3)";
        for (int i = 0; i < (max_y - 8) / 2; i++) {

            cout << " ";
        }
        cout << " ";
        cout << char(186);
        cout << endl;
        cout << char(186);
        for (int i = 0; i < (max_y - 8) / 2; i++) {

            cout << " ";
        }
        cout << "Wyjdz(4)";
        for (int i = 0; i < (max_y - 8) / 2; i++) {

            cout << " ";
        }
        cout << " ";
        cout << char(186);
        cout << endl;
        cout << char(200);
        for (int i = 0; i < max_y; i++) {

            cout << char(205);

        }
        cout << char(188);
        while (true) {
            cin >> n;

            if ((n >= 1) && (n <= 4)) {
                break;
            }
            else {
                cout << "\nnieprawdlowa komenda uzytkowniku!! Sprobuj ponownie..." << endl;
            }
        }
        if (n == 1) {

            kolko_i_krzyzyk(p, *g1, *g2, koniec_gry);

        }
        else if (n == 2) {

            pentago(p, *g1, *g2, koniec_gry);

        }
        else if (n == 3) {
            system("cls");
            wypisz_pomoc();

        }
        else if (n == 4) {

            wyjdz_z_programu = true;//warunek wyjscia z programu

        }

    }
    cout << "bywaj...." << endl; // do zobaczenia na wiedzminskim szlaku!

}
int main() {
    //wczytaj_imiona(&gracz1.nazwa_gracza, &gracz2.nazwa_gracza);
    gracz gracz1;
    gracz gracz2;
    //domyslne nazwy graczy i symbole
    gracz1.nazwa_gracza = "gracz1";
    gracz2.nazwa_gracza = "gracz2";
    ustaw_zeton(&gracz1.zeton, 'X');
    ustaw_zeton(&gracz2.zeton, 'O');
    // wymiary konsoli
    const int max_x = 80;
    const int max_y = 25;
    // deklaracja tablicy [[lewy gorny][prawy gorny][lewy dolny][prawy dolny]][1-9]
    char plansza[4][9];
    //warunek konca gry
    bool koniec_gry = false;
    system("cls");
    MenuGlowne(max_x, max_y, plansza, &gracz1, &gracz2, &koniec_gry);

    return 0;

}5