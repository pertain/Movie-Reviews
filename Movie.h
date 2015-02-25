//  Movie.h
//
//  Header file for Movie.cpp, MovieList.cpp, MovieReviews.cpp
//  Written by: William Ersing
//	October 15, 2013


//	Movie stores a movie and reviews
//	arranged by:
//	title, releaseYear movieID, cr1, cr2, cr3, ur
//
// 	Movie class has the following methods
//
//-----------------------------------------------------------------------------------
//
//	Movie(string, int)
//
//	Parameters:			title,string, represents the movie name, passed by value
//									releaseYear, int, represents the movie release year, passed by value
//	Post-condition: the parameterized constructor allows the programmer to instantiate
//									Movie objects
//	
//-----------------------------------------------------------------------------------
//
//	setTitle(Movie, string)
//
//	Parameters:			mv, Movie, represents a Movie object, passed by reference
//									newTitle, string, represents the name to be set, passed by value
//	Post-condition: sets the Movie title
//	
//-----------------------------------------------------------------------------------
//
//	setYear(Movie, int)
//
//	Parameters:			mv, Movie, represents a Movie object, passed by reference
//									newYear, int,
//	Post-condition: sets the Movie release year
//	
//-----------------------------------------------------------------------------------
//
//	setID(Movie, int)
//
//	Parameters:			mv, Movie, represents a Movie object, passed by reference
//									newID, int,
//	Post-condition: sets the Movie ID number
//	
//-----------------------------------------------------------------------------------
//
//	setReview(Movie, int, float)
//
//	Parameters:			mv, Movie, represents a Movie object, passed by reference
//									whichReview, int,
//									rating, float,
//	Post-condition: sets the Movie review for the chosen critic/user
//	
//-----------------------------------------------------------------------------------
//
//	getTitle()
//
//	Parameters:			
//	Post-condition: returns the Movie title as a string
//	
//-----------------------------------------------------------------------------------
//
//	getYear()
//
//	Parameters:			
//	Post-condition: returns the Movie release year as an int
//	
//-----------------------------------------------------------------------------------
//
//	getID()
//
//	Parameters:			
//	Post-condition: returns the Movie ID number as an int
//	
//-----------------------------------------------------------------------------------
//
//	getReview(int)
//
//	Parameters:			whichReview, int,
//	Post-condition: returns the chosen Movie review as a float
//	
//-----------------------------------------------------------------------------------
//
//	compareToCritic(int)
//
//	Parameters:			critic, int,
//	Post-condition: calculates the square of the difference between user review and the chosen critic review
//									returns the value as a float
//	
//-----------------------------------------------------------------------------------


// 	Movie class also has the following friend methods
//
//-----------------------------------------------------------------------------------
//	operator<<(ostream, Movie)
//
//	Parameters:			out, ostream, represents an output stream, passed by reference
//									mv, Movie, represents a Movie object, passed by reference
//	Post-condition: overloads output stream and prints Movie objects to screen
//	
//-----------------------------------------------------------------------------------




//	MovieList stores an array of Movie objects
//	the array has a fixed size of 1900
//
// 	MovieList class has the following methods
//
//-----------------------------------------------------------------------------------
//
//	MovieList()
//
//	Parameters:			
//	Post-condition: allows the programmer to instantiate a MovieList object
//	
//-----------------------------------------------------------------------------------
//
//	getMovie(Movie, int)
//
//	Parameters:			mv, Movie, represents a Movie object, passed by reference
//									index, int, represents the index of the MovieList array where the Movie is located, passed by value
//	Post-condition: returns the chosen Movie object
//	
//-----------------------------------------------------------------------------------
//
//	getMaxMovies()
//
//	Parameters:			
//	Post-condition: returns the maximum number of Movies the MovieList array can hold as an int
//	
//-----------------------------------------------------------------------------------
//
//	getMovieCount()
//
//	Parameters:			
//	Post-condition: returns the current quantity of Movies in the MovieList array as an int
//	
//-----------------------------------------------------------------------------------
//
//	getReviewCount()
//
//	Parameters:			
//	Post-condition: returns the current quantity of user reviews in the MovieList array as an int
//	
//-----------------------------------------------------------------------------------
//
//	findMovie(MovieList, string)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//									nm, string, represents the Movie title, passed by value
//	Post-condition: searched the MovieList array for a Movie whose title matches the string input
//									returns the index in the MovieList array where the matching Movie is located
//									returns value as an int
//	
//-----------------------------------------------------------------------------------
//
//	incReviewCount(MovieList)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//	Post-condition: increments the user review count
//	
//-----------------------------------------------------------------------------------
//
//	readFile(MovieList)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//	Post-condition: reads in a csv file and stores data in the appropriate Movie variables
//									populates the MovieList array with Movie objects
//	
//-----------------------------------------------------------------------------------
//
//	writeFile(MovieList)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//	Post-condition: writes contents of the MovieList array to a file with .csv formatting
//	
//-----------------------------------------------------------------------------------
//
//	addMovie(MovieList, string, int)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//									name, string, represents the name of the Movie, passed by value
//									year, int, represents the release year of the Movie, passed by value
//	Post-condition: adds a Movie to the MovieList array
//	
//-----------------------------------------------------------------------------------
//
//	updateMovie(MovieList, Movie, int)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//									mv, Movie, represents a Movie object, passed by reference
//									i, int, represents the index in MovieList array were Movie is located, passed by value
//	Post-condition: updates the changes to a Movie in MovieList
//	
//-----------------------------------------------------------------------------------
//
//	recommendMovies(MovieList, int)
//
//	Parameters:			ml, MovieList, represents a MovieList object, passed by reference
//									whichCrit, int, represents a specific critic, passed by value
//	Post-condition: prints a list of movie recommendations on the screen
//									recommendations are based on results from distCalc()
//	
//-----------------------------------------------------------------------------------
//
//	distCalc()
//
//	Parameters:			
//	Post-condition: calculates the distance from user reviews to each other critic
//									calculations are based on results from Movie member function compareToCritic()
//									returns an int that indicates which critic is closest to the user's reviews
//	
//-----------------------------------------------------------------------------------


#include <iostream>
using namespace std;


class Movie{

private:
  string title;
  int releaseYear, movieID;
  float cr1, cr2, cr3, ur;

public:
	Movie(string = "", int year = -1);
	void setTitle(Movie &, string);
	void setYear(Movie &, int);
	void setID(Movie &, int);
	void setReview(Movie &, int, float);
  const string getTitle() const;
  const int getYear() const;
  const int getID() const;
  const float getReview(int) const;
  float compareToCritic(int);
  friend ostream &operator<<(ostream &, Movie &);
};

class MovieList{

private:
		static const int maxMovies = 1900;
		int movieCount;
		int userReviewCount;
		int nextID;
		Movie movieArray[maxMovies];

public:
		MovieList();
		const Movie getMovie(Movie &, int) const;
		const int getMaxMovies() const;
		const int getMovieCount() const;
		const int getReviewCount() const;
		const int findMovie(const MovieList &, string) const;
		void incReviewCount(MovieList &);
		void readFile(MovieList &);
		void writeFile(MovieList &);
		void addMovie(MovieList &, string, int);
		void updateMovie(MovieList &, Movie &, int);
		void recommendMovies(MovieList &, int);
		int distCalc();
};
