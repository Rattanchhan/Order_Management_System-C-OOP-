#include"headerAuthentication.hpp"
#include<cstring>
using namespace std;
// Definition authentication class
bool Authentication::check_character(char str, int &x, int &y, int &i)
{
    if (str == 8)
    {
        if (x > 20)
        {
            gotoxy(x--, y + 5);
            show_message(" ");
            i--;
        }
        else if (x == 20)
        {
            gotoxy(x--, y + 5);
            show_message(" ");
            x++;
            i--;
        }
        return false;
    }
    else
    {
        gotoxy(x, y + 5);
        show_message("*");
        x++;
        return true;
    }
}
char *Authentication::get_password(int x, int y)
{
    char *password;
    password = new char[20]{'0'};
    char str;
    bool flag;
    int i = 0;
    gotoxy(x, y + 5);
    clear_text(x + 13, y + 5);
    do
    {
        if ((str = _getch()))
        {
            if (str == 13)
            {
                break;
            }
            else if (check_character(str, x, y, i))
            {
                password[i] = str;
                i++;
                flag = true;
            }
            else
            {
                flag = true;
            }
        }
    } while (flag);
    password[i] = '\0';
    return password;
}
void Authentication::clear_text(int x, int y)
{
    if (_getch() || _getch() == 8)
    {
        for (int i = 20; i < 34; i++)
        {
            gotoxy(x--, y);
            show_message(" ");
        }
    }
}
char *Authentication::get_name(int x, int y)
{
    char *name;
    name = (char *)malloc(sizeof(char));
    bool flag;
    do
    {
        clear_text(x + 13, y + 1);
        gotoxy(x, y + 1);
        cin.getline(name, 20);
        if (check_string(name))
        {
            flag = true;
        }
        else
        {
            gotoxy(x, y + 8);
            setcolor(12);
            show_message("Please input your name...");
            flag = false;
            _getch();
            system("cls");
            front_display(x, y);
        }
    } while (!flag);
    return name;
}
char *Authentication::get_passwordInput(int x, int y, int x1)
{
    char *password;
    password = new char[20]{'0'};
    char str;
    bool flag;
    int i = 0;
    gotoxy(x, y - 1);
    do
    {
        if ((str = _getch()))
        {
            if (str == 13 && password[0] == '0')
            {
                flag = true;
                gotoxy(x - 16, y);
                setcolor(12);
                show_message("Please input your password...");
                _getch();
                system("cls");
                setcolor(15);
                show_message("\tEnter password: ");
                gotoxy(x, y - 1);
            }
            else if (str == 13 && password[0] != '0')
            {
                break;
            }
            else if (check_passwordInput(str, x, y, i, x1))
            {
                password[i] = str;
                i++;
                flag = true;
            }
            else
                flag = true;
        }
    } while (flag);
    password[i] = '\0';
    return password;
}
bool Authentication::check_passwordInput(char str, int &x, int &y, int &i, int x1)
{
    if (str == 8)
    {
        if (x > x1)
        {
            gotoxy(x--, y - 1);
            show_message(" ");
            i--;
        }
        else if (x == x1)
        {
            gotoxy(x--, y - 1);
            show_message(" ");
            x++;
            i--;
        }
        return false;
    }
    else
    {
        gotoxy(x, y - 1);
        show_message("*");
        x++;
        return true;
    }
}
void Authentication::front_display(int x, int y)
{
    setcolor(15);
    setcolor(3);
    gotoxy(x, 5);
    cout << ("LOGIN");
    setcolor(15);
    gotoxy(x, y);
    cout << ("Username");
    gotoxy(x, y + 1);
    setcolor(8);
    cout << ("Enter username");
    setcolor(15);
    gotoxy(x, y + 3);
    cout << ("Password");
    gotoxy(x, y + 5);
    setcolor(8);
    cout << ("Enter Password");
    gotoxy(x, y + 1);
}
void Authentication::gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Authentication::setcolor(int Color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
void Authentication::show_message(char* st)
{
    cout << st;
}
bool Authentication::check_string(char *name)
{
    if (name[0] == '\0')
    {
        return false;
    }
    return true;
}
char *Authentication::get_usernameInput(int x, int y)
{
    char *name;
    name = new char;
    bool flag;
    gotoxy(x, y - 1);
    do
    {
        cin.getline(name, 20);
        if (check_string(name))
        {
            flag = true;
        }
        else
        {
            gotoxy(x, y + 1);
            setcolor(12);
            show_message("Please input your name...");
            flag = false;
            _getch();
            system("cls");
            setcolor(15);
            show_message("\tEnter username: ");
            gotoxy(x, y - 1);
        }
    } while (!flag);
    return name;
}
char *Authentication::getUsername()
{
    return this->username;
}

// End

// Definition of Register class

void Register::newValue(char *username, char *currentPassword)
{
    strcpy(this->password, currentPassword);
    strcpy(this->username, username);
}
Register::Register()
{
    strcpy(password, "N/A");
    strcpy(username, "N/A");
}
Register::Register(char *username, char *password)
{
    strcpy(this->password, password);
    strcpy(this->username, username);
}
char *Register::getPassword()
{
    return this->password;
}
void Register::input()
{
    show_message("\tEnter username: ");
    strcpy(username, get_usernameInput(8, 0));
    system("cls");
    show_message("\tEnter password: ");
    strcpy(password, get_passwordInput(24, 1, 24));
}
void Register::operator<<(Register &_register)
{
    ofstream writeFile;
    writeFile.open("login.bat", ios::out | ios::binary);
    writeFile.write((char *)(&_register), sizeof(_register));
    writeFile.close();
}
Register Register::operator>>(Register &getRegister)
{
    ifstream loadFile;
    loadFile.open("login.bat", ios::in | ios::binary);
    try
    {
        loadFile.read((char *)(&getRegister), sizeof(getRegister));
        if (!loadFile)
        {
            ofstream writeFile;
            writeFile.open("login.bat", ios::out | ios::binary);
            throw(1);
        }
    }
    catch (int num)
    {
        cout << "\tDo not have file to open..." << endl;
    }
    loadFile.close();
    return getRegister;
}

// End

// Definition of Login class

Login::Login()
{
    strcpy(password, "N/A");
    strcpy(username, "N/A");
}
Login::Login(char *username, char *password)
{
    strcpy(this->password, password);
    strcpy(this->username, username);
}
void Login::input()
{
    strcpy(username, get_name(20, 7));
    strcpy(password, get_password(20, 7));
}
bool Login::verify(char *username, char *password, int x, int y)
{
    if (password[0] == 0)
    {
        gotoxy(x, y + 6);
        setcolor(12);
        show_message("Please input your password...\n");
        _getch();
    }
    if (strcmp(this->username, username) == 0 && strcmp(this->password, password) == 0)
    {
        gotoxy(x, y + 6);
        setcolor(2);
        show_message("Successfully!!!\n");
        _getch();
        return true;
    }
    else
    {
        gotoxy(x, y + 6);
        setcolor(12);
        show_message("Sorry,please try again!!!\n");
        _getch();
        return false;
    }
}
void ChangePassword::intro()
{
    setcolor(15);
    setcolor(3);
    gotoxy(20, 5);
    cout << ("Change password");
    setcolor(15);
    gotoxy(20, 8);
    cout << ("Current password");
    setcolor(8);
    gotoxy(20, 9);
    cout << "Password";
    setcolor(15);
    gotoxy(20, 11);
    cout << ("New password");
    setcolor(8);
    gotoxy(20, 12);
    cout << "Password";
    setcolor(15);
    gotoxy(20, 14);
    cout << ("Confirm new password");
    setcolor(8);
    gotoxy(20, 15);
    cout << "Cofirm";
}
// End

// Definition change password

void ChangePassword::input()
{
    system("cls");
    intro();
    gotoxy(20, 9);
    clear_text(28, 9);
    strcpy(currentPassword, get_passwordInput(20, 10, 20));
    gotoxy(20, 12);
    clear_text(28, 12);
    strcpy(newPassword, get_passwordInput(20, 13, 20));
    gotoxy(20, 15);
    clear_text(26, 15);
    strcpy(confirmPassword, get_passwordInput(20, 16, 20));
}
bool ChangePassword::verifyNewPassword(char *username, char *currentPassword)
{
    if (strcmp(this->currentPassword, currentPassword) != 0)
    {
        setcolor(12);
        gotoxy(20, 16);
        show_message("Currentpassword incorrect!!!");
        return false;
    }
    else if (strcmp(newPassword, confirmPassword) != 0)
    {
        setcolor(12);
        gotoxy(20, 16);
        show_message("Password not match!!!");
        return false;
    }
    else if (strcmp(this->currentPassword, currentPassword) == 0 && strcmp(newPassword, confirmPassword) == 0)
    {
        setcolor(2);
        gotoxy(20, 16);
        show_message("Password updated!!!");
        strcpy(this->currentPassword, newPassword);
        strcpy(this->username, username);
        return true;
    }
    else
    {
        setcolor(12);
        gotoxy(20, 16);
        show_message("Invalid!!!");
        return false;
    }
}
char *ChangePassword::getCurrentPassword()
{
    return currentPassword;
}
void menuOrder()
{
    cout << "\t1.CREATE ORDER" << endl;
    cout << "\t2.VIEW ORDER" << endl;
    cout << "\t3.EDIT ORDER" << endl;
    cout << "\t4.WRITE TO FILE" << endl;
    cout << "\t5.LOAD FROM FILE" << endl;
    cout << "\t0.Exit program" << endl;
    cout << "\tPlease choose one option (1-5): ";
}