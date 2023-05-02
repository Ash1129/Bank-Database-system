#include <iostream>
#include<cmath>

using namespace std;

class Bank
{
private:
    float balance;
    string name;
    long bankid;
    float rate;
public:
    Bank(string na, long bid, int bal, float r);
    ~Bank();
    void Deposit(float amount);
    void Withdrawal(float amount);
    float Compound(float amount, int time, int num);
    float getBalance();
    void Menu();
    friend ostream & operator<<(ostream &os, Bank &b);
};



ostream & operator<<(ostream &os, Bank &b)
{
    os<<"Name: "<<b.name<<endl;
    os<<"Bank ID: "<<b.bankid<<endl;
    os<<"Balance: "<<b.getBalance()<<endl;
    return os;
}
int main()
{
    Bank b("Ashwin", 12094, 5000.0, 5);
    b.Menu();
    cout<<"\nYour details are:\n";
    cout<<b;
    return 0;
}

Bank::Bank(string na, long bid, int bal, float r)
{
    balance =  bal;
    name = na;
    bankid = bid;
    rate = r;
}

void Bank::Deposit(float amount)
{
    balance+=amount;
}

void Bank::Withdrawal(float amount)
{
    if(balance<amount)
    {
        cout<<"Insufficient Funds"<<endl;
        return;
    }
    else
        balance-=amount;
    if(balance<500)
        cout<<"The balance is falling under the monthly balance. Please Deposit to avoid fines at the end of the month"<<endl;
}

float Bank::Compound(float amount, int time, int num)
{
    float ta;
    rate/=100;
    ta = amount * (pow((1+(rate/num)), (num*time)));
    return ta;
}

float Bank::getBalance()
{
    return balance;
}

void Bank::Menu()
{
    int x, time, num;
    float amount;
    cout<<"Menu-Driven Program for Banking System\n\t1. To make a deposit\n\t2. To make a withdrawal\n\t3. To check compounded interest over an amount\n\t4. To check balance\n\t0. Exit program\n";
    do
    {
        cout<<"Enter choice: ";
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter amount: ";
                cin>>amount;
                Deposit(amount);
                break;
            case 2:
                cout<<"Enter amount: ";
                cin>>amount;
                Withdrawal(amount);
                break;
            case 3:
                cout<<"Enter the amount, duration of loan and the number of times interest applied per time period:\n";
                cin>>amount>>time>>num;
                cout<<Compound(amount, time, num)<<endl;
                break;
            case 4:
                cout<<"Your balance is: "<<getBalance()<<endl;
                break;
            case 0:
                return;
                break;
            default:
                cout<<"Invalid selection. Try again!"<<endl;
        }
    }while(x);
}

Bank::~Bank()
{
    name = "";
    bankid = 0;
    balance = 0.0;
    rate = 0;
}
