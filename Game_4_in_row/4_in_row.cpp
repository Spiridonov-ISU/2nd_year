#include <iostream>

using namespace std;

enum Cell 
{
	EMPTY,
	RED,
	YELLOW
};

const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int DIR_NUMBER = 4;
const int WIN_LENGTH = 4;

class Field 
{
private:
	int FIELD_WIDTH = 6;
	int FIELD_HEIGHT = 7;
	Cell cells[6][7];
	bool isRedTurn;
	Cell winner;

public:
	Field(bool isRedFirst);
	void clear(bool isRedFirst);
	bool makeTurn(int column);
	void checkWinner();
	bool isWon(bool red) const;
	bool isOver() const;
	Cell getCell(int i, int j) const;
	bool isRedTurnNow() const;
	void print() const;
	void printResult() const;
};

Field::Field(bool isRedFirst) 
{
	clear(isRedFirst);
}

void Field::clear(bool isRedFirst)
{
	isRedTurn = isRedFirst;
	winner = EMPTY;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			cells[i][j] = EMPTY;
}

bool Field::makeTurn(int column)
{
	if (winner != EMPTY || column < 1 || column > FIELD_HEIGHT)
		return false;
	int j = column - 1;
	for (int i = 0; i < FIELD_WIDTH; i++)
		if (getCell(i, j) == EMPTY)
		{
			cells[i][j] = isRedTurn ? RED : YELLOW;
			checkWinner();
			isRedTurn = !isRedTurn;
			return true;
		}
	return false;
}

void Field::checkWinner()
{
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			Cell start = getCell(i, j);
			if (start == EMPTY) continue;
			for (int dir = 0; dir < DIR_NUMBER; dir++)
			{
				int length = 0, iline = i, jline = j;
				while (++length < WIN_LENGTH)
				{
					iline += di[dir];
					jline += dj[dir];
					if (iline < 0 || iline >= FIELD_WIDTH || jline < 0 || jline >= FIELD_HEIGHT)
						break;
					if (getCell(iline, jline) != start) break;
				}
				if (length == WIN_LENGTH)
				{
					winner = start;
					return;
				}
			}
		}
}

bool Field::isOver() const
{
	if (winner != EMPTY)
		return true;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			if (getCell(i, j) == EMPTY)
				return false;
	return true;
}

/////
bool Field::isWon(bool red) const 
{
	Cell cell;
	if (red) {
		cell = RED;
	}
	else {
		cell = YELLOW;
	}
	if (winner == cell) {
		return true;
	}
	else {
		return false;
	}
}

Cell Field::getCell(int i, int j) const 
{
	return cells[i][j];
}

bool Field::isRedTurnNow() const 
{
	return isRedTurn;
}

void Field::print() const 
{
	for (int i = FIELD_WIDTH - 1; i >= 0; i--)
	{
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			if (getCell(i, j) == RED) {
				cout << "R ";
			}
			else if (getCell(i, j) == YELLOW) {
				cout << "Y ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

void Field::printResult() const 
{
	if (isWon(true)) {
		cout << "Победа красного!";
	}
	else if (!isWon(true)) {
		cout << "Победа желтого!";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Field field(true);
	while (!field.isOver())
	{
		field.print();
		cout << "Ходит " << (field.isRedTurnNow() ? "красный" : "желтый") << " игрок, введите ход (1-7)" << endl;
		int column; cin >> column;
		field.makeTurn(column);
	}
	field.printResult();
	return 0;
}