/**
 * This file is part of ORA.
 *
 * ORA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ORA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ORA.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
#include <map>


namespace ORA {

#define _MATRIX_TEMPLATE template <class TYPE_DATA>
#define _MATRIX_METHOD(ret, name) _MATRIX_TEMPLATE ret Matrix<TYPE_DATA>::name
#define _MATRIX Matrix<TYPE_DATA>

_MATRIX_TEMPLATE
class Matrix {
private:
	int m, n;
	std::map<int, std::map<int, TYPE_DATA>> values;

public:

	Matrix() : m(0), n(0) {
	}
	~Matrix() {
	}
	int rows() { return m; };
	int cols() { return n; };
	_MATRIX operator +(_MATRIX &B);
	_MATRIX operator -(_MATRIX &B);
	_MATRIX operator *(_MATRIX &B);
	_MATRIX operator /(_MATRIX &B);
	_MATRIX transposed();
	void print();
	void set(int i, int j, TYPE_DATA value);
	void set_all(int m, int n, TYPE_DATA values[]);
	TYPE_DATA * get_all();
	TYPE_DATA get(int i, int j);


private:

};


_MATRIX_METHOD(_MATRIX, operator +)(_MATRIX &B) {
	if (rows() != B.rows() || cols() != B.cols()) {
		/// @fixme exception
	}
	_MATRIX C;

	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			C.set(i, j, get(i, j) + B.get(i, j));
		}
	}

	return C;
}

_MATRIX_METHOD(_MATRIX, operator -)(_MATRIX &B) {
	if (rows() != B.rows() || cols() != B.cols()) {
		/// @fixme exception
	}

	_MATRIX C;

	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			C.set(i, j, get(i, j) - B.get(i, j));
		}
	}

	return C;
}

_MATRIX_METHOD(_MATRIX, operator *)(_MATRIX &B) {
	if (cols() != B.rows()) {
		/// @fixme exception
	}
	_MATRIX C;

	TYPE_DATA value;
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			value = 0;
			for (int k = 0; k < cols(); k++) {
				value += get(i, k) * B.get(k, j);
			}
			C.set(i, j, value);
		}
	}


	return C;
}

_MATRIX_METHOD(_MATRIX, operator /)(_MATRIX &B) {
	if (cols() != B.rows()) {
		/// @fixme exception
	}
	_MATRIX C;

	return C;
}

_MATRIX_METHOD(_MATRIX, transposed)() {
	_MATRIX C;

	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			C.set(j, i, get(i, j));
		}
	}

	return C;
}

_MATRIX_METHOD(void, set)(int i, int j, TYPE_DATA value) {
	if (value == 0) {
		values[i].erase(j);
		if (! values[i].size()) {
			values.erase(i);
		}
	}

	values[i][j] = value;

	if (++i > m) {
		m = i;
	}
	if (++j > n) {
		n = j;
	}
}

_MATRIX_METHOD(void, set_all)(int m, int n, TYPE_DATA values[]) {
	if (n == 1) {
		for (int i = 0; i < m; i++) {
			set(i, 0, values[i]);
		}
		return ;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			set(i, j, values[m * i + j]);
		}
	}
}

_MATRIX_METHOD(TYPE_DATA *, get_all)() {
	double *values;
	if (cols() == 1) {
		values = new double[rows()];
		for (int i = 0; i < rows(); i++) {
			values[i] = get(i, 0);
		}

		return values;
	}

	values = new double[rows() * cols()];
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			values[rows() * i + j] = get(i, j);
		}
	}
	return values;
}

_MATRIX_METHOD(TYPE_DATA, get)(int i, int j) {
	if (i >= rows() || j >= cols()) {
		/// @fixme exception
	}

	return values[i][j];
}

_MATRIX_METHOD(void, print)() {
	std::cout << "Print " << rows() << " x " << cols() << std::endl;
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			std::cout << get(i, j) << " ";
		}
		std::cout << std::endl;
	}
}



};

#endif
