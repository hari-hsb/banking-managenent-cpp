#include<bits/stdc++.h>
#include<string>
using namespace std;
	fstream file;
	fstream helper;
	class account{
		int acc_no;
		string name;
		int dep;
		string type;
		public:
			void create_accnt();
			void show_accnt();
			void modify();
			void deposit(int x);
			void withdraw(int x);
			void report();
			int retaccnt();
			int retdeposit();
			string rettype();
			string retname();
	};
	string account::retname()
	{
		return name;
	}
	void account::create_accnt()
	{
		char ch;
		cout<<"enter account number"<<endl;
		cin>>acc_no;
		cout<<"enter the name of holder"<<endl;
		cin.ignore();
		getline(cin,name);
		cout<<"enter the type of account....." <<endl<<"C for curent"<<endl<<"S for Saving"<<endl;
		cin>>ch;
		ch=toupper(ch);
		type=(ch=='C')?"Current":"Saving";
		cout<<"enter the initial amout"<<endl;
		cin>>dep;
		cout<<"ACCOUNT CREATED SUCESSFULLY...."<<endl;
		
		
	}
	void account::show_accnt()
	{
		cout<<"Accnt. Number:  "<<acc_no<<endl;
		cout<<"Accnt. Holder Name:  "<<name<<endl;
		cout<<"Accnt. type:  "<<type<<endl;
		cout<<"Accnt. Balance:  "<<dep<<endl;
		
	}
	void account::modify()
	{
		char ch;
		cout<<"Accnt. Number:  "<<acc_no<<endl;
		cout<<"Modifiy  name of holder"<<endl;
		cin.ignore();
		getline(cin,name);
		cout<<" Modify the type of account....." <<endl<<"C for curent"<<endl<<"S for Saving"<<endl;
		cin>>ch;
		ch=toupper(ch);
		type=(ch=='C')?"Current":"Saving";
		cout<<"Modify the initial amout"<<endl;
		cin>>dep;
		
	}
	void account::deposit(int x)
	{
		dep+=x;
	}
	void account::withdraw(int x)
	{
		dep-=x;
	}
	void account::report()
	{
		cout<<acc_no<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<dep<<endl;
	}
	int account::retaccnt()
	{
		return acc_no;
	}
	int account::retdeposit()
	{
		return dep;
	}
	string account::rettype()
	{
		return type;
	}
	// functions
	 void new_accnt();
	 void display_accnt(int);
	 void modify_accnt(int x);
	 void delete_accnt(int x);
	 void display_all();
	 void deposit_withdraw(int x,int y);
	 void intro();
	 
	 int main()
	 {
	 	char c;
	 	int accno;
	 	//intro();
	 	do{
	 		system("cls");
	 		cout<<"*****  MAIN MENU ******"<<endl<<endl<<endl;
	 		cout<<"\t 01. NEW ACCNT "<<endl;
	 		cout<<"\t 02. DEPOSIT "<<endl;
	 		cout<<"\t 03. WITHDRAW "<<endl;
	 		cout<<"\t 04. Balance Inquary"<<endl;
	 		cout<< "\t 05. All Acconut holder list"<<endl;
	 		cout<<"\t 06. close an Accnt"<<endl;
			cout<<"\t 07. Modify an Accnt "<<endl;
			cout<<"\t 08. Exit"<<endl;	 	
			cout<<"Enter your choice (1-8)"<<endl;
			cin>>c;
			system("cls");
			switch(c)
			{
				case '1':
					new_accnt();
					break;
				case '2':
					cout<<"enter the account number"<<endl;
					cin>>accno;
					deposit_withdraw(accno,1);
					break;
				case '3':
					cout<<"enter the account number"<<endl;
					cin>>accno;
					deposit_withdraw(accno,2);
					break;
				case '4':
					cout<<"enter the account number"<<endl;
					cin>>accno;
					display_accnt(accno);
					break;
				case '5':
					 display_all();
					 break;
				case '6':
					cout<<"enter the account number"<<endl;
					cin>>accno;
					delete_accnt(accno);
					break;
				case '7':
					cout<<"enter the account number"<<endl;
					cin>>accno;
					modify_accnt(accno);
					break;
				case '8':
					cout<<"thank u for ur visit"<<endl;
					break;
				default:
					cout<<"\a";
					
				
			}
			cin.ignore();
			cin.get();	
		 }
		 while(c!='8');
		 
		return 0;
		 
	 	
	 }
	 
	 //func_desc
	void new_accnt()
	{
		
	account ac;
	
	file.open("account.txt",ios::binary|ios::app);
	ac.create_accnt();
	file<<ac.retaccnt()<<"|"<<ac.retname()<<"|"<<ac.rettype()<<"|"<<ac.retdeposit()<<endl;
	file.close();
	

    
	}
	void display_accnt(int id)
	{
		bool flag=false;
		
		
		string str,accnt,name,type,deposit;
		file.open("account.txt",ios::binary|ios::in|ios::out);
		if(!file)
		{
			cout<<"FILE NOT FOUND..........."<<endl;
			return;
		}
		cout<<"Balance Detalis..."<<endl;
		while(getline(file,str))
		{
		//	cout<<"not end of file"<<endl;
		
		stringstream X(str);
		getline(X,accnt,'|');
		getline(X,name,'|');
		getline(X,type,'|');
		getline(X,deposit,'\n');
		//cout<<accnt<<" "<<name<<" "<<type<<" "<<deposit<<endl;
		
		    string str1=to_string(id);
		    
		   
			if(str1==accnt)
			{
				cout<<"Accnt. Number:  "<<accnt<<endl;
			cout<<"Accnt. Holder Name:  "<<name<<endl;
			cout<<"Accnt. type:  "<<type<<endl;
			cout<<"Accnt. Balance:  "<<deposit<<endl;
				flag=true;
				break;
				
				
			}
			
		}
			file.close();
			if(flag==false)
			{
				cout<<"account details not exist";
				
			}
			
	}
	
	void modify_accnt(int x)
	{
	
		bool flag=false;
		string new_name,new_type,new_dep;
		
		string str,accnt,name,type,deposit;
		file.open("account.txt",ios::binary|ios::in|ios::out);
		helper.open("helper.txt",ios::out|ios::app);
		
		if(!file)
		{
			cout<<"FILE NOT FOUND"<<endl;
			return;
		}
		
		while(getline(file,str))
		{
		//	cout<<"not end of file"<<endl;
		
			stringstream X(str);
			getline(X,accnt,'|');
			getline(X,name,'|');
			getline(X,type,'|');
			getline(X,deposit,'\n');
			 string str1=to_string(x);
			if(str1==accnt)
			{
				
				char ch;
			
				cout<<"Modifiy  name of holder"<<endl;
				cin.ignore();
			
				getline(cin,new_name);
				cout<<" Modify the type of account....." <<endl<<"C for curent"<<endl<<"S for Saving"<<endl;
				cin>>ch;
				ch=toupper(ch);
				new_type=(ch=='C')?"Current":"Saving";
				cout<<"Modify the initial amout"<<endl;
				cin>>new_dep;
				
				helper<<x<<"|"<<new_name<<"|"<<new_type<<"|"<<new_dep<<endl;
				flag=true;
			}
			else
			{
				helper<<accnt<<"|"<<name<<"|"<<type<<"|"<<deposit<<endl;
			}
		}
		file.close();
		helper.close();
		
		if(flag==false)
		{
			cout<<"account details not exist";
				
		}
		else
    	{
        	cout<<"THE RECORD IS UPDATED "<<(char)1<<endl;

    	}
    	remove("account.txt");
    	rename("helper.txt","account.txt");

			
		
	}
	void delete_accnt(int x)
	{
		bool flag=false;
	//	string new_name,new_type,new_dep;
		
		string str,accnt,name,type,deposit;
		file.open("account.txt",ios::binary|ios::in|ios::out);
		helper.open("helper.txt",ios::out|ios::app);
		
		if(!file)
		{
			cout<<"FILE NOT FOUND"<<endl;
			return;
		}
		
		while(getline(file,str))
		{
		//	cout<<"not end of file"<<endl;
		
			stringstream X(str);
			getline(X,accnt,'|');
			getline(X,name,'|');
			getline(X,type,'|');
			getline(X,deposit,'\n');
			string str1=to_string(x);
			if(str1!=accnt)
			{
				
				helper<<accnt<<"|"<<name<<"|"<<type<<"|"<<deposit<<endl;
				flag=true;
			}
		
		}
		file.close();
		helper.close();
		
		if(flag==false)
		{
			cout<<"account details not exist";
				
		}
		else
    	{
        	cout<<"THE ACCOUNT IS DELETED "<<(char)1<<endl;

    	}
    	remove("account.txt");
    	rename("helper.txt","account.txt");

	}
	
	void display_all()
	{
		cout<<"-----------------------------------------------------------------------------"<<endl;
		cout<<"************************         ALL USERS          *************************"<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Accnt.no                 Name                   type              balance"<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		string str,accnt,name,type,deposit;
		file.open("account.txt",ios::binary|ios::in|ios::out);
	//	helper.open("helper.txt",ios::out|ios::app);
		
		if(!file)
		{
			cout<<"FILE NOT FOUND"<<endl;
			return;
		}
		
		while(getline(file,str))
		{
		//	cout<<"not end of file"<<endl;
		
			stringstream X(str);
			getline(X,accnt,'|');
			getline(X,name,'|');
			getline(X,type,'|');
			getline(X,deposit,'\n');
			cout<<setw(8)<<accnt<<setw(30)<<name<<setw(15)<<type<<setw(20)<<deposit<<endl;
		}
		file.close();
	}
	void deposit_withdraw(int x,int y)
	{
		int bal;
		
		bool flag=false;
		bool limit=true;
		string new_name,new_type,new_dep;
		
		string str,accnt,name,type,deposit;
		file.open("account.txt",ios::binary|ios::in|ios::out);
		helper.open("helper.txt",ios::out|ios::app);
		
		if(!file)
		{
			cout<<"FILE NOT FOUND"<<endl;
			return;
		}
		
		while(getline(file,str))
		{
		//	cout<<"not end of file"<<endl;
		
			stringstream X(str);
			getline(X,accnt,'|');
			getline(X,name,'|');
			getline(X,type,'|');
			getline(X,deposit,'\n');
			 string str1=to_string(x);
			if(str1==accnt)
			{
				
				int depo;
				bal=stoi(deposit);
				switch(y)
				{
					case 1:
						cout<<"enter the amount you want to deposit: ";
						cin>>depo;
						bal=bal+depo;
						break;
					
					case 2:
						cout<<"enter the amount you want to withdraw: ";
						cin>>depo;
						if(depo>bal) 
						{
							cout<<"insufficient balance \n return to main menu"<<endl;
							limit=false;
							
							
						}
						else
						{
							bal=bal-depo;	
						}
						
						break;
						
				}
				
				
				deposit=to_string(bal);
				flag=true;
			}
		
				helper<<accnt<<"|"<<name<<"|"<<type<<"|"<<deposit<<endl;
			
		}
		file.close();
		helper.close();
		
		if(flag==false)
		{
			cout<<"account details not exist";
				
		}
		else
    	{
        	if(y==1) cout<<"deposit sucessful!!!"<<endl;
        	if(y==2 && limit==true) cout<<"withdraw sucessfull!!!"<<endl;
        	cout<<"remaining balance: "<<bal<<endl;

    	}
    	remove("account.txt");
    	rename("helper.txt","account.txt");
	}

	

