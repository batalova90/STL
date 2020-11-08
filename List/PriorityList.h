#pragma once
#include <string>
#include <list>

enum Priority {high = 1, normal, low };
class PriorityNode
{
private:
	struct Node
	{
		std::string name{ "" };
		Priority level;
		Node(std::string name_, Priority level_) : name(name_), level(level_) {}
	};
	std::list<Node> elementPriority;
	//количество элементов по приоритету
	int sizeHigh{ 0 };
	int sizeNormal{ 0 };
	int sizeLow{ 0 };
	void IncrementSizePriority(Priority level);
	void push_back_on_priority(Node current);
	std::list<Node>::iterator iteratorMethod(int delay);
	void ChangePriority(std::list<Node>::iterator begin, std::list<Node>::iterator end, Priority level_);
public:
	PriorityNode(std::string name_, Priority level_);
	~PriorityNode();
	void pushElement(const std::string& element, Priority priority);
	std::string frontPriority();
	std::string backPriority();
	void Accelerate();
	friend std::ostream& operator << (std::ostream& out, const PriorityNode& queue);


};

inline void PriorityNode::IncrementSizePriority(Priority level_)
{
	if (level_ == Priority::high)
		sizeHigh++;
	else if (level_ == Priority::normal)
		sizeNormal++;
	else
		sizeHigh++;
}

inline void PriorityNode::push_back_on_priority(Node current)
{
	
	switch (current.level)
	{
		case(high):
			sizeHigh++; //ћожет быть после вставки увеличивать на единицу????
			elementPriority.insert(iteratorMethod(sizeHigh), current);
			break;
		case(normal):
			sizeNormal++;
			elementPriority.insert(iteratorMethod(sizeHigh + sizeNormal), current);
			break;
		case(low):
			sizeLow++;
			elementPriority.push_back(current);
			break;
	}
		
}

inline std::list<PriorityNode::Node>::iterator PriorityNode::iteratorMethod(int delay)
{
	std::list<PriorityNode::Node>::iterator it = elementPriority.begin();
	while(it != elementPriority.end())
	{
		if (delay == 1)
		{
			return it; //ј, если delay изначально нулевой?
		}
		else
			delay--;
		it++;
	}

	return --it;
	
}

inline void PriorityNode::ChangePriority(std::list<Node>::iterator begin, std::list<Node>::iterator end,  Priority level_)
{
	for (auto it = begin; it != end; ++it)
	{
		it->level = level_;
	}
}

PriorityNode::PriorityNode(std::string name_, Priority level_)
{
	PriorityNode::Node current(name_, level_);
	elementPriority.push_back(current);
	IncrementSizePriority(level_);

}

PriorityNode::~PriorityNode()
{
	while (!elementPriority.empty())
	{
		elementPriority.pop_back();
	}
}

void PriorityNode::pushElement(const std::string& element, Priority priority)
{
	PriorityNode::Node current(element, priority);
	if (elementPriority.empty())
	{
		elementPriority.push_back(current);
		IncrementSizePriority(priority);
	}
	
	else
	{
		push_back_on_priority(current);
	}
}

std::string PriorityNode::frontPriority()
{
	PriorityNode::Node top = elementPriority.front();
	std::cout << "\nlevel top: " << top.level << "\n";
	return top.name;
}

std::string PriorityNode::backPriority()
{
	PriorityNode::Node back = elementPriority.back();
	std::cerr << "\nlevel back: " << back.level << "\n";
	return back.name;
}

inline void PriorityNode::Accelerate()
{
	std::list<PriorityNode::Node>::iterator lowBegin = iteratorMethod(sizeHigh + sizeNormal + 1); //начало low
	std::list<PriorityNode::Node>::iterator highEnd = iteratorMethod(sizeHigh + 1); //начало normal
	ChangePriority(lowBegin, elementPriority.end(), high); //не забывать увеличивать, уменьшать счетчик!!!!
	int count = sizeLow;
	for (auto it = lowBegin; it != elementPriority.end(); ++it)
	{
		elementPriority.insert(highEnd, *it);
		sizeLow--;
		sizeHigh++;
	}
	lowBegin = iteratorMethod(sizeHigh + sizeNormal);
	while (count)
	{
		elementPriority.pop_back();
		count--;

	}
		

	
	

}

std::ostream& operator << (std::ostream& out, const PriorityNode& queue)
{
	for (auto it : queue.elementPriority)
		out << "Element name: " << it.name << "\telement level: " << it.level << "\n";
	return out;
}
