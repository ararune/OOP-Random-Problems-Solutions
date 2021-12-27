#include <iostream>

// Given the main function, write Money class and necessary operators so that the output will display 13 dollars and 20 cents
class Money {
	int dollar = 0;
	int cent = 0;
	
public:
	Money(int a, int b);
	Money(int a);
	Money();
	Money operator+(Money& other);
	friend std::ostream& operator<<(std::ostream& os, Money& bill);

	int getDollar();
	int getCent();

	void setDollar(int x);
	void setCent(int y);

};

std::ostream& operator<<(std::ostream& os, Money& bill)
{
	os << bill.getDollar() << " dollars " << bill.getCent() << " cents";
	return os;
}
int Money::getDollar() {
	return dollar;
}
int Money::getCent() {
	return cent;
}
void Money::setDollar(int x) {
	dollar += x;
}

void Money::setCent(int y) {
	cent += y;
}
Money Money::operator+(Money& other) { 

	dollar += other.dollar;
	cent += other.cent;
	if (cent >= 100)
	{
		setCent(-100);
		setDollar(1);
	}
	return Money(dollar, cent);
}
Money::Money(int a, int b) {
	dollar += a;
	cent += b;
}
Money::Money(int a) {
	dollar += a;
}
Money::Money() {

}
int main()
{
	Money papers(6, 50), coffee(5, 70), sugar(1);
	Money bill;
	bill = papers + coffee + sugar;
	std::cout << "Total : " << bill << std::endl;
}

