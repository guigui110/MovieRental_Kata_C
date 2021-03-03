// 文件为Movie Retal的初始文件
// Created by Administrator on 2021/2/27.
//

#include "MovieRental.h"

std::string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    std::vector<Rental>::iterator  each = _rentals.begin();
    std::string result = "Rental Record for " + GetName() + "\r\n";
    while (each != _rentals.end()) {
        double thisAmount = 0;

        // determine amounts for each line
        switch (each->GetMovie().GetPriceCode()) {
            case Movie::REGULAR:
                thisAmount += 2;
                if (each->GetDaysRented() > 2) {
                    thisAmount += (each->GetDaysRented() - 2) * 1.5;
                }
                break;
            case Movie::NEW_RELEASE:
                thisAmount += each->GetDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if (each->GetDaysRented() > 3) {
                    thisAmount += (each->GetDaysRented() - 3) * 1.5;
                }
                break;
        }

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ((each->GetMovie().GetPriceCode() == Movie::NEW_RELEASE) &&
            (each->GetDaysRented() > 1)) {
            frequentRenterPoints++;
        }

        // show figures for this rental
        char ch[64] = {0};
        sprintf_s(ch, "%g", thisAmount);
        result += "\t" + each->GetMovie().GetTitle() + "\t" + std::string(ch) + "\r\n";
        totalAmount += thisAmount;

        each++;
    }

    // add footer lines
    char amount[64] = {0};
    sprintf_s(amount, "%g", totalAmount);
    result += "Amount owed is " + std::string(amount) + "\r\n";
    char points[64] = {0};
    sprintf_s(points, "%d", frequentRenterPoints);
    result += "You earned " + std::string(points) + " frequent renter points";

    return  result;
}
