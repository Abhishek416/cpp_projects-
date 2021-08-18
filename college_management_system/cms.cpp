#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<stdio.h>
#include<fstream> 

using namespace std;

char un[20];

class Admin
{
	char name[20];
	int totsub;
	char subject[10][10];
	char mobile[15],mail[50],fname[20];
	char passwd[20],rpasswd[20];
public:
	char rollno[15];
	//this function is used to get the student data entry from the ADMIN 
	//portal...all the records entries are made by this method
	//
	void getstdata(){
		cout<<"\nEnter the Student Name: ";
		cin>>name;
		cout<<"\nEnter the Student ID/Roll No.: ";
		cin>>rollno;
		cout<<"\nEnter the Student Father's Name: ";
		cin>>fname;
		cout<<"\nEnter the Mobile Number: ";
		cin>>mobile;
		cout<<"\nEnter the E-Mail ID: ";
		cin>>mail;
		cout<<"\nEnter the Total Subjects: ";
		cin>>totsub;
		for(int i=0; i<totsub;i++){
			cout<<"\nEnter the Subject "<<i+1<<" Name: ";
			cin>>subject[i];
		}
		cout<<"\nCreate Your Login Password: ";
		cin>>passwd;
		cout<<"\nEnter the Unique Keyword to Recover Passord: ";
		cin>>rpasswd;
		cout<<"\n\nPlease note your UserName is Id/Roll no. \n";
	}

	//this function authenticates the login of both the student & faculties. 
	// With their reference to their unique ID/PASSWORD login is provided
	//
	int login(){
		if((strcmp(::un, rollno))==0){
			cout<<"\nEnter the Login Password: ";
			int len=0;
			len=strlen(passwd);
			char inputpasswd[20];
			for(int i=0; i<len; i++){
				inputpasswd[i]=getchar();
				cout<<"#";
			}
			inputpasswd[len]=NULL;
			//cout<<"\nThe Entered Password is "<<inputpasswd;
			if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
				return 1;
			else return 0;
		}
		else return 0;
	}

	//this function help both the students & faculties to recover to password
	//with the help of unique keyword provided by the Admin
	//
	int recover(){
		//cout<<"\nThe Input Username is "<<::un;
		char key[20];
		if(strcmp(::un,rollno)==0){
			cout<<"\nEnter the Unique Keyword ( Provided by The Admin ): ";
			cin>>key;
			if((strcmp(key,rpasswd)==0)){
				cout<<"\nYou are Valid user.";
				cout<<"\nYour Password is "<<passwd;
				cout<<"\nPlease Exit To Login Again ";
				return 1;
			}
			else 
				return 0;
		}
		else 
			return 0;
	}
	
	//this function displays the faculty profile to the faculty at their respective portals 
	//
	int faprofile(){
		if((strcmp(::un,rollno)==0)){
			cout<<"\nFaculty Name: 		: "<<name;
			cout<<"\nFaculty Father's Name	: "<<fname;
			cout<<"\nFaculty Mobile No.	: "<<mobile;
			cout<<"\nFaculty E-Mail ID	: "<<mail;
			return 1;
		}
		else return 0;
	}
	
	//this function displays the different subjects of the faculty at their 
	//respective portals 
	//
	int knowfasub(){
		if((strcmp(::un,rollno)==0)){
			cout<<"\nFaculity Total subjects :- "<<totsub;
			for(int i=0; i<totsub; i++){
				cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
			}
			return 1;
		}
			else 
				return 0; 
		}

	//this function helps a faculty to add a subject in their module;
	//
	void addfasub(){
		if((strcmp(::un, rollno)==0)){
			cout<<"\nEnter the New subject: ";
			cin>>subject[totsub];
			totsub++;
			cout<<"\n\nNew Subject Added Successfully...";
		}
	}
	
	//this function helps a faculty to delete a subject from their module 
	//
	void delfasub(){
		knowfasub();
		int de=0;
		if((strcmp(::un,rollno)==0)){
			if(totsub==0 || totsub<0){
				totsub=0;
				cout<<"\nNone Subject Exist...";
				getchar();
				exit(0);
			}
			cout<<"\nEnter the Subject No. to be Deleted: ";
			cin>>de;
			if(de==totsub){
				totsub--;
				strcpy(subject[totsub]," ");
			}
			else if(totsub==1){
				totsub=0;
				strcpy(subject[totsub]," ");
			}
			else{
				de--;
				strcpy(subject[totsub]," ");
						for(int p=de; p<totsub; p++){
							strcpy(subject[p],subject[p+1]);
						}
						totsub--;
			}
			cout<<"\n Records Updated Successfully...";
		}
	}

	//this function helps a faculty to modify his personal profile
	//
	void modfaprofile(){
		if((strcmp(::un,rollno)==0)){
				cout<<"\nThe Profile Details are: ";
				cout<<"\n 1. Faculity E-Mail: "<<mail;
				cout<<"\n 2. Faculty Mobile: "<<mobile;
				int g=-1;
				cout<<"\n\nEnter the Detail No. to be Modified: ";
				cin>>g;
				if(g==1){
					char nmail[50];
					cout<<"\nEnter the New Mail Address: ";
					cin>>nmail;
					strcpy(mail,nmail);
					cout<<"\nRecords Updated Successfully...";
				}
				else if(g==2){
					char nmobile[15];
					cout<<"\nEnter the New Mobile No.: ";
					cin>>nmobile;
					strcpy(mobile,nmobile);
					cout<<"\nRecords Updated Successfully...";
				}
				else
					cout<<"\nInvalid Input Provided...";
		}
	}

	//This funciton displays the student profile at the student potal
	//
	int stprofile(){
		if((strcmp(::un,rollno)==0)){
			cout<<"\nStudent Name: 		"<<name;
			cout<<"\nStudent Father's Name: "<<fname;
			cout<<"\nStudent Mobile No.:	"<<mobile;
			cout<<"\nStudent E-Mail ID:	"<<mail;
			return 1;
		}
		else return 0;
	}

	//this funciton displays the different enrolled subjects of the respective students...according to their profile.
	//
	int knowstsub(){
		if((strcmp(::un,rollno)==0)){
			cout<<"\nStudent Total Subjects :- "<<totsub;
			for(int i=0; i<totsub; i++){
				cout<<"\n\t Subject "<<i+1<<" : "<<subject[i];
			}
			return 1;
		}
		else 
			return 0;
	}
	
	//this function allows the student to add a subjects in total subjects of 
	//the student profile...
	//
	void addstsub(){
		if((strcmp(::un,rollno)==0)){
			cout<<"\nEnter the New Subject: ";
			cin>>subject[totsub];
			totsub++;
			cout<<"\n\nNew Subject Added Successfully...";
		}
	}
	
	//this funciton allows the student to delete a subjects in total subject of the student profile...
	//
	void delstsub(){
		knowstsub();
		int de=0;
		if((strcmp(::un,rollno)==0)){
			if(totsub==0||totsub<0){
				totsub=0;
				cout<<"\nNone Subjects Exist...";
				getchar();
				exit(0);
			}
			cout<<"\nEnter the Subject No. to be Deleted: ";
			cin>>de;
			if(de=totsub){
				totsub--;
				strcpy(subject[totsub]," ");
			}
			else if(totsub==1){
				totsub=0;
				strcpy(subject[totsub]," ");
			}
			else{
				de--;
				strcpy(subject[totsub]," ");
				for(int p=de; p<totsub; p++){
					strcpy(subject[p],subject[p+1]);
				}
				totsub--;
			}
			cout<<"\n Second Updated Successfully...";
		}
	}

	//this funciton allows the student to modify their their personal profile details 
	//at the student portal
	//
	void modstprofile(){
		if((strcmp(::un,rollno)==0)){
			cout<<"\nThe Profile Details are: ";
			cout<<"\n 1. Student E-Mail: "<<mail;
			cout<<"\n 2. Student Mobile: "<<mobile;
			int g=-1;
			cout<<"\n\nEnter the Detail No. to be Modified: ";
			cin>>g;
			if(g==1){
				char nmail[50];
				cout<<"\nEnter the New Mail Address: ";
				cin>>nmail;
				strcpy(mail,nmail);
				cout<<"\nRecords Updates Successfully...";
			}
			else if(g==2){
				char nmobile[15];
				cout<<"\nEnter the New Mobile No.: ";
				cin>>nmobile;
				strcpy(mobile,nmobile);
				cout<<"\nRecords Updated Successfullyy...";
			}
			else
				cout<<"\nInvalid Input Provided...";
		}
	}

	//This funciton allow the ADMIN to make a new Record Entry for the different new faculties...
	//records are updated with the help of this function
	//
	void getfadata(){
		cout<<"\nEnter the Faculty Name: ";
		cin>>name;
		cout<<"\nEnter the Faculty ID/Roll no.: ";
		cin>>rollno;
		cout<<"\nEnter the Faculty Father's Name: ";
		cin>>fname;
		cout<<"\nEtner the Mobile No.: ";
		cin>>mobile;
		cout<<"\nEnter the E-Mail Id: ";
		cin>>mail;
		cout<<"\nEnter the Total Subjects: ";
		cin>>totsub;
		//cout<<"\nThe total subjects choosen are: "<<totsub;
		for(int i=0; i<totsub; i++){
			cout<<"\nEnter the Subject "<<i+1<<" Name : ";
			cin>>subject[i];
		}
		cout<<"\nCreate Your Login Password: ";
		cin>>passwd;
		cout<<"\Enter the Unique Keyword to Recover Password :";
		cin>>rpasswd;
		cout<<"\n\nPlease note your UserName is ID/Roll no. \n";
	}
	
	//This funciton displays all the relevent information to the admin related 
	//to thi Students at the ADMIN portals 
	//
	void stdisplay(){
		cout<<"\nStudent Name: 		"<<name;
		cout<<"\nStudent ID/Roll No.: 	"<<rollno;
		cout<<"\nStudent Father's Name: "<<fname;
		cout<<"\nStudent Mobile No.:	"<<mobile;
		cout<<"\nStudent E-Mail ID: 	"<<mail;
		cout<<"\nStudent Subjects:	"<<totsub;
		for(int i=0; i<totsub; i++){
			cout<<"\n	Subject "<<i+1<<" : "<<subject[i];
		}
		if(totsub==0)
			cout<<"( None Suvjects Specified...)";
	}

	//This function displays all the revelant information to the admin related
	//to the Faculty at the ADMIN portals
	//
	void fadisplay(){
		cout<<"\nFaculty Name:		"<<name;
		cout<<"\nFaculty ID/Roll No.:	"<<rollno;
		cout<<"\nFaculty Father's Name:	"<<fname;
		cout<<"\nFaculty Mobile No.:	"<<mobile;
		cout<<"\nFaculty E-Mail ID:	"<<mail;
		cout<<"\nFaculty Subjects:	"<<totsub;
		for(int i=0; i<totsub; i++){
			cout<<"\n	Subjects "<<i+1<<" : "<<subject[i];
		}
		if(totsub==0)
			cout<<"None Subjects Specified...";
	}
}a;
		
				
Admin f;


int main(){
	int ch;
	cout<<"\n\n\n\t\t\tWelcome to RKGIT Databse Portal ";
	cout<<"\n\n\n\t\t\tEnter to Continue ";
	getchar();
	system("clear");
	cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
	cout<<"\n\t\t\tPress 2 for Faculty Portal";
	cout<<"\n\t\t\tPress 3 for Student Portal";
	cout<<"\n\n\t\tEnter Your Choice: ";
	cin>>ch;
	if(ch==1){
		char adminuser[20],adminpass[20];
		cout<<"\n\t\tWelcome To Admin Login Portal ";
		cout<<"\n\nEnter the UserName: ";
		cin>>adminuser;
		cout<<"\nEnter the Password: ";
		for(int k=0;k<8;k++){
			adminpass[k]=getchar();
			cout<<"*";
		}
		getchar();
		adminpass[8]=NULL;
		if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0)){
			system("clear");
		}
		else{
			cout<<"\n\n\t\t\t	Invalid Access to Portal ";
			cout<<"\n\n\t\t\t\tThank You !!!";
			getchar();
			exit(0);
		}
		char opera='y';
		do{
			int tmp;
			cout<<"\n\t\t\tWelcome To Admin Panel";
			cout<<"\n\nPress 1 to Add a Faculty Record ";
			cout<<"\nPress 2 to Add Multiple Records of Faculty ";
			cout<<"\nPress 3 to View All Records of Faculty ";
			cout<<"\nPress 4 to Delete a faculty Record ";
			cout<<"\nPress 5 to Add a Student Record ";
			cout<<"\nPress 6 to Add Multiple Records of Students ";
			cout<<"\nPress 7 to View All Records of Students ";
			cout<<"\nPress 8 to Delete a Student Records ";
			cout<<"\nPress 9 to Exit.";
			cout<<"\n\n\tEnter Your Choice: ";
			cin>>tmp;
			system("clear");
			if(tmp==1){ //for inserting d single faculty records 
				cout<<"\nEnter the Details :- ";
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
				a.getfadata();
				fs.write((char *)&a,sizeof(Admin));
				fs.close();
				cout<<"\nRecord Entered Successfully...";
			}
			if(tmp==2){ //for inserting d multiple faculty records
				int m=0;
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
				do{
					cout<<"\nEnter the Details :- ";
					a.getfadata();
					fs.write((char *)&a,sizeof(Admin));
					cout<<"Press 0 if you want to Enter More Records : ";
					cin>>m;
				}while(m==0);
				fs.close();
				cout<<"\nRecord Entered Successfully...";
			}
			if(tmp==3){ //for view all faculty records 
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&a,sizeof(Admin));
					a.fadisplay();
				}
				fs.close();
			}
			if(tmp==4){ //for deleting a faculty records
				char tmpfaid[15];
				int de=0,result=-1;
				cout<<"\nEnter the Faculty ID/Rollno. :-";
				cin>>tmpfaid;
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fstream fs1;
				fs1.open("fanewinfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&a,sizeof(Admin));
					result=strcmp(tmpfaid,a.rollno);
					if(result==0)
						de=1;
					else
						fs1.write((char *)&a,sizeof(Admin));
				}
				if(de==1)
					cout<<"\nRecord Deleted Successfully...";
				else
					cout<<"\nRecord not found...";
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("fanewinfo.txt","fainfo.txt");
			}
			if(tmp==5){ //for a single student record input	
				cout<<"\nEnter the Details :- ";
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
				a.getstdata();
				fs.write((char *)&a,sizeof(Admin));
				fs.close();
				cout<<"\nRecord Entered Successfully...";
			}
			if(tmp==6){ //for multiple student record inut
				int m=0;
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
				do{
					cout<<"\nEnter the Details :- ";
					a.getfadata();
					fs.write((char *)&a,sizeof(Admin));
					cout<<"Press 0 if you want to Enter More Records : ";
					cin>>m;
				}while(m==0);
				fs.close();
				cout<<"\nRecords Entered Successfully...";
			}
			if(tmp==7){ //for view of all student record
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					a.stdisplay();
				}
			}
			if(tmp==8){ //for deleting a student record
				char tmpstid[15];
				int de=0,result=-1;
				cout<<"\nEnter the Student ID/Rollnp. :- ";
				cin>>tmpstid;
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fstream fs1;
				fs1.open("stnewinfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&a,sizeof(Admin));
					result=strcmp(tmpstid,a.rollno);
					if(result==0)
						de=1;
					else
						fs1.write((char *)&a,sizeof(Admin));
				}
				if(de==1)
					cout<<"\n Record Deleted Successfully...";
				else cout<<"\nRecord not found...";
				fs.close();
				fs1.close();
				remove("stinfoi.txt");
				rename("stnewinfo.txt","stinfo.txt");
			}

			if(tmp==9){
				cout<<"\n\n\n\n\t\t\t\tThank You !!!";
				getchar();
				exit(0);
			}
			if(tmp<1 || tmp>9){
				system("clear");
				cout<<"\n\n\n\t\t\t\tInvalid Input .....";
			}
			getchar();
			cout<<"\n\nPress Y; For More Operation otherwise n : ";
			cin>>opera;
			if(opera != 'y'){
				getchar();
				system("clear");
				cout<<"\n\n\n\n\n\t\t\t\tThank You !!!";
				getchar();
			}
		}while(opera=='Y' || opera=='y');
	} //Closing of Admin Login
	
	if(ch==2){//begin of faculty view portal 
		system("clear");
		char un[20];
		int val,s=0;
		cout<<"\n\t\t\tWelcome to Faculty Login Page";
		cout<<"\n\nEnter the UserName: ";
		cin>>::un;
		fstream fs;
		fs.open("fainfo.txt",ios::in|ios::binary);
		fs.seekg(0);
		while(!fs.eof()){
			val=-1;
			fs.read((char *)&f,sizeof(Admin));
			val=f.login();
			if(val==1){
				s=1;
				break;
			}
		}
		fs.close();
		
		if(s==1){
			system("clear");
		}	
		if(s!=1){ //if first login is invalid then
			system("clear");
			int ho=0;
			cout<<"\n\n\t\tYour Login Credentials are In-Correct";
			cout<<"\nThe UserName is Your ID/Rollno.";
			cout<<"\nThe Password is Case-Sensitive.";
			cout<<"\nPress 1 to Recover Password & 2 to Re-Attempt Login ";
			cout<<"\nEnter Your Choice: ";
			cin>>ho;
			if(ho==1){ //recover password
				cout<<"Enter the UserName :- ";
				cin>>::un;
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				int re,su=-1;
				while(!fs.eof()){
					re=-1;
					fs.read((char *)&f,sizeof(Admin));
					re=f.recover();
					if(re==1){
						su=1;
						break;
					}
				}
				fs.close();
				if(su==1){
					getchar();
					system("clear");
					cout<<"\n\n\n\n\t\t\tThank You !!! ";
					getchar();
					exit(0);
				}
				else{
					cout<<"\nYou are a Invalid User.";
					getchar();
					exit(0);
				}
			} //recover password

			if(ho==2){ //re-attempt of login
				cout<<"\n\nEnter the UserName: ";
				cin>>::un;
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				int suc=-1,valu;
				while(!fs.eof()){
					valu=-1;
					fs.read((char *)&f,sizeof(Admin));
					valu=f.login();
					if(valu==1){
						suc=1;
						break;
					}
				}
				fs.close();
				if(suc==1)
					system("clear");
				else{
					getchar();
					cout<<"\nYou are an Invalid User...";
					cout<<"\nThank You !!!";
					getchar();
					exit(0);
					exit(0);
				}
			}
			if(ho!=1&&ho!=2){
				cout<<"\n\nInvalid Input Provided ";
				cout<<"\n\n\t\t\t\tThank You !!!";
				getchar();
				exit(0);
			}
		}

		//Begin of Faculty
		//
		char con='y';
		do{
			system("clear");
			cout<<"\n\n\t\t\tWelcome to Faculty Panel ";
			cout<<"\n\n\t\t\t\t\t	Your UserId is : "<<::un;
			cout<<"\n\nPress 1 to View Profile.";
			cout<<"\nPress 2 to know Your Subjects.";
			cout<<"\nPress 3 to Add a Subject.";
			cout<<"\nPress 4 to Delete a Subject.";
			cout<<"\nPress 5 to Modify Your Profile.";
			int choice;
			cout<<"\n\nEnter Your Choice: ";
			cin>>choice;
			if(choice==1){
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fs.seekg(0);
				int x;
				while(!fs.eof()){
					x=0;
					fs.read((char *)&f,sizeof(Admin));
					x=f.faprofile();
					if(x==1)
					break;
				}
				fs.close();
			}

			if(choice==2){
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fs.seekg(0);
				int y;
				while(!fs.eof()){
					y=0;
					fs.read((char *)&f,sizeof(Admin));
					int y=f.knowfasub();
					if(y==1)
						break;
				}
				fs.close();
			}
			if(choice==3){
				fstream fs;
				fstream fs1;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs1.open("tmpfainfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.addfasub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("tmpfainfo.txt","fainfo.txt");
			}
			if(choice==4){
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fstream fs1;
				fs1.open("delfainfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.delfasub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("delfainfo.txt","fainfo.txt");
			}

			if(choice == 5){
				fstream fs;
				fstream fs1;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				fs1.open("modfainfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.modfaprofile();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("modfainfo.txt","fainfo.txt");
			}

			if(choice<1||choice>5)
				cout<<"\nInvalid Input Provided !!!";
				
			cout<<"\n\n\t\t\t\tEnter To Continue";
			getchar();
			cout<<"\n\nPress y to Continue; otherwise  n : ";
			cin>>con;
			if(con!='y' && con!='Y'){
				system("clear");
				cout<<"\n\n\n\n\t\t\t\tThank You !!! ";
				getchar();
				exit(0);
			}
		}while(con=='y'||con=='Y');
	}//close of faculity view

	//begin of student view 
	//
	if(ch==3){//begin of student view 
		system("clear");
		int value,s1=0;
		cout<<"\n\t\t\tWelcome to Student Login Page";
		cout<<"\n\nEnter the UserName: ";
		cin>>::un;
		fstream fs;
		fs.open("stinfo.txt",ios::in|ios::binary);
		fs.seekg(0);
		while(!fs.eof()){
			value=-1;
			fs.read((char *)&f,sizeof(Admin));
			value=f.login();
			if(value==1){
				s1=1;
				break;
			}
		}
		fs.close();
		if(s1==1){
			system("close");
			//cout<<"\n\n\n\t\t\t\tWelcome to Student Page ";
		}
		if(s1!=1){// if first login is invalid then 
			system("clear");
			int sho=0;
			cout<<"\n\n\t\tYour Login Credentials are In-Correct";
			cout<<"\nThe UserName is Your Id/Rollno.";
			cout<<"\nThe Password is Case-Sensitive.";
			cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
			cin>>sho;
			if(sho==1){ //recover password 
				cout<<"Enter the UserName :- ";
				cin>>::un;
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				int re,su=-1;
				while(!fs.eof()){
					re=-1;
					fs.read((char *)&f,sizeof(Admin));
					re=f.recover();
					if(re==1){
						su=1;
						break;
					}
				}
				fs.close();
				if(su==1){
					getchar();
					system("clear");
					cout<<"\n\n\n\n\t\t\tThank You !!!";
					getchar();
					exit(0);
				}
				else{
					cout<<"\nYou are a Invalid User.";
					cout<<"\nThank You !!!";
					getchar();
					exit(0);
				}
			}// recover password 
			
			if(sho==2){ //re-attempt of login
				cout<<"\n\nEnter the UserName: ";
				cin>>::un;
				fstream fs;
				fs.open("stindo.txt",ios::in| ios::binary);
				fs.seekg(0);
				int suc=-1, valu;
				while(!fs.eof()){
					valu=-1;
					fs.read((char *)&f,sizeof(Admin));
					value=f.login();
					if(valu==1){
						suc=1;
						break;
					}
				}
				fs.close();
				if(suc==1){
					system("clear");
				}
				else{
					getchar();
					cout<<"\nYou are an Invalid User...";
					cout<<"\nThank You !!!";
					exit(0);
					exit(0);
				}
			}
			if(sho!= 1&& sho!= 2){
				cout<<"\n\nInvalid Input Provided. ";
				cout<<"\n\n\t\t\tthank You !!!";
				getchar();
				exit(0);
			}
		}

		
		// Begin of Student Panel
		//
		char moreop='y';
		do{
			system("clear");
			cout<<"\n\n\t\t\tWelcome to Student Panel ";
			cout<<"\n\n\t\t\t\t\t	Your UserId is: "<<::un;
			cout<<"\n\nPress 1 to View Your Profile.";
			cout<<"\nPress 2 to know Your Subject.";
			cout<<"\nPress 3 to Add a Subject.";
			cout<<"\nPress 4 to Delete a Subject.";
			cout<<"\nPress 5 to Modify Your Profile.";
			int inchoice;
			cout<<"\n\nEnter Your Choice: ";
			cin>>inchoice;
			if(inchoice==1){
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				int x;
				while(!fs.eof()){
					x=0;
					fs.read((char *)&f,sizeof(Admin));
					x=f.stprofile();
					if(x==1)
						break;
				}
				fs.close();
			}
			
			if(inchoice==2){
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				int y;
				while(!fs.eof()){
					y=0;
					fs.read((char *)&f,sizeof(Admin));
					int y=f.knowstsub();
					if(y==1)
						break;
				}
				fs.close();
			}

			if(inchoice==3){
				fstream fs;
				fstream fs1;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fs1.open("tmpstinfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.addstsub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("tmpstinfo.txt","stinfo.txt");
			}

			if(inchoice==4){
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fstream fs1;
				fs1.open("delstinfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.delstsub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("delstinfo.txt","stinfo.txt");
			}

			if(inchoice==5){
				fstream fs;
				fstream fs1;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				fs1.open("modstinfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.modstprofile();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("modstinfo.txt","stinfo.txt");
			}
			if(inchoice<1||inchoice>5)
				cout<<"\nInvalid Input Provided...";
			cout<<"\n\n\n\t\t\tEnter to Continue ";
			getchar();
			cout<<"\n\nPress Y, Otherwise n to perform More Operations : ";
			cin>>moreop;
			if(moreop!='Y'&&moreop!='y'){
				system("clear");
				cout<<"\n\n\n\t\t\tThank You !!!";
				getchar();
				exit(0);
			}
		}while(moreop=='Y'||moreop=='y');
		getchar();
	}
	
	if(ch<1||ch>3){
		cout<<"Invalid Input Provided !!!";
		system("clear");
		cout<<"\n\n\n\t\t\tThank You";
	}

	return 0;
	
}




			
			
