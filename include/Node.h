#include <Vector.h>

#pragma once

namespace HTML {

class Node {
protected:
  Vector<Node> m_children;
};

}
