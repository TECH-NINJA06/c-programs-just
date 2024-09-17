#include <iostream>
using namespace std;

class Account {
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;

public:
    void setDetails(string name, int accNum, string accType, double bal) {
        customerName = name;
        accountNumber = accNum;
        accountType = accType;
        balance = bal;
    }

    void addMoney(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance << endl;
    }

    void showBalance() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    void addInterest(double rate, int years) {
        double interest = balance * rate * years / 100;
        balance += interest;
        cout << "Interest added: " << interest << ". New balance: " << balance << endl;
    }
};

class CurrentAccount : public Account {
    const double minBalance = 1000.0;
    const double penalty = 100.0;

public:
    void withdrawMoney(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New balance: " << balance << endl;
        }
    }

    void enforceMinBalance() {
        if (balance < minBalance) {
            cout << "Balance below minimum! Penalty of " << penalty << " imposed." << endl;
            balance -= penalty;
            cout << "New balance after penalty: " << balance << endl;
        } else {
            cout << "Balance is above the minimum requirement." << endl;
        }
    }
};

int main() {
    int choice;
    SavingsAccount sa;
    CurrentAccount ca;
    string name, type;
    int accNum;
    double bal, amount, rate;
    int years;

    while (true) {
        cout << "1. Create Savings Account\n2. Create Current Account\n3. Deposit Money\n4. Withdraw Money\n5. Add Interest\n6. Show Balance\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter account type: ";
                cin >> type;
                cout << "Enter balance: ";
                cin >> bal;
                sa.setDetails(name, accNum, type, bal);
                break;
            case 2:
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter account type: ";
                cin >> type;
                cout << "Enter balance: ";
                cin >> bal;
                ca.setDetails(name, accNum, type, bal);
                break;
            case 3:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                sa.addMoney(amount);
                break;
            case 4:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                ca.withdrawMoney(amount);
                break;
            case 5:
                cout << "Enter rate of interest: ";
                cin >> rate;
                cout << "Enter number of years: ";
                cin >> years;
                sa.addInterest(rate, years);
                break;
            case 6:
                cout << "Savings Account:\n";
                sa.showBalance();
                cout << "Current Account:\n";
                ca.showBalance();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
