// This program computes personal income tax (PAYE-style, individuals in
// business) based on the chargeable income (CY) and residency status.
// Enter 0 for resident, 1 for non-resident.
//
// +----------------------+------------------------------------------+------------------------------------------+
// | CHARGEABLE INCOME, CY| RESIDENTS                                 | NON-RESIDENTS                             |
// | (UGX Annual)          | RATE OF TAX                              | RATE OF TAX                               |
// +----------------------+------------------------------------------+------------------------------------------+
// | 0 to 2,820,000        | Nil                                       | CY x 10%                                  |
// | 2,820,000 to           | (CY - 2,820,000) x 10%                    | CY x 10%                                  |
// | 4,020,000              |                                            |                                            |
// | 4,020,000 to           | (CY - 4,020,000) x 20% + 120,000          | (CY - 4,020,000) x 20% + 402,000          |
// | 4,920,000              |                                            |                                            |
// | 4,920,000 to           | (CY - 4,920,000) x 30% + 300,000          | (CY - 4,920,000) x 30% + 582,000          |
// | 120,000,000            |                                            |                                            |
// | Above 120,000,000      | [(CY - 4,920,000) x 30% + 300,000]        | [(CY - 4,920,000) x 30% + 582,000]        |
// |                        | + [(CY - 120,000,000) x 10%]              | + [(CY - 120,000,000) x 10%]              |
// +----------------------+------------------------------------------+------------------------------------------+

#include <iostream>
using namespace std;

int main() {
    // Bracket thresholds (UGX)
    const double B1 = 2820000;   // tax-free threshold (residents only)
    const double B2 = 4020000;
    const double B3 = 4920000;
    const double B4 = 120000000;

    int status;
    double cy;

    cout << "Enter residence status (0 = resident, 1 = non-resident): ";
    cin >> status;

    cout << "Enter chargeable income (CY) in UGX: ";
    cin >> cy;

    double tax = 0.0;

    if (status == 0) {
        // ---------- RESIDENT ----------
        if (cy <= B1) {
            tax = 0.0;
        } else if (cy <= B2) {
            tax = (cy - B1) * 0.10;
        } else if (cy <= B3) {
            tax = (cy - B2) * 0.20 + 120000;
        } else if (cy <= B4) {
            tax = (cy - B3) * 0.30 + 300000;
        } else { // above 120,000,000
            tax = (B4 - B3) * 0.30 + 300000        // tax up to 120m
                  + (cy - B4) * 0.10;               // extra 10% above 120m
        }
    } else if (status == 1) {
        // ---------- NON-RESIDENT ----------
        if (cy <= B2) {
            tax = cy * 0.10;
        } else if (cy <= B3) {
            tax = (cy - B2) * 0.20 + 402000;
        } else if (cy <= B4) {
            tax = (cy - B3) * 0.30 + 582000;
        } else { // above 120,000,000
            tax = (B4 - B3) * 0.30 + 582000         // tax up to 120m
                  + (cy - B4) * 0.10;                 // extra 10% above 120m
        }
    } else {
        cout << "Invalid residence status entered. Please enter 0 or 1." << endl;
        return 1;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Chargeable income: UGX " << cy << endl;
    cout << "Residence status : " << (status == 0 ? "Resident" : "Non-resident") << endl;
    cout << "Tax payable      : UGX " << tax << endl;

    return 0;
}
