#include"List.h"

int main()
{
	MyList<int> obj(5);
	obj.addElement(2);
	obj.addElement(3);
	obj.addElement(3);
	obj.addElement(21);
	obj.addElement(6);
	obj.show();
	obj.removeElementFromSpecificPositionList(5);
	obj.show();
	obj.firstNonRepeatingElement();
	obj.firstRepeatingElement();
	obj.findPairs(5);
	obj.show();
	system("pause");
	return 0;
}