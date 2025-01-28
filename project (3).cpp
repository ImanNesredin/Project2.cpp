/*   Project Title: LOGIN REGISTRATION SYSTEM 
**This minor project is about the Login registration system in any
*sector by importing the iostream and fstream libraries and have 
*Menu with clear options for easy choices. The contents are the
*full works the system and handle errors that are out of the
*choices. 
**The code mainly uses void, int,and struct-User data types inorder
*to function and it uses file to save the username and password 
*incase the "users" forgot their password it will find it using 
* their username.
GROUP MEMBERS.            ID NO.                 SECTION 
IMAN NESREDIN.          UGR/30708/15.               9
MAHLET TIUMAY.          UGR/30847/15.               9
HAYAT LULU.             UGR/30637/15.               9
HANA GETU.              UGR/30624/15.               9
HAWI LEMU.              UGR/30636/15.              10
*/
#include<iostream>
#include<fstream>
using namespace std;

void login();
void registration();
void forgot();
// Define a struct to store user information
struct User {
    char username[50];
    char password[50];
};

int main()
{
    int c;
    cout<< "\t\t\t____________________________________________\n\n\n";
    cout<< "\t\t\t         Welcome to the Login page           \n\n\n" ;
    cout<< "\t\t\t____________        MENU        ______________\n\n";
    cout<< "                                                     \n\n";
    
    cout<< "\t| press 1 to REGISTER                   |"<<endl;
    cout<< "\t| press 2 to LOGIN                      |"<<endl;
    cout<< "\t| press 3 if you FORGOT your password   |"<<endl;
    cout<< "\t| press 4 to EXIT                       |"<<endl;
    cout<< "\t| please enter your choice :            |"<<endl;
    cin>>c;
    cout<<endl;
    
    switch(c)
    { 
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\t\t\t  Thankyou!  \n\n"<<endl;
            break;       
        default :
           cout<<"\t\t\t Please select from the option given above \n"<<endl;
           main();
    }
}
 // Function to register a new user
  void registration()
  {
      User users[50]; 
      int userCount; 
      cout<<"\t\t\t Enter USERNAME  : "<<endl;
      cin >> users[userCount].username;
      
      cout<<"\t\t\t Enter PASSWORD  :"<<endl;
      cin >> users[userCount].password;
      // Save user information to file
      ofstream f1("records.txt"  ,ios::app);
      f1<< users[userCount].username << " " << users[userCount].password << endl;
      cout<< "\n\t\t\t  Registration is successful ! \n";
      main();
  }
  // Function to perform user login
  void login()
  {
      int count;
      string userId, password, ID, pass;
      cout<<"\t\t\t Please enter username and password  : "<<endl;
      cout<<"\t\t\t USERNAME  : ";
      cin>>userId ;
      cout<<"\t\t\t PASSWORD  :";
      cin>>password;
  
      ifstream  input("records.txt");
      while(input>>ID>>pass)
      {
          if(ID==userId && pass==password)
          {
              count=1;
          
          }
      
      }
      input.close();
      
      if(count==1)
      {
          cout<<"\nYour LOGIN is successful \nThankyou  for logging in !\n";
          main();
      }
      else
      {
          cout<<"\nLOGIN ERROR \nPlease check your username and password.\n";
          main();
          
      }
  }
 
  void forgot()
  {
      int option;
      cout<<"\t\t\t You FORGOT your password no worries!'_< \n";
      cout<< "press 1 to search your ID by user name." << endl;
      cout<< "press 2 to go back to the main MENU ." << endl;
      cout<<"\t\t\t Enter your choice :";
      cin>>option;
      
      switch(option)
      {
           case 1 :
          {
              int count=0;
              string suserId ,sID ,spass ;
              cout<< "\n\t\t\t Enter your username which you remembered :" << endl;
              cin>> suserId ;
              
              ifstream f2("records.txt");
              while(f2>>sID>>spass)
              {    
                  if(sID==suserId)
                  {;
                      count=1;
                  }
              }   
              f2.close();
              if (count ==1)
              {
                  cout<< "\n\nYour account is found! \n";
                  cout<< "\n\n Your password is :"<< spass;
                  main();
              }
              else{    
                  cout << "\n\t sorry! your account is not found. \n";
                  main();
                  break;
              }
          }
          case 2 :
          {
              main();
              break;
          }
          default:
          cout << "\t Wrong choice please try again!" << endl;
          forgot();
      }
  }