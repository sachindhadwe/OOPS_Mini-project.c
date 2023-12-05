#include <bits/stdc++.h>
using namespace std;

class hotel
{
public:
    fstream f;
    string ord[30];
    int count = 0, sum = 0;
    int tableno, pri[30], total[30], Q[30];
    void get_data();
    void get_order();
    void order();
    void total_price();
    void bill();
};

void hotel::get_data()
{
    f.open("Hotel.txt", ios::out);
    cout << "Enter Table No:- ";
    cin >> tableno;
    f<< "Table Number:- "<<tableno<<endl;
    f.close();
}

void hotel::get_order()
{
    string order, ch;
    cout << "Enter your order and if you want to stop enter Done \n";
    while (1)
    {

        cout << "Enter:- ";
        cin >> order;
        ord[count] = order;
        if (order == "Done")
        {
            break;
        }
        cout << "Enter Quantity of " << order << ":- ";
        cin >> Q[count];
        count++;
    }
}

void hotel::order()
{
    for (int j = 0; j < count; j++)
    {
        if (ord[j] == "Mix-Veg")
        {
            total[j] = 100;
        }
        else if (ord[j] == "Panner-Masala")
        {
            total[j] = 120;
        }
        else if (ord[j] == "Veg-Kolhapuri")
        {
            total[j] = 130;
        }
        else if (ord[j] == "Roti")
        {
            total[j] = 10;
        }
        else if (ord[j] == "Water-Bottle")
        {
            total[j] = 20;
        }
        else if (ord[j] == "Rice")
        {
            total[j] = 40;
        }
        else
        {
            continue;
        }
    }
}

void hotel::total_price()
{
    f.open("Hotel.txt", ios::app);
    // cout<<"tellg="<<f.tellg();
    // f.open("oops.txt", ios::app);
    f << "\n--------------------------------------------------------------" << endl;
    f << "\t\t*** List of Order ***\n";
    f << "--------------------------------------------------------------" << endl;

    f << setw(20) << left << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Total"<< "\n";
    for (int i = 0; i < count; i++)
    {
        pri[i] = total[i] * Q[i];
    }
    for (int i = 0; i < count; i++)
    {
        sum = sum + pri[i];
    }
    for (int i = 0; i < count; i++)
    {
        f << setw(20) << left << ord[i] << setw(15) << total[i] << setw(15) << Q[i] << setw(15) << pri[i] << "\n";
    }
    f << "\t\t\t\t\t\tTotal Bill:" << sum << endl;
}

void hotel::bill()
{
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "\t\t*** List of Order ***\n";
    cout << "--------------------------------------------------------------" << endl;

    // f.open("oops.txt");

    cout << setw(20) << left << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Total"<< "\n";

    for (int i = 0; i < count; i++)
    {
        // f.read(reinterpret_cast<char *>(&nam[i]), sizeof(nam[i]));
        // f.read(reinterpret_cast<char *>(&pri[i]), sizeof(pri[i]));
        // f.read(reinterpret_cast<char *>(&quan[i]), sizeof(quan[i]));

        cout << setw(20) << left << ord[i] << setw(15) << total[i] << setw(15) << Q[i] << setw(15) << pri[i] << "\n";
    }
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tTotal Bill:" << sum << endl;
    f.close();
}

int main()
{
    hotel h;
    fstream file;
    // int count=0;

    h.get_data();

    cout << "-------------- ~~~ --------------" << endl;
    cout << "\t\tMENU\t\t" << endl;
    cout << "-------------- ~~~ --------------" << endl;

    cout << "Mix-Veg"
         << "\t\t\t"
         << "100/-" << endl
         << "Panner-Masala"
         << "\t\t"
         << "120/-" << endl
         << "Veg-Kolhapuri"
         << "\t\t"
         << "130/-" << endl
         << "Rice"
         << "\t\t\t"
         << "40/-" << endl
         << "Roti"
         << "\t\t\t"
         << "10/-" << endl
         << "Water-Bottle"
         << "\t\t"
         << "20/-" << endl;

    cout << endl
         << endl;
    h.get_order();
    // count++;
    h.order();
    h.total_price();
    h.bill();

    return 0;
}