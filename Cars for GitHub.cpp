#include<iostream>
#include<string>
using namespace std;

struct Cars {
	string Name;
	string Model;
	//string RegNo;
	string HP;
	string Color;
	int Varieties;
	float Price;
	bool Available;
};
struct Customers {
	string Name;
	string CNIC;
	string Adress;
	string BankAccNo;
};

int main()
{
	Customers Customer[100];
	int customerIndex = 0;
	int models;
	cout<<"Company Panel!\n";
	cout<<"How much models do your company have? ";
	cin>>models;
	Cars Car[models];
	for(int i=0; i<models; i++)
	{
		cout<<"Enter the Name of Car "<<i+1<<": ";cin>>Car[i].Name;
		cout<<"Enter the Model of Car "<<i+1<<": ";cin>>Car[i].Model;
	//	cout<<"Enter the Registration Number of Car "<<i+1<<": ";cin>>Car[i].RegNo;
		cout<<"Enter the Horse Power of Car "<<i+1<<": ";cin>>Car[i].HP;
		cout<<"Enter the Color of Car "<<i+1<<": ";cin>>Car[i].Color;
		cout<<"Enter the Varieties of Car"<<i+1<<": ";cin>>Car[i].Varieties;
		cout<<"Enter the Price of Car "<<i+1<<": ";cin>>Car[i].Price;
		if(Car[i].Varieties>=1)
		{
			Car[i].Available = true;
		}
		else
		{
			Car[i].Available = false;
		}
		cout<<endl;
	}
	cout<<"\n\n\n";
	cout<<"Customer Panel!\n";
	int Option;
	do
	{
		for(int i=0; i<models; i++)
	{
		cout<<i+1<<". "<<Car[i].Name<<"\n"<<"Model: "<<Car[i].Model;
		cout<<"\tHorse Power: "<<Car[i].HP<<"\nColor: "<<Car[i].Color<<"\t Varieties: "<<Car[i].Varieties;
		cout<<"\nPrice: "<<Car[i].Price;
		if(Car[i].Available==true)
		{
			cout<<"\tAvailable\n";
		}
		else
		{
			cout<<"\tNot Available\n";
		}
		cout<<endl;
	}
		cout<<"Enter the S.No of car which you want buy or Enter 0 to end: ";cin>>Option;
		int carOption = Option - 1;
		if(Option!=0)
		{
			cout<<Car[carOption].Name<<"\n"<<"Model: "<<Car[carOption].Model;
		cout<<"\tHorse Power: "<<Car[carOption].HP<<"\nColor: "<<Car[carOption].Color<<"\t Varieties: "<<Car[carOption].Varieties;
		cout<<"\nPrice: "<<Car[carOption].Price;
		if(Car[carOption].Available==true)
		{
			cout<<"\tAvailable\n";
		}
		else
		{
			cout<<"\tNot Available\n";
		}
		    int buyOption;
		    cout<<"If you want to buy Enter 1 or to cancel order enter 0: ";cin>>buyOption;
		    while(true)
		    {
		    	if(buyOption==1)
		    	{
		    		if(Car[carOption].Available==true)
		    		{
		    			cout<<"Enter your Name: ";cin>>Customer[customerIndex].Name;
		    			cout<<"Enter your CNIC: ";cin>>Customer[customerIndex].CNIC;
		    			cout<<"Enter your Adress: ";cin>>Customer[customerIndex].Adress;
		    			cout<<"Enter your Bank Account Number: ";cin>>Customer[customerIndex].BankAccNo;
		    			int confirmOrder;
		    			cout<<"Enter 0 to cancel order or enter 1 to confirm order: ";cin>>confirmOrder;
		    			if(confirmOrder==1)
		    			{
		    				customerIndex += 1;
		    			cout<<"Thanks for shopping your car will arrive soon!\n\n";
		    			Car[carOption].Varieties -= 1;
						}
		    			else
		    			{
		    				cout<<"Order canceled!\n\n";
						}	
					}
					else
					{
						cout<<"This car is not available, Thank you!\n\n";	
					}
					break;
				}
				else if(buyOption==0)
				{
					break;
				}
				else
				{
					cout<<"Enter the correct Option: ";cin>>buyOption;
				}
			}
			cout<<"Continue Shopping 1, Exit 0: ";cin>>Option;
			while(Option!=1&&Option!=0)
			{
				cout<<"Enter the right option: ";cin>>Option;
			}
			if(Option==0)
			{
				break;
			}
		}
		else if(Option==0)
		{
			break;
		}
		else
		{
			cout<<"Enter the right option: ";cin>>Option;
		}
	} while(true);
	return 0;
}
