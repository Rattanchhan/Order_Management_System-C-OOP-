#include<iostream>
#include"headerFunction.hpp"
#include"headerDataInformation.hpp"
#include"headerAuthentication.hpp"
#include<conio.h>
using namespace std;
void run(){
    Register _register;
    Login login;
    int option;
    bool found=false;
    enum OPTION
    {
        EXIT = 0,
        Register,
        LOGIN,
        CHANGE_PASSWORD
    };
    do{
        system("cls");
        login_menu();
        option=getOption();
        switch(option){
            case OPTION::Register:{
                system("cls");
                cin.ignore();
                //register account
                _register.input();
                cout<<endl;
                //write account into file
                _register<<_register;
                _register.setcolor(2);
                cout << "\tRegister successfully..." << endl;
                _register.setcolor(15);
            }break;
            case OPTION::LOGIN:{
                // read account from file
                _register >> _register;
                cin.ignore();
                do{
                    system("cls");
                    login.front_display(20, 7);
                    login.input();
                    // verify account login
                    found = login.verify(_register.getUsername(), _register.getPassword(), 20, 7);
                    login.setcolor(15);
                }while(found!=true);
                order();
            }break;
            case OPTION::CHANGE_PASSWORD:{
                ChangePassword changePassword;
                bool flag=false;
                _register << _register;
                do{
                    changePassword.input();
                    flag = changePassword.verifyNewPassword(_register.getUsername(), _register.getPassword());
                    _getch();
                }while(flag!=true);
                _register.newValue(changePassword.getUsername(),changePassword.getCurrentPassword());
                _register<<_register;
                changePassword.setcolor(15);
            }break;
            case 0:{
                char ch;
                cout<<"\tAre you sure to exit program(y/n): ";
                cin.ignore();
                cin>> ch;
                if(ch=='y'||ch=='Y'){
                    exit(0);
                }
                else{
                    continue;
                }
            }break;
            default:{
                cout<<"\tInvalid option..."<<endl;
            }break;
        }
        _getch();
    }while(option!=0);
}
int getOption(){
    int option;
    cin>>option;
    return option;
}
void login_menu()
{
    cout << "\t=====  WELCOME TO THE PIZZA RESTRAURANT  ====="<< endl;
    cout << "\t1.REGISTER" << endl;
    cout << "\t2.LOGIN"<<endl;
    cout << "\t3.CHANGE PASSWORD" << endl;
    cout << "\t0.EXIT" << endl;
    cout << "\tPlease choice one option(1-3):";
}
void order()
{
    int option;
    Order *order;
    int n=20;
    order = new Order[20];
    enum OPTION
    {
        EXIT = 0,
        CREATER_ORDER,
        VIEW_ORDER,
        EDIT_ORDER,
        WRITE_FILE,
        LOAD_FILE
    };
    do
    {
        system("cls");
        menuOrder();
        option = getOption();
        switch (option)
        {
        case OPTION::CREATER_ORDER:
        {
                cout << "\tInput n: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    order[i].createOrder();
                }
                cout << endl;
        }
        break;
        case OPTION::VIEW_ORDER:
        {
                for (int i = 0; i < n; i++)
                {
                    order[i].reciept();
                    cout << endl;
                }
                cout << endl;
                getch();
        }
        break;
        case OPTION::EDIT_ORDER:
        {
                int id;
                cout << "\tInput custom id to update: ";
                cin >> id;
                for (int i = 0; i < n; i++)
                {
                    if (id == order[i].customer.getID())
                    {
                        order[i].editOrder();
                        break;
                    }
                }
        }
        break;
        case OPTION::WRITE_FILE:
        {
                for (int i = 0; i < n; i++)
                {
                    order[i] << order[i];
                }
                cout << endl;
        }
        break;
        case OPTION::LOAD_FILE:
        {
                for (int i = 0; i < n; i++)
                {
                    order[i] >> order[i];
                }
                cout << endl;
        }
        break;
        case OPTION::EXIT:
        {
                char ch;
                cout << "\tAre you sure to exit program(y/n):";
                cin.ignore();
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    exit(0);
                }
                else
                {
                    continue;
                }
        }
        break;
        default:
        {
                cout << "\tInvalid option..." << endl;
        }
        break;
        }
        _getch();
    } while (option != 0);
}
