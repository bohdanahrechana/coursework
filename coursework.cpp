#include <iostream>

void board(char* cells);
void player1(char* cells, char p1);
void player2(char* cells, char p2);
//bool winner();
//bool tie();

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	char p1;
	char p2;
	do {
		std::cout << "Оберiть символ першого гравця (Х або 0) -  ";
		std::cin >> p1;
	} while (p1 != 'X' && p1 != '0');

	do {
		std::cout << "Оберiть символ другого гравця (Х або 0) - ";
		std::cin >> p2;
	} while (p2 != 'X' && p2 != '0' || p2 == p1);

	char cells[9] = { ' ', ' ', ' ', ' ', ' ', ' ' , ' ', ' ', ' ' };

	std::cout << p1 << " - символ першого гравця\n" << p2 << " - сивол другого гравця\nПочинаємо гру!\n";
	board(cells);
	system("pause");
	player1(cells, p1);
	player2(cells, p2);
}

void board(char* cells) {
	std::cout << "     |     |     \n";
	std::cout << "  " << cells[0] << "  |  " << cells[1] << "  |  " << cells[2] << " \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << cells[3] << "  |  " << cells[4] << "  |  " << cells[5] << " \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << cells[6] << "  |  " << cells[7] << "  |  " << cells[8] << " \n";
	std::cout << "     |     |     \n";
}

void player1(char* cells, char p1) {
	system("cls");
	int cellindex;
	std::cout << "Хiд першого гравця! Оберiть номер клiтинки (1-9) - ";
	while (true) {
		std::cin >> cellindex;

		if (cellindex <= 9 && cellindex >= 1) {
			if (cells[cellindex - 1] == ' ') {
				cells[cellindex - 1] = p1;
				board(cells); break;
			}
			else {
				std::cout << "Клiтинка зайнята! Оберiть iнший номер - ";
			}
		}
		else { std::cout << "Такої клiтинки не iснує! Оберiть iнший номер - "; }
	}
	system("pause");
}

void player2(char* cells, char p2) {
	system("cls");
	int cellindex;
	std::cout << "Хiд другого гравця! Оберiть номер клiтинки (1-9) - ";
	while (true) {

		std::cin >> cellindex;

		if (cellindex <= 9 && cellindex >= 1) {
			if (cells[cellindex - 1] == ' ') {
				cells[cellindex - 1] = p2;
				board(cells); break;
			}
			else {
				std::cout << "Клiтинка зайнята! Оберiть iнший номер - ";
			}
		}
		else { std::cout << "Такої клiтинки не iснує! Оберiть iнший номер - "; }
	}
	system("pause");
}
