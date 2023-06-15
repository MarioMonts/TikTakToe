
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>

using namespace std;
void instrucciones();
char AskYesNo(string question);
char humansymbol();
char opponent(char player);
char winner(vector<char> board);

const char EMPTY = ' '; //Constante global para determinar el valor en los espacios que en este caso es vacio
const char  X = 'X'; //Creamos una variable global porque es un valor que es parte del juego
const char  O = 'O'; //Creamos una variable global porque es un valor que es parte del juego
const char NO_ONE = 'N';
const char TIE = 'T';

int main()

{

	setlocale(LC_ALL, "spanish");
	char validation;
	char player = humansymbol(); //Para que tome el valor de la funcion que creamos abajo en caso de querer comenzar primero
	char computer = opponent(player); //Para que tome el valor contrario que elija el jugador usando la funcion de opponent
	char turn = X ; //porque es mas natural que el juego inicie con la X. Toma su valor de la constante global


	const int NUM_SQUARES = 9; //Contsante para declarar el tamaño
	vector<char> board(NUM_SQUARES, EMPTY); /// 10 es el numero de espacios y los espacios van a estar vacios

	//Mostrar Instrucciones
	instrucciones();
	
   //Funcion para que el jugador elija que letra quiere usar

	while (winner(board) == NO_ONE)
	{

	}

}



void instrucciones()

{

	cout << "\nBienvenido: \n";
	cout << "\nElige una posicion entre el 0 y el 8.\n\n";
	cout << "|0|1|2|\n" ;
	cout << "|3|4|5|\n" ;
	cout << "|6|7|8|\n" ;
	
	cout << "\nQue comience la batalla!\n";
}


char AskYesNo(string question) //Esta es una funcion exclusivamente para obtener algo del answer que en este caso es Yes o No
{

	char answer;

	do
	{
		cout << "\n" << question << "(y/n)";
		cin >> answer;

	} while (answer != 'y' && answer != 'n');

	return answer;
	


}

char humansymbol() //esta funcion es para usar el Yes o No de arriba y asignar OTRO resultado que en este caso son nuestras contsantes globales
{

	char gofirst = AskYesNo("Deseas comenzar la partida?");

	if (gofirst == 'y')
	{
		return X;
	}

	else
	{
		return O;
	}

}

char opponent(char player)
{

	if (player == X)

	{
		return O;

	}

	else
	{
		return X;
	}
}



char winner(vector<char> board)
{
	//Son todas las posibilidades para ganar
	const int WINNING_POS[8][3] = { {0, 1, 2},
									{3, 4, 5},
									{6, 7, 8},
									{0, 3, 6},
									{1, 4, 7},
									{2, 5, 8},
									{2, 4, 6},
									{0, 4, 8},};

	const int TOTAL_ROWS = 8;

	//Para regresar al ganador.
	//Logica: el for nes para ir aumentando de fila en fila porque ahí está cada condicion de gane
	//los diferentes IFs es para que se cumpla suponiendo que la X esta en el espacio 0,1,2 y 3,4,5, etc.
	//porque si el espacio 1 es igual al 2 y el 2 al 3, entonces se cumple el win
	for (int row = 0; row < TOTAL_ROWS; row++)
	{

if  ((board[WINNING_POS[row][0]] != EMPTY) && //Para que el espacio no este vacio
	(board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) && // [row] es la fila y [] es el numero de la columna
	(board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]])) // [row] es la fila y [] es el numero de la columna
{
	return board[WINNING_POS[row][0]];

}
	}

	//Para regresar si es un empate. Porque checa todo el tablero que este llenom y si esta lleno y no hubo un ganador
	//por la fucnion de arriba, significa que nadie gano

	if (count(board.begin(), board.end(), EMPTY) == 0) //el count es una funcion que se reinicia
	{
		return TIE;
	}

	//regresar que nadie ha ganado todavia

	return NO_ONE;

}


//Examen: Referencias y Matrices