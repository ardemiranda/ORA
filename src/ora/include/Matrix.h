#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>


namespace ORA {

#define _MATRIX_TEMPLATE template <class TYPE_DATA>
#define _MATRIX_METHOD(ret, name) _MATRIX_TEMPLATE ret Matrix<TYPE_DATA>::name
#define _MATRIX Matrix<TYPE_DATA>

_MATRIX_TEMPLATE
class Matrix {
private:
	int m, n;
	TYPE_DATA **values;

public:

	typedef TYPE_DATA (*callback_iterate)(int i, int j, TYPE_DATA A);

	Matrix(int m, int n) : m(m), n(n), values(0) {
		if (rows() <= 0 || cols() <= 0) {
			/// @fixme exception
		}


		values = new TYPE_DATA*[m];
		for (int i = 0; i < m; i++) {
			values[i] = new TYPE_DATA[n];
			for (int j = 0; j < m; j++) {
				values[i][j] = 0;
			}
		}
	}
	~Matrix() {
		//delete values;
	}
	void init();
	void init(double **values);
	int rows() { return m; };
	int cols() { return n; };
	_MATRIX operator +(_MATRIX &B);
	_MATRIX operator -(_MATRIX &B);
	_MATRIX operator *(_MATRIX &B);
	_MATRIX operator /(_MATRIX &B);
	_MATRIX transposed();
	void print();
	void set(int i, int j, TYPE_DATA value);
	TYPE_DATA get(int i, int j);

private:

};

_MATRIX_METHOD(void, init)() {
	//_iterateMatrix(_initNull);
}

_MATRIX_METHOD(void, init)(double **values) {
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			this->values[i][j] = values[i][j];
		}
	}
}



_MATRIX_METHOD(_MATRIX, operator +)(_MATRIX &B) {
	if (rows() != B.rows() || cols() != B.cols()) {
		/// @fixme exception
	}
	_MATRIX C(rows(), cols());

	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			set(i, j, get(i, j) + B.get(i, j));
		}
	}

	return C;
}

_MATRIX_METHOD(_MATRIX, operator -)(_MATRIX &B) {
	if (rows() != B.rows() || cols() != B.cols()) {
		/// @fixme exception
	}

	_MATRIX C(rows(), cols());

	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			set(i, j, get(i, j) - B.get(i, j));
		}
	}

	return C;
}

_MATRIX_METHOD(_MATRIX, operator *)(_MATRIX &B) {
	if (cols() != B.rows()) {
		/// @fixme exception
	}
	_MATRIX C(rows(), B.cols());

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
	_MATRIX C(rows(), B.cols());


	return C;
}

_MATRIX_METHOD(_MATRIX, transposed)() {
	Matrix<TYPE_DATA> C(cols(), rows());

	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			C.set(j, i, get(i, j));
		}
	}

	return C;
}

_MATRIX_METHOD(void, set)(int i, int j, TYPE_DATA value) {
	values[i][j] = value;
}

_MATRIX_METHOD(TYPE_DATA, get)(int i, int j) {
	if (i >= rows() || j >= cols()) {
		/// @fixme exception
	}
	return values[i][j];
}



_MATRIX_METHOD(void, print)() {
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < cols(); j++) {
			std::cout << get(i, j) << " ";
		}
		std::cout << std::endl;
	}
}


};

#endif
