#include<iostream>
#include<queue>
using namespace std;
void fcfs()
{
	class process 
{
	public:
		int arrival;
		int burst;
		int waiting;
		int exit;
		int tat;
		int id;
		int done;
		int excutionorder;
};
	cout<<"enter no of processes"<<endl;
	int n;
	cin>>n;
	cout<<"enter arrival time and burst time for each process"<<endl;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].arrival;
		cin>>p[i].burst;
		p[i].id=i;
		p[i].done=0;
	}
int exitime=0;
int count=0;
int minimum=1000;
int id;
int flag=0;
int j=1;
int order=0;
while(j==1)
{
	minimum=1000;
	flag=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].arrival<=count && p[i].done==0)
		{
		 if(p[i].arrival<minimum)
		 {
		 minimum=p[i].arrival;
		 id=i;	
		 }	
		
		}
	}
	for(int i=0;i<p[id].burst;i++)
	{
		count++;
	}
	p[id].done=1;
	p[id].exit=count;
	p[id].excutionorder=order;
	order++;
	for(int i=0;i<n;i++)
	{
		if(p[i].done!=1)
		{
			flag=1;
		   break;
		}
	}
    if(flag==0)
    {
    	break;
	}

}
int sum=0;
for(int i=0;i<n;i++)
{
	p[i].tat=p[i].exit-p[i].arrival;
	p[i].waiting=p[i].tat-p[i].burst;
    sum=sum+p[i].waiting;
}
float avg=(sum*1.0)/n;
cout<<"avg waiting time is "<<avg<<endl<<endl;
cout<<"processnum           excution order            waiting           turnaround"<<endl;
for(int i=0;i<n;i++)
{
	
cout<<"     p"<<p[i].id<<"                 "<<p[i].excutionorder<<"                          "<<p[i].waiting<<"                    "<<p[i].tat<<endl;
}
}
void sjf()

{
	class process 
{
	public:
		int arrival;
		int burst;
		int waiting;
		int exit;
		int tat;
		int id;
		int done;
		int excutionorder;
};
cout<<"enter no of processes"<<endl;
	int n;
	cin>>n;
	cout<<"enter arrival time and burst time for each process"<<endl;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].arrival;
		cin>>p[i].burst;
		p[i].id=i;
		p[i].done=0;
	}
int exitime=0;
int count=0;
int minimum=1000;
int id;
int flag=0;
int j=1;
int order=0;
while(j==1)
{
	minimum=1000;
	flag=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].arrival<=count && p[i].done==0)
		{
		 if(p[i].burst<minimum)
		 {
		 minimum=p[i].burst;
		 id=i;	
		 }	
		
		}
	}
	for(int i=0;i<p[id].burst;i++)
	{
		count++;
	}
	p[id].done=1;
	p[id].exit=count;
	p[id].excutionorder=order;
	order++;
	for(int i=0;i<n;i++)
	{
		if(p[i].done!=1)
		{
			flag=1;
		   break;
		}
	}
    if(flag==0)
    {
    	break;
	}

}
int sum=0;
for(int i=0;i<n;i++)
{
	p[i].tat=p[i].exit-p[i].arrival;
	p[i].waiting=p[i].tat-p[i].burst;
    sum=sum+p[i].waiting;
}
float avg=(sum*1.0)/n;
cout<<"avg waiting time is "<<avg<<endl<<endl;
cout<<"processnum           excution order            waiting           turnaround"<<endl;
for(int i=0;i<n;i++)
{
	
cout<<"     p"<<p[i].id<<"                 "<<p[i].excutionorder<<"                          "<<p[i].waiting<<"                    "<<p[i].tat<<endl;
}	
}
void srtf()
{
	class process 
{
	public:
		int arrival;
		int burst;
		int waiting;
		int exit;
		int tat;
		int id;
		
		int remaingtime;
};
	cout<<"enter no of processes"<<endl;
	int n;
	cin>>n;
	cout<<"enter arrival time and burst time for each process"<<endl;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].arrival;
		cin>>p[i].burst;
		p[i].id=i;
		//p[i].done=0;
		p[i].remaingtime=p[i].burst;
	}

int count=0;
int minimum=1000;
int id;
int flag=0;
int k=1;
int excution[100][2];
int order=0;
int a=0;
while(k==1)
{
	
	minimum=1000;
	flag=0;
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].arrival<=count && p[i].remaingtime!=0)
		{
		 if(p[i].burst<minimum)
		 {
		 		
		 minimum=p[i].burst;
		 id=i;	
		 }	
		
		}
	}
	for(int i=0;i<p[id].remaingtime;i++)
	{
		
		int val=0;
		x++;
		count++;
		for(int j=0;j<n;j++)
		{
			if(count==p[j].arrival)
			{
				val=1;
				break;
			}
		}
	 
	  if(val==1)
	  {
	  	break;
	  }
	}
	excution[a][0]=id;
	excution[a][1]=x;
	a++;
	 p[id].remaingtime=p[id].remaingtime-x;
	//cout<<id<<"  "<<p[id].remaingtime<<endl;
	//p[id].done=1;
	if(p[id].remaingtime==0)
	{
		p[id].exit=count;
	}
	//p[id].excutionorder=order;
	//order++;
	for(int i=0;i<n;i++)
	{
		if(p[i].remaingtime!=0)
		{
			flag=1;
		  
		   break;
		}
	}
    if(flag==0)
    {
    	
		break;
	}

} 
int sum=0;
for(int i=0;i<n;i++)
{
	p[i].tat=p[i].exit-p[i].arrival;
	p[i].waiting=p[i].tat-p[i].burst;
    sum=sum+p[i].waiting;
}
float avg=(sum*1.0)/n;
cout<<"avg waiting time is "<<avg<<endl<<endl;
cout<<"processnum           waiting           turnaround"<<endl;
for(int i=0;i<n;i++)
{
       cout<<"p"<<p[i].id<<"                      "<<p[i].waiting<<"                    "<<p[i].tat<<endl;
}

cout<<endl<<endl<<endl;
cout<<"excution order is"<<endl<<endl;
cout<<"processid     time"<<endl;
for(int i=0;i<a;i++)
{
	for(int j=0;j<2;j++)
	{
		cout<<excution[i][j]<<"                ";
	}
cout<<endl;
}
}
void priwith()

{

class process 
{
	public:
		int arrival;
		int burst;
		int waiting;
		int exit;
		int tat;
		int id;
		int priority;
		int remaingtime;
};
	cout<<"enter no of processes"<<endl;
	int n;
	cin>>n;
	cout<<"enter arrival time,burst time and priority for each process"<<endl;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].arrival;
		cin>>p[i].burst;
		cin>>p[i].priority;
		p[i].id=i;
		//p[i].done=0;
		p[i].remaingtime=p[i].burst;
	}

int count=0;
int max=0;
int id;
int flag=0;
int k=1;
int excution[100][2];
int order=0;
int a=0;
while(k==1)
{
	
	max=0;
	flag=0;
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].arrival<=count && p[i].remaingtime!=0)
		{
		 if(p[i].priority>max)
		 {
		 		
		 max=p[i].priority;
		 id=i;	
		 }	
		
		}
	}
	for(int i=0;i<p[id].remaingtime;i++)
	{
		
		int val=0;
		x++;
		count++;
		for(int j=0;j<n;j++)
		{
			if(count==p[j].arrival)
			{
				val=1;
				break;
			}
		}
	 
	  if(val==1)
	  {
	  	break;
	  }
	}
	excution[a][0]=id;
	excution[a][1]=x;
	a++;
	 p[id].remaingtime=p[id].remaingtime-x;
	//cout<<id<<"  "<<p[id].remaingtime<<endl;
	//p[id].done=1;
	if(p[id].remaingtime==0)
	{
		p[id].exit=count;
	}
	//p[id].excutionorder=order;
	//order++;
	for(int i=0;i<n;i++)
	{
		if(p[i].remaingtime!=0)
		{
			flag=1;
		  
		   break;
		}
	}
    if(flag==0)
    {
    	
		break;
	}

} 
int sum=0;
for(int i=0;i<n;i++)
{
	p[i].tat=p[i].exit-p[i].arrival;
	p[i].waiting=p[i].tat-p[i].burst;
    sum=sum+p[i].waiting;
}
float avg=(sum*1.0)/n;
cout<<"avg waiting time is "<<avg<<endl<<endl;
cout<<"processnum           waiting           turnaround"<<endl;
for(int i=0;i<n;i++)
{
       cout<<"p"<<p[i].id<<"                      "<<p[i].waiting<<"                    "<<p[i].tat<<endl;
}

cout<<endl<<endl<<endl;
cout<<"excution order is"<<endl<<endl;
cout<<"processid     time"<<endl;
for(int i=0;i<a;i++)
{
	for(int j=0;j<2;j++)
	{
		cout<<excution[i][j]<<"                ";
	}
cout<<endl;
}
}
void priwithout()
{
	class process 
{
	public:
		int arrival;
		int burst;
		int waiting;
		int exit;
		int tat;
		int id;
		int priority;
		int done;
		int excutionorder;
};
	cout<<"enter no of processes"<<endl;
	int n;
	cin>>n;
	cout<<"enter arrival time ,burst time and priority for each process"<<endl;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].arrival;
		cin>>p[i].burst;
		cin>>p[i].priority;
		p[i].id=i;
		p[i].done=0;
	}
int exitime=0;
int count=0;
int max=0;
int id;
int flag=0;
int j=1;
int order=0;
while(j==1)
{
	max=0;
	flag=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].arrival<=count && p[i].done==0)
		{
		 if(p[i].priority>max)
		 {
		 max=p[i].priority;
		 id=i;	
		 }	
		
		}
	}
	for(int i=0;i<p[id].burst;i++)
	{
		count++;
	}
	p[id].done=1;
	p[id].exit=count;
	p[id].excutionorder=order;
	order++;
	for(int i=0;i<n;i++)
	{
		if(p[i].done!=1)
		{
			flag=1;
		   break;
		}
	}
    if(flag==0)
    {
    	break;
	}

}
int sum=0;
for(int i=0;i<n;i++)
{
	p[i].tat=p[i].exit-p[i].arrival;
	p[i].waiting=p[i].tat-p[i].burst;
    sum=sum+p[i].waiting;
}
float avg=(sum*1.0)/n;
cout<<"avg waiting time is "<<avg<<endl<<endl;
cout<<"processnum           excution order            waiting           turnaround"<<endl;
for(int i=0;i<n;i++)
{
	
cout<<"     p"<<p[i].id<<"                 "<<p[i].excutionorder<<"                          "<<p[i].waiting<<"                    "<<p[i].tat<<endl;
}
}
void round()
{
	class process 
{
	public:
		int arrival;
		int burst;
		int waiting;
		int exit;
		int tat;
		int id;
		
		int remaingtime;
};
	cout<<"enter no of processes"<<endl;
	int n;
	cin>>n;
	cout<<"enter time quantum"<<endl;
	int time;
	cin>>time;
	cout<<"enter arrival time and burst time for each process"<<endl;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].arrival;
		cin>>p[i].burst;
		p[i].id=i;
		//p[i].done=0;
		p[i].remaingtime=p[i].burst;
	}

int count=0;
int minimum=1000;
int id;
int flag=0;
int k=1;
int excution[100][2];
int order=0;
int a=0;
queue<int> q;
for(int i=0;i<n;i++)
{
	if(p[i].arrival==0)
	{
		q.push(i);
	}
}

while(k==1)
{
	
	//minimum=1000;
	//flag=0;
	int x=0;
 
  
		int b=q.front();
		q.pop();
		if(p[b].arrival<=count && p[b].remaingtime!=0)
		{
		id=b;
	    }
	    else
	    {
	    	continue;
		}
       
	   if(p[id].remaingtime<=time)
	   {
	   	  
		  for(int i=0;i<p[id].remaingtime;i++)
		  {
		 count++;
		  	for(int i=0;i<n;i++)
		  	 {
		  	   if(p[i].arrival==count)
				 {
				 q.push(i)	;
				 }	
			  }
		  
		  }
		  x=p[id].remaingtime;
		  
		 
		  
	   }
	   else
	   {
	   
	   
	    for(int i=0;i<time;i++)
        {
          
	    count++;
	    for(int i=0;i<n;i++)
	    {
		
		  	 
		  	   if(p[i].arrival==count)
				 {
				 q.push(i)	;
				 }	
	    
	    }
       x++;
	   }
}
	  p[id].remaingtime=p[id].remaingtime-x;
       if(p[id].remaingtime!=0)
       {
       	q.push(id);
	   }
   
     excution[a][0]=id;
	 excution[a][1]=x;
	 a++;
	 
	if(p[id].remaingtime==0)
	{
		p[id].exit=count;
	}
	
	if(q.empty())
	{
		break;
	}

} 
int sum=0;
for(int i=0;i<n;i++)
{
	p[i].tat=p[i].exit-p[i].arrival;
	p[i].waiting=p[i].tat-p[i].burst;
    sum=sum+p[i].waiting;
}
float avg=(sum*1.0)/n;
cout<<"avg waiting time is "<<avg<<endl<<endl;
cout<<"processnum           waiting           turnaround"<<endl;
for(int i=0;i<n;i++)
{
       cout<<"p"<<p[i].id<<"                      "<<p[i].waiting<<"                    "<<p[i].tat<<endl;
}

cout<<endl<<endl<<endl;
cout<<"excution order is"<<endl<<endl;
cout<<"processid     time"<<endl;
for(int i=0;i<a;i++)
{
	for(int j=0;j<2;j++)
	{
		cout<<excution[i][j]<<"                ";
	}
cout<<endl;
}
}
int main()

{
int n=8;
	while(n!=0)
	{
	
	cout<<"press 1 for fcfs"<<endl;
	cout<<"press 2 for sjf"<<endl;
	cout<<"press 3 for srtf"<<endl;
	cout<<"press 4 for prioriy with premention"<<endl;
    cout<<"press 5 for priority without premention"<<endl;
    cout<<"press 6 for round robin"<<endl;
    cout<<"press 0 to exit"<<endl;
    
    cin>>n;
   
	switch(n)
    {
    	case 1:
    		{
			fcfs();
    		break;
           }
		case 2:
			{
		   sjf();
		   break;
			}
		   	
	    case 3:
	    	{
	    		srtf();
	    		break;
			}
	    case 4:
	    	{
	    		priwith();
	    		break;
			}
	    case 5:
	    	{
	    		priwithout();
	    		break;
			}
	    case 6:
	    	{
	    		round();
	    		break;
			}
	   case 0:
	   	    {
	   	    	cout<<"programme teriminated"<<endl;
				   break;
			   }
	    default:
	    	{
			cout<<"enter correct number"<<endl;
	        break;
	        }
	
	}
}
return 0;
}
