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
#include <gtest/gtest.h>

#include "ora.h"

// The fixture for testing class Foo.
class GaussTest: public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	GaussTest() {
		// You can do set-up work for each test here.
	}

	virtual ~GaussTest() {
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

TEST_F(GaussTest, MethodExec) {

	double inputA[9] = {
		5, -2, 3,
		-3, 9, 1,
		2, -1, -7,
	};
	double input_b[3] = {
		-1,
		2,
		3
	};
	double input_x[3] = {
		0,
		0,
		0
	};
	double expected_x[3] = {
		0.18639322687334783,
		0.33120532522108065,
		-0.4226312673534835
	};
	ORA::Matrix<double> A;
	ORA::Matrix<double> b;
	ORA::Matrix<double> x;

	A.set_all(3, 3, inputA);
	b.set_all(3, 1, input_b);
	x.set_all(3, 1, input_x);

	ORA::Gauss gauss(A, x, b);
	gauss.setInteractions(4);
	x = gauss.exec();

	EXPECT_DOUBLE_EQ(expected_x[0], x.get(0, 0));
	EXPECT_DOUBLE_EQ(expected_x[1], x.get(1, 0));
	EXPECT_DOUBLE_EQ(expected_x[2], x.get(2, 0));
}
