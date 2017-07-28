#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int row, col;
	char dir;

	int _size;
	int *_data;
	int findPosition();
public:
	Matrix(int size);
	~Matrix();
	void fill();
	friend ostream& operator<< (ostream& out, const Matrix& m);
};

Matrix::Matrix(int size) : _size(size), row(-1), col(0), dir('D') {
	_data = new int[size *size];
	memset(_data, 0, sizeof(int)*_size*_size);
}

Matrix::~Matrix() {
	delete[] _data;
}

int Matrix::findPosition() {
	switch (dir) {
	case 'D':
		if (row < _size - 1 && _data[(row + 1)*_size + col] == 0)
			row++;
		else {
			dir = 'R';
			col++;
		}
		break;
	case 'R':
		if (col < _size - 1 && _data[row*_size + col + 1] == 0)
			col++;
		else {
			dir = 'U';
			row--;
		}
		break;
	case 'U':
		if (row > 0 && _data[(row - 1)*_size + col] == 0)
			row--;
		else {
			dir = 'L';
			col--;
		}
		break;
	case 'L':
		if (col > 0 && _data[row*_size + col - 1] == 0)
			col--;
		else {
			dir = 'D';
			row++;
		}
		break;
	}
	return row * _size + col;
}

ostream& operator<< (ostream& out, const Matrix& m) {
	for (int r = 0; r < m._size; r++) {
		for (int c = 0; c < m._size; c++)
			cout << *(m._data + r*m._size + c) << '\t';
		cout << endl;
	}
	return out;
}

void Matrix::fill() {
	for (int num = 1; num <= _size*_size; num++) {
		int pos = findPosition();
		_data[pos] = num;
	}
}

int main() {
	cout << "Please input N: ";
	int size;
	cin >> size;
	Matrix obj(size);
	obj.fill();
	cout << obj;
	return 0;
}