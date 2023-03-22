#include "visitors.h"
#include <cmath>

int PowerVisitor::visit(const Calculator &v, int a, int b) const {
    return std::pow(a,b);
}
