#include <iostream>
#include <vector>

using namespace std;

vector <int> vectorSort;

int partition(int p,const int r);

void quickSort(int p,const int r);

int main()
{
	int x;
	vectorSort.push_back(1);
	vectorSort.push_back(-23);
	vectorSort.push_back(456);
	vectorSort.push_back(10);
	vectorSort.push_back(17);
	vectorSort.push_back(21);
	vectorSort.push_back(170);
	vectorSort.push_back(168);
	vectorSort.push_back(-1);
	vectorSort.push_back(100);
	
	vector<int>::iterator ptr;
	
	for(ptr=vectorSort.begin();ptr!=vectorSort.end();ptr++)
	{
		cout<<*ptr<<endl;
	}
	
	cout<<endl;

	quickSort(0,9);
	
	for(ptr=vectorSort.begin();ptr!=vectorSort.end();ptr++)
	{
		cout<<*ptr<<endl;
	}
	
}

int partition(int p,const int r)
{
	int q=p;
	int u;
	int tmp;
	
	for(u=p;u<(r);u++)
	{
		if(vectorSort[u]<vectorSort[r])
		{
			tmp=vectorSort[q];
			vectorSort[q]=vectorSort[u];
			vectorSort[u]=tmp;
			q++;
		}
		
	}
	
	tmp=vectorSort[q];
	vectorSort[q]=vectorSort[r];
	vectorSort[r]=tmp;
	
	return q;
	
}

void quickSort(int p,const int r)
{
	if(p>=r)
	{
		return;
	}
	
	int q=partition(p,r);
	
	quickSort(p,q-1);
	quickSort(q+1,r);
	
}