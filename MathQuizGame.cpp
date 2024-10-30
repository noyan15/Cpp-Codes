#include<iostream>
#include<string>
using namespace std;

void Shuffle(int* Arr,int* index, int* Equation,int* One, int* Two,int* Three)
{
	int i=0;
	while(i<29)
	{
		int temp=Arr[i];
		Arr[i]=Arr[i+1];
		Arr[i+1]=temp;
		i+=*index;
	}
	*One = Arr[7];
	*Two = Arr[14];
	*Three = Arr[28];
	*Equation = Arr[15];
	
}

void Options (int ans, int* Marks, int* option, int* Fade)
{
	if(*Fade==4)
	{
		*Fade=8;
	}
	else if(*Fade==8)
	{
		*Fade=6;
	}
	else if(*Fade==6)
	{
		*Fade=5;
	}
	else if(*Fade==5)
	{
		*Fade=3;
	}
	else
	{
		*Fade=4;
	}
	int options[4] = {ans,ans-7+(*Fade),ans+11-(*Fade),ans+3*(*Fade)};
	
	int i=0;
	if(*option==1)
	{
		for(int k=0; k<3; k++)
		{
			int temp = options[k];
	    	options[k] = options[k+1];
	    	options[k+1] = temp;
		}
	}
	else if(*option==2)
	{
		while(i<3)
		{
	    	int temp = options[i];
	    	options[i] = options[i+1];
	    	options[i+1] = temp;
	    	i += *option;
    	}
	}
	else if (*option == 3)
	{
		int temp = options[2];
		options[2] = options[0] ;
		options[0] = temp;
	}
	*option+=1;
	if(*option>4)
	{
		*option=1;
	}
	for(int j=0; j<4; j++)
	{
		cout<<j+1<<". "<<options[j]<<endl;
	}
	cout<<"Enter answer: ";
}

void EquationPart(float ans, int* Marks, int* option, float* Ans, int* Fade)
{
	Options (ans, Marks, option, Fade);
		cin>>*Ans;
		if(ans==*Ans)
		{
			*Marks+=1;
			cout<<"Great you entered right answer\n";
		}
		else
		{
			cout<<"Oops your answer is wrong better luck next time\n";
		}
}

void Equations (int* Equation, int* Marks, int one, int two, int three, int* option, int* Fade)
{
	if(*Equation>30)
	{
		*Equation = 1;
	}
	float ans;
	float Ans;
	cout<<"\n";
	if(*Equation==1)
	{
		cout<<one<<"*"<<two<<'/'<<three<<"+("<<two<<"+"<<three<<'-'<<two<<"):\n";
		ans = one*two/three+(two+three-two);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==2)
	{
		cout<<one<<"+"<<two<<'/'<<one<<"*("<<three<<"+"<<one<<'*'<<three<<"):\n";
		ans = one + two / one * ( three + one * three );
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==3)
	{
		cout<<one<<"-"<<two<<'+'<<three<<"*("<<one<<"*"<<three<<") / ("<<one<<'+'<<two<<'-'<<three<<"):\n";
		ans = one-two+three*(one*three)/(one+two-three);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==4)
	{
		cout<<"("<<one<<"*"<<two<<") / "<<three<<" - "<<two<<":\n";
		ans = (one*two)/three-two;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==5)
	{
		cout<<one<<"+"<<three<<'*'<<"+("<<two<<"-"<<"("<<one<<'+'<<one<<")"<<"):\n";
		ans = one+three*(two-(one+one));
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==6)
	{
		cout<<three*one<<"/"<<two<<"-"<<"("<<one<<"*"<<three<<"+"<<two<<"):\n";
		ans = three*one/two-(one*three+two);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==7)
	{
		cout<<two<<"-"<<one<<"*"<<three<<"-("<<one<<"+"<<two<<"):\n";
		ans = two-one*three-(one+two);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==8)
	{
		cout<<"("<<three<<"+"<<one<<")"<<"/"<<one<<"+"<<three<<":\n";
		ans = (three+one)/one+three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==9)
	{
		cout<<three<<"+"<<two<<"*("<<one<<"+"<<one<<")/"<<one<<":\n";
		ans = three+two*(one+one)/one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==10)
	{
		cout<<"("<<two+two<<"+"<<one<<")/"<<one<<"-("<<three<<"):\n";
		ans = (two+two+one)/one-three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==11)
	{
		cout<<one<<"+"<<one<<"-"<<one<<"+"<<two<<"*"<<three<<":\n";
		ans = one+one-one+two*three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==12)
	{
		cout<<"("<<two<<"+"<<one<<")-"<<two<<"*"<<one<<":\n";
		ans = (two+one)-two*one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==13)
	{
		cout<<three<<"-("<<one<<"+"<<two<<")*"<<three<<":\n";
		ans = three-(one+two)*three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==14)
	{
		cout<<two<<"*"<<three<<"-("<<one<<"+"<<one<<"-"<<two<<"):\n";
		ans = two*three-(one+one-two);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==15)
	{
		cout<<one<<"+"<<three<<"-("<<two<<"*"<<three<<")/"<<one<<":\n";
		ans = one+three-(two*three)/one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==16)
	{
		cout<<three<<"*("<<two<<"+"<<one<<")/"<<one<<":\n";
		ans = three*(two+one)/one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==17)
	{
		cout<<one<<"/"<<one<<"+("<<two<<"+"<<three<<")-"<<two<<":\n";
		ans = one/one+(two+three)-two;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==18)
	{
		cout<<"("<<two<<"+"<<two<<"+"<<two<<")/"<<one<<"+"<<three<<":\n";
		ans = (two+two+two)/one+three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==19)
	{
		cout<<"("<<two<<"+"<<one<<")-"<<three<<"*"<<one<<":\n";
		ans = (two+one)-three*one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==20)
	{
		cout<<one<<"-"<<one<<"+("<<three<<"*"<<one<<"-"<<two<<"):\n";
		ans = one-one+(three*one-two);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==21)
	{
		cout<<three<<"+("<<two<<"+"<<two<<"-"<<two<<")*"<<one<<":\n";
		ans = three+(two+two-two)*one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==22)
	{
		cout<<"("<<two<<"+"<<one<<")*"<<three<<"+("<<two<<"-"<<two<<"):\n";
		ans = (two+one)*three+(two-two);
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==23)
	{
		cout<<one<<"-"<<one<<"+"<<two<<"*"<<three<<":\n";
		ans = one-one+two*three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==24)
	{
		cout<<two<<"+"<<two<<"*"<<two<<"/"<<two<<"+"<<one<<"*"<<three<<":\n";
		ans = two+two*two/two+one*three;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==25)
	{
		cout<<"("<<three<<"*"<<one<<")/"<<two<<":\n";
		ans = (three*one)/two;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==26)
	{
		cout<<three<<"+"<<three<<"*"<<one<<"-("<<three<<"+"<<one<<")-"<<two<<":\n";
		ans = three+three*one-(three+one)-two;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==27)
	{
		cout<<two<<"+("<<one<<"+"<<three<<")-"<<two<<"*"<<one<<":\n";
		ans = two+(one+three)-two*one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==28)
	{
		cout<<three<<"+"<<"("<<one<<"*"<<one<<"/"<<one<<")-"<<two<<":\n";
		ans = three+(one*one/one)-two;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==29)
	{
		cout<<one<<"*("<<two<<"+"<<three<<")-"<<one<<":\n";
		ans = one*(two+three)-one;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
	else if(*Equation==30)
	{
		cout<<two<<"+"<<one<<"*("<<one<<"/"<<one<<"+"<<three<<")-"<<two<<":\n";
		ans = two+one*(one/one+three)-two;
		EquationPart(ans, Marks, option, &Ans, Fade);
	}
}

void result(int* Marks)
{
	cout<<endl;
	if(*Marks>=8)
	{
		cout<<"Your score is "<<*Marks<<" out of 10"<<"\nRemarks: Excellent\n";
	}
	else if(*Marks>=6&&*Marks<=7)
	{
		cout<<"Your score is "<<*Marks<<" out of 10"<<"\nRemarks: Good\n";
	}
	else if(*Marks==5)
	{
		cout<<"Your score is "<<*Marks<<" out of 10"<<"\nRemarks: Fine\n";
	}
	else if(*Marks<5)
	{
		cout<<"Your score is "<<*Marks<<" out of 10"<<"\nRemarks: Better luck next time\n";
	}
	cout<<endl;
}

int main()
{
	int Arr[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int index = 1;
	int Fade = 4;
	int option = 2;
	int Marks = 0;
	int Equation = 1;
	int One,Two,Three;
	int controlOption;
	int anyNumber;
	cout<<"Enter any number between 1 and 100: ";
	cin>>anyNumber;
	for(int i=0;i<anyNumber; i++)
	{
		Shuffle(Arr,&index,&Equation,&One,&Two,&Three);
	}
	cout<<"Enter 1 to start the game or 0 to end the program: ";
	while(true)
	{
		Marks = 0;
		cin>>controlOption;
		if(controlOption==1)
		{
			int k=0;
			while(k<10)
			{
				Shuffle(Arr,&index,&Equation,&One,&Two,&Three);
				Equations (&Equation, &Marks, One, Two, Three, &option, &Fade);
				k++;
			}
			result(&Marks);
			cout<<"Enter 1 to play again or 0 to end game: ";
		}
		else if (controlOption==0)
		{
			cout<<"Ba Bye";
			break;
		}
		else
		{
			cout<<"Invalid Entry\n";
			cout<<"Enter 1 to start the game or 0 to end the program: ";
		}
	}
	return 0;
}
