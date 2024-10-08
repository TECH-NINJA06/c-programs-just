#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>  // For time-related functions
using namespace std;

int main() {
    string taxiNo, customerName,Drivername, fromLocation, toLocation;
    float ratePerKm, waitingCharges, tollCharges, ferryCharges, nightCharges, otherCharges,openingKms,closingKms,totalKms;
    string startingTime, closingTime;
    long mob;

    //take input:
    cout << "Enter Taxi No: ";
    getline(cin, taxiNo);
    cout << "Enter Customer Name: ";
    getline(cin, customerName);
    cout << "Enter Driver Name: ";
    getline(cin, Drivername);
    cout << "Enter From Location: ";
    getline(cin, fromLocation);
    cout << "Enter To Location: ";
    getline(cin, toLocation);
    cout << "Enter Rate per Km: ";
    cin >> ratePerKm;
    cout << "Enter Waiting Charges: ";
    cin >> waitingCharges;
    cout << "Enter Toll Charges: ";
    cin >> tollCharges;
    cout << "Enter Ferry Charges: ";
    cin >> ferryCharges;
    cout << "Enter Night Charges: ";
    cin >> nightCharges;
    cout << "Enter Other Charges: ";
    cin >> otherCharges;
    cout << "Enter Opening Kms: ";
    cin >> openingKms;
    cout << "Enter Closing Kms: ";
    cin >> closingKms;
    cout << "Enter Total Kms: ";
    cin >> totalKms;
    cout << "Enter Starting Time: ";
    cin >> startingTime;
    cout << "Enter Closing Time: ";
    cin >> closingTime;
    cout << "Enter Mobile Number: ";
    cin >> mob;

    // Calculate total amount
    float totalAmount = ratePerKm + waitingCharges + tollCharges + ferryCharges + nightCharges + otherCharges;

    time_t t = time(0); // Get current time
    tm* now = localtime(&t);

    // Printing receipt
    cout.precision(2);
    cout << fixed;  // To ensure we print two decimal places

    // Top Header part
    cout << "|"<<setw(77) << setfill('-') << "-" <<right<<"|" <<endl;
    cout << "|" << setw(48) << setfill(' ') << "MARUTI TAXI ASSOCIATION" << setw(30) << right << "|" << endl;
    cout << "|" << setw(68) << right << "Office Address: Near Water Tank, Shantinagar, Ponda - Goa" << setw(10) << "|" << endl;
    cout << "|" << setw(42) << setfill(' ') << "BILL/RECEIPT" << setw(36) << right << "|" << endl;
    cout << "|"<<setw(77) << setfill('-') << "-" <<right<<"|" <<endl;

    // Display input data (Details section)
    cout <<setfill(' ')<< "|" << setw(26) << left << "Reg. No.: 818/Goa/2013"  << setw(10) << left<<"Taxi No: " << left << setw(10) <<taxiNo<<setw(15) <<left <<"Mobile Number: "<<setw(14)<<left<<mob<<setw(3)<<right<< "|" << endl;
    cout << "|"<<setw(35) << setfill(' ') << " " <<setw(10)<<setfill('-')<<"-"<<setw(16)<<setfill(' ')<<" "<<setw(10)<<setfill('-')<<"-"<< setw(7)<<setfill(' ')<<right<<"|" <<endl;


    cout << "|" << setw(8) << left << "Bill No.:" << setw(10) << left << "123456789" << setw(32) << right << "Date:" << setw(2) << setfill(' ') << now->tm_mday << "/" << setw(2) << setfill(' ') << (now->tm_mon + 1) << "/" << setw(2) << setfill(' ') << (now->tm_year + 1900) % 100 << setw(19) << right <<"|" << endl;
    cout << "|"<<setw(9) << setfill(' ') << " " <<setw(9)<<setfill('-')<<"-"<<setw(34)<<setfill(' ')<<" "<<setw(8)<<setfill('-')<<"-"<<setw(18)<<setfill(' ')<<right<<"|" <<endl;
    // Print the current date in DD/MM/YY format

    cout<<"|"<<setw(8)<<left<<"From.:"<<setw(15)<<left<<fromLocation<<setw(26)<<right<<"To: "<<setw(15)<<left<<toLocation <<setw(14)<<right<<"|"<<endl;
    cout << "|"<<setw(8) <<setfill(' ')<<" "<<setw(15)<< setfill('-') << "-" <<setw(26)<<setfill(' ')<<" "<<setw(15)<<setfill('-')<<"-"<<setw(14)<<setfill(' ')<<right<<"|" <<endl;


    cout<<"|"<<setw(15)<<left<<"Opening Kms.:"<<setw(10)<<left<<openingKms<<setw(35)<<right<<"Starting Time "<<setw(15)<<left<<startingTime <<setw(3)<<right<<"|"<<endl;
    cout << "|"<<setw(15) << setfill(' ') << " " <<setw(10)<<setfill('-')<<"-"<<setw(35)<<setfill(' ')<<" "<<setw(10)<<left<<setfill('-')<<"-"<<setw(3)<<setfill(' ')<<right<<"|" <<endl;

    //i want same closing km and time like above but along with total kms in middle well formatted
    cout<<"|"<<setw(13)<<left<<"Closing Kms.:"<<setw(5)<<left<<closingKms<<left<<setw(15)<<right<<"Total Kms. "<<left<<setw(5)<<openingKms+closingKms<< setw(18)<<right<<"Closing Time "<<setw(10)<<left<<closingTime <<setw(12)<<right<<"|"<<endl;
cout << "|"<<setw(13) << setfill(' ') << " "
     <<setw(8)<<setfill('-')<<"-"
     <<setw(12)<<setfill(' ')<<" "
     <<setw(8)<<setfill('-')<<"-"
     <<setw(20)<<setfill(' ')<<" "
     <<setw(10)<<setfill('-')<<"-"
     <<setw(7)<<setfill(' ')<<right<<"|" <<endl;

    // Line under details
    cout << "|"<<setw(77) << setfill('-') << "-" <<right<<"|" <<endl;

    // Particulars header
    cout <<setfill(' ')<< "|" << setw(42) << right << "Particulars" <<setw(20)<<right<< "|" << setw(11) << right << "Amount" << setw(5) << "|" << endl;
    cout <<"|"<< setw(77) << setfill('-') << "-" <<"|" <<endl;
    cout << setfill(' ');

    // Column for Rs and Paise
    cout << "|" << setw(61) << left << " " << "|" << setw(8) << "Rs." << "|" << setw(6) <<left << "Paise" <<right<<"|"<< endl;

    // Printing the details (Particulars section)
    cout << setw(62) <<left<<"|" <<setfill(' ')<< right<<"|" <<setfill('-')<<setw(16)<<right<<"|"<< endl;
    cout << setfill(' ') << "|" << setw(61) << left << "Rate of Km. in Rs." << "|" << setw(8) << (int)(ratePerKm *(closingKms-openingKms)) << "|" << setw(6) << (ratePerKm - (int)ratePerKm) * 100*(closingKms-openingKms) << "|" << endl;
    cout << "|" << setw(61) << left << "Waiting Charges" << "|" << setw(8) << (int)waitingCharges << "|" << setw(6) << (waitingCharges - (int)waitingCharges) * 100 << "|" << endl;
    cout << "|" << setw(61) << left << "Toll Charges" << "|" << setw(8) << (int)tollCharges << "|" << setw(6) << (tollCharges - (int)tollCharges) * 100 << "|" << endl;
    cout << "|" << setw(61) << left << "Ferry Charges" << "|" << setw(8) << (int)ferryCharges << "|" << setw(6) << (ferryCharges - (int)ferryCharges) * 100 << "|" << endl;
    cout << "|" << setw(61) << left << "Night Charges" << "|" << setw(8) << (int)nightCharges << "|" << setw(6) << (nightCharges - (int)nightCharges) * 100 << "|" << endl;
    cout << "|" << setw(61) << left << "Other Charges" << "|" << setw(8) << (int)otherCharges << "|" << setw(6) << (otherCharges - (int)otherCharges) * 100 << "|" << endl;

    // Total amount
    cout << "|"<<setw(77) << setfill('-') << "-" <<right<<"|" <<endl;
    cout << setfill(' ') << "|" << setw(61) << left << "Total Amount" << "|" << setw(8) << (int)totalAmount << "|" << setw(6) << (totalAmount - (int)totalAmount) * 100 << "|" << endl;
    cout << "|"<<setw(77) << setfill('-') << "-" <<right<<"|" <<endl;

    // Footer
    cout << "|" <<setfill(' ')<< setw(61) << left << "Customer Signature" << setw(17) << right << "Driver's Sign|" << endl;
    cout << "|" << setw(40) << left << customerName << setw(37) << right <<Drivername << "|" << endl;
    cout << "|"<<setw(77) << setfill(' ') << " " <<right<<"|" <<endl;
    cout << "|"<<setw(77) << setfill('-') << "-" <<right<<"|" <<endl;

    return 0;
}
