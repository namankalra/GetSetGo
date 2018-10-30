/*		                  ********************************
 ******************************** The Ultimate *****************************
 ******************************** FEES CALCULATOR *****************************
		                 ********************************
/****************************************************************************/

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>

class FEES
{
	char name[20];
	char sex;
	char sec;
	int roll,clas;
	int Tfee,Tution,Devep,Annual,Pupil,Grp;

	public:
	int display(int);
	int FeeCalc(int);
	void enter();
	int Receipt(int);
	void ReceiptCalc(int);
}Students;

int main()
{
	system("cls");
	int choice,rollno;
	cout<<"\n    ** Menu **  "
		 <<"\n 1. Enter new records : "
		 <<"\n 2. Fees Calculator : "
		 <<"\n 3. Display records : "
		 <<"\n 4. Fee Receipt : "
		 <<"\n 5. Exit : \n ";
	cin>>choice;
	if(choice==1)
	{
		ofstream f1("RECORDS.DAT",ios::out|ios::binary|ios::app);
		f1.seekp(ios::end);
		Students.enter();
		f1.seekp(ios::end);
		f1.write((char*) &Students,sizeof(Students));
		cout<<"\n\n       * Record Entered successfully *   ";
		getch();
		f1.close();
		main();
	}

	else
	if(choice==2)
	{
		int k;
		system("cls");
		cout<<"\n ** FEES CALCULATOR ** ";
		cout<<"\n Enter Roll No. : ";
		cin>>rollno;
		ifstream f2("RECORDS.DAT",ios::in|ios::binary);
		if(!f2)
		{
			cout<<"\n File not Found ! ";
			getch();
			main();
		}
		while(!f2.eof())
		{
			f2.read((char*) &Students,sizeof(Students));
			k=Students.FeeCalc(rollno);
			if(k==1)
			{	break;
			}
		}
		f2.close();
		getch();
		main();
	}

	else
	if(choice==3)
	{
		system("cls");
		int k;
		cout<<"\n   ** Records Display ** ";
		ifstream f3("RECORDS.DAT",ios::in|ios::binary);
		cout<<"\n Enter Roll No. : ";
		cin>>rollno;
		if(!f3)
		{
			cout<<"\n File not Found ! ";
			getch();
			main();
		}
		f3.seekg(0);
		while(!f3.eof())
		{
			f3.read((char*) &Students,sizeof(Students));
			k=Students.display(rollno);
			if(k==1)
			break;
		}

		f3.close();
		getch();
		main();
	}

	else
	if(choice==4)
	{
		clrscr();
		int k;
		cout<<"\n Enter Roll No. : ";
		cin>>rollno;
		cout<<"\n   ** Fee Receipt ** ";
		ifstream f4("RECORDS.DAT",ios::in|ios::binary);
		f4.seekg(0);
		if(!f4)
		{
			cout<<"\n File not found ! " ;
			getch();
			main();
		}
		while(!f4.eof())
		{
			f4.read((char*)& Students,sizeof(Students));
			k=Students.Receipt(rollno);
			if(k==1)
			break;
		}
		f4.close();
		getch();
		main();
	}

	else
	if(choice==5)
	{
		exit(1);
	}
	else
	if(choice==9)
	{
		remove("RECORDS.DAT");
		cout<<"\n File RECORDS.DAT Removed ";
		getch();
		main();
	}
	getch();
	return 0;
}


void FEES::enter()
{
	system("cls");
	char ch;

	cout<<"\n   ** Records Entry ** \n";
	cout<<"\n Enter Name : ";
	cin.ignore();
	cin.getline(name,20);
	cout<<"\n Enter Roll no. : ";
	cin>>roll;
	cout<<"\n Enter sex : ";
	cin>>sex;
	cout<<"\n Enter class : ";
	cin>>clas;
	cout<<"\n Enter Section : ";
	cin>>sec;

}

int FEES::FeeCalc(int rollno)
{
	int found=0;
	if(roll==rollno)
	{
		found=1;
		if(clas>=1&&clas<=5)
		{
			ReceiptCalc(clas);
			Tfee=Tution+Devep+Annual+Pupil+Grp;
		}
		if(clas>=6&&clas<=10)
		{
			ReceiptCalc(clas);
			Tfee=Tution+Devep+Annual+Pupil+Grp;
		}
		if(clas>=11&&clas<=12)
		{
			ReceiptCalc(clas);
			Tfee=Tution+Devep+Annual+Pupil+Grp;
		}
		cout<<"\n\n Total Fees : "<<Tfee;
	}

	return found;

}

int FEES::display(int rollno)
{
	int found=0;
	if(roll==rollno)
	{
		cin.ignore();
		cout<<"\n Name : "<<name;
		cout<<"\n Roll No. : "<<rollno;
		cout<<"\n Sex : "<<sex;
		cout<<"\n Class : "<<clas;
		cout<<"\n Section : "<<sec;
		found=1;
	}
	return found;
}

int FEES::Receipt(int rollno)
{
	int found=0 ;
	if(roll==rollno)
	{
		ReceiptCalc(clas);
		cout<<"\n Tution Fees : \t\t"<<Tution;
		cout<<"\n Development Fund :\t"<<Devep;
		cout<<"\n Annual Charges : \t" <<Annual;
		cout<<"\n Pupils Fund : \t\t"<<Pupil;
		cout<<"\n Group Insurance : \t"<<Grp;
		cout<<"\n\n Total Fees : \t\t"<<Tfee;
		found=1;
	}
	return found;
}

void FEES::ReceiptCalc(int clas)
{
		if(clas>=1&&clas<=5)
		{
			Tution=5680;
			Annual=1935;
			Devep=950;
			Pupil=125;
			Grp=61;
			Tfee=Tution+Devep+Annual+Pupil+Grp;
		}
		if(clas>=6&&clas<=10)
		{
			Tution=5980;
			Devep=1050;
			Annual=2035;
			Pupil=225;
			Grp=81;
			Tfee=Tution+Devep+Annual+Pupil+Grp;
		}
		if(clas>=11&&clas<=12)
		{
			Tution=8680;
			Devep=1150;
			Annual=2135;
			Pupil=251;
			Grp=101;
			Tfee=Tution+Devep+Annual+Pupil+Grp;
		}
}

