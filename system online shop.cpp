/*outhers:
mohamed tarek fathi
function of this code:
this program is system to halp sellers to manage their shops and store with datails about items they sell and their information
 */
#include <iostream>
#include <string>
using namespace std;
class item
{
private:
    int ID, quantity;
    float price;
    string name;
    static int counter;
public:
    //default Constructor 
    item()
    {
        quantity = 0;
        name = " ";
        price = 0;


    }
    //parametrized Constructor 
    item(string n, int q, float p)
    {
        name = n;
        quantity = q;
        price = p;

    }
    //copy Constructor 
    item(const item& i1)
    {
        ID = i1.ID;
        quantity = i1.quantity;
        price = i1.price;
        name = i1.name;

    }
    void setid()
    {
        counter++;
        ID = counter;
    }
    void setquantity(int q)
    {
        quantity = q;
    }
    void setprice(float p)
    {
        price = p;
    }
    void setname(string n)
    {
        name = n;
    }
    int getid() const { return ID; }
    int getquantity() const { return quantity; }
    float getprice() const { return price; }
    string getname()const { return name; }
    //overloading operator to add quantity if the item already exist
    void  operator +=(item i1)
    {
        quantity = quantity + i1.quantity;

    }
    //overloading operator to subs quantity when seller sell item
    void operator -= (int q)
    {

        quantity = quantity - q;

    }
    //overloading operator to check if names of two object is same
    friend bool operator == (item& i1, item& i2);
    //overloading operator to take data of item
    friend ostream& operator << (ostream& out, const  item& i1);
    //overloading operator to print data of item
    friend istream& operator >> (istream& in, item& i1);
};
//definition of overloading operators
bool operator == (item& i1, item& i2)
{
    if (i1.name == i2.name)
        return true;
    else return false;
}

ostream& operator << (ostream& out, const item& i1)
{
    out << "ID : " << i1.ID << endl << "name: " << i1.name << endl << "price: " << i1.price << endl << "quantity: " << i1.quantity << endl;
    return out;
}
istream& operator >> (istream& in, item& i1)
{
    cout << "enter the name :";
    in >> i1.name;
    cout << "enter the quantity :";
    in >> i1.quantity;
    cout << "enter the price :";
    in >> i1.price;
    return in;
}
//initialize counter id of each item
int item::counter = 0;
class Seller
{
private:
    string name, email;
    item* items;
    int maxitems;
public:
    //parametrized constructor take name & email & store capacity
    Seller(string n, string e, int max)
    {
        maxitems = max;
        name = n;
        email = e;
        items = new item[maxitems];

    }
    //operator overloading to print seller information
    friend ostream& operator << (ostream& out, Seller& s1);
    //counter to count number of items the seller store
    static int count;
    /*take object of item and make seller enter his item if it already exist it will add quantity
    else it will add item with it's data*/
    bool Add_item(item i1)
    {

        for (int i = 0; i < count; i++)
        {
            if (i1 == items[i])
            {
                items[i] += i1;
                cout << "item already exist and quantity has been add" << endl;
                return true;
            }
        }
        if (count < maxitems)
        {
            items[count] = i1;
            //to set id to each item
            items[count].setid();
            //to increase counter id
            count++;
            cout << "sucessful add item " << endl;
            return true;
        }
        else
        {
            cout << "fail to add item " << endl;
            return false;
        }
    }
    /*take string name & integer quantity and search item by name if exist it will sell specific quantity
    else it will print remaining quantity */
    bool Sell_item(string n, int q)
    {
        for (int i = 0; i < count; i++)
        {
            if (n == items[i].getname())
            {
                if (q <= items[i].getquantity())
                {
                    items[i] -= q;
                    cout << "item was found and sell spicific quantity" << endl;
                    return true;
                }
                else
                {
                    cout << "there is only " << items[i].getquantity() << " left for this item" << endl;
                    return true;
                }
            }

        }
        cout << "there is no item exist with this name" << endl;
        return false;
    }
    //using overload operator to print item information
    void print_item()
    {
        for (int i = 0; i < count; i++)
        {
            cout << endl << "item " << i + 1 << ": " << endl << items[i];
        }
    }
    //take integer from seller and search about item with this id
    item find_item(int id)
    {
        for (int i = 0; i < maxitems; i++)
        {
            if (items[i].getid() == id)
                return items[i];
        }
    }
    //distructor to free memory
    ~Seller()
    {
        delete[] items;
    }
};
//initialize counter of item
int Seller::count = 0;
ostream& operator << (ostream& out, Seller& s1)
{
    cout << "name : " << s1.name << endl << "email : " << s1.email << endl << "the store capacity is : " << s1.maxitems;
    return out;
}
int main()
{
    int maxx;
    string n, e;
    cout << "Please enter your details: " << endl << "your name : ";
    getline(cin, n);
    cout << "your email : ";
    cin >> e;
    cout << " enter your store capacity : ";
    cin >> maxx;
    Seller s1(n, e, maxx);

    bool cond = true;
    cout << "please enter number of your choice of the following Menu :";
    while (cond)
    {
        int choice;
        cout << endl << "1. Print My Info" << endl
            << "2. Add An Item" << endl << "3. Sell An Item" << endl
            << "4. Print Items" << endl << "5. Find an Item by ID" << endl << "6. Exit" << endl;
        cin >> choice;
        if (choice == 1)
            cout << s1;
        else if (choice == 2)
        {

            item i1;
            cin >> i1;
            s1.Add_item(i1);

        }
        else if (choice == 3)
        {
            int q; string n;
            cout << "enter item's name : ";
            cin >> n;
            cout << "enter item's quantity :";
            cin >> q;
            s1.Sell_item(n, q);
        }
        else if (choice == 4)
            s1.print_item();
        else if (choice == 5)
        {
            int id;
            cout << "enter ID of item : ";
            cin >> id;
            cout << s1.find_item(id);
        }
        else if (choice == 6)
            cond = false;
    }
    return 0;
}