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
	std::cout << "\n\t * ��������-������ *";
	std::cout << "\n\t ===================\n";
	std::cout << "\n `��������-������ � �� ��� � ������ i����i��.\n";
	std::cout << " `����i ���i��i� ��� � �������� ������ ������� �� �� ���i� ������������� ������.\n";
	std::cout << " `� ���� ���� ������� �� ����� ��� ������� ����i� ��i�, ����� �� �������� ���i��� �i����� �������.\n";
	std::cout << " `� ��������� ��i�i ��� �� ������ �� �����������i.\n";
	std::cout << " `����� ���� �������� �� ������i�i��� ���� ���������� ���������� ����� �i��� �� ��������.";
	menu();

	return 0;
}

void menu() {
	std::cout << "\n\n\t����i�� '1' ��� ��������� ������.\n\t����i�� '2' ��� ����� �����.\n\t����i�� '3' ��� ����� ������i���.\n\t����i�� '4' ��� ���������.\n\t->";
	std::cin >> m;
	if (m < '1' || m > '4') {
		do
		{
			std::cin.ignore(256, '\n');
			std::cout << "\n\t����i�� 1, 2, 3 ��� 4!\n\t->"; std::cin >> m; std::cin.ignore(256, '\n');
		} while (m < '1' || m > '4');
	}
	switch (m) {
	case '1': rules(); break;
	case '2': game(); break;
	case '3': game(); break;
	case '4': std::cout << "\n\t�i����� �����i� - " << rounds << "\n\t������� � ������� ������ - " << w1 << "\n\t������� � ������� ������ - " << w2 << "\n\t�i��� - " << ties << "\n\n\t������i�� Enter ��� ������!"; std::cin.ignore(); std::cin.get();
	};
}

void rules() {
	system("cls");
	std::cout << " \t\t****�������!****\n";
	std::cout << " � ��� ������ ����� ��� �������i�.\n";
	std::cout << " ����� � ��� ����� ������ (X ��� 0) �� ������� ���� � ��������� ����i�����. \n";
	std::cout << " I����� ���� �i������ �� 9 ���������i�-���i���. ������� ����� ���i��� ������� �� ����� (1-9). \n";
	std::cout << " �������� ���, ��� ������ ������ �������� ����i���i� �i ����� ������� �� ����������i, ��������i ��� �ia�����i.\n";
	std::cout << "\n������� �����\n";
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
		std::cout << " ����i�� ������ ������� ������ (� ��� 0) - ";
		std::cin >> p1;
	} while (p1 != 'X' && p1 != '0');

	p1 == '0' ? c = p2 = 'X' : c = p2 = '0';

	char cells[9] = { ' ', ' ', ' ', ' ', ' ', ' ' , ' ', ' ', ' ' };

	std::cout << "\t" << p1 << " - ������ ������� ������\n\t" << p2 << " - ����� ������� ������\n �������� ���!\n";
	std::cout << " ������i�� Enter, ��� ����������!";
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
	std::cout << " �i� ������� ������! ����i�� ����� ��i����� (1-9) - ";
	while (true) {
		std::cin >> cellindex;

		if (cellindex <= 9 && cellindex >= 1) {
			if (cells[cellindex - 1] == ' ') {
				cells[cellindex - 1] = p1;
				break;
			}
			else {
				std::cout << " ��i����� �������! ����i�� i���� ����� - ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << " ���� ��i����� �� i���! ����i�� i���� ����� - ";
		}
	}
	std::cout << " ������i�� Enter, ��� ����������!";
	std::cin.ignore();
	std::cin.get();
}

void player2(char* cells) {
	system("cls");
	int cellindex;
	board(cells);
	std::cout << " �i� ������� ������! ����i�� ����� ��i����� (1-9) - ";
	while (true) {

		std::cin >> cellindex;

		if (cellindex <= 9 && cellindex >= 1) {
			if (cells[cellindex - 1] == ' ') {
				cells[cellindex - 1] = p2;
				break;
			}
			else {
				std::cout << " ��i���� �������! ����i�� i���� ����� - ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << " ���� ��i����� �� i���! ����i�� i���� ����� - ";
		}
	}
	std::cout << " ������i�� Enter, ��� ����������!";
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
{   //��������
	if (cells[0] != ' ' && cells[0] == cells[1] && cells[1] == cells[2]) {
		if (cells[0] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	else if (cells[3] != ' ' && cells[3] == cells[4] && cells[4] == cells[5]) {
		if (cells[3] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	else if (cells[6] != ' ' && cells[6] == cells[7] && cells[7] == cells[8]) {
		if (cells[6] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	//���������
	else if (cells[0] != ' ' && cells[0] == cells[3] && cells[3] == cells[6]) {
		if (cells[0] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	else if (cells[1] != ' ' && cells[1] == cells[4] && cells[4] == cells[7]) {
		if (cells[1] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	else if (cells[2] != ' ' && cells[2] == cells[5] && cells[5] == cells[8]) {
		if (cells[2] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	//��������
	else if (cells[0] != ' ' && cells[0] == cells[4] && cells[4] == cells[8]) {
		if (cells[0] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}
	else if (cells[2] != ' ' && cells[2] == cells[4] && cells[4] == cells[6]) {
		if (cells[2] == p1) { std::cout << "\t�������� ������ �������!\n"; w1++; }
		else { std::cout << "\t�������� ������ �������!\n"; w2++; }
	}

	else { return 0; }
	board(cells);
	return 1;
}

bool tie(char* cells) {
	for (int i = 0; i < 9; i++) {
		if (cells[i] == ' ') return 0;
	}
	std::cout << "\t�i���!\n";
	ties++;
	return 1;
}

