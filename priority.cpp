#include <bits/stdc++.h>
using namespace std;

struct job
{
	int pr,id,at,bt,ct,wt,tat,rem,flag;
};
int main()
{
	int n;
	cout<<"Enter Number of Processes\n";
	cin>>n;
	job arr[n];
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter Arrival Time,Burst Time and Priority of Process\n";
		cin>>arr[i].at>>arr[i].bt>>arr[i].pr;
		arr[i].id = i+1;
		arr[i].rem = arr[i].bt;
		arr[i].flag = 0;
	}
	int curr = 0;
	int done = 0;
	int prev = 0;
	double avg_tat = 0,avg_wt = 0;
	while(done != n)
	{
		int j = -1;
		int mx = INT_MIN;
		for(int i = 0;i<n;i++)
		{
			if(arr[i].at<=curr && arr[i].flag == 0)
			{
				if(arr[i].pr > mx)
				{
					j = i;
					mx = arr[i].pr;
				}
				if(arr[i].pr == mx && (arr[i].at<arr[j].at ||(arr[i].at==arr[j].at && arr[i].id<arr[j].id)))
				{
					j = i;
					mx = arr[i].pr;
				}
			}
		}
		if(j == -1)
		{
			curr++;
		}
		else
		{
			arr[j].rem--;
			curr++;
			prev = curr;
			if(arr[j].rem == 0)
			{
				arr[j].ct = curr;
				arr[j].tat =arr[j].ct-arr[j].at;
				arr[j].wt = arr[j].tat-arr[j].bt;
				avg_tat+=arr[j].tat;
				avg_wt+=arr[j].wt;
				arr[j].flag = 1;
				done++;
			}
		}
	}
	cout<<"ID\tCT\tWT\tTAT\n";
	for(int i = 0;i<n;i++)
	{
		
		cout<<arr[i].id<<'\t'<<arr[i].ct<<'\t'<<arr[i].wt<<'\t'<<arr[i].tat<<'\n';
	}
	cout<<"Average Waiting time = "<<avg_wt/n<<'\n';
	cout<<"Average Turnaround  time = "<<avg_tat/n<<'\n';
	cout<<"Throughput = "<<(double)(n)/(double)(curr)<<'\n';



}