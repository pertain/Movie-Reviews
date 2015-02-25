//  MovieReviews.cpp
//
//  Driver program for Movie.cpp and MovieList.cpp
//  Written by: William Ersing
//	October 15, 2013


#include "Movie.h"
#include <iostream>
using namespace std;


int main(void){
	Movie mov;
	MovieList ml;
	ml.readFile(ml);
	int maxMov = ml.getMaxMovies();
	int count = ml.getMovieCount();
	int relYear, nearCrit;
	float userRev;
	string movieName;
	int movIndex;
	int userChoice = 0;

	//	User interface
	cout << "\n\nWelcome to MovieReview!" << endl;
	while(userChoice != 6){
		cout << "\n\nPlease select an option\n" << endl;
		cout << "1. Get reviews for a movie" << endl;
		cout << "2. Review a movie" << endl;
		cout << "3. Add a movie" << endl;
		cout << "4. Get movie recommendations" << endl;
		cout << "5. Print movie review file" << endl;
		cout << "6. Quit\n" << endl;
		cout << "Selection: ";
		int tempIn = 0;
		cin >> tempIn;
		if(!cin){
			cin.clear();
			cin.ignore();
			cout << "\nNot a valid selection\n" << endl;
		}
		else{
			userChoice = tempIn;
		}
		switch(userChoice){
			case 1:
				while(getline(cin, movieName) && userChoice == 1){
					cout << "\nEnter a movie name (Capitalize first letter of each word)" << endl;
					cout << "Title: ";
					getline(cin, movieName);
					movIndex = ml.findMovie(ml, movieName);
					if(movIndex != -1){
						mov = ml.getMovie(mov, movIndex);
						cout << "\n" << mov;
					}
					else{
						cout << movieName << " is not a valid selection" << endl;
					}
					userChoice = 0;
					cout << "\nPress \"ENTER\" to continue" << endl;
				}
				break;
			case 2:
				while(getline(cin, movieName) && userChoice == 2){
					cout << "\nEnter a movie name (Capitalize first letter of each word)" << endl;
					cout << "Title: ";
					getline(cin, movieName);
					movIndex = ml.findMovie(ml, movieName);
					if(movIndex != -1){
						mov = ml.getMovie(mov, movIndex);
						cout << "\nEnter your review (low 0-4 high): ";
						cin >> userRev;
						mov.setReview(mov, 4, userRev);
						ml.updateMovie(ml, mov, movIndex);
						ml.incReviewCount(ml);
						cout << "\n" << mov;
					}
					else{
						cout << "\n" << movieName << " is not a valid selection" << endl;
						cout << "\nPress \"ENTER\" to continue" << endl;
					}
					userChoice = 0;
				}
				break;
			case 3:
				while(getline(cin, movieName) && userChoice == 3){
					cout << "\nEnter a movie name (Capitalize first letter of each word)" << endl;
					cout << "Title: ";
					getline(cin, movieName);
					cout << "\nWhat year was \"" << movieName << "\" released? " << endl;
					cout << "Year: ";
					cin >> relYear;
					ml.addMovie(ml, movieName, relYear);	
					userChoice = 0;
				}
				break;
			case 4:
					if(ml.getReviewCount() > 4){
						nearCrit = ml.distCalc();
						ml.recommendMovies(ml, nearCrit);
					}
					else{
						cout << "\nYou must add at least 5 reviews to calculate movie recommendations." << endl;
						cout << "Current review count: " << ml.getReviewCount() << endl;
					}
				break;
			case 5:
				ml.writeFile(ml);
				break;
			case 6:
				cout << "\nGoodbye!\n" << endl;
			default:
				break;
		}
	}
}
