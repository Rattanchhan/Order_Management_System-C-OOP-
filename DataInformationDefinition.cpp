#include <iostream>
#include<fstream>
#include <iomanip>
#include "headerDataInformation.hpp"
#include <cstring>
using namespace std;

//Definition pizza class
void Pizza::addProduct()
{
    cout << "\tInput  pizza name: ";
    cin.ignore();
    cin.getline(productName, 20);
    cout << "\tInput pizza size(L,M,S): ";
    cin >> size;
    cout << "\tInput quantity: ";
    cin >> quantity;
    cout << "\tInput price: ";
    cin >> price;
    amount = price * quantity;
}
int Pizza::getQuantity()
{
    return quantity;
}
float Pizza::getPrice()
{
    return price;
}
char *Pizza::getProdcutName()
{
    return productName;
}
char Pizza::getSize()
{
    return size;
}
float Pizza::getAmount()
{
    return amount;
}

// Definiton of Drink class
void Drink::addProduct()
{
    cout << "\tInput  drink name: ";
    cin.ignore();
    cin.getline(productName, 20);
    cout << "\tInput quantity: ";
    cin >> quantity;
    cout << "\tInput price: ";
    cin >> price;
    amount = price * quantity;
}
int Drink::getQuantity()
{
    return quantity;
}
float Drink::getPrice()
{
    return price;
}
char *Drink::getProdcutName()
{
    return productName;
}
char Drink::getSize()
{
    return '0';
}
float Drink::getAmount()
{
    return amount;
}

//Definition date class
void Date::setDate()
{
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    hour = (1 + ltm->tm_hour) - 1;
    minute = (1 + ltm->tm_min) - 1;
    month = (1 + ltm->tm_mon);
    year = (1 + ltm->tm_year + 1900) - 1;
    day = (1 + ltm->tm_mday) - 1;
}
Date::Date()
{
    hour = 0;
    minute = 0;
    month = 0;
    year = 0;
    day = 0;
}
int Date::getHour()
{
    return hour;
}
int Date::getMinute()
{
    return minute;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
{
    return year;
}
int Date::getDay()
{
    return day;
}

//Definition customer class
void Customer::addCustomer()
{
    cout << "\t=====Customer Information=====" << endl;
    cout << "\tInput customer id: ";
    cin >> id;
    cout << "\tInput customer name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "\tInput phone number: ";
    cin.getline(customerPhoneNumber, 20);
    cout << "\tInput address : ";
    cin.getline(customerAddress, 20);
}
int Customer::getID()
{
    return id;
}
char *Customer::getName()
{
    return name;
}
char *Customer::getPhoneNumber()
{
    return customerPhoneNumber;
}
char *Customer::getAddress()
{
    return customerAddress;
}

//Definition orderDetail class
float OrderDetail::vat = 10;
void OrderDetail::chageCount(int count)
{
    this->count = count;
}
void OrderDetail::detail()
{
    int i = 0;
    int option;
    do
    {
        system("cls");
        menu();
        cin >> option;
        switch (option)
        {
        case 1:
        {
            product[i] = new Pizza;
            product[i]->addProduct();
        }
        break;
        case 2:
        {
            product[i] = new Drink;
            product[i]->addProduct();
        }
        break;
        }
        total_usd = product[i]->getAmount() + total_usd;
        i++;
    } while (i < count);
    net_amt = total_usd - (0.1 * total_usd);
}
void OrderDetail::menu()
{
    cout << "\t1.Pizza" << endl;
    cout << "\t2.Drink" << endl;
    cout << "\tPlease choose (1-2): ";
}
void OrderDetail::reciept()
{
    for (int l = 0; l < count; l++)
    {
        if (l < 10)
        {
            cout << right << setw(32) << "0" << l + 1;
            cout << right << setw(7 + strlen(product[l]->getProdcutName())) << product[l]->getProdcutName() << endl;
            cout << right << setw(38) << product[l]->getQuantity() << " pcs * " << left << setw(15) << product[l]->getPrice();
            cout << right << setw(15) << product[l]->getAmount() << " $" << left << setw(10) << endl;
        }
        else
        {
            cout << right << setw(32) << l + 1;
            cout << right << setw(7 + strlen(product[l]->getProdcutName())) << product[l]->getProdcutName() << endl;
            cout << right << setw(38) << product[l]->getQuantity() << " pcs * " << left << setw(15) << product[l]->getPrice();
            cout << right << setw(15) << product[l]->getAmount() << " $" << left << setw(10) << endl;
        }
    }
}
float OrderDetail::getTotalAmount()
{
    return total_usd;
}
float OrderDetail::getVat()
{
    return vat;
}
float OrderDetail::getNetAmt()
{
    return net_amt;
}
int OrderDetail::getCount()
{
    return count;
}
void OrderDetail::newValue()
{
    total_usd = 0;
}

//Definition order class
void Order::createOrder()
{
    customer.addCustomer();
    date.setDate();
    cout << "\tInput number of product: ";
    cin >> n;
    orderDetail.chageCount(n);
    orderDetail.detail();
}
void Order::editOrder()
{
    orderDetail.newValue();
    cout << "\tUpdate" << endl;
    date.setDate();
    cout << "\tInput number of product: ";
    cin >> n;
    orderDetail.chageCount(n);
    orderDetail.detail();
}
void Order::reciept()
{
    counts++;
    cout << endl;
    cout << right << setw(76) << "The pizza resturant: #107, Phoum 4 ANZ Road" << endl;
    cout << right << setw(67) << "Sangkat Boeung Kakti 2," << endl;
    cout << right << setw(72) << "Khan Toul Kork Phnom Penh, 120408" << endl;
    cout << right << setw(71) << "Call & Pick up  : 088 50 60 697" << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(61) << "Receiption " << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(38) << "Slip:  "
         << "000000000C92000000" << counts << endl;
    cout << right << setw(38) << "Date:  " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " " << date.getHour() << ":" << date.getMinute() << endl;
    cout << right << setw(38) << "Id:    " << customer.getID() << endl;
    cout << right << setw(40) << "Name:    " << customer.getName() << endl;
    cout << right << setw(47) << "Phone number:   " << customer.getPhoneNumber() << endl;
    cout << right << setw(43) << "Address:    " << customer.getAddress() << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(64) << "** PRINT BILL ** " << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(80) << "No.      Description                    Amount   " << endl;
    cout << endl;
    orderDetail.reciept();
    cout << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(40) << "Total USD" << left << setw(20) << right << setw(35) << orderDetail.getTotalAmount() << " $" << left << setw(12) << endl;
    cout << right << setw(40) << "Total KHR" << left << setw(20) << right << setw(35) << fixed << setprecision(2) << orderDetail.getTotalAmount() * 4100 << " R" << left << setw(12) << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(80) << "   VAT%     Net.Amt         VAT            Amount" << endl;
    cout << right << setw(32) << "$" << left << setw(2) << " " << orderDetail.getVat();
    cout << left << setw(7) << " " << left << setw(5) << orderDetail.getNetAmt() << left << setw(8) << " " << left << setw(8) << orderDetail.getVat() << right << setw(10) << orderDetail.getTotalAmount() << endl;
    cout << right << setw(80) << "-------------------------------------------------" << endl;
    cout << right << setw(71) << "Thank you,  See you again soon!" << endl;
}
Order Order::operator<<(Order &order)
{
    ofstream writeFile;
    writeFile.open("order.bat", ios::out | ios::binary|ios::app);
    writeFile.write((char *)&order, sizeof(Order));
    writeFile.close();
    return order;
}
Order Order::operator>>(Order &getOrder)
{
    ifstream loadFile;
    loadFile.open("order.bat", ios::in | ios::binary);
    try
    {
        loadFile.read((char*)&getOrder, sizeof(Order));
        if (!loadFile)
        {
            ofstream writeFile;
            writeFile.open("order.bat", ios::out | ios::binary);
            throw(1);
        }
    }
    catch (int num)
    {
        cout << "\tDo not file to open..." << endl;
    }
    getchar();
    loadFile.close();
    return getOrder;
}