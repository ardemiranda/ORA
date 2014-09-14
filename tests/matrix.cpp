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

#include <iostream>
#include "ora.h"
#include <gtest/gtest.h>

// The fixture for testing class Foo.
class MatrixTest: public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	MatrixTest() {
		// You can do set-up work for each test here.
	}

	virtual ~MatrixTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(MatrixTest, MethodAdd) {
	ORA::Matrix<double> A;
	ORA::Matrix<double> B;
	ORA::Matrix<double> C;


	A.set(0, 0, 1);
	A.set(1, 1, 1);

	B.set(0, 0, 1);
	B.set(1, 1, 1);

	C = A + B;

	double expected[2][2] = {
		{2, 0},
		{0, 2}
	};

	EXPECT_EQ(A.rows(), C.rows());
	EXPECT_EQ(A.cols(), C.cols());

	for (int i = 0; i < C.rows(); i++) {
		for (int j = 0; j < C.cols(); j++) {
			EXPECT_EQ(expected[i][j], C.get(i, j));
		}
	}
}


TEST_F(MatrixTest, MethodSub) {
	ORA::Matrix<double> A;
	ORA::Matrix<double> B;
	ORA::Matrix<double> C;


	A.set(0, 0, 1);
	A.set(1, 1, 1);

	B.set(0, 0, 1);
	B.set(1, 1, 1);

	C = A - B;

	double expected[2][2] = {
		{0, 0},
		{0, 0}
	};

	EXPECT_EQ(A.rows(), C.rows());
	EXPECT_EQ(A.cols(), C.cols());

	for (int i = 0; i < C.rows(); i++) {
		for (int j = 0; j < C.cols(); j++) {
			EXPECT_EQ(expected[i][j], C.get(i, j));
		}
	}
}


TEST_F(MatrixTest, MethodMultiplySquare) {
	double expected[2][2] = {
		{1, 0},
		{0, 1}
	};


	ORA::Matrix<double> A;
	ORA::Matrix<double> B;
	ORA::Matrix<double> C;

	A.set(0, 0, 1);
	A.set(1, 1, 1);

	B.set(0, 0, 1);
	B.set(1, 1, 1);

	C = A * B;

	EXPECT_EQ(A.rows(), C.rows());
	EXPECT_EQ(A.cols(), C.cols());

	for (int i = 0; i < C.rows(); i++) {
		for (int j = 0; j < C.cols(); j++) {
			EXPECT_EQ(expected[i][j], C.get(i, j));
		}
	}
}


TEST_F(MatrixTest, MethodMultiply) {
	double expected[3][2] = {
		{1, 0},
		{0, 1},
		{0, 1}
	};

	ORA::Matrix<double> A;
	ORA::Matrix<double> B;
	ORA::Matrix<double> C;


	A.set(0, 0, 1);
	A.set(1, 1, 1);
	A.set(2, 1, 1);

	B.set(0, 0, 1);
	B.set(1, 1, 1);

	C = A * B;

	EXPECT_EQ(A.rows(), C.rows());
	EXPECT_EQ(B.cols(), C.cols());

	for (int i = 0; i < C.rows(); i++) {
		for (int j = 0; j < C.cols(); j++) {
			EXPECT_EQ(expected[i][j], C.get(i, j));
		}
	}
}

TEST_F(MatrixTest, MethodTransposed) {
	double test[3][2] = {
		{1, 0},
		{0, 1},
		{0, 1}
	};
	double expected[2][3] = {
		{1, 0, 0},
		{0, 1, 1}
	};

	ORA::Matrix<double> A;
	ORA::Matrix<double> B;
	A.set_all(3, 2, (double **) test);

	B = A.transposed();

	EXPECT_EQ(A.rows(), B.cols());
	EXPECT_EQ(A.cols(), B.rows());

	for (int i = 0; i < B.rows(); i++) {
		for (int j = 0; j < B.cols(); j++) {
			EXPECT_EQ(expected[i][j], B.get(i, j));
		}
	}
}
