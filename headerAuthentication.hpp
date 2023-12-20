#include <iostream>
#include<string.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
class Authentication
{
protected:
    char password[20];
    char username[20];

public:
    char *get_usernameInput(int, int);
    void gotoxy(short, short);
    void setcolor(int);
    void show_message(char*);
    bool check_string(char *);
    bool check_passwordInput(char, int &, int &, int &, int);
    char *get_passwordInput(int, int, int);
    void front_display(int, int);
    void clear_text(int, int);
    char *get_name(int, int);
    char *get_password(int, int);
    bool check_character(char, int &, int &, int &);
    char *getUsername();
};
class Login : public Authentication
{
public:
    Login();
    Login(char *, char *);
    void input();
    bool verify(char *, char *, int, int);
};
class ChangePassword : public Authentication
{
private:
    char currentPassword[20];
    char newPassword[20];
    char confirmPassword[20];

public:
    void input();
    char *getCurrentPassword();
    void intro();
    bool verifyNewPassword(char *, char *);
};
class Register : public Authentication
{
public:
    Register();
    Register(char *, char *);
    char *getPassword();
    void newValue(char *, char *);
    void input();
    // read and write file using operator overloading
    void operator<<(Register &);
    Register operator>>(Register &);
};