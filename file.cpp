#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void show(){

    cout<<"id"<<"        "<<"name"<<"           "<<"mony"<<endl;

    char id[25];
    char name[25];
    char mony[25];
    fstream client;
   client.open("client.txt",ios::in);

      while(!client.eof()){
     client.getline(id ,25,'|');
      client.getline(name ,25,'|');
      client.getline(mony ,25);

      cout<<id<<"        "<<name<<"        "<<mony<<endl;
}
}

 void enter(){
      char id[25];
    char name[25];
    char mony[25];
     cin.ignore();  //nnn
    cout<<"enter the id"<<endl;
    cin.getline(id,25);
    cout<<"enter the name"<<endl;
    cin.getline(name,25);
    cout<<"enter the mony"<<endl;
    cin.getline(mony,25);
    ofstream client;
    client.open("client.txt",ios::app);
    client<<id<<"|"<<name<<"|"<<mony<<endl;
    client.close();
    cout<<"<<<<<<<<<<<<<the client successfully added>>>>>>>>>>>"<<endl;

}

void serch(){

    char id[25];
    char name[25];
    char mony[25];
    char a[25];
  fstream client;
  client.open("client.txt",ios::in);
 cin.ignore();
 cout<<"enter the id"<<endl;
  cin.getline(a,25);
  while(!client.eof()){
    client.getline(id ,25,'|');
     client.getline(name ,25,'|');
      client.getline(mony ,25);
    if(strcmp(id,a)==0){cout<<"the mony is>>"<<mony;}
}

client.close();


}


void chang_data_byid(){
fstream client;
fstream newc;
client.open("client.txt",ios::in);
 newc.open("newc.txt",ios::out);
    char id[25];
    char name[25];
    char mony[25];
   char a[25];
   cin.ignore();
    cout<<"enter id to update the mony"<<endl;
    cin.getline(a,25);
    while(!client.eof()){
       client.getline(id ,25,'|');
       client.getline(name ,25,'|');
       client.getline(mony ,25);
        if(strcmp(id,a)==0){

             cout<<"entre new mony"<<endl;
            cin.getline(mony,25);
           newc<<id<<"|"<<name<<"|"<<mony<<endl;
        }else{ newc<<id<<"|"<<name<<"|"<<mony<<endl;}
    }

client.close();
newc.close();

client.open("client.txt",ios::out);
 newc.open("newc.txt",ios::in);
      while(!newc.eof()){
       newc.getline(id ,25,'|');
       newc.getline(name ,25,'|');
       newc.getline(mony ,25);

      client<<id<<"|"<<name<<"|"<<mony<<endl;}
     client.close();
      newc.close();
      remove("newc.txt");
      cout<<"done!!"<<endl;
}


void deletdata(){
    fstream client;
fstream newc;
client.open("client.txt",ios::in);
 newc.open("newc.txt",ios::out);
    char id[25];
    char name[25];
    char mony[25];
    char a[25];
    cin.ignore();
    cout<<"enter the id to delete account"<<endl;
    cin.getline(a,25);
    while(!client.eof()){
       client.getline(id ,25,'|');
       client.getline(name ,25,'|');
       client.getline(mony ,25);
        if(strcmp(id,a)==0){
           continue;
        }else{ newc<<id<<"|"<<name<<"|"<<mony<<endl;}
    }

client.close();
newc.close();

client.open("client.txt",ios::out);
 newc.open("newc.txt",ios::in);
      while(!newc.eof()){
       newc.getline(id ,25,'|');
       newc.getline(name ,25,'|');
       newc.getline(mony ,25);

      client<<id<<"|"<<name<<"|"<<mony<<endl;}
     client.close();
      newc.close();
      remove("newc.txt");
      cout<<"done!!!!!!!!"<<endl;
      }


int main()
{
int a;
     cout<<"             *welcome on our program*"<<endl;
s:


   cout<<"*1.to add anew client "<<endl;
   cout<<"*2.to check money in the account"<<endl;
   cout<<"*3.to show the all cient"<<endl;
   cout<<"*4.to check out and desposit money from the account  "<<endl;
   cout<<"*5.to delete the client account"<<endl;
   cout<<"*6.to exit "<<endl;

cin>>a;

   switch(a){

        case 1:
        enter();
        goto s;
        break;


      case 2:
      serch();
      goto s;
      break;


     case 3:
     show();
     goto s;
     break;


     case 4:
     chang_data_byid();
     goto s;
     break;

    case 5:
    deletdata();
    goto s;
    break;



    case 6:
    cout<<"<<<<<<<<<<<<<<<<<<<<<thank you to use our program>>>>>>>>>>>>>>>>>>>>>"<<endl;
    break;

   default:
   cout<<"**************choose the correct answer******************* "<<endl;
   goto s;
}
}
