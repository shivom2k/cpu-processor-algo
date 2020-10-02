#include<iostream>
using namespace std;

int main()
{	
	cout<<"Enter the number of processes"<<endl;
	int pro;
	cin>>pro;
	
	cout<<"Enter the number of resources"<<endl;
	int res;
	cin>>res;
	
	string* process[pro];
	
	//CLAIM MATRIX
	cout<<"Enter the values for the claim matrix"<<endl;
	int** claim = new int*[pro];
	for(int i=0;i<pro;i++)
	{
		claim[i] = new int[res];
	}
	
	for(int i=0;i<pro;i++)
	{
		for(int j=0;j<res;j++)
		{
			cin>>claim[i][j];
		}
	}
	
	//ALLOCATION MATRIX
	cout<<"Enter the value for the allocation matrix"<<endl;
	
	int** allocation = new int*[pro];
	for(int i=0;i<pro;i++)
	{
		allocation[i] = new int[res];
	}
	
	for(int i=0;i<pro;i++)
	{
		for(int j=0;j<res;j++)
		{
			cin>>allocation[i][j];
		}
	}
	
	//MAXIMUM
	cout<<"Enter the maximum number of instances"<<endl;
	int* maximum = new int[res];
	int num = 0;
	for(int i=0;i<res;i++)
	{
		cin>>maximum[i];
		num+=maximum[i];
	}
	
	//Making the duplicate of the maximum
	/*int* dup_max = new int[res];
	dup_max = maximum;
	*/
	//AVAILABLE
	int* available = new int[res];
	for(int i=0;i<res;i++)
	{
		available[i] = 0;
	}
	
	for(int i=0;i<pro;i++)
	{
		for(int j=0;j<res;j++)
		{
			available[j]+=allocation[i][j];
		}
	}
	
	cout<<"Printing the total number of allocated resources"<<endl;
	
	for(int i=0;i<res;i++)
	{
		cout<<available[i]<<" ";
	}

	//NEED MATRIX
	int** need = new int*[pro];
	for(int i=0;i<res;i++)
	{
		need[i] = new int[4];
	}
	
	for(int i=0;i<pro;i++)
	{
		for(int j=0;j<res;j++)
		{
			need[i][j] = claim[i][j] - allocation[i][j];
		}
	}
	
	cout<<"\nPrinting the need matrix"<<endl;
	
	for(int i=0;i<pro;i++)
	{
		for(int j=0;j<res;j++)
		{
			cout<<need[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//Now the working of the Banker's algorithm
	int* work = new int[res];
	
	for(int i=0;i<res;i++)
	{
		work[i] = maximum[i]-available[i];
	}
	
	int* temp = new int[res]; 
	int* dup_temp = new int[res]; 
	temp = work;
	
	//dup_temp = temp;
	for(int p=0;p<res;p++)
	{
		dup_temp[p] = temp[p];
	}
	
	int flag = 0;
	int* name = new int[pro];
	int u = 0;
	for(int i=0;i<u;i++)
	{
		name[u] = -1;
	}
	int i=0;
	
	while(i<pro)
	{
		flag = 0;
		int j=0;
		//dup_temp = temp;
		for(int p=0;p<res;p++)
		{
			dup_temp[p] = temp[p];
		}
		
		while(j<res && need[i][j]!=INT_MIN)  
		{
			flag = 2;
			temp[j] = temp[j]-need[i][j];
			if(temp[j]<0)
			{
				flag = 1;
				break;
			}
			j++;
		}
		if(flag==1)
		{
			//temp = dup_temp;
			for(int p=0;p<res;p++)
			{
				temp[p] = dup_temp[p];
			}
		}
		else if(flag == 2)
		{
			//dup_temp = temp;
			for(int p=0;p<res;p++)
			{
				dup_temp[p] = temp[p];
			}
			name[u] = i;
			u++;
			
			for(int k=0;k<res;k++)
			{
				need[i][k] = INT_MIN;
				temp[k] += claim[i][k];
			}
			
			//dup_temp = temp;
			for(int p=0;p<res;p++)
			{
				dup_temp[p] = temp[p];
			}
			i=-1;
		}
		
		i++;
	}
	
	int unique = 0;
	for(int p=0;p<u;p++)
	{
		if(name[p]<0)
		{
			unique = 1;
			break;
		}
	}
	
	if(unique == 1)
	{
		cout<<"The system is in deadlock"<<endl;
	}
	else
	{
		cout<<"\nSafe sequesnce is"<<endl;
		for(int i=0;i<pro;i++)
		{
			cout<<"Process "<<name[i]<<endl;
		}
	}
	
	
	/*
	2 2 4
	2 1 3
	3 4 1
	1 2 1
	2 0 1
	2 2 1
	5 5 5
	*/
	
	/*
	3 2 2
	6 1 3
	3 1 4
	4 2 2
	1 0 0
	6 1 2
	2 1 1
	0 0 2
	9 3 6
	*/
	
	/*
	4 1 2
	1 5 1
	1 2 3
	1 0 2
	0 3 1
	1 0 2
	4 5 5
	*/
	return 0;
}
