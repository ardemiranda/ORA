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

#ifndef GAUSS_H_
#define GAUSS_H_

#include "Matrix.h"

namespace ORA {

class Gauss {
private:
	Matrix<double> A;
	Matrix<double> x;
	Matrix<double> b;
	int interactions;

public:
	Gauss(Matrix<double> m, Matrix<double> x, Matrix<double> b);

	void setInteractions(int k);
	Matrix<double> exec();
};

} /* namespace ORA */

#endif /* GAUSS_H_ */
