

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>

using namespace std;
void instrucciones();
char AskYesNo(string question);
int AskNumber(string question, int a, int b);
char humansymbol();
char opponent(char player);
char winner(vector<char> board);
void displayboard(const vector<char>& board);
inline bool isLegal(int move, const vector<char>& board);
char AskParImpar(string question);
char ParImpar();
int humanMove(const vector<char>& board);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char human, char computer);


const char EMPTY = ' '; //Constante global para determinar el valor en los espacios que en este caso es vacio
const char  X = 'X'; //Creamos una variable global porque es un valor que es parte del juego
const char  O = 'O'; //Creamos una variable global porque es un valor que es parte del juego
const char NO_ONE = 'N';
const char TIE = 'T';

int main()

{

	setlocale(LC_ALL, "spanish");
	char validation;
	char player = ParImpar(); //Para que tome el valor de la funcion que creamos abajo en caso de querer comenzar primero
	char computer = opponent(player); //Para que tome el valor contrario que elija el jugador usando la funcion de opponent
	char turn = X; //porque es mas natural que el juego inicie con la X. Toma su valor de la constante global
	int move; //Variable para almacenar los enteros que va a meter el jugador

	const int NUM_SQUARES = 9; //Contsante para declarar el tamaño
	vector<char> board(NUM_SQUARES, EMPTY); /// 10 es el numero de espacios y los espacios van a estar vacios

	//Mostrar Instrucciones
	instrucciones();

	//Funcion para que el jugador elija que letra quiere usar


	while (winner(board) == NO_ONE) //Mientras nadie haya ganado
	{

		if (turn == player) //si yo decidi empezar entonces hago mi movimiento 

		{
			move = humanMove(board); //mi movimiento se reemplaza en el tablero
			board[move] = player; //para igualarlo al tablero
		}

		else

		{
			move = computerMove(board, computer); //para que se ejecute el turno de la PC
			board[move] = computer; //para igualarlo al tablero
		}

		turn = opponent(turn); //El opuesto de X seria la 0 y el de la 0 es la X
		displayboard(board); //para mostrar el tablero actualizado
	}

	announceWinner(winner(board), player, computer);

}

void instrucciones()

{

	cout << "\nBienvenido: \n";
	cout << "\nTendras que elegir una posicion en el tablero.\n\n";
	cout << "|0|1|2|\n";
	cout << "|3|4|5|\n";
	cout << "|6|7|8|\n";

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

int AskNumber(string question, int high, int low) //Funcion para pedirle un valor al jugador y que solo me acepte valores correctos 
{

	string input;
	bool isValid = false;
	// int num = 0; /// Esta variable solo existe dentro de la funcion. Por lo tanto no puede usarse en el main
	//si quisiera una variable global (que funcione en todos lados), tendria que ir arriba del main. Pero esto no es buena practica
	//nunca hacer globales. Hay que hacer variables constantes. 

	//Funciona al revés tambié, si pusiera una variable de main aquí, no la reconocería la función

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	do {

		cout << question << "(" << low << " - " << high << ")";
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

//FUNCIONES PARA EXAMEN

char AskParImpar(string question) //Esta es una funcion exclusivamente para obtener algo del answer que en este caso es P o I
{

	char answerparimpar;

	do
	{
		cout << "\n" << question << "(P/I)";
		cin >> answerparimpar;

		if (answerparimpar != 'P' && answerparimpar != 'I')
		{
			cout << "Valor no valido, vuelve a intentarlo" << endl;
		}

		else
		{

		}

	} while (answerparimpar != 'P' && answerparimpar != 'I');


	return answerparimpar;



}


char ParImpar()

{
	char gofirst2 = AskParImpar("Deseas elegir Par o Impar? Selecciona P o I respectivamente");

	if (gofirst2 == 'P')
	{

		cout << "Elegiste Par" << endl;

	}

	else

	{
		cout << "Elegiste Impar" << endl;



	}

	//Simulaciond de dado

	cout << "Vamos a tirar un dado" << endl;

	int high = 7;
	int low = 1;


	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = low + (rand() % (high - low));
	int secretNumber = randomNumber;

	cout << "El resultado del dado es: " << secretNumber << endl; //Depuracion
	cout << "\n" << endl;

	if (secretNumber == 2 || secretNumber == 4 || secretNumber == 6)

	{
		cout << "El resultado es Par" << endl;


	}

	else

	{
		cout << "El resultado es Impar" << endl;


	}


	if ((gofirst2 == 'I') && (secretNumber == 1 || secretNumber == 3 || secretNumber == 5))
	{

		cout << "Felicidaes, te toca iniciar la partida" << endl;
		return X;
	}


	if ((gofirst2 == 'P') && (secretNumber == 2 || secretNumber == 4 || secretNumber == 6))
	{
		cout << "Felicidades, te toca iniciar la partida" << endl;
		return X;

	}


	else
	{
		cout << "Perdiste, comenzaras en el segundo turno" << endl;
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
									{0, 4, 8}, };

	const int TOTAL_ROWS = 8;

	//Para regresar al ganador.
	//Logica: el for nes para ir aumentando de fila en fila porque ahí está cada condicion de gane
	//los diferentes IFs es para que se cumpla suponiendo que la X esta en el espacio 0,1,2 y 3,4,5, etc.
	//porque si el espacio 1 es igual al 2 y el 2 al 3, entonces se cumple el win
	for (int row = 0; row < TOTAL_ROWS; row++)
	{

		if ((board[WINNING_POS[row][0]] != EMPTY) && //Para que el espacio no este vacio
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




inline bool isLegal(int move, const vector<char>& board) //funcion para que valide que el jugador esta ingresando un valor en un espacio vacio

{
	bool isLegal = false;

	if (board[move] == EMPTY)
	{
		isLegal = true;
	}

	return isLegal;
		
    //return (board[move] == EMPTY); Esto de aqui es lo mismo que todo lo de arriba
}


int humanMove(const vector<char>& board) //Funcion para que se valide que lo que metio el jugador si sea una casilla no repetida
{

	int move = AskNumber("¿Elige una posición del tablero?", (board.size() - 1), 0);

	while (!isLegal(move, board)) {
		cout << "\nEsa posición ya está ocupada humano tonto.\n";
		move = AskNumber("¿Elige una posición del tablero?", (board.size() - 1), 0);
	}

	cout << "Bien..\n";
	return move;
}

int computerMove(vector<char> board, char computer) // Esta parte es para saber si la compu es la que va a ganar ya en este turno. El board NO va como referencia porque solo quiere hacer simulaciones, no quiere cambiar el tablero de verdad
{
	int move = 0;
	bool foundSpace = false;

	while (!foundSpace && move < board.size()) {

		if (isLegal(move, board))
		{
			board[move] = computer;
			foundSpace = winner(board) == computer;

			if (winner(board) == computer) {
				foundSpace = true;
			}

			board[move] = EMPTY;
		}

		if (!foundSpace)
		{
			move++;
		}
	}

	// Este es el ciclo para que la PC sepa donde poner su valor para que el oponente no gane
	if (!foundSpace)
	{
		move = 0;
		char human = opponent(computer);
		while (!foundSpace && move < board.size()) {

			if (isLegal(move, board))
			{
				board[move] = human;
				foundSpace = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!foundSpace)
			{
				move++;
			}
		}
	}

	//Para que la PC sepa cuales son las mejores posiciones para usar en caso de que no haya ganador todavia
	if (!foundSpace) {
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVE[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 }; //Los valores dentro del vector son los valores dentro del board ordenado con prioridad de ganar. Comenzamos con el centro y luego las esquinas

		while (!foundSpace && i < board.size()) {

			move = BEST_MOVE[i];
			if (isLegal(move, board)) {
				foundSpace = true;
			}

			++i;
		}
	}

	cout << "Usaré la posición " << move << endl;
	return move;

}


void announceWinner(char winner, char human, char computer) //Funcion para anunciar quien es el ganador

{
	if (winner == computer)
	{

		cout << "El ganador es " << winner << endl;
		cout << "El ganador es la PC. Ganaron las maquinas!" << endl;

	}

	else if (winner == human)
	{
		cout << "El ganador es " << winner << endl;
		cout << "Ha ganado el humano" << endl;
	}

	else
	{
		cout << "Es un empate" << endl;
		cout << "Que suerte tienes Humano" << endl;
	}
	
}