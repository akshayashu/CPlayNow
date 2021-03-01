#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student{
	
	char name[30];
 	int rollNo;
	int age;
	int classNo;
 	char phone[15];
 	char address[60];

public:
	int retClassNo();
	int retRollNo();
	void getData();
	void showData();
	
};

int Student :: retClassNo(){
	return classNo;
}
int Student :: retRollNo(){
	return rollNo;
}

void Student :: getData(){
	cout<<"Enter your name : ";
	cin.ignore();
	cin.getline(name, 30);
	cout<<"Enter your roll number : ";
	cin>>rollNo;
	cout<<"Enter your age : ";
	cin>>age;
	cout<<"Enter your Phone Number : ";
	cin.ignore();
	cin.getline(phone, 15);
	cout<<"Enter your class (Numerical Number only) : ";
	cin>>classNo;
	cout<<"Enter your address : ";
	cin.ignore();
	cin.getline(address, 60);
	cout<<"\n\n\n\n";
}

void Student :: showData(){
	cout<<"\n\n------------------------------------\n\n";
	cout<<"Name: "<<name<<endl;
	cout<<"Roll number: "<<rollNo<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Class: "<<classNo<<endl;
	cout<<"Phone Number: "<<phone<<endl;
	cout<<"Address: "<<address<<endl;
}

void addStudent();
void getStudData(int, int);
void getAllStudData();
void changeStudData(int, int);
void deleteStudent(int, int);

int main()
{

	cout<<"------------ Student DataBase ------------\n\n";

	int ch;
	do{

		system("cls");
		cout<<"\n1) Add a student data";
		cout<<"\n2) Get a student data";
		cout<<"\n3) Get all student data";
		cout<<"\n4) Change student data";
		cout<<"\n5) Delete a student data";
		cout<<"\n6) Exit";
    	cout<<"\n\nWhat is your Choice (1/2/3/4/5/6) ";
    	cin>>ch;

		system("cls");

		int cl, roll;

		switch(ch){
			case 1: addStudent();
				break;

			case 2:	cout<<"Enter your class number : ";
					cin>>cl;
					cout<<"Enter your roll number : ";
					cin>> roll;
					getStudData(cl, roll);
					break;

			case 3: getAllStudData();
					break;

			case 4:	cout<<"Enter your class number : ";
					cin>>cl;
					cout<<"Enter your roll number : ";
					cin>> roll;
					changeStudData(cl, roll);
					break;
			case 5:	cout<<"Enter your class number : ";
					cin>>cl;
					cout<<"Enter your roll number : ";
					cin>> roll;
					deleteStudent(cl, roll);
					break;
			case 6:	cout<<"Thank you!\n\n";
					exit(0);
			default:
				break;
		}

	}while(ch != 6);

	return 0;
}

void addStudent(){
	Student st;
	st.getData();

	ofstream outfile;
	outfile.open("data.dat", ios::binary | ios::app);
	outfile.write(reinterpret_cast<char *> (&st), sizeof(Student));
	outfile.close();

	cout<< "Student data has been added!\n\n";
}

void getStudData(int classNo, int rollNo){

	Student st;
	bool flag = false;

	ifstream infile;
	infile.open("data.dat", ios::binary);
	if(!infile){
		cout<<"No data is found! Please try again.\n\n";
		cin.ignore();
		cin.get();
		return;
	}
	while(infile.read(reinterpret_cast<char *> (&st), sizeof(Student))){
		if(st.retRollNo() == rollNo && st.retClassNo() == classNo){
			st.showData();
			flag = true;
		}
	}
	infile.close();

	if(!flag){
		cout<<"\n\nNo records found!\n\n";
	}
	cin.ignore();
	cin.get();
}

void getAllStudData(){

	Student st;

	ifstream infile;
	infile.open("data.dat", ios::binary);
	if(!infile){
		cout<<"No data is found! Please try again.\n\n";
		cin.ignore();
		cin.get();
		return;
	}
	while(infile.read(reinterpret_cast<char *> (&st), sizeof(Student))){
		st.showData();
	}
	infile.close();
	cin.ignore();
	cin.get();
}

void changeStudData(int classNo, int rollNo){

	Student stud;

	fstream file;
	file.open("data.dat", ios::binary | ios::in | ios::out);
	if(!file){
		cout<<"No data is found! Please try again.\n\n";
		cin.ignore();
		cin.get();
		return;
	}
	while(file.read(reinterpret_cast<char *> (&stud), sizeof(Student))){
		if(stud.retClassNo() == classNo && stud.retRollNo() == rollNo){
			stud.showData();
			cout<<"\n *******Enter new Details for this student.*******\n\n";
			stud.getData();

			int pos = (-1)*static_cast<int>(sizeof(Student));
			file.seekp(pos, ios::cur);
			file.write(reinterpret_cast<char *> (&stud), sizeof(Student));
			cout<<"**************Recorded new data!**************\n";
		}
	}
	file.close();
	cin.ignore();
	cin.get();
}

void deleteStudent(int classNo, int rollNo){

	Student stud;
	bool flag = false;
	ifstream infile;
	infile.open("data.dat", ios::binary);
	if(!infile){
		cout<<"No data is found! Please try again.\n\n";
		cin.ignore();
		cin.get();
		return;
	}

	ofstream outfile;
	outfile.open("temp.dat", ios::out);
	infile.seekg(0, ios::beg);
	while(infile.read(reinterpret_cast<char *> (&stud), sizeof(Student))){
		if(stud.retRollNo() == rollNo && stud.retClassNo() == classNo){
			cout<<"\n***********Deleting this record!***********\n";
			stud.showData();
			cout<<"\n***********RECORD DELETED***********\n";
			flag = true;
		}else{
			outfile.write(reinterpret_cast<char *> (&stud), sizeof(Student));
		}
	}
	infile.close();
	outfile.close();
	remove("data.dat");
	rename("temp.dat", "data.dat");
	if(!flag){
		cout<<"\nNo record found!\n";
	}
	cin.ignore();
	cin.get();
}