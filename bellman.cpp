#include <iostream>
#include <vector>
#include <map>

using namespace std;

void relax(int i, int j, int** adjmatrix,int* distance, int* pred);

int main()
{
	
	int numOfNodes;
	vector<int> vectori;
	vector<int> vectorj;
	
	cout<<"How many nodes do you want: ";
	cin>>numOfNodes;
	
	int** adjmatrix = new int*[numOfNodes];
	for(int i = 0; i < numOfNodes; ++i)
	{
		adjmatrix[i] = new int[numOfNodes];
	}
	
	for(int i=0;i<numOfNodes;i++)
	{
		for(int j=0; j<numOfNodes;j++)
		{
			adjmatrix[i][j]=32767;	
		}
	}
	

	for(int i=0;i<numOfNodes;i++)
	{
		int numOfExiting; //finds number of exiting edges
		cout<<"How many edges emanate from node "<<i<<": ";
		cin>>numOfExiting;
		
		for(int j=0; j<numOfExiting; j++)
		{
			int edge1;
			int distance;
			cout<<"Where does edge "<<(j+1)<<" go to?"<<endl;
			cin>>edge1;
			cout<<"Whats is the weight?"<<endl;
			cin>>distance;
			adjmatrix[i][edge1]=distance;
			
			vectori.push_back(i);
			vectorj.push_back(edge1);
		}
	}

	int* distance= new int[numOfNodes];
	int* pred= new int[numOfNodes];
	
	distance[0]=0;
	pred[0]=-1;
	
	for(int i=1;i<numOfNodes;i++)
	{
		distance[i]=32767;
		pred[i]=-1;
	}

	for(int i=0;i<(numOfNodes-1);i++)
	{
		for(int j=0;j<vectori.size();j++)
		{
			relax(vectori[j],vectorj[j],adjmatrix, distance, pred);
		}
	}
	
	cout<<endl;
	
	for(int i=0; i<numOfNodes;i++)
	{
		cout<<distance[i]<<endl;
	}
	
	cout<<endl;
	
	for(int i=0; i<numOfNodes;i++)
	{
		cout<<pred[i]<<endl;
	}
}


void relax(int i, int j, int** adjmatrix,int* distance, int* pred)
{
		if(distance[j]> adjmatrix[i][j]+distance[i])
		{
			distance[j]= adjmatrix[i][j]+distance[i];
			pred[j]=i;
		}
}

