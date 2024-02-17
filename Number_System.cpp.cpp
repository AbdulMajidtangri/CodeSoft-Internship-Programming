#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;
int main(){
	 system("color 71");
    int number;
    int hidden_number=8;
    char choice;
  cout<<"\t\t******************************************************************************"<<endl;
  cout<<"\t\t*                                                                            *"<<endl;
  cout<<"\t\t*             NUMBER SYSTEM                                                  * "<<endl; 
  cout<<"\t\t*                             GAME                                           *"<<endl;
  cout<<"\t\t*                                                                            *"<<endl;
  cout<<"\t\t*                                                                            *"<<endl;
  cout<<"\t\t******************************************************************************"<<endl<<endl;
   do
   {
    cout<<"\t\t\tenter the number 1-50"<<endl;
   setw(50);cin>>number;
   
        if(number>hidden_number)
            cout<<"\t\t\tentered number is to High"<<endl;
        else if(number<hidden_number)
     cout<<"\t\t\tentered number is to low"<<endl;    
     else
     cout<<"\t\tyou have have guessed right number   congratulations"<<endl;
      cout << "\t\t\tDo you want to play again? (y/n): ";
        cin >> choice;
   }while(choice == 'y' || choice == 'Y');
}
