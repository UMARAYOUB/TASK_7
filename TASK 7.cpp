#include <iostream>
#include <string>
#include <iomanip>
 using namespace std;

const int NUM_CHARITIES = 3;

struct Charity {
    string name;
    int totalDonation;
};

void displayCharities(const Charity charities[]) {
    cout << "Available Charities:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << i + 1 << ". " << charities[i].name << "\n";
    }
}

int main() {


    Charity charities[NUM_CHARITIES];
    // Initialize charities
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << "Enter name for Charity " << i + 1 << ": ";
        getline(cin >> ws, charities[i].name);
        charities[i].totalDonation = 0;
    }

    int choice;
    double billAmount;
    int donation;
    int totals[NUM_CHARITIES] = {0};

    do {
        displayCharities(charities);
        cout << "Enter your choice (1-3) or -1 to show totals: ";
        cin >> choice;

        if (choice >= 1 && choice <= NUM_CHARITIES) {
            cout << "Enter the bill amount: $";
            cin >> billAmount;

            donation = billAmount * 0.25;
            charities[choice - 1].totalDonation += donation;
            totals[choice - 1] += donation;

            cout << "Donated $" << donation << " to " << charities[choice - 1].name << "\n";
        } else if (choice != -1) {
            cout << "Invalid choice. Please choose 1, 2, 3, or -1 to show totals.\n";
        }
    } while (choice != -1);

    // Display totals in descending order
    cout << "\nTotals Donated:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        int maxIdx = 0;
        for (int j = 1; j < NUM_CHARITIES; ++j) {
            if (totals[j] > totals[maxIdx]) {
                maxIdx = j;
            }
        }
        cout << charities[maxIdx].name << ": $" << totals[maxIdx] << "\n";
        totals[maxIdx] = -1; // Mark as visited
    }

    // Calculate and display grand total
    int grandTotal = 0;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        grandTotal += charities[i].totalDonation;
    }
    cout << "GRAND TOTAL DONATED TO CHARITY: $" << grandTotal << "\n";

    return 0;
}

