//Product class
class Product
{
    protected:
        int quantity;
        float price;
        char productName[20];
        float amount;

    public:
        virtual void addProduct() = 0;
        virtual int getQuantity() = 0;
        virtual float getPrice() = 0;
        virtual char *getProdcutName() = 0;
        virtual char getSize() = 0;
        virtual float getAmount() = 0;
};

//Pizza class
class Pizza : public Product
{
    private:
        char size;

    public:
        void addProduct();
        int getQuantity();
        float getPrice();
        char *getProdcutName();
        char getSize();
        float getAmount();
};
//Drink class
class Drink : public Product
{
    public:
        void addProduct();
        int getQuantity();
        float getPrice();
        char *getProdcutName();
        char getSize();
        float getAmount();
};

//Date class
class Date
{
    protected:
        int hour;
        int minute;
        int month;
        int year;
        int day;

    public:
        Date();
        void setDate();
        int getHour();
        int getMinute();
        int getMonth();
        int getYear();
        int getDay();
};

//Customer class
class Customer
{
    protected:
        int id;
        char name[20];
        char customerPhoneNumber[20];
        char customerAddress[20];

    public:
        void addCustomer();
        int getID();
        char *getName();
        char *getPhoneNumber();
        char *getAddress();
};

//OrderDetail class
class OrderDetail
{
    protected:
        Product *product[20];
        float total_usd = 0;
        static float vat;
        float net_amt;
        int count=0;

    public:
        void chageCount(int);
        void detail();
        void menu();
        void reciept();
        float getTotalAmount();
        float getVat();
        float getNetAmt();
        int getCount();
        void newValue();
};

//Order class
class Order
{
private:
    OrderDetail orderDetail;
    Date date;
    int counts;

public:
    Customer customer;
    int n;
    void createOrder();
    void editOrder();
    void reciept();
    Order operator<<(Order &);
    Order operator>>(Order &);
};