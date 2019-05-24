#include <iostream>
#include <fstream>

using namespace std;

class Human
{

	
	
	public:
	
	unsigned virgin :1;
	
	Human(unsigned int sex)
	{
		virgin=sex;
		
	}
	
	~Human(){;}
	
	
	
};


int main()
{	
	Human Jeevan (0);
	
	cout<<Jeevan.virgin;
}










