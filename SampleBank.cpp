#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    string applicantName, rejectionReasons;
    int applicantAge, creditScore, loanTerm;
    double annualIncome, loanAmount;
    char existingLoan, evaluateAgain;
    bool isEligible = true;

    do {
        cout << "Enter applicant's Name: ";
        getline(cin, applicantName);
        cout << "Enter applicant's Age: ";
        cin >> applicantAge;
        cout << "Enter annual income: ";
        cin >> annualIncome;
        cout << "Enter credit score: ";
        cin >> creditScore;
        cout << "Enter loan amount: ";
        cin >> loanAmount;
        cout << "Enter loan term (years): ";
        cin >> loanTerm;
        cout << "Do you have an existing loan with the bank? (Y/N): ";
        cin >> existingLoan;
        cin.ignore();

        if (applicantAge < 21 || applicantAge > 60) {
            isEligible = false;
            rejectionReasons += "Age Requirement: You must be between 21 and 60 years old. \n";
        }
        if ((loanAmount < 50000 && annualIncome < 30000) || 
            (loanAmount >= 50000 && loanAmount <= 100000 && annualIncome < 50000) || 
            (loanAmount > 100000 && annualIncome < 80000)) {
            isEligible = false;
            rejectionReasons += "Income Requirement: Your annual income does not meet the required income for the loan amount requested.\n";
        }
        if (creditScore < 700) {
            isEligible = false;
            rejectionReasons += "Credit Score Requirement: A credit score of 700 or higher is required. \n";
        }
        if (loanTerm < 1 || loanTerm > 20) {
            isEligible = false;
            rejectionReasons += "Loan Term Requirement: The loan term must be between 1 and 20 years.\n";
        }
        if (existingLoan == 'Y' || existingLoan == 'y') {
            isEligible = false;
            rejectionReasons += "Existing Loan: You must not have an existing loan with the bank. Please \n";
        }
        cout << "Loan Application Result for " << applicantName << ":\n";
        if (isEligible) {
            double annualInterest = 6.0; 
            if (annualIncome > 100000) {
                annualInterest += 1.0; 
            } else if (loanAmount < 50000) {
                annualInterest -= 1.0; 
            }
            double monthlyInterest = annualInterest / 12; 
            int totalMonths = loanTerm * 12;

            double monthlyAmortization = (loanAmount * monthlyInterest) / (1 - pow(1 + monthlyInterest, -totalMonths));

            cout << "Status: Approved\n";
            cout << "Interest Rate: " << annualInterest << "%\n";
            cout << "Loan Term: " << loanTerm << " years\n";
            cout << "Monthly Amortization: Php " << fixed << setprecision(2) << monthlyAmortization << endl; 
        } else {
            cout << "Status: Rejected\n";
            cout << "Reasons for Rejection:\n" << rejectionReasons;
        }

        cout << "Do you want to evaluate another loan? (Y/N): ";
        cin >> evaluateAgain;
        cin.ignore();

    } while (evaluateAgain == 'Y' || evaluateAgain == 'y');

    return 0;
}