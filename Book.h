#ifndef BOOK_HEADER_H
#define BOOK_HEADER_H

#include <iostream>
#include "LinkedListUtils.h"
#include "BookSold.h"

using namespace std;
using std::string;

const int MAX_CATEGORIES = 20;

class BookData {
public:
	string name;
	string category;
	float price;
	string author;
	int qty;
	string reviews;
	float ratings = 0.0f;
	int ratingCount = 0;
	float total = 0.0f;
};

class Book
{
public:
	Book();
	Book(string&, string&);
	~Book();
	void initializeBookCollection();
	void loadList(const string&name, const string&category, const float&price, const int& qty, const string&author, const string&reviews, float rating, int ratingCount, const float& total);
	void insert(const string&name, const string&category, const float&price, const int& qty, const string&author, const string&reviews, float rating, int ratingCount);
	void update(const string&, const string&, const float&, const string&, int, const string&, float, int);
	void display();
	void displayAdmin();
	void adminSearchBook();
	void addBook();
	void displayUser();
	void userSearchBook();
	void displayDetailsAdmin(BookData&data, int key);
	void editBook(BookData &data, int key);
	void deleteBook(int key);
	void displayDetailsUser(BookData&);
	void soldBook(int bookNumber);
	void soldBook(BookData &data);
	bool serach(int&);
	bool serach(const string&);
	int size();
	void printAll();
	void promptForBookAction();
	void myPurchasesAscending();
	void myPurchasesDescending();
	void printData(const BookData& data);
	void saveToCSV(const string& filename);
	void loadFromCSV(const string& filename);
	void logout();
	void reloadBookCollection();
	void advancedSearch();
	void generateReports();
	void displayDescending();
	void displayAscending();
	void sortDescending(StackUtils<BookData>& stack);
	void sortAscending(QueueUtils<BookData>& queue);

	// void rateAndReviewBooks();
	// void displayBookRatingAndReviews(int bookKey);
	// void addReview(int bookKey);
	// void addRating(int bookKey);
	// void displayReviews(int bookKey);
	// void displayRatings(int bookKey);

private:
	LinkedListUtils<BookData> book_node;
	BookSold sold_node;
	string username;
	string visitorName;
	int defaultQty = 10;

	// ================== Advanced Search Functions ==================
	void searchByAuthor();
	void searchByCategory();
	void searchByPriceRange();

	// ================== Reports Functions ==================
	void reportTotalBooks();
	void reportBooksByCategory();
	void reportReservedBooks();

};

#endif //BOOK_HEADER_H