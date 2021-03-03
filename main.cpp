#include <iostream>
#include "MovieRental.h"

int main()
{
    Movie regular("zhanlang1", Movie::REGULAR);
    Movie newrelease("zhanlang2", Movie::NEW_RELEASE);
    Rental rental(regular, 3);
    Rental rental2(newrelease, 1);
    Customer customer("xuguibin");
    customer.AddRental(rental);
    customer.AddRental(rental2);


    std::string detailBills = customer.statement();

    std::cout << detailBills << std::endl;
    return 0;
}
