#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;
int main()
{
	string sequence;
	
	cout<<"please put in a sequence"<<endl;
	cin>>sequence;
	
	transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);
	
	int state=0;
	
	int appearance=0;
	
	for(int i=0;i<sequence.length()+1;i++)
	{
		switch(state)
		{
			case 0:
			
			if(sequence[i]=='T')
			{
				state=1;
			}
			break;
			
			case 1:
			if(sequence[i]=='A')
			{
				state=2;
			}
			else if( sequence[i]!='T')
			{
				state=0;
			}
			break;
			
			case 2:
			if(sequence[i]='T')
			{
				state=3;
			}
			
			else
			{
			 state=0;	
			}
			
			break;
			
			case 3:
			appearance+=1;
			if(sequence[i]=='A')
			{
				state=2;
			}
			
			else if(sequence[i]=='T')
			{
				state=1;	
			}
			
			else
			{
				state=0;
			}
			
			break;
			default:
			state=0;
		}
	}
	
	cout<<appearance<<endl;
	
}