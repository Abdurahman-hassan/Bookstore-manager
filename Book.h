#ifndef BOOK_HEADER_H
#define BOOK_HEADER_H

#include <iostream>
#include "LinkedListUtils.h"
using namespace std;
using std::string;

const int MAX_CATEGORIES = 20;

class BookData {
public:
	string name;
	string category;
	float price;
	string author;
	bool isReserved;
	string reservedBy;
	string reviews;
	float ratings = 0.0f;
	int ratingCount = 0;
};

class Book
{
public:
	Book();
	Book(string&, string&);
	~Book();
	void initializeBookCollection();
	void insert(const string&name, const string&category, const float&price, const string&author, bool isReserved, const string&reservedBy, const string&reviews, float rating, int ratingCount);
	void update(const string&, const string&, const float&, const string&, bool, const string&, const string&, float, int);
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
	void reserveBook(int bookNumber);
	void reserveBook(BookData &data);
	bool serach(int&);
	bool serach(const string&);
	int size();
	void printAll();
	void promptForBookAction();
	void myReservation();
	void printData(const BookData& data);
	void saveToCSV(const string& filename);
	void loadFromCSV(const string& filename);
	void logout();
	void reloadBookCollection();
	void advancedSearch();
	void generateReports();

	// void rateAndReviewBooks();
	// void displayBookRatingAndReviews(int bookKey);
	// void addReview(int bookKey);
	// void addRating(int bookKey);
	// void displayReviews(int bookKey);
	// void displayRatings(int bookKey);

private:
	LinkedListUtils<BookData> book_node;
	string username;
	string visitorName;

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