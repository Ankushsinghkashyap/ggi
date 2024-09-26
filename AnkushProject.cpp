#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<unistd.h>
using namespace std;
class student
{
private:
    string fname, lname, father_fname, father_lname, roll_no, course, address, email_id;
    long long int contact_no;

public:
    void menu();
    void insert();
    void display();
    void update();
    void search();
    void deleted();
};
// Student Menu section 
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Update Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit " << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout<<endl;
            cout << " Add more student (y/n) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        update();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        cout << " Program Is Exit";
        exit(0);
    default:
        cout << "Invalid Choice... Please Try Again...";
    }
    system("pause");
    goto menustart;
}
void student::insert() // Add student details
{
    system("cls");
    fstream file;
    cout << "Enter First Name: ";
    cin >> fname;
    cout << "Enter Last Name: ";
    cin >> lname;
    cout << "Enter your Father's first Name :";
    cin >> father_fname;
    cout << "Enter your Father's last Name :";
    cin >> father_lname;
    cout << "Enter Roll No.: ";
    cin >> roll_no;
    cout << "Enter Course: ";
    cin >> course;
    cout << "Enter Email Id : ";
    cin >> email_id;
    cout << "Enter Contact No : ";
    cin >> contact_no;
    cout << "Enter Address: ";
    cin >> address;
    cout<<endl;
    sleep(3);
    cout << "SUCCESSFULLY ADDED !";
    cout<<endl;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << fname << " " << lname << " " << father_fname << " " << father_lname << " " << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
void student::display() // Display data of student
{
    system("cls");
    fstream file;
    int total = 1;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout<<"============================================================================================================"<<endl;
            cout<<"============================================================================================================"<<endl;
            cout << "Student No.: " << total++ << endl;
            cout << "First Name: " << fname << endl;
            cout << "last Name: " << lname << endl;
            cout << "Father's first name : " << father_fname << endl;
            cout << "Father's last name : " << father_lname << endl;
            cout << "Roll No.: " << roll_no << endl;
            cout << "Course: " << course << endl;
            cout << "Email Id: " << email_id << endl;
            cout << "Contact No.: " << contact_no << endl;
            cout << "Address: " << address << endl;
            file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
            cout<<endl;
        }
        if (total == 0)
        {

            cout << "No Data is Present..." << endl;
        }
    }

    file.close();
}
void student::update() // Modify details of student
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "No Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
                file1 << " " << fname << " " << lname << " " << father_fname << " " << father_lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "Enter Name: ";
                cin >> fname;
                cout << "Enter last Name: ";
                cin >> lname;
                cout << "Enter Your Father's first Name :";
                cin >> father_fname;
                cout << "Enter your Father's last name : ";
                cin >> father_lname;
                cout << "Enter Roll No.: ";
                cin >> roll_no;
                cout << "Enter Course: ";
                cin >> course;
                cout << "Enter Email Id : ";
                cin >> email_id;
                cout << "Enter Contact No : ";
                cin >> contact_no;
                cout << "Enter Address: ";
                cin >> address;
                file1 << " " << fname << " " << lname << " " << father_fname << " " << father_lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "First Name: " << fname << endl;
                cout << "last Name: " << lname << endl;
                cout << "Father's first Name : " << father_fname << endl;
                cout << "Father's Last Name : " << father_lname << endl;
                cout << "Roll No.: " << roll_no << endl;
                cout << "Course: " << course << endl;
                cout << "Email Id: " << email_id << endl;
                cout << "Contact No.: " << contact_no << endl;
                cout << "Address: " << address << endl;
                found++;
            }
            file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << " Not found !";
            }
        }
        file.close();
    }
}
void student::deleted() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << fname << " " << lname << " " << father_fname << " " << father_lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "SUCCESSFULLY DELETED !";
                cout<<endl;
            }
            file >> fname >> lname >> father_fname >> father_lname >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "  Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

class admin:public student{
    public:
  void signup();
  void login();
  void forget();
    admin(){
        system("cls");
    cout<<"\t \t   ______________________________________________________________________________________ "<<endl;
    cout<<"\t \t  |                                                                                      |"<<endl;
    cout<<"\t \t  |======================================================================================|"<<endl;
    cout<<"\t \t  |==========        WELCOME TO STUDENT MANAGEMENT SYSTEM !!                 ============|"<<endl;
    cout<<"\t \t  |==========                                                                ============|"<<endl;
    cout<<"\t \t  |==========       **  GGI **                                               ============|"<<endl;
    cout<<"\t \t  |==========                           GULZAR GROUP OF INSTITUTION          ============|"<<endl;
    cout<<"\t \t  |==========                                GT ROAD LIBRA KHANNA            ============|"<<endl;
    cout<<"\t \t  |==========                               LUDHIANA PUNJAB INDIA            ============|"<<endl;
    cout<<"\t \t  |==========                                                                ============|"<<endl;
    cout<<"\t \t  |======================================================================================|"<<endl;
    cout<<"\t \t  |______________________________________________________________________________________|"<<endl;
    cout<<"\t"<<endl;
    int choice;
    cout<<"\t \t  _____________________________________________"<<endl;
    cout<<"\t \t |                                             |"<<endl;
    cout<<"\t \t |*********************************************|"<<endl;
    cout<<"\t \t |*******                                ******|"<<endl;
    cout<<"\t \t |*******          Admin Section         ******|"<<endl;
    cout<<"\t \t |*******                                ******|"<<endl;
    cout<<"\t \t |*********************************************|"<<endl;
    cout<<"\t \t |_____________________________________________|"<<endl;
    cout<<"\t \t 1. signup "<<endl;
    cout<<"\t \t 2. login "<<endl;
    cout<<"\t \t 3. forgot "<<endl;
    cout<<"\t \t 4. EXIT ! "<<endl;
    cout<<"\t \t enter your choice ::";
    cin>>choice;
    switch(choice){
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            forget();
            break;
        case 4:
            exit;
            default:
            cout<<"invalid choice !!"<<endl;    
    }
}
    };
void admin::signup(){
        system("cls");
        string ruserid,rpassword,rid,rpass;
        cout<<"enter the username : ";
        fflush(stdin);
        getline(cin,ruserid);
        cout<<endl;
        cout<<"enter password :";
        fflush(stdin);
        getline(cin,rpassword);
        cout<<endl;
        ofstream outfile;
        outfile.open("database.txt",ios::app);
        outfile<<ruserid<<" \t"<<rpassword<<endl;
        outfile.close();
        cout<<"** Registration successful ! **"<<endl;
        sleep(3);
        admin();
    }
 void admin:: login(){
    student s1;
        int count;
        string username,password,id,pass;
        cout<<"Enter the username : ";
        fflush(stdin);
        getline(cin,username);
        cout<<endl;
        cout<<"Enter new password :";
        fflush(stdin);
        getline(cin,password);
        cout<<endl;
        ifstream infile("database.txt");
        while(infile>>id>>pass){
            if(id==username && pass==password){
                count=1;
                system("cls");
            }
           
        }
         infile.close();
         if(count==1){
            cout<<"login successful !"<<endl;
            cout<<"please wait for 3 sec :"<<endl;
            sleep(3);
            //student driver code is written here
            s1.menu();
            system("cls");
            admin();
         }else{
            cout<<"not register!!"<<endl;
            sleep(3);
            admin();
         }
        }
void admin::forget(){
        int option;
        system("cls");
        cout<<"\t 1. go back to menu :"<<endl;
        cout<<"\t 2.search by  username:"<<endl;
        cout<<"\t   enter your choice :";
        cin>>option;
        switch(option){
            case 1:
            admin();
            break;
            case 2:
            int count=0;
            string searchuser,searchid,searchpassword;
            cout<<"enter username :";
            fflush(stdin);
            getline(cin,searchuser);
            cout<<endl;
            ifstream f("database.txt",ios::in);
            while(f>>searchid>>searchpassword){
                if(searchid==searchuser){
                    count=1;
                    
                }
            }
            f.close();
            if(count==1){
                cout<<"your account is found : "<<searchuser<<endl;
                cout<<"your password is : "<<searchpassword<<endl;
                system("pause");
                admin();
            }else{
                cout<<"sorry !! Not Found !! "<<endl;
                sleep(3);
                admin();
            }
            
            
        }
}
int main()
{

   admin A1;
    return 0;
}
