#ifndef _NODE_H_
#define _NODE_H_

#include <CppUtil/Basic/Element.h>

#include <vector>

#define NODE_SETUP(CLASS) \
ELE_SETUP(CLASS)\
virtual void TraverseAccept(CppUtil::Basic::EleVisitor::Ptr eleVisitor){\
	eleVisitor->Visit(CThis());\
	eleVisitor->Visit(This());\
	for (auto child : children)\
		child->TraverseAccept(eleVisitor); \
}\
virtual void TraverseAccept(CppUtil::Basic::EleVisitor::Ptr eleVisitor) const{\
	eleVisitor->Visit(CThis());\
	for (auto child : children)\
		child->TraverseAccept(eleVisitor); \
}

namespace CppUtil {
	namespace Basic {
		class Node : public Element {
			NODE_SETUP(Node)

		public:
			void AddChild(Node::Ptr child);

		protected:
			std::vector<Node::Ptr> children;
		};
	}
}

#endif // !_NODE_H_