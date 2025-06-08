#include <iostream>
#include <cstdlib>
#include <ctime>

void menu();
char m;

int rounds = 0;
int w1 = 0;
int w2 = 0;
int ties = 0;

void rules();
void game();

void board(char* cells);
void player1(char* cells);
char p1;
void player2(char* cells);
char p2;
void computer(char* cells);
char c;

bool winner(char* cells);
bool tie(char* cells);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ukrainian");
	system("Color 0B");
	std::cout << "\t ===================";
	std::cout << "\n\t * Хрестики-нулики *";
	std::cout << "\n\t ===================\n";
	std::cout << "\n `Хрестики-нулики – це гра з довгою iсторiєю.\n";
	std::cout << " `Першi варiацiї гри в хрестики нулики виникли ще за часiв стародавнього Єгипту.\n";
	std::cout << " `З того часу правила та назва гри зазнали безлiч змiн, проте її сучасний варiант вiдомий кожному.\n";
	std::cout << " `У сучасному свiтi гра не втрачає своєї актуальностi.\n";
	std::cout << " `Через свою простоту та зрозумiлiсть вона залишається популярною серед дiтей та дорослих.";
	menu();

	return 0;
}

void menu() {
	std::cout << "\n\n\tВведiть '1' для перегляду правил.\n\tВведiть '2' щоб грати удвох.\n\tВведiть '3' щоб грати самостiйно.\n\tВведiть '4' щоб завершити.\n\t->";
	std::cin >> m;
	if (m < '1' || m > '4') {
		do
		{
			std::cin.ignore(256, '\n');
			std::cout << "\n\tВведiть 1, 2, 3 або 4!\n\t->"; std::cin >> m; std::cin.ignore(256, '\n');
		} while (m < '1' || m > '4');
	}
	switch (m) {
	case '1': rules(); break;
	case '2': game(); break;
	case '3': game(); break;
	case '4': std::cout << "\n\tЗiграно раундiв - " << rounds << "\n\tПеремог у першого гравця - " << w1 << "\n\tПеремог у другого гравця - " << w2 << "\n\tНiчиїх - " << ties << "\n\n\tНатиснiть Enter для виходу!"; std::cin.ignore(); std::cin.get();
	};
}

void rules() {
	system("cls");
	std::cout << " \t\t****Правила!****\n";
	std::cout << " У гру можуть грати двоє учасникiв.\n";
	std::cout << " Кожен з них обирає символ (X або 0) та вводить його з латинської клавiатури. \n";
	std::cout << " Iгрове поле дiлиться на 9 квадратикiв-комiрок. Гравець обирає комiрку вводячи її номер (1-9). \n";
	std::cout << " Перемагає той, хто перший складе виграшну комбiнацiю зi свого символа по горизонталi, вертикалi або дiaгоналi.\n";
	std::cout << "\nГральна дошка\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << 1 << "  |  " << 2 << "  |  " << 3 << " \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << 4 << "  |  " << 5 << "  |  " << 6 << " \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << 7 << "  |  " << 8 << "  |  " << 9 << " \n";
	std::cout << "     |     |     \n";
	menu();
}

void game() {
	system("cls");
	m == '2' ? system("Color 0E") : system("Color 0A");
	bool running = 1;
	do {
		std::cout << " Оберiть символ першого гравця (Х або 0) - ";
		std::cin >> p1;
	} while (p1 != 'X' && p1 != '0');

	p1 == '0' ? c = p2 = 'X' : c = p2 = '0';

	char cells[9] = { ' ', ' ', ' ', ' ', ' ', ' ' , ' ', ' ', ' ' };

	std::cout << "\t" << p1 << " - символ першого гравця\n\t" << p2 << " - сивол другого гравця\n Починаємо гру!\n";
	std::cout << " Натиснiть Enter, щоб продовжити!";
	std::cin.ignore();
	std::cin.get();
	while (1) {
		player1(cells);
		if (winner(cells) == 1) { running = 0; break; }
		else if (tie(cells) == 1) { board(cells); running = 0; break; }
		if (m == '2') {
			player2(cells);
			if (winner(cells) == 1) { running = 0; break; }
			else if (tie(cells) == 1) { board(cells); running = 0; break; }
		}
		else if (m == '3')
			computer(cells);
		if (winner(cells) == 1) { running = 0; break; }
		else if (tie(cells) == 1) { board(cells); running = 0; break; }
	}
	rounds++;
	menu();
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

void player1(char* cells) {
	system("cls");
	int cellindex;
	board(cells);
	std::cout << " Хiд першого гравця! Оберiть номер клiтинки (1-9) - ";
	while (true) {
		std::cin >> cellindex;

		if (cellindex <= 9 && cellindex >= 1) {
			if (cells[cellindex - 1] == ' ') {
				cells[cellindex - 1] = p1;
				break;
			}
			else {
				std::cout << " Клiтинка зайнята! Оберiть iнший номер - ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << " Такої клiтинки не iснує! Оберiть iнший номер - ";
		}
	}
	std::cout << " Натиснiть Enter, щоб продовжити!";
	std::cin.ignore();
	std::cin.get();
}

void player2(char* cells) {
	system("cls");
	int cellindex;
	board(cells);
	std::cout << " Хiд другого гравця! Оберiть номер клiтинки (1-9) - ";
	while (true) {

		std::cin >> cellindex;

		if (cellindex <= 9 && cellindex >= 1) {
			if (cells[cellindex - 1] == ' ') {
				cells[cellindex - 1] = p2;
				break;
			}
			else {
				std::cout << " Клiтика зайнята! Оберiть iнший номер - ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << " Такої клiтинки не iснує! Оберiть iнший номер - ";
		}
	}
	std::cout << " Натиснiть Enter, щоб продовжити!";
	std::cin.ignore();
	std::cin.get();
}

void computer(char* cells)
{
	int cellindex;
	while (true) {
		cellindex = rand() % 9;
		if (cells[cellindex] == ' ') {
			cells[cellindex] = c;
			break;
		}
	}
}

bool winner(char* cells)
{   //горизонт
	if (cells[0] != ' ' && cells[0] == cells[1] && cells[1] == cells[2]) {
		if (cells[0] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	else if (cells[3] != ' ' && cells[3] == cells[4] && cells[4] == cells[5]) {
		if (cells[3] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	else if (cells[6] != ' ' && cells[6] == cells[7] && cells[7] == cells[8]) {
		if (cells[6] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	//вертикаль
	else if (cells[0] != ' ' && cells[0] == cells[3] && cells[3] == cells[6]) {
		if (cells[0] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	else if (cells[1] != ' ' && cells[1] == cells[4] && cells[4] == cells[7]) {
		if (cells[1] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	else if (cells[2] != ' ' && cells[2] == cells[5] && cells[5] == cells[8]) {
		if (cells[2] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	//діагональ
	else if (cells[0] != ' ' && cells[0] == cells[4] && cells[4] == cells[8]) {
		if (cells[0] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}
	else if (cells[2] != ' ' && cells[2] == cells[4] && cells[4] == cells[6]) {
		if (cells[2] == p1) { std::cout << "\tПеремагає перший гравець!\n"; w1++; }
		else { std::cout << "\tПеремагає другий гравець!\n"; w2++; }
	}

	else { return 0; }
	board(cells);
	return 1;
}

bool tie(char* cells) {
	for (int i = 0; i < 9; i++) {
		if (cells[i] == ' ') return 0;
	}
	std::cout << "\tНiчия!\n";
	ties++;
	return 1;
}
