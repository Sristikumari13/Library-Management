#include<bits/stdc++.h>
  using namespace std;
  
  class Date
  {
  	private:
  		int dd,mm,yy;
  		void rectifyDate()
  		{
  			if(dd>30)
  			{
  			    dd -= 30;
				mm++;	
			}
			if (mm>12)
			{
				mm -= 12;
				yy++;
			}
		  }
  
  public:
  	Date()
  	{
  		dd= 1;
  		mm= 1;
  		yy= 2022;
	}
	void setDate()
	{
		cout<<"\t\t Enter Date: "<<endl;
		cin>>dd;
		cout<<"\t\t Enter Month: "<<endl;
		cin>>mm;
		cout<<"\t\t Enter year: "<<endl;
		cin>>yy;
	}
	void setDate(Date temp)
	{
		dd = temp.dd + 15;
		mm = temp.mm;
		yy = temp.yy;
		rectifyDate();
	}
	void ShowDate()
	{
		cout<<dd<<"/"<<mm<<"/"<<yy;
	}		
};
class Menu
{  
	public:
		void breakline();
		void mainMenu();
		void studentMenu();
		void bookMenu();
		void issueBook();
		void returnBook();
};

void Menu:: breakline()
{
	int i=0;
	for(;i<360;i++)
	cout<<"*";
	cout<<endl;
	return ;
}

void Menu :: mainMenu()

{
		cout<<endl;
		system("color 0A");
		cout<<"\t\t\t\t\t    WELCOME TO LIBRARY MANAGEMENT SYSTEM \n";
		cout<<endl;
		breakline();
		cout<<endl;
	cout<<"\t\t\t\t\t  **********  Main Menu  ***********\t\t\t\t\t"<<endl<<endl;
	cout<<"\t\t1. Student Menu\n \t\t2. Book Menu\n \t\t3. Issue Book \n \t\t4. Return Book\n";
	cout<<" \t\t5. Exit"<<endl;
}

void Menu :: studentMenu()
{
	cout<<endl;
		system("color 0B");
		cout<<"\t\t\t\t\t    WELCOME TO STUDENT MENU \n";
		cout<<endl;
		breakline();
		cout<<endl;
	cout<<"\t\t\t\t\t  **********  Student Menu  ***********\t\t\t\t\t"<<endl<<endl;
	cout<<" \t\t1. New Entry\n \t\t2. Modify Entry\n \t\t3. Search Entry\n \t\t4. Delete Entry"<<endl;
	cout<<" \t\t5. View Student Detail\n \t\t6. GO back to Perivious Menu"<<endl;
}

void Menu :: bookMenu()
{
	cout<<endl;
		system("color 0e");
		cout<<"\t\t\t\t\t    WELCOME TO BOOK MENU \n";
		cout<<endl;
		breakline();
		cout<<endl;
	cout<<"\t\t\t\t\t  **********  Book Menu  ***********\t\t\t\t\t"<<endl<<endl;
	cout<<" \t\t1. New Entry\n \t\t2. Modify Entry\n \t\t3. Search Entry \n \t\t4. Delete Entry"<<endl;
	cout<<" \t\t5. View Book Detail\n \t\t6. GO back to Perivious Menu"<<endl;
}
class BookData
{
   public:
   char title[30],author[30],Publisher[30];
   int status,issueRoolNo;
   float price;
   Date  issuedate;
   Date returnDate;
   BookData()
   {
   	  status=   0;
   	  issueRoolNo = -9999;
   }
};
class studentData
{
	public:
	int rollNo;
	char name[30],address[40],branch[5],booktitle[30];
	int status;
	studentData()
	{
		status = 0;
	}
};

           // BOOK CLASS STARTED HERE //
class Book
{
	public:
	void inputDetails();
	void modifyDetails();
	void serchDetails();
	void deleteDetails();
	void viewAllBookDetail();
};

                   // BOOK  ALL FUNCTION STARTED HERE //  
            
	
 void Book :: inputDetails()
 {
 	fstream ofp;
 	ofp.open("bookDatabase.dat",ios :: out | ios :: binary | ios :: app);
 	if(!ofp)
 	{
 		cout<<" \t\t\t Unable To Open file!!! \t\t"<<endl;
 		return;
	}
	
	BookData book;
	cout<<"\n\n\t\t Enter book Title: ";
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //buffer flush
	cin.getline(book.title, 30);
	cout<<"\t\t Enter Author's Name: ";
		cin.getline(book.author, 30);
	cout<<"\t\t Enter Book Publisher: ";
		cin.getline(book.Publisher, 30);
	cout<<"\t\t Enter Book Price: ";
	cin>>book.price;
	  ofp.write((char*)&book,sizeof(book));
	  ofp.close();
	  cout<<"\n\n\t\t\t BOOK IS ADDED TO DATABASE !!!\t\t "<<endl;
	  system("pause");
	  return;
 }
 void Book :: modifyDetails()
 {
 	fstream file;
 	file.open("bookDatabase.dat", ios :: binary | ios :: in | ios :: out| ios :: ate);
 	
 	if(!file)
 	{
 		cout<<" \t\t\t Unable To Open file!!! \t\t"<<endl;
 		system("pause");
 		return;
	}
	  file.seekg( 0 , ios :: beg);
	  
	  BookData book;
	  char title[30];
	  cout<<"\t\t\t Enter Book title of the Book you want to modify : "<<endl;
	  cin.getline(title, 30);
	  
	  while(file.read((char*)&book,sizeof(book)))
	  {
	  	if(strcmp(book.title,title) == 0 )
	  	{
	  		int position = -1;
			position *=  sizeof(book);
	  		file.seekp(position,  ios :: cur);
	  		
	  		cout<<"\t\t Enter New book Title: ";
				  cin.getline(book.title, 30);
			cout<<"\t\t Enter New Author's Name: ";
				  cin.getline(book.author, 30);
			cout<<"\t\t Enter New Book Publisher: ";
				  cin.getline(book.Publisher, 30);
			cout<<"\t\t Enter New Book Price: ";
			cin>>book.price;
			
			cout<<" \t\t\t RECORD UPDATED!!! \t\t" <<endl;
			system("pause"); 
			return ;
		}
	  }
	  cout<<" \t\t\t Book not found !!! \t\t";
	  system("pause"); 
	  file.close();
	  return;	  
 }

void Book :: serchDetails()
{
	fstream file;
 	file.open("bookDatabase.dat",ios :: in | ios :: binary);
 	if(!file)
 	{
 		cout<<" \t\t\t Unable To Open file!!! \t\t"<<endl;
 		system("pause");
 		return;
	}
	  BookData book;
	  char title[30];
	  
	  cout<<"Enter Book title of the Book you want to modify : "<<endl;
	  cin>>title;
	  
	   while(file.read((char*)&book,sizeof(book)))
	  {
	  	if(strcmp(book.title,title) == 0 )
	  	{
	  		cout<<"Book title: "<<book.title<<endl;
	  		cout<<"Book Publisher: "<<book.Publisher<<endl;
	  		cout<<"Book Author: "<<book.author<<endl;
	  		cout<<"Book Price:"<<book.price<<endl;
	  		if(book.status == 1)
	  		{
	  			cout<<"Issue Status :"<<book.issueRoolNo<<endl;
	  			cout<<"Issued Date :";
	  			book.issuedate.ShowDate();
	  			cout<<endl<<"Return Date: ";
	  			book.returnDate.ShowDate();
	  			cout<<endl;
			}
			else
			{
				cout<<"\t\t\t Issued status: None\t\t"<<endl;
			}
			system("pause"); 
			return;
		}
	}
	cout<<" \t\t\t Book Not found !!! \t\t"<<endl;
	system("pause"); 
	file.close();
	return;  	
}


void Book :: deleteDetails()
{
	fstream file,temp ;
	file.open("bookDatabase.dat",ios ::binary | ios :: in);
	temp.open("temp.dat", ios :: binary | ios :: out);
	
	char  title[30];
	BookData book;
	int flag = 0 ;
	
	cout<< " \n\t\t Enter the Book title to Remove : ";
	cin>> title;
	while(file.read((char*)&book,sizeof(book)))
	{
		if (strcmp(book.title , title) == 0)
		{
			flag++;
			continue;
		}
		temp.write((char*)&book,sizeof (book));
	}
	file.close();
	temp.close();
	remove("bookDatabase.dat");
	rename("temp.dat","bookDatabase.dat");
	
	if(flag == 1)
	{
		cout<<" \n\n\t\t\t RECORD DELETED!!! \t\t "<<endl;
	}
	else 
	{
		cout<<" \n\n\t\t\t RECORD NOT FOUND !!! \t\t"<<endl;
	}
	system("pause");
	return;
}

void Book :: viewAllBookDetail()
{
 	fstream file;
 	file.open("bookDatabase.dat", ios :: binary | ios :: in );
 	file.seekg( 0 , ios :: beg);
 	BookData book;
	int choice = 1;
 	 
 	 while(file.read((char*)&book,sizeof(book))&&choice)
 	 {
 	 		
 	 		system("cls"); // clear
 	 		cout<<"\t\t Book title: "<<book.title<<endl;
	  		cout<<"\t\t Book Publisher: "<<book.Publisher<<endl;
	  		cout<<"\t\t Book Author: "<<book.author<<endl;
	  		cout<<"\t\t Book Price:"<<book.price<<endl;;
	  		if(book.status == 1)
	  		{
	  			cout<<"\t\t Issue Status :"<<book.issueRoolNo<<endl;
	  			cout<<"\t\t Issued Date :";
	  			book.issuedate.ShowDate();
	  			cout<<endl<<"Return Date: ";
	  			book.returnDate.ShowDate();
 	 		}
 	 		else 
 	 		{
 	 			cout<<"\n\t\t\t Issued status: NONE \t\t "<<endl;
			}
		cout<< " \n\n\t\t\t Press 1 to view the next Book else 0 !!! \t";
		cin>>choice;
	  }
	  cout<<" \n\n\t\t\t Book is not Available!!! \t\t"<<endl;
	  system("pause");
	  return;
}

          // Student CLASS STARTED HERE //  
          
class student 
{
	public:
	void inputDetails();
	void modifyDetails();
	void searchDetails();
	void viewAllStudentDetail();
	void deleteDetails();
};      

         // STUDENT  ALL FUNCTION STARTED HERE //  

void student :: inputDetails()
{
	fstream ofp;   // output file pointer
	ofp.open("studentDatabase.dat",ios :: out| ios :: app | ios :: binary);
	
	if (!ofp)
	{
		cout<<" \t\t\t UNABLE TO OPEN FILE!!! \t\t "<<endl;
		system("pause");
		return;
	}
	studentData student ;
	cout<<"\t\t Enter Student's Roll No. : ";
		  cin>>student.rollNo;
	cout<<"\t\t Enter Student's Name : ";
	      cin.ignore(numeric_limits<streamsize>::max(),'\n');
		  cin.getline(student.name, 30);
	cout<<"\t\t Enter Student's Address : ";
		  cin.getline(student.address, 30);
	cout<<"\t\t Enter The Student's Branch : ";
		  cin.getline(student.branch, 30);
	
	cout<<" \n\n\t\t\t RECORD ADDED TO DATABASE!!! \t\t"<<endl;
	ofp.write((char*)&student,sizeof(student));
	ofp.close();
	system("pause");
}

void student :: modifyDetails()
{
	fstream fp;
	fp.open("studentDatabase.dat", ios :: binary | ios :: in | ios :: out| ios :: ate);
	   
	   if(!fp)
	   {
	   	cout<<" \t\t\t Unable to open file!!! \t\t"<<endl;
	   	system("pause");
	   	return ;
	   }

	   fp.seekg(0, ios :: beg);
	   int target ;
	   cout <<" \t\t Enter the Students's Roll No. To modify : "<<endl;
	   cin>>target ;
	   
	   studentData student ;
	   
	    while(fp.read((char*)&student,sizeof(student)))
	  {
	  	if(target == student.rollNo)
	  	{
	  		int position = -1;
			position *= sizeof(student);
	  		fp.seekp(position,  ios :: cur);
	  		
	  		cout<<"\t\t Enter Student's new Roll No. : ";
			cin>>student.rollNo;
			cout<<"\t\t Enter Student's new Name : ";
				  cin.getline(student.name, 30);
				  cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\t\t Enter Student's new Address : ";
				  cin.getline(student.address, 30);
			cout<<"\t\t Enter Student's new  branch : ";
				  cin.getline(student.branch, 30);
			
			fp.write((char*)&student, sizeof(student));
			fp.close();
            
            cout<<" \\t\t\t RECORD UPDATED!!! \t\t"<<endl;
            return;
		}
	  }
	  cout<< " \t\t\t ROll NO. NOT FOUND!!! \t\t "<<endl;
	  fp.close();
	  system("pause");
	  return;
}

void student :: searchDetails()
{
	fstream ifp;
 	ifp.open("studentDatabase.dat",ios :: in | ios :: binary);
 	if(!ifp)
 	{
 		cout<<" \t\t\t Unable To Open file! \t\t "<<endl;
 		system("pause");
 		return;		
	}
	   int target;
	   cout<<"\n\n\t\t\tEnter Roll no. to Search : ";
	   cin>>target;
	   
	   studentData student;
	    while(ifp.read((char*)&student, sizeof(student)))
	    {
	    	if ( target == student.rollNo)
	    	{
	    		cout<<"\n\t\t\t RECORD FOUND! \t\t"<<endl;
	    		cout<<"\t\t Student's Name: "<<student.name<<endl;
	    		cout<<"\t\t Student's Roll no. : "<<student.rollNo<<endl;
	    		cout<<"\t\t Student's Branch : "<<student.branch<<endl;
	    		cout<<"\t\t Student's Address : "<<student.address<<endl;
	    		
	    		if (student.status == 1)
	    		{
	    			cout<<"\t\t  Issued Book name is : "<<student.booktitle<<endl;
				}
				else
				{
					cout<<" \t\t\t No Book Is issued for this roll no. \t\t"<< endl;
				}
	    		system("pause");
			    ifp.close();
	    		return;
			}
		}
		
		cout<<" \t\t\t Record not Found!!! \t\t"<<endl;
		ifp.close();
		system("pause");
		return;
}
 void student :: viewAllStudentDetail()
 {
 	system("cls");
 	fstream ifp;
 	ifp.open("studentDatabase.dat", ios :: in | ios ::binary);
 	
 	if ( !ifp)
 	{
 		cout<<"\t\t\t Unable to open file!!!\t\t "<<endl;
	   	return ;
	}
	
	studentData student;
	int choice = 1;
	
	while(ifp.read((char*)&student, sizeof(student)) && choice)
	{
	 	system("cls");
	    cout<<"\t\t Student's Name: "<<student.name<<endl;
	    cout<<"\t\t Student's Roll no. : "<<student.rollNo<<endl;
	   	cout<<"\t\t Student's Branch : "<<student.branch<<endl;
	   	cout<<"\t\t Student's Address: "<<student.address<<endl;
	   	 
	   	 if (student.status == 1)
	   	 {
	   	 	cout<<"\t\t Issued Book Name Is : "<<student.booktitle<<endl;
		 }
		 else
		 {
		 	cout<<"\n\t\t No Book Is Issued for this Roll no.!!! \t\t "<<endl;
		 }
		 cout<< " \n\n\t\t\t Press 1 to view the next record else 0 !!! \t ";
		 cin>>choice;		
	}
	cout<<" \n\n\t\t\t Student is not Available!!! \t\t"<<endl;
	system("pause");
	return;
 }
void student :: deleteDetails()
{
	fstream file , temp;
	file.open("studentDatabase.dat", ios ::in | ios :: binary);
	temp.open("temp.dat", ios :: out | ios :: binary);
	
	studentData student;
	int target;
	int flag = 0;
	cout<<" \t\t\t Enter Roll no. To delete Data : ";
	cin>> target;

	while (file.read((char*)&student, sizeof(student)))     
	{
		if(student.rollNo == target)
		{
			flag++;
			continue;
		}
		temp.write((char*)&student,sizeof(student));  
	}
	file.close();
	temp.close();
	remove("studentDatabase.dat");
	rename("temp.dat","studentDatabase.dat");
	
	if(flag == 1)
	{
		cout<<" \t\t\t RECORD DELETED \t\t\t" <<endl;
	}
	else 
	{
		cout<<"\t\t\t Roll No. NOT FOUND !!! \t\t"<<endl;
	}
	system("pause"); 
	return;
}
      // function of issue book

void Menu :: issueBook()
{
	fstream sp, bp ;
	sp.open("studentDatabase.dat",ios :: in |ios :: out | ios ::ate |ios ::binary);
	bp.open("bookDatabase.dat",ios::in | ios :: out | ios:: ate |ios ::binary);
		bp.seekg(0, ios :: beg);
		sp.seekg(0, ios :: beg);
		
		int rollNo, flagS= 0, flagB = 0, position;
		char title[30];
		studentData student;
		BookData book;
		
		cout<<" \n\n\t\t Enter Student's Roll No. To Issue Book :  ";
		cin>>rollNo;
		
		while( sp.read((char*)&student,sizeof(student)))
		{
			if( student.rollNo == rollNo)
			{
				position = (-1);
				position *= sizeof(student);
				sp.seekp(position,ios ::cur);
				flagS++;
				break;
			}
		} 
		if (flagS != 1)
		{
			cout<<"\t\t\t Records not Found!!! \t\t"<<endl;
			system("pause");
			sp.close();
			bp.close();
			return;
		}
		
		cout<<" \n\n\t\t Enter Book Tittle you want to issue : " ;
		cin>>title;
		
		while(bp.read((char*)&book,sizeof(book)))
		{
			if(strcmp(book.title,title) == 0)
			{
				position = (-1);
				position*= sizeof(book);
				bp.seekp(position,ios:: cur);
				flagB++;
				break;
			}
		}
		
		if( flagB != 1)
		{
			cout<<"\t\t\t Record Not found!!! \t\t"<<endl;
			system("pause");
			sp.close();
			bp.close();
			return;
		}
		 
		 if (student.status != 1 && book.status != 1)
		 {
		 	strcpy(student.booktitle,title);
		 	student.status = 1;
		 	book.status = 1;
		 	book.issueRoolNo = student.rollNo;
		 	book.issuedate.setDate();
		 	book.returnDate.setDate(book.issuedate);
		 	sp.write((char*)&student,sizeof(student));
		 	bp.write((char*)&book,sizeof(book));
		 	sp.close();
		 	bp.close();
		 	cout<< "\n\n\t\t\t Book is issued \t\t "<<endl;
		 	system("pause");
		 }
		 else
		 {
		 	if(student.status == 1)
		 	{
		 		cout<<" \n\n\t\t\t Student's Acccount is Already Full!!!  \t\t"<<endl;
		 		system("pause");
		 		sp.close();
		 		bp.close();
		 		return;
			 }
			 else
			 {
			 	cout<<"\n\n\t\t\t Book Is Already issued \t\t"<<endl;
			 	system("pause");
			 	sp.close();
			 	bp.close();
			 	return;
			 }
		 }
}

void Menu :: returnBook()
{
	    cout<<endl;
		cout<<"\t\t\t\t\t    WELCOME TO RETURN BOOK MENU \n";
		cout<<endl;
		breakline();
		cout<<endl;
	fstream sp, bp ;
	sp.open("studentDatabase.dat",ios :: in |ios :: out | ios ::ate |ios ::binary);
	bp.open("bookDatabase.dat",ios::in | ios :: out | ios:: ate |ios ::binary);
		bp.seekg(0, ios :: beg);
		sp.seekg(0, ios :: beg);
		
		int rollNo, flagS= 0 ,flagB = 0, position;
		char title[20];
		studentData student;
		BookData book;
		
		cout<<" \t\t\t Enter Student's Roll No.  To Return Book : \t\t"<<endl;
		cin>>rollNo;
		
		while( sp.read((char*)&student,sizeof(student)))
		{
			if( student.rollNo == rollNo)
			{
				position = (-1);
				position*=  sizeof(student);
				sp.seekp(position,ios ::cur);
				flagS++;
				break;
			}
		}
		if (flagS != 1)
		{
			cout<<" \t\t\t Records not Found \t\t"<<endl;
			system("pause");
			sp.close();
			bp.close();
			return;
		}
		  
		  while( bp.read((char*)&book,sizeof(book)))
		  {
		  	if(strcmp(book.title,student.booktitle) == 0)
		  	{
		  		position = (-1);
				position*= sizeof(book);
				sp.seekp(position,ios ::cur);
				flagB++;
				break;
			}
		  }
		  	if (flagB != 1)
		{
			cout<<" \t\t\t Records not Found \t\t"<<endl;
			system("pause");
			sp.close();
			bp.close();
			return;
		}
		if (student.status == 1 && book.status ==1)
		 {
		 	student.status = 0;
		 	book.status = 0;
		 	book.issueRoolNo = -9999;
		 	sp.write((char*)&student,sizeof(student));
		 	bp.write((char*)&book,sizeof(book));
		 	sp.close();
		 	bp.close();
		 }
		 else
		 {
		 	if(student.status == 1)
		 	{
		 		cout<<"\t\t\t Student's Acccount is Already Full!!! \t\t"<<endl;
		 		system("pause");
		 		sp.close();
		 		bp.close();
		 		return;
			 }
			 else
			 {
			 	cout<<" \t\t\t Book Is Already issued!!! \t\t "<<endl;
			 	system("pause");
			 	sp.close();
			 	bp.close();
			 	return;
			 }
		 }
}

                                   //  Main MENU   
    
    
int main()
{
	Menu menu;
	int quit = 0;
	char choice[3];
	
	 while ( !quit)
	 {
	 	system("cls");
	 	system("color 0A");
	 	menu.mainMenu();
	 	cout<<" \n\n\t\t\t Please Enter Your Choice : ";
	 	cin>>choice;
	 	switch(atoi(choice))    // atoi converts in string to integer 
	 	
	 	{
	 		case 1:
	 			{
	 				system("cls");
	 				system("color 0B");
	 				menu.studentMenu();
	 				cout<<" \n\n\t\t\t Please Enter Your Choice : ";
	 				cin>>choice;
	 				student s1;
	 				switch(atoi(choice))
	 				{
	 					case 1: s1.inputDetails();
	 					break;
	 					case 2: s1.modifyDetails();
	 					break;
	 					case 3: s1.searchDetails();
	 					break;
	 					case 4: s1.deleteDetails();
	 					break;
	 					case 5: s1.viewAllStudentDetail();
	 					break;
	 					case 6: break;
	 					default: cout<<" \n\n\t\t\t Wrong Input recived!!! \\t\t"<<endl;
	 					system("pause");
					 }
					 break;
				 }
	 		
			 case 2 : {
				system("cls");
				system("color 0e");
				menu.bookMenu();
				cout<<"\n\n\t\t\t Please Enter your choice: ";
				cin>>choice;
				Book b1;
				switch(atoi(choice))
				{
					case 1: b1.inputDetails();
					        break;
					case 2: b1.modifyDetails();
							break;
					case 3: b1.serchDetails();
							break;
					case 4: b1.deleteDetails();
							break;
					case 5: b1.viewAllBookDetail();
							break;
					case 6: break;
					default: cout<<" \n\n\t\t\t Wrong Input recived!!! \t\t"<<endl;
					system("pause");
				}
					    break;    
				}
			case 3: system("color 9");
					menu.issueBook();
			   		break;	
			case 4: system("color 0d");
					menu.returnBook();
			   		break;
			case 5: system("color 4");
			        quit++;
					break;
			default:    system("color 4");
			            cout<<"\n\\n\t\t\t\t  ########  Please Enter Correct input!!! ######## \t\t\t\t"<<endl;
						cin>>choice; 	
	}
}

}
