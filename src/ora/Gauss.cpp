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

#include "Gauss.h"
#include <iostream>

namespace ORA {

Gauss::Gauss(Matrix<double> A, Matrix<double> x, Matrix<double> b)
	: A(A), x(x), b(b), interactions(7) {
	// TODO Auto-generated constructor stub
}

void Gauss::setInteractions(int k) {
	interactions = k;
}

Matrix<double> Gauss::exec() {
	int k = 0;

	while (k < interactions) {
		for (int i = 0; i < A.rows(); i++) {
			double soma = b.get(i, 0);
			for (int j = 0; j < A.cols(); j++) {
				if (i != j) {
					soma -= A.get(i, j) * x.get(j, 0);
				}
			}
			soma /= A.get(i, i);
			x.set(i, 0, soma);
		}
		k++;
	}
	return x;
}

} /* namespace ORA */
