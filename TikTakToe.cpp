
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

const char EMPTY = ' '; //Constante global para determinar el valor en los espacios que en este caso es vacio
const char  X = 'X'; //Creamos una variable global porque es un valor que es parte del juego
const char  O = 'O'; //Creamos una variable global porque es un valor que es parte del juego
const char NO_ONE = 'N';
const char TIE = 'T';

int main()
{
	
	char player = humansymbol(); //Para que tome el valor de la funcion que creamos abajo en caso de querer comenzar primero
	char computer = opponent(player); //Para que tome el valor contrario que elija el jugador usando la funcion de opponent
	char turn = X ; //porque es mas natural que el juego inicie con la X. Toma su valor de la constante global


	const int NUM_SQUARES = 9; //Contsante para declarar el tamaño
	vector<char> board(NUM_SQUARES, EMPTY); /// 10 es el numero de espacios y los espacios van a estar vacios

	//Mostrar Instrucciones
	instrucciones();
	
   //Funcion para que el jugador elija que letra quiere usar

	while (winner() == NO_ONE)


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


//Tarea: acabar la funcion y que me retorne X,O,NONE o TIE. Meter Board como Referencia y no como copia, es decir, hacerla constante(?)
//Tarea: Solo es crear la funcion para que me retorne lo de abajo. 
//Tarea: Para vlidar que jale, crear una nueva linea de mi vector board y agregarle valores para saber si sirve. board = {x,x,x,0,0,0...etc.)

char winner(board)
{

	return X;
	return O;
	return NO_ONE;
	return TIE;	

}

