//���� "������"
//��������� ������ � ������ ����� �������
//���� �� �������� ���� �������� � �������������� ���������
//� ��� ��������� ���� �� ������ ��� ����
#include <iostream>
#include <ctime>
using namespace std;

char symb[] = "ABCDEFGHIJKLMNOPQR";//������ � ������� ������� ����� ���������� � ���� ����� �������� 18 ������, ��� ��� ������������ ������ ���� 36 ������ 36/2 = 18
int side = 0;
char field[6][6];
bool checkField[6][6];//������ ������� �� ����� ��������� �������, � ����� ������ �������� �� ���, ���� ������ ����� � ������ ����� ����� ���������


void setLvl() {
	int lvl;//���������� ��� ������ ���������. ���� 4�4 ���� ���� 6�6
	cout << "Set level:" << endl;
	cout << "1 - easy (field 4x4)" << endl;
	cout << "2 - hard (field 6x6)" << endl;
	cin >> lvl;
	if (lvl == 1)
		side = 4;
	else
		side = 6;
}

void fillField() {
	cout << "side = " << side << endl;
	int k = 0;
	for (size_t i = 0; i < side; i++) {
		for (size_t j = 0; j < side; j++)
		{
			field[i][j] = symb[k % (side * side / 2)];
			k++;
			checkField[i][j] = false;
		}
	}

	for (size_t i = 0; i < side; i++) {
		for (size_t j = 0; j < side; j++)
		{
			cout << field[i][j];
		}cout << endl;
	}
	cout << "Check Field: " << endl;
	for (size_t i = 0; i < side; i++) {
		for (size_t j = 0; j < side; j++)
		{
			cout << checkField[i][j];
		}cout << endl;
	}
		
}

void shake() { //������� ������ ����������� ��� ����������� ������
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int x1 = rand() % side;
		int x2 = rand() % side;
		int y1 = rand() % side;
		int y2 = rand() % side;
		char temp = field[x1][y1];
		field[x1][y1] = field[x2][y2];
		field[x2][y2] = temp;
	}

	for (size_t i = 0; i < side; i++) {
		for (size_t j = 0; j < side; j++)
		{
			cout << field[i][j];
		}cout << endl;
	}
}

bool check() {
	for (size_t i = 0; i < side; i++)
		for (size_t j = 0; j < side; j++)
			if (checkField[i][j] == false)
				return false;
	return true;//���� ���� ���� ���� ������� � ������� ������� ����, ��� ����� ���������� ����, ��� ������ ��� ������ ���, ��� ������ ���, � ���� ����������
}

void printField(int x1, int y1, int x2, int y2) {
	system("cls");
	for (size_t i = 0; i < side; i++) {
		for (size_t j = 0; j < side; j++)
			if ((i == x1 && j == y1 || i == x2 && j == y2) || checkField[i][j])//����� ������ � ���� ��� ��� ���� ��� �� �� ��� ����� ��������� ��� ��������� ��� ��������
				cout << field[i][j];
			else
				cout << " ";
		cout << endl;
	}
		
}

void game() {
	int x1, x2, y1, y2;
	int k = 0;//���-�� �����
	while (!check()) {//���� ������� check ���������� ����� ���� ������������, ��� ������ ������ ���, ���� �������������, �� ����������
		k++;//������� ���-�� �����
		cout << "enter x1 and y1: ";
		cin >> x1 >> y1;
		cout << "enter x2 and y2: ";
		cin >> x2 >> y2;
		if (field[x1][y1] == field[x2][y2]) {
			checkField[x1][y1] = true;
			checkField[x2][y2] = true;
		}
		printField(x1, y1, x2, y2);
	}
	cout << "\t\t CONGRATULATIONS" << endl;
	cout << k << " steps to win..." << endl;
}

int main() {
	setLvl();//����� ���������
	fillField();//���������� ����
	cout << endl;
	cout << "Shake" << endl;
	shake();//��������� ������������� ������������ ����
	game();//���������� ����� ����

	return 0;
}