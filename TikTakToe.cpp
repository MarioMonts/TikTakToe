
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
void displayboard(const vector<char>& board);
int GuessParams(string question, int a, int b);
int playerMove(const vector<char>& board);


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
	int move; //Variable para almacenar los enteros que va a meter el jugador

	const int NUM_SQUARES = 9; //Contsante para declarar el tamaño
	vector<char> board(NUM_SQUARES, EMPTY); /// 10 es el numero de espacios y los espacios van a estar vacios

	//Mostrar Instrucciones
	instrucciones();
	
   //Funcion para que el jugador elija que letra quiere usar


	while (winner(board) == NO_ONE)
	{

		if (turn == player)

		{
			//cout << "\nIngresa el espacio que deseas rellenar\n";
			//cin >> move; //para pedirle al jugador que ingrese su movimiento
		
			move = playerMove(board);
			board[move] = player; //para igualarlo al tablero
			displayboard(board); //funcion para que me muestre el tablero actualizado
        }

		else

		{

		}

	}

}

void instrucciones()

{

	cout << "\nBienvenido: \n";
	cout << "\nTendras que elegir una posicion en el tablero.\n\n";
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


void displayboard(const vector<char>& board) //Funcion para acomodar el board en la vista del gato
{

	cout << board[0] << "|" << board[1] << "|" << board[2] << "|" << endl;
	cout << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
	cout << board[6] << "|" << board[7] << "|" << board[8] << "|" << endl;
}

//funcion para que el resultado de GuessParams me lo guarde en un variable de Entero

int playerMove(const vector<char>& board)
{
	int numb = GuessParams("\nElige un numero ", 8, 0);
	if (numb != EMPTY)
	{
		return numb;

	}
	
	else

	{

		cout << "This space is already taken" << endl;

	}
}




//Funcion para pedirle un valor al jugador y que solo me acepte valores correctos 
int GuessParams(string question, int a, int b)
{

	string input;
	bool isValid = false;
	// int num = 0; /// Esta variable solo existe dentro de la funcion. Por lo tanto no puede usarse en el main
	//si quisiera una variable global (que funcione en todos lados), tendria que ir arriba del main. Pero esto no es buena practica
	//nunca hacer globales. Hay que hacer variables constantes. 

	//Funciona al revés tambié, si pusiera una variable de main aquí, no la reconocería la función

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	do {

		cout << question << "entre " << b << " y " << a << endl;
		getline(cin, input); //se usa para que el jugador meta strings con espacios
		

		for (char c : input) // forma corta de hacer el for. Todo se almacena en la c hasta que se recorre todo el input

		{
			if (isdigit(c)) // el ! es para negar algo, es lo mismo a isdigit = false
			{
				isValid = true;
				break;
			}

		}


		if (!isValid)
		{
			cout << "Entrada invalida, por favor elige solo numeros.";

		}

	} while (!isValid || input.empty());

	// while (num > a || num < b); //el AND aqui no funcionaba porque no era posible. Se usa un OR

	return stoi(input); //String to Int es par aconvertir un string a un entero

}



//Examen: Referencias y Matrices