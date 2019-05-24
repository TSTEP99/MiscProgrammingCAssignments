#include <iostream>
#include <list>
#include <vector>

using namespace std;

class edge
{
	public:
	edge(int num1);
	int getNode(void){return node;}
	
	private:
	int node;
};

edge::edge(int num1)
{
	node=num1;
}



int main()
{
	edge line(4);
}