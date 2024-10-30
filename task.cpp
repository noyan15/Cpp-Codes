#include<iostream>
#include<string>
using namespace std;
int main(){
	string number = "LIIV";
	int numberr = 0;
	for (int i=0;i<4;i++)
	{
		if(number[i]=='L'){
			numberr = numberr+50;
		}
		else if(number[i]=='I'){
			numberr = numberr+1;
		}
		else if(number[i]=='V'){
			numberr = numberr+5;
		}
	}
	cout<<numberr;
	return 0;
}
