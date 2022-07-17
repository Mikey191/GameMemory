//игра "память"
//открываем ячейку и должны найти такуюже
//если не отгадали поле приходит в первоначальное состояние
//и так повторяем пока не найдем все пары
#include <iostream>
#include <ctime>
using namespace std;

char symb[] = "ABCDEFGHIJKLMNOPQR";//массив с данными которые будут заполнятся в поле нужно максимум 18 знаков, так как максимальный размер поля 36 клеток 36/2 = 18
int side = 0;
char field[6][6];
bool checkField[6][6];//массив который мы будем заполнять фолсами, а потом менять значение на тру, если первый выбор и второй выбор будет совпадать


void setLvl() {
	int lvl;//переменная для выбора сложности. либо 4х4 поле либо 6х6
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

void shake() { //функция кторая размешивает наш заполненный массив
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
	return true;//пока есть хоть один элемент в булевом массиве фаол, чек будет возвращать фолс, как только все станут тру, чек вернет тру, и игра закончится
}

void printField(int x1, int y1, int x2, int y2) {
	system("cls");
	for (size_t i = 0; i < side; i++) {
		for (size_t j = 0; j < side; j++)
			if ((i == x1 && j == y1 || i == x2 && j == y2) || checkField[i][j])//булев массив в этом иФЕ для того что бы он все время показывал нам угаданные уже элементы
				cout << field[i][j];
			else
				cout << " ";
		cout << endl;
	}
		
}

void game() {
	int x1, x2, y1, y2;
	int k = 0;//кол-во ходов
	while (!check()) {//пока функция check возвращает фаолс игра продолжается, как только вернет тру, игра заканчивается, ты победитель
		k++;//считаем кол-во ходов
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
	setLvl();//выбор сложности
	fillField();//заполнение поля
	cout << endl;
	cout << "Shake" << endl;
	shake();//рандомное перемешивание заполненного поля
	game();//реализация самой игры

	return 0;
}