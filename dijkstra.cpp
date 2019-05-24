#include <iostream>
#include <vector>


using namespace std;

int min( int* array1, int length);



class edge
{
	public:
	edge(int num1,int num2);
	int getNode(void) const{return node;}
	int getWeight(void) const{return weight;} 
	
	private:
	int node;
	int weight;
};

edge::edge(int num1,int num2)
{
	node=num1;
	weight=num2;
}

void relax(vector<edge>& edgevec, int key,int* distance,int* finaldistance,int* pred); 

int main()
{
	int numOfNodes;
	
	cout<<"How many nodes do you want: ";
	cin>>numOfNodes;
	
	
	vector< vector<edge> > adjvec(numOfNodes);
	
	 
	
	for(int i=0;i<adjvec.size();i++)
	{
		int numOfExiting; //finds number of exiting edges
		cout<<"How many edges emanate from node "<<i<<": ";
		cin>>numOfExiting;
		
		if(numOfExiting==0)
		{
			edge newedge(-1,-1);
			adjvec[i].push_back(newedge);
			continue;
		}
		for(int j=0; j<numOfExiting; j++)
		{
			int edge1;
			int distance;
			cout<<"Where does edge "<<(j+1)<<" go to?"<<endl;
			cin>>edge1;
			cout<<"Whats is the weight?"<<endl;
			cin>>distance;
			edge newedge(edge1,distance);
			adjvec[i].push_back(newedge);
			
		}
	}
	
	
	int* distance= new int[numOfNodes];
	int* pred= new int[numOfNodes];
	
	for(int i=0; i<numOfNodes; i++)
	{
		pred[i]=-1;
		
	}
	
	
	distance[0]=0;
	
	for(int i=1;i<numOfNodes;i++)
	{
		distance[i]=32767;
	}
	
	int finaldistance[numOfNodes];
	
	for(int i=0;i<numOfNodes;i++)
	{
		finaldistance[i]=distance[i];
	}
	
	
	
	
	for(int i=0;i<numOfNodes;i++)
	{
	int key= min(distance,numOfNodes);
	
	relax(adjvec[key],key,distance,finaldistance,pred);
	}
	
	cout<<endl;
	
	for(int i=0; i<numOfNodes; i++)
	{
		cout<<finaldistance[i]<<endl;
	}
	
	cout<<endl;
	
	for(int i=0;i<numOfNodes;i++)
	{
			cout<<pred[i]<<endl;
	}	
}

int min(int* distance,int length)
{
	int minimum=32767;
	int minindex;
	
	for(int i=0; i<length; i++)
	{
		if(distance[i]!=-1)
		{
			if(distance[i]<minimum)
			{
				minimum=distance[i];
				minindex=i;
			}
		}
	}
	
	distance[minindex]=-1;
	return minindex;
}

void relax( vector<edge>& edgevec,int key,int* distance,int *finaldistance,int* pred)
{
	if(edgevec[0].getWeight()==-1)
	{
		return;
	}
	
	
	for(int i=0;i<edgevec.size();i++)
	{
		int edgelength=edgevec[i].getWeight();
		int num=edgevec[i].getNode();
		if(finaldistance[num]> (finaldistance[key]+edgelength))
		{
			pred[num]=key;
			distance[num]=finaldistance[key]+edgelength; 
			finaldistance[num]=finaldistance[key]+edgelength;
		}
	}
}

