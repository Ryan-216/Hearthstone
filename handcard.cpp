#include "handcard.h"

handcard::handcard(QWidget* parent)
{
	mycard.resize(9, nullptr);
}

void handcard::add(card* c)
{
	mycard.push_back(c);
}

void handcard::remove(card*c)
{
	// find(mycard.begin(), mycard.end(), c);
	// mycard.erase(find(mycard.begin(), mycard.end(), c));
}
