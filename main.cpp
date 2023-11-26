#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{   
    char choose;
    cout << "\t\t Welcome to Echo Flow " << endl;
    cout << " Press l to Login. \n Press s if you are not registered."  << endl;
    cin >> choose;

    string loggedInUser;

    switch(tolower(choose)){
        case 's' :{
              signUp();
              break;
        }                
        case 'l' :{
              loggedInUser = login();
              viewMessages(loggedInUser);
              messaging(loggedInUser);
              break;
        }                         
       default :{
             cout << "Invalid Input !" << endl;  
               break;
        }
                       
    }

 return 0;
}