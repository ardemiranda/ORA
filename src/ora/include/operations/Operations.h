/*
 * Operations.h
 *
 *  Created on: 14.09.2014
 *      Author: andre
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "Matrix.h"

namespace ORA {
namespace Operations {

class Operations {
public:
	Operations();
	virtual void exec() const;
	virtual ~Operations();
};

} /* namespace Operations */
} /* namespace ORA */

#endif /* OPERATIONS_H_ */
