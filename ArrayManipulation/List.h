#include<iostream>
using namespace std;
template<typename T>
class List{
protected:
	T *arr;
	int size;
	int curr_size;
public:
	List(){
		size = 0;
		curr_size = 0;
		arr = nullptr;
	}
	List(int size)
	{
		this->size = size;
		curr_size = 0;
		arr = new T[size];
	}
	virtual T removeElementFromSpecificPositionList(int loc) = 0;
	virtual void firstRepeatingElement() = 0;
	virtual void firstNonRepeatingElement() = 0;
	virtual void findPairs(int Target) = 0;


	~List()
	{
		delete[]arr;
	}

};
template<typename T>
class MyList : public List<T>
{
public:
	MyList(int s) :List<T>(s){}
	void addElement(T element) {
		if (curr_size < size) {
			this->arr[curr_size++] = element;
		}
		else {
			cout << "Array List is Full" << endl;
		}
	}
	void show()
	{
		cout << "Array is " << endl;
		for (int i = 0; i < curr_size; i++)
		{
			cout<< arr[i]<<" ";
		}
		cout << endl;
	}
	T removeElementFromSpecificPositionList(int loc)override{
		if (loc < 0 || loc > curr_size)
		{
			cout << "invalid location" << endl;
		}
		else{
			T removed = this->arr[loc];
			for (int i = loc; i < curr_size; i++)
			{
				arr[i] = arr[i + 1];

			}
			curr_size--;
			
			return removed;
		}
		
	}
	void firstRepeatingElement()override {

		bool found;
		if (arr==nullptr)
		{
			cout << "Array do not have values " << endl;
		}
		else{

			for (int i = 0; i < curr_size; i++)
			{
				 found = false;
				for (int j = i + 1; j < curr_size; j++)
				{
					if (arr[i] == arr[j])
					{
						found = true;
						cout << "first repeating element is " << arr[i] << endl;
						
					}
				}
			}
		}
		if (found)
		{
			cout << "there is no repeating element " << endl;
		}
		
	}

	void firstNonRepeatingElement(){
		bool found = false;
		for (int i = 0; i < curr_size; i++)
		{
			bool isRepeating = false;
			for (int j = 0; j < curr_size; j++)
			{
				if (i != j&&arr[i] == arr[j])
				{
					isRepeating = true;
					break;
				}
			}
			if (!isRepeating) {
				cout << "First Non-Repeating Element: " << this->arr[i] << endl;
				found = true;
				break;
				
			}
		}
		if (!found) {
			cout << "No Non-Repeating Element Found" << endl;
		}
	}
	void  findPairs(T Target)
	{
		bool found;
		for (int i = 0; i < curr_size; i++)
		{
			 found = false;
			for (int j= i + 1; j < curr_size; j++)
			{
				if (arr[i] + arr[j] == Target)
				{
					cout << "(" << arr[i] << "," << arr[j] << ")";
					found=true;
				}
			}
			
		}
		if (found)
		{
			cout << "pair not found " << endl;
		}
		cout << endl;
	}
};