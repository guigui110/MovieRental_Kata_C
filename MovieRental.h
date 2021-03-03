// 文件为Movie Retal的初始文件
// Created by Administrator on 2021/2/27.
//

#ifndef MOVIE_RENTAL_MOVIERENTAL_H
#define MOVIE_RENTAL_MOVIERENTAL_H

#include <string>
#include <vector>

class Movie {
public:
    Movie() {
        _title = "";
        _priceCode = 0;
    }

    Movie& operator=(const Movie& arg) {
        _title = arg._title;
        _priceCode = arg._priceCode;
        return *this;
    }

    Movie(const Movie& arg) {
        _title = arg._title;
        _priceCode = arg._priceCode;
    }

    Movie(std::string title, int priceCode) {
        _title = title;
        _priceCode = priceCode;
    }
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;
    static const int CHILDRENS = 2;
public:
    int GetPriceCode() {
        return _priceCode;
    }

    std::string GetTitle() {
        return _title;
    }
private:
    std::string _title;
    int _priceCode;
};

class Rental {
public:
    Rental(Movie movie, int daysRented) {
        _movie = movie;
        _daysRented = daysRented;
    }

    int GetDaysRented() {
        return _daysRented;
    }
    Movie GetMovie() {
        return _movie;
    }
private:
    int _daysRented;
    Movie _movie;

};

class Customer {
public:
    Customer(std::string name) {
        _name = name;
    }
    void AddRental(Rental rental) {
        _rentals.push_back(rental);
    }

    std::string statement();

    std::string GetName() {
        return _name;
    }
private:
    std::string _name;
    std::vector<Rental> _rentals;
};



#endif //MOVIE_RENTAL_MOVIERENTAL_H
