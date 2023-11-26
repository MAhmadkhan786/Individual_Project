#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct User
{
    string username, phoneNumber, password1, password2;
};

void signUp(){
   
   User u;

    cout << " Enter username or email : " << endl;
    cin.ignore(); 
    getline(cin, u.username);

    cout << "\n Enter password : " << endl;
    getline(cin, u.password1);

    
    do {
        cout << "\n Re-enter password : " << endl;
        getline(cin, u.password2);

            if (u.password1 != u.password2){
                cout << " Passwords don't match! Try again." << endl;
            }
        } while (u.password1 != u.password2);



        ofstream put("user.txt", ios :: app);
        if(!put.is_open())
        {
            cout <<"\n File could not be opened.";
        }
        else{
         if (put.is_open()){

                  put << u.username    << " "
                      << u.password1   << " "
                      << endl;
        }
      
      cout << "\n Your account has been created successfully ! "<< endl;
       }
}
bool checkCredentials(string name, string pass){

   string * cUser =new  string [10]; 
   string * cpass =new  string [10]; 
   int i=0;
       ifstream read("user.txt", ios::in);
       if(!read.is_open()){
        cout << " Unable to open file ! " << endl;
       }else{
           while(!read.eof()){
              read >> cUser[i]
                   >> cpass[i]; 
               i++;    
           }
       }
       for (int k=0; k<i; k++){
           if (name == cUser[k] && pass == cpass[k]){
               delete[]cUser;
               delete[]cpass;
               return true;
           }
       }
        delete[]cUser;
        delete[]cpass;
       return false;
}

string login(){
  User u1;
while(true){  
    cout << "\n Enter your Username/Email: ";
    cin.ignore(); 
    getline(cin, u1.username);

    cout << "\n Enter Password : ";
    getline(cin, u1.password1);
    
     if (checkCredentials(u1.username, u1.password1)){
 
         cout <<"\n Hi ! "<<u1.username << " Welcome to Echo Flow ! " << endl;
         break;
     }
     else{
          cout << " Invalid Credentials! Try Again." << endl;
          continue;
          }
    }
     return u1.username;
} 

bool checkUser(string name){
    
    int i=0;
    string* cUser = new string[10];
    string* cpass = new string[10];

      ifstream read("user.txt", ios::in);
       if(!read.is_open()){
        cout << " Unable to open file ! " << endl;
       }else{
           while(!read.eof()){
              read >> cUser[i];
               i++;    
           }
       }
       for (int k=0; k<i; k++){
           if (name == cUser[k] ||  name == cpass[k]){
               delete[]cUser;
               delete[]cpass;
               return true;
           }
       }
       delete[]cUser;
       delete[]cpass;
       return false;
}
  void messaging (string loggedInUser) {
    string message;
    User   receiver, sender;

    sender.username = loggedInUser;
      
       cout << "\n Who do you want to send a message ? " << endl;
       cout << "\n Please enter the username of the user you wish to send a message to : ";
       cin  >> receiver.username;

       // Checking if the user is registered or not.

      if(checkUser(receiver.username) ){
         
         cout << "\n Send any message to "<< receiver.username << " " << endl;
            cin.ignore(); 
            getline(cin, message);
      }
     else{
         cout << "\n User does not exist." << endl;
     }
// Sender File
    ofstream senderFile(sender.username + "_messages.txt", ios::app);
    if (!senderFile.is_open()) {
        cout << "\n Error opening the sender file. " << endl;
        return;
    } else {
        senderFile <<  "To: " 
                   <<  receiver.username 
                   <<  endl
                   <<  "Message: " 
                   <<  message 
                   <<  endl;
        cout << "\n Message sent successfully!" << endl;
    }
   senderFile.close();

// Receiver file
       ofstream receiverFile(receiver.username + "_messages.txt", ios::app);
    if (!receiverFile.is_open()) {
        cout << "\n Error opening the receiver file. " << endl;
        return;
    } else {
        receiverFile << "From: " 
                     << sender.username
                     << endl
                     << " Message: " 
                     << message 
                     << endl;
        cout << "\n Message received successfully!" << endl;
    }
    receiverFile.close();
}


void viewMessages(string loggedInUser){
    string message;
    string * readMessage = new string[100];
    int i=0;

    ifstream read(loggedInUser + "_messages.txt", ios::in);
    if(!read.is_open())
    {

        cout << "\nError in reading messages" << endl;
    }
    while (getline(read, message)) 
    {
      
      readMessage[i] = message;  
      i++;
    }
   
   cout <<"\n Your messages " << endl;

   for (int j = 0; j < i ; ++j) {
     cout<<"["<<j+1<<"]\t"<< readMessage[j] << endl << endl;
   }

}