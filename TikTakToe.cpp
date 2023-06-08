#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>

using namespace std;

int main ()

{

    char player1; //OJO - ESTE ES CHAR PORQUE LOS VALORES DE MI MATRIZ ESTÁN EN COMILLAS, NO SON NUMEROS
    char player2; //OJO - ESTE ES CHAR PORQUE LOS VALORES DE MI MATRIZ ESTÁN EN COMILLAS, NO SON NUMEROS


    cout << "\n---Welcome to the Game TIC TAC TOE, let's play!---\n";
    cout << "\nPlayer 1, you are playing with O's in the board";
    cout << "\nPlayer 2, you are playing with X's in the board";

    cout << "\n";


    //Nota, nunca hacer VARIABLES fuera del main. Solo las CONSTANTES que no cambian, podrian definirse fuera del main.

    //Codigo para crear la matriz

    const int ROWS = 3;
    const int COLUMNS = 3;
    int attempts = 9;

    char board[ROWS][COLUMNS] = { {'1', '2', '3',},
                                       {'4', '5', '6',},
                                       {'7', '8', '9',} };

    cout << "\n---TIC TAC TOE---\n";
    for (int i = 0; i < ROWS; i++)
    {

        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];

        }

        cout << endl;

    }



    do {

        //Interaccion con el jugador 1

        cout << "\nPlayer 1 Turn:";
        cout << "\nWhich space in the board you want to fill in?";
        cout << "\nChoose a number from the board\n";
        cin >> player1;
        system("cls");

        if (player1 != 'X')

        {

            for (int i = 0; i < ROWS; i++)
            {

                for (int j = 0; j < COLUMNS; j++)
                {
                    if (board[i][j] == player1)
                    {

                        board[i][j] = 'O';
                        attempts = attempts - 1;

                    }


                }

            }




        }

        else
        {

            cout << "invalid option. You have lost your turn" << endl;

        }

        cout << "\n---TIC TAC TOE---\n";
        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLUMNS; j++)
            {
                cout << board[i][j];

            }

            cout << endl;

        }


        //Interaccion con el jugador 2

        cout << "\nPlayer 2 Turn:";
        cout << "\nWhich space in the board you want to fill in?";
        cout << "\nChoose a number in the board\n";
        cin >> player2;
        system("cls");

        if (player2 != 'O')
        {

            for (int i = 0; i < ROWS; i++)
            {

                for (int j = 0; j < COLUMNS; j++)
                {
                    if (board[i][j] == player2)
                    {

                        board[i][j] = 'X';
                        attempts = attempts - 1;

                    }

                }

            }


        }

        else
        {

            cout << "invalid option. You have lost your turn" << endl;

        }

        cout << "\n---TIC TAC TOE---\n";
        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLUMNS; j++)
            {
                cout << board[i][j];

            }

            cout << endl;

        }

    } while (attempts > 0);


    cout << "\nThe board is already full!" << endl;

    //Determinacion del jugador ganador lado horizontal

    cout << "\n";

    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')

        cout << "\nPlayer 1 Wins!";


    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')

        cout << "\nPlayer 2 Wins!";

    //Determinacion del jugador ganador lado vertical


    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    //Determinacion del jugador ganador cruzado 


    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')

        cout << "\nPlayer 2 Wins!";

    cout << "\n";


    cout << "\nTHANKS FOR PLAYING!";

}
