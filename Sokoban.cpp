#include <iostream>

const int mapa1_y = 15;
const int mapa1_x = 10;
const int mapa2_y = 20; // rozmiary map, mapa 1 i "2" maja takie same rozmiary
const int mapa2_x = 20; // mapa druga ma indeks mapa3 poniewaz byla stworzona po mapie2
const int mapa_max_y = 100;
const int mapa_max_x = 100;
void wypelnij_mapa1(char mapa1[mapa1_y][mapa1_x], int limit, int cel1_x, int cel1_y);
void wyswietl_mapa1(char mapa1[mapa1_y][mapa1_x]);
void sterowanie(int& postac1_x, int& postac1_y, char mapa[mapa1_y][mapa1_x], char guzik, int& licznik);
void sterowanie2(int& postac1_x, int& postac1_y, char mapa[mapa2_y][mapa2_x], char guzik, int& licznik);
int czy_wygrana(char mapa1[mapa1_y][mapa1_x]);
int czy_wygrana2(char mapa2[mapa2_y][mapa2_x]);
void wypelnij_mapa2(char mapa2[mapa2_y][mapa2_x]);
void wypelnij_mapa3(char mapa3[mapa1_y][mapa1_x], int limit, int cel1_x, int cel1_y);
void wyswietl_mapa2(char mapa2[mapa2_y][mapa2_x]);

int main()
{

    int licznik = 0;
    int limit1 = 18;
    int limit2 = 80;
    int limit3 = 25;
    int wygrana1 = 1;
    int wygrana2 = 4;
    int wygrana3 = 1;
    int zeton = 0;
    char guzik;
    int postac1_x = 1, postac1_y = 1;
    int cel1_x = 5, cel1_y = 10;
    char mapa1[mapa1_y][mapa1_x];
    char mapa2[mapa2_y][mapa2_y];
    char mapa3[mapa1_y][mapa1_x];
    int guzik_wyboru = 0;
    std::cout << R"(                  _______.  ______    __  ___   ______   .______        ___      .__   __.
                 /       | /  __  \  |  |/  /  /  __  \  |   _  \      /   \     |  \ |  |
                |   (----`|  |  |  | |  '  /  |  |  |  | |  |_)  |    /  ^  \    |   \|  |
                 \   \    |  |  |  | |    <   |  |  |  | |   _  <    /  /_\  \   |  . `  |
             .----)   |   |  `--'  | |  .  \  |  `--'  | |  |_)  |  /  _____  \  |  |\   |
              _______/     \______/  |__|\__\  \______/  |______/  /__/     \__\ |__| \__| )" << std::endl;

    std::cout << "                                   GRA W STYLU SOKOBAN  " << std::endl;
    std::cout << "                              Nikodem Kozak ACiR gr2 s193388" << std::endl;
    system("pause");
    while (guzik_wyboru != 6)
    {
        system("cls");
        std::cout << "  \n      Menu" << std::endl << "  1. Poziom pierwszy \n" << "  2. Poziom drugi "; if (zeton == 0) std::cout << "(zablokowany) "; if (zeton == 1) std::cout << "(odblokowany) ";
        std::cout << "\n  3. Poziom trzeci "; if (zeton == 0 || zeton == 1) std::cout << "(zablokowany) "; if (zeton == 2) std::cout << "(odblokowany) ";
        std::cout << "\n  4. Credits \n" << "  5. Sterowanie \n" << "  6. Wyjdz z gry"; if (zeton > 3) std::cout << "\n \n Gratuluje przejscia gry!!!!";
        std::cin >> guzik_wyboru;
        if (guzik_wyboru == 1)
        {
            wypelnij_mapa1(mapa1, limit1, cel1_x, cel1_y);
            do
            {
                system("cls");
                std::cout << postac1_x - 1 << " " << postac1_y - 1 << " <-- Twoje wspolrzedne" << std::endl;
                std::cout << "Wykonales " << licznik << " ruchow" << " (limit to " << limit1 << " )" << std::endl;
                wyswietl_mapa1(mapa1);
                std::cin >> guzik;

                sterowanie(postac1_x, postac1_y, mapa1, guzik, licznik);

            } while (czy_wygrana(mapa1) < wygrana1 && licznik < limit1 && guzik != 'q');
            if (czy_wygrana(mapa1) == wygrana1)
            {
                system("cls");
                wyswietl_mapa1(mapa1);
                std::cout << "Gratuluje wygrales w " << licznik << " ruchach ! \n";
                licznik = 0;
                postac1_x = 1;
                postac1_y = 1;
                zeton = 1;
                system("pause");
            }
            else if (guzik == 'q')
            {
                std::cout << "\n   Wyszedles do menu \n";
                licznik = 0;
                system("pause");
            }
            else
            {
                licznik = 0;
                system("cls");
                std::cout << "Przegrales :((((( \n Skonczyly ci sie ruchy \n";
                postac1_x = 1;
                postac1_y = 1;
                system("pause");
            }
        }

        if (guzik_wyboru == 2 && zeton == 1)
        {
            wypelnij_mapa3(mapa3, limit3, cel1_x, cel1_y);
            do
            {
                system("cls");
                std::cout << postac1_x - 1 << " " << postac1_y - 1 << " <-- Twoje wspolrzedne" << std::endl;
                std::cout << "Wykonales " << licznik << " ruchow" << " (limit to " << limit3 << " )" << std::endl;
                wyswietl_mapa1(mapa3);
                std::cin >> guzik;

                sterowanie(postac1_x, postac1_y, mapa3, guzik, licznik);

            } while (czy_wygrana(mapa3) < wygrana3 && licznik < limit3 && guzik != 'q');
            if (czy_wygrana(mapa3) == wygrana3)
            {
                system("cls");
                wyswietl_mapa1(mapa3);
                std::cout << "Gratuluje wygrales w " << licznik << " ruchach ! \n";
                licznik = 0;
                postac1_x = 1;
                postac1_y = 1;
                zeton = 2;
                system("pause");
            }
            else if (guzik == 'q')
            {
                std::cout << "\n   Wyszedles do menu \n";
                licznik = 0;
                system("pause");
            }
            else
            {
                licznik = 0;
                system("cls");
                std::cout << "Przegrales :((((( \n Skonczyly ci sie ruchy \n";
                postac1_x = 1;
                postac1_y = 1;
                system("pause");
            }
        }
        if (guzik_wyboru == 2 && zeton == 0)
        {
            std::cout << " Najpierw ukoncz poziom pierwszy " << std::endl;
            system("pause");
        }

        if (guzik_wyboru == 3 && zeton == 2)
        {
            wypelnij_mapa2(mapa2);
            do
            {
                system("cls");
                std::cout << postac1_x - 1 << " " << postac1_y - 1 << " <-- Twoje wspolrzedne" << std::endl;
                std::cout << "Wykonales " << licznik << " ruchow" << " (limit to " << limit2 << " )" << std::endl;
                wyswietl_mapa2(mapa2);
                std::cin >> guzik;

                sterowanie2(postac1_x, postac1_y, mapa2, guzik, licznik);

            } while (czy_wygrana2(mapa2) < wygrana2 && licznik < limit2 && guzik != 'q');
            if (czy_wygrana2(mapa2) == wygrana2)
            {
                system("cls");
                wyswietl_mapa2(mapa2);
                std::cout << "Gratuluje wygrales w " << licznik << " ruchach ! \n";
                zeton = 4;
                licznik = 0;
                postac1_x = 1;
                postac1_y = 1;
                system("pause");
            }
            else if (guzik == 'q')
            {
                std::cout << "\n   Wyszedles do menu \n";
                licznik = 0;
                system("pause");
            }
            else
            {
                licznik = 0;
                system("cls");
                std::cout << "Przegrales :((((( \n Skonczyly ci sie ruchy \n";
                postac1_x = 1;
                postac1_y = 1;
                system("pause");
            }
        }
        if (guzik_wyboru == 3 && (zeton == 0 || zeton == 1))
        {
            std::cout << " Najpierw ukoncz poziom pierwszy i drugi" << std::endl;
            system("pause");
        }
        if (guzik_wyboru == 4)
        {
            std::cout << std::endl;
            std::cout << "  (~ _ |  _ |_  _ ._   " << std::endl;
            std::cout << "  _)(_)|<(_)|_)(_|| |  " << std::endl;

            std::cout << "  Nikodem Kozak s193388 AciR gr2" << std::endl;
            system("pause");
        }

        if (guzik_wyboru == 5)
        {
            std::cout << "                          MENU STEROWANIA W GRZE SOKOBAN    " << std::endl;
            std::cout << "                              W + enter -> ruch w gore      " << std::endl;
            std::cout << "                              A + enter -> ruch w lewo      " << std::endl;
            std::cout << "                              S + enter -> ruch w dol       " << std::endl;
            std::cout << "                              D + enter -> ruch w prawo     " << std::endl;
            std::cout << "                              Q + enter -> wyjdz do menu    " << std::endl;
            std::cout << "                     (w menu) Q + enter -> wyjdz do pulpitu " << std::endl;
            system("pause");
        }


    }
}


void wypelnij_mapa1(char mapa1[mapa1_y][mapa1_x], int limit, int cel1_x, int cel1_y)
{
    limit = 15;
    for (int i = 0; i < mapa1_y; i++)
    {
        for (int j = 0; j < mapa1_x; j++)
        {
            if (i == 0 || i == (mapa1_y - 1) || j == 0 || j == (mapa1_x - 1))
            {
                mapa1[i][j] = (char)88;

            }
            else if (i == 1 && j == 1)
            {
                mapa1[i][j] = (char)64;

            }
            else if (i == 2 && j == 2)
            {
                mapa1[i][j] = (char)219;

            }
            else if (i == 10 && j == 5)
            {
                mapa1[i][j] = (char)153;

            }
            else if (i < 5 && j == 4)
            {
                mapa1[i][j] = (char)88;

            }
            else if (i == 4 && (j == 6 || j == 5 || j == 7 || j == 8))
            {
                mapa1[i][j] = (char)88;

            }
            else if (i == 8 && (j == 1 || j == 2))
            {
                mapa1[i][j] = (char)88;

            }
            else
                mapa1[i][j] = (char)32;

        }

    }
}
void wyswietl_mapa1(char mapa1[mapa1_y][mapa1_x])
{

    for (int i = 0; i < mapa1_y; i++)
    {
        for (int j = 0; j < mapa1_x; j++)
        {
            std::cout << mapa1[i][j];



        }
        std::cout << std::endl;
    }
}

void wypelnij_mapa2(char mapa2[mapa2_y][mapa2_x])
{
    for (int i = 0; i < mapa2_y; i++)
    {
        for (int j = 0; j < mapa2_x; j++)
        {
            if (i == 0 || i == (mapa2_y - 1) || j == 0 || j == (mapa2_x - 1))
            {
                mapa2[i][j] = (char)88;

            }
            else if (i == 1 && j == 1)
            {
                mapa2[i][j] = (char)64;

            }
            else if (i == 12 && j > 0 && j < 7)
            {
                mapa2[i][j] = (char)88;

            }
            else if (i == 2 && (j < 11))
            {
                mapa2[i][j] = (char)88;

            }
            else if (i == 4 && (j < 11))
            {
                mapa2[i][j] = (char)88;

            }
            else if (j == 11 && (i == 2 || i == 4 || i == 3))
            {
                mapa2[i][j] = (char)88;

            }
            else if (i > 12 && j < 19 && j == 6)
            {
                mapa2[i][j] = (char)88;

            }
            else if ((i == 7 || i == 8 || i == 9) && (j < 19 && j > 10 || j == 7))
            {
                mapa2[i][j] = (char)88;

            }

            else if (i == 11 && (j == 2 || j == 4))
            {
                mapa2[i][j] = (char)153;

            }
            else if (i == 7 && (j == 2 || j == 4))
            {
                mapa2[i][j] = (char)219;

            }
            else if (i == 3 && j == 18)
            {
                mapa2[i][j] = (char)153;

            }
            else if (i == 3 && j == 14)
            {
                mapa2[i][j] = (char)219;

            }
            else if (i == 18 && j == 18)
            {
                mapa2[i][j] = (char)153;

            }
            else if (i == 15 && j == 15)
            {
                mapa2[i][j] = (char)219;

            }
            else
                mapa2[i][j] = (char)32;

        }




    }






}

void wyswietl_mapa2(char mapa2[mapa2_y][mapa2_x])
{

    for (int i = 0; i < mapa2_y; i++)
    {
        for (int j = 0; j < mapa2_x; j++)
        {
            std::cout << mapa2[i][j];



        }
        std::cout << std::endl;
    }
}

void wypelnij_mapa3(char mapa3[mapa1_y][mapa1_x], int limit, int cel1_x, int cel1_y)
{
    for (int i = 0; i < mapa1_y; i++)
    {
        for (int j = 0; j < mapa1_x; j++)
        {
            if (i == 0 || i == (mapa1_y - 1) || j == 0 || j == (mapa1_x - 1))
            {
                mapa3[i][j] = (char)88;

            }
            else if (i == 1 && j == 1)
            {
                mapa3[i][j] = (char)64;

            }
            else if (i == 2 && j == 5)
            {
                mapa3[i][j] = (char)219;

            }
            else if (i == 11 && j == 5)
            {
                mapa3[i][j] = (char)153;

            }
            else if ((i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7) && (j == 4 || j == 6))
            {
                mapa3[i][j] = (char)88;

            }
            else if ((i == 2 || i == 7) && j != 5)
            {
                mapa3[i][j] = (char)88;

            }
            else if (i == 10 && j == 5)
            {
                mapa3[i][j] = (char)88;

            }



            else
                mapa3[i][j] = (char)32;

        }

    }
}




void sterowanie(int& postac1_x, int& postac1_y, char mapa1[mapa1_y][mapa1_x], char guzik, int& licznik)
{


    switch (guzik)
    {
    case 'd':
        if (mapa1[postac1_y][postac1_x + 1] == (char)32)
        {
            mapa1[postac1_y][postac1_x + 1] = (char)64;
            mapa1[postac1_y][postac1_x] = (char)32;


            postac1_x += 1;
            licznik++;

        }
        else if (mapa1[postac1_y][postac1_x + 1] == (char)219 && mapa1[postac1_y][postac1_x + 2] == (char)32)
        {
            mapa1[postac1_y][postac1_x + 1] = (char)64;
            mapa1[postac1_y][postac1_x + 2] = (char)219;
            mapa1[postac1_y][postac1_x] = (char)32;
            licznik++;

            postac1_x += 1;


        }
        else if ((mapa1[postac1_y][postac1_x + 1] == (char)219 && mapa1[postac1_y][postac1_x + 2] == (char)88))
        {
            5 == 5;

        }
        else if (mapa1[postac1_y][postac1_x + 1] == (char)219 && mapa1[postac1_y][postac1_x + 2] == (char)153)
        {
            mapa1[postac1_y][postac1_x + 1] = (char)64;
            mapa1[postac1_y][postac1_x + 2] = (char)36;
            mapa1[postac1_y][postac1_x] = (char)32;
            licznik++;

            postac1_x += 1;


        }
        else if (mapa1[postac1_y][postac1_x + 1] == (char)36 && mapa1[postac1_y][postac1_x + 2] == (char)32)
        {
            mapa1[postac1_y][postac1_x + 2] = (char)219;
            mapa1[postac1_y][postac1_x + 1] = (char)64;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_x += 1;
            licznik++;

        }
        else if (mapa1[postac1_y][postac1_x + 1] == (char)88)
        {
            5 == 5;

        }
        break;
    case 'a':
        if (mapa1[postac1_y][postac1_x - 1] == (char)32)
        {
            mapa1[postac1_y][postac1_x - 1] = (char)64;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_x -= 1;
            licznik++;

        }
        else if (mapa1[postac1_y][postac1_x - 1] == (char)219 && mapa1[postac1_y][postac1_x - 2] == (char)32)
        {
            mapa1[postac1_y][postac1_x - 1] = (char)64;
            mapa1[postac1_y][postac1_x - 2] = (char)219;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_x -= 1;
            licznik++;

        }
        else if ((mapa1[postac1_y][postac1_x - 1] == (char)219 && mapa1[postac1_y][postac1_x - 2] == (char)88))
        {
            5 == 5;

        }
        else if (mapa1[postac1_y][postac1_x - 1] == (char)219 && mapa1[postac1_y][postac1_x - 2] == (char)153)
        {
            mapa1[postac1_y][postac1_x - 1] = (char)64;
            mapa1[postac1_y][postac1_x - 2] = (char)36;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_x -= 1;
            licznik++;

        }
        else if (mapa1[postac1_y][postac1_x - 1] == (char)88)
        {
            5 == 5;

        }
        break;
    case 'w':
        if (mapa1[postac1_y - 1][postac1_x] == (char)32)
        {
            mapa1[postac1_y - 1][postac1_x] = (char)64;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_y -= 1;
            licznik++;

        }
        else if (mapa1[postac1_y - 1][postac1_x] == (char)219 && mapa1[postac1_y - 2][postac1_x] == (char)32)
        {
            mapa1[postac1_y - 1][postac1_x] = (char)64;
            mapa1[postac1_y - 2][postac1_x] = (char)219;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_y -= 1;
            licznik++;

        }
        else if ((mapa1[postac1_y - 1][postac1_x] == (char)219 && mapa1[postac1_y - 2][postac1_x] == (char)88))
        {
            5 == 5;

        }
        else if (mapa1[postac1_y - 1][postac1_x] == (char)219 && mapa1[postac1_y - 2][postac1_x] == (char)153)
        {
            mapa1[postac1_y - 1][postac1_x] = (char)64;
            mapa1[postac1_y - 2][postac1_x] = (char)36;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_y -= 1;
            licznik++;

        }
        else if (mapa1[postac1_y - 1][postac1_x] == char(88))
        {
            5 == 5;

        }
        break;

    case 's':
        if (mapa1[postac1_y + 1][postac1_x] == (char)32)
        {
            mapa1[postac1_y + 1][postac1_x] = (char)64;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_y += 1;
            licznik++;

        }
        else if (mapa1[postac1_y + 1][postac1_x] == (char)219 && mapa1[postac1_y + 2][postac1_x] == (char)32)
        {
            mapa1[postac1_y + 1][postac1_x] = (char)64;
            mapa1[postac1_y + 2][postac1_x] = (char)219;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_y += 1;
            licznik++;

        }
        else if ((mapa1[postac1_y + 1][postac1_x] == (char)219 && mapa1[postac1_y + 2][postac1_x] == (char)88))
        {
            5 == 5;

        }
        else if (mapa1[postac1_y + 1][postac1_x] == (char)219 && mapa1[postac1_y + 2][postac1_x] == (char)153)
        {
            mapa1[postac1_y + 1][postac1_x] = (char)64;
            mapa1[postac1_y + 2][postac1_x] = (char)36;
            mapa1[postac1_y][postac1_x] = (char)32;

            postac1_y += 1;
            licznik++;

        }
        else if (mapa1[postac1_y + 1][postac1_x] == (char)88)
        {
            5 == 5;

        }
        break;


    }
}

int czy_wygrana(char mapa1[mapa1_y][mapa1_x])
{
    int wskaznik = 0;
    for (int i = 0; i < mapa1_y; i++)
    {
        for (int j = 0; j < mapa1_x; j++)
        {
            if (mapa1[i][j] == (char)36)
                wskaznik++;

        }

    }

    return wskaznik;


}

int czy_wygrana2(char mapa2[mapa2_y][mapa2_x])
{
    int wskaznik = 0;
    for (int i = 0; i < mapa2_y; i++)
    {
        for (int j = 0; j < mapa2_x; j++)
        {
            if (mapa2[i][j] == (char)36)
                wskaznik++;

        }

    }

    return wskaznik;


}



void sterowanie2(int& postac1_x, int& postac1_y, char mapa2[mapa2_y][mapa2_x], char guzik, int& licznik)
{
    switch (guzik)
    {
    case 'd':
        if (mapa2[postac1_y][postac1_x + 1] == (char)32)
        {
            mapa2[postac1_y][postac1_x + 1] = (char)64;
            mapa2[postac1_y][postac1_x] = (char)32;

            postac1_x += 1;
            licznik++;

        }
        else if (mapa2[postac1_y][postac1_x + 1] == (char)219 && mapa2[postac1_y][postac1_x + 2] == (char)32)
        {
            mapa2[postac1_y][postac1_x + 1] = (char)64;
            mapa2[postac1_y][postac1_x + 2] = (char)219;
            mapa2[postac1_y][postac1_x] = (char)32;
            licznik++;
            postac1_x += 1;


        }
        else if ((mapa2[postac1_y][postac1_x + 1] == (char)219 && mapa2[postac1_y][postac1_x + 2] == (char)88))
        {
            5 == 5;

        }
        else if (mapa2[postac1_y][postac1_x + 1] == (char)219 && mapa2[postac1_y][postac1_x + 2] == (char)153)
        {
            mapa2[postac1_y][postac1_x + 1] = (char)64;
            mapa2[postac1_y][postac1_x + 2] = (char)36;
            mapa2[postac1_y][postac1_x] = (char)32;
            licznik++;
            postac1_x += 1;


        }
        else if (mapa2[postac1_y][postac1_x + 1] == (char)36 && mapa2[postac1_y][postac1_x + 2] == (char)32)
        {
            mapa2[postac1_y][postac1_x + 2] = (char)219;
            mapa2[postac1_y][postac1_x + 1] = (char)64;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_x += 1;
            licznik++;

        }
        else if (mapa2[postac1_y][postac1_x + 1] == (char)88)
        {
            5 == 5;

        }
        break;
    case 'a':
        if (mapa2[postac1_y][postac1_x - 1] == (char)32)
        {
            mapa2[postac1_y][postac1_x - 1] = (char)64;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_x -= 1;
            licznik++;

        }
        else if (mapa2[postac1_y][postac1_x - 1] == (char)219 && mapa2[postac1_y][postac1_x - 2] == (char)32)
        {
            mapa2[postac1_y][postac1_x - 1] = (char)64;
            mapa2[postac1_y][postac1_x - 2] = (char)219;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_x -= 1;
            licznik++;

        }
        else if ((mapa2[postac1_y][postac1_x - 1] == (char)219 && mapa2[postac1_y][postac1_x - 2] == (char)88))
        {
            5 == 5;

        }
        else if (mapa2[postac1_y][postac1_x - 1] == (char)219 && mapa2[postac1_y][postac1_x - 2] == (char)153)
        {
            mapa2[postac1_y][postac1_x - 1] = (char)64;
            mapa2[postac1_y][postac1_x - 2] = (char)36;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_x -= 1;
            licznik++;

        }
        else if (mapa2[postac1_y][postac1_x - 1] == (char)88)
        {
            5 == 5;

        }
        break;
    case 'w':
        if (mapa2[postac1_y - 1][postac1_x] == (char)32)
        {
            mapa2[postac1_y - 1][postac1_x] = (char)64;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_y -= 1;
            licznik++;

        }
        else if (mapa2[postac1_y - 1][postac1_x] == (char)219 && mapa2[postac1_y - 2][postac1_x] == (char)32)
        {
            mapa2[postac1_y - 1][postac1_x] = (char)64;
            mapa2[postac1_y - 2][postac1_x] = (char)219;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_y -= 1;
            licznik++;

        }
        else if ((mapa2[postac1_y - 1][postac1_x] == (char)219 && mapa2[postac1_y - 2][postac1_x] == (char)88))
        {
            5 == 5;

        }
        else if (mapa2[postac1_y - 1][postac1_x] == (char)219 && mapa2[postac1_y - 2][postac1_x] == (char)153)
        {
            mapa2[postac1_y - 1][postac1_x] = (char)64;
            mapa2[postac1_y - 2][postac1_x] = (char)36;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_y -= 1;
            licznik++;

        }
        else if (mapa2[postac1_y - 1][postac1_x] == char(88))
        {
            5 == 5;

        }
        break;

    case 's':
        if (mapa2[postac1_y + 1][postac1_x] == (char)32)
        {
            mapa2[postac1_y + 1][postac1_x] = (char)64;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_y += 1;
            licznik++;

        }
        else if (mapa2[postac1_y + 1][postac1_x] == (char)219 && mapa2[postac1_y + 2][postac1_x] == (char)32)
        {
            mapa2[postac1_y + 1][postac1_x] = (char)64;
            mapa2[postac1_y + 2][postac1_x] = (char)219;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_y += 1;
            licznik++;

        }
        else if ((mapa2[postac1_y + 1][postac1_x] == (char)219 && mapa2[postac1_y + 2][postac1_x] == (char)88))
        {
            5 == 5;

        }
        else if (mapa2[postac1_y + 1][postac1_x] == (char)219 && mapa2[postac1_y + 2][postac1_x] == (char)153)
        {
            mapa2[postac1_y + 1][postac1_x] = (char)64;
            mapa2[postac1_y + 2][postac1_x] = (char)36;
            mapa2[postac1_y][postac1_x] = (char)32;
            postac1_y += 1;
            licznik++;

        }
        else if (mapa2[postac1_y + 1][postac1_x] == (char)88)
        {
            5 == 5;

        }
        break;
    }
}