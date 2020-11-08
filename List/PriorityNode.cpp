#include <string>
#include "PriorityList.h"
#include <list>

class PriorityNode
{
private:
	struct Node
	{
		std::string name{ "" };
		std::string level{ "" };
		Node(std::string name_, std::string level_) : name(name_), level(level_) {}
	};
	std::list<Node> elementPriority;
	int sizeHigh{0};
	int sizeNormal{0};
	int sizeLow{0};
	public:
		PriorityNode(std::string name_, std::string level_);
		~PriorityNode();



};

PriorityNode::PriorityNode(std::string name_, std::string level_)
{
	PriorityNode::Node current(name_, level_);
	elementPriority.push_back(current);
}

PriorityNode::~PriorityNode()
{
	while (!elementPriority.empty())
	{
		elementPriority.pop_back();
	}
}
