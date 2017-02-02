//  Movie.h
//
//  Header file for Movie.cpp, MovieList.cpp, MovieReviews.cpp
//  Written by: William Ersing
//  October 15, 2013


//  Movie stores a movie and reviews
//  arranged by:
//  title, releaseYear movieID, cr1, cr2, cr3, ur
//
//  Movie class has the following methods
//
//-----------------------------------------------------------------------------------
//
//  Movie(string, int)
//
//  Parameters:     title, string:      represents the movie name
//                                      (passed by value)
//                  releaseYear, int:   represents the movie release year
//                                      (passed by value)
//
//  Post-condition: parameterized constructor allows the programmer to instantiate
//                  Movie objects
//  
//-----------------------------------------------------------------------------------
//
//  setTitle(Movie, string)
//
//  Parameters:     mv, Movie:          represents a Movie object
//                                      (passed by reference)
//                  newTitle, string:   represents the name to be set
//                                      (passed by value)
//
//  Post-condition: sets the Movie title
//  
//-----------------------------------------------------------------------------------
//
//  setYear(Movie, int)
//
//  Parameters:     mv, Movie:      represents a Movie object
//                                  (passed by reference)
//                  newYear, int:   represents release year of movie
//                                  (passed by value)
//
//  Post-condition: sets the Movie release year
//  
//-----------------------------------------------------------------------------------
//
//  setID(Movie, int)
//
//  Parameters:     mv, Movie:  represents a Movie object
//                              (passed by reference)
//                  newID, int: represents movie ID number
//                              (passed by value)
//
//  Post-condition: sets the Movie ID number
//  
//-----------------------------------------------------------------------------------
//
//  setReview(Movie, int, float)
//
//  Parameters:     mv, Movie:          represents a Movie object
//                                      (passed by reference)
//                  whichReview, int:   represents a specific reviewer
//                                      (passed by value)
//                  rating, float:      represents rating for movie
//                                      (passed by value)
//
//  Post-condition: sets the Movie review for the chosen critic/user
//  
//-----------------------------------------------------------------------------------
//
//  getTitle()
//
//  Parameters:
//
//  Post-condition: returns the Movie title (string)
//  
//-----------------------------------------------------------------------------------
//
//  getYear()
//
//  Parameters:
//
//  Post-condition: returns the Movie release year (int)
//  
//-----------------------------------------------------------------------------------
//
//  getID()
//
//  Parameters:
//
//  Post-condition: returns the Movie ID number (int)
//  
//-----------------------------------------------------------------------------------
//
//  getReview(int)
//
//  Parameters:     whichReview, int:   represents a specific reviewer
//                                      (passed by value)
//
//  Post-condition: returns the chosen Movie review (float)
//  
//-----------------------------------------------------------------------------------
//
//  compareToCritic(int)
//
//  Parameters:     critic, int:    represents a specific critic
//                                  (passed by value)
//
//  Post-condition: calculates the square of the difference between user review
//                  and the chosen critic review - returns the value (float)
//  
//-----------------------------------------------------------------------------------


//  Movie class also has the following friend methods
//
//-----------------------------------------------------------------------------------
//  operator<<(ostream, Movie)
//
//  Parameters:     out, ostream:   represents an output stream
//                                  (passed by reference)
//                  mv, Movie:      represents a Movie object
//                                  (passed by reference)
//
//  Post-condition: overloads output stream and prints Movie objects to screen
//  
//-----------------------------------------------------------------------------------




//  MovieList stores an array of Movie objects
//  the array has a fixed size of 1900
//
//  MovieList class has the following methods
//
//-----------------------------------------------------------------------------------
//
//  MovieList()
//
//  Parameters:
//
//  Post-condition: allows the programmer to instantiate a MovieList object
//  
//-----------------------------------------------------------------------------------
//
//  getMovie(Movie, int)
//
//  Parameters:     mv, Movie:  represents a Movie object
//                              (passed by reference)
//                  index, int: represents index of Movie in MovieList array
//                              (passed by value)
//
//  Post-condition: returns the chosen Movie object
//  
//-----------------------------------------------------------------------------------
//
//  getMaxMovies()
//
//  Parameters:
//
//  Post-condition: returns maximum size of MovieList array
//  
//-----------------------------------------------------------------------------------
//
//  getMovieCount()
//
//  Parameters:
//
//  Post-condition: returns number (int) of Movies in MovieList array
//  
//-----------------------------------------------------------------------------------
//
//  getReviewCount()
//
//  Parameters:
//
//  Post-condition: returns number (int) of user reviews in MovieList array
//  
//-----------------------------------------------------------------------------------
//
//  findMovie(MovieList, string)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//                  nm, string:     represents the Movie title
//                                  (passed by value)
//
//  Post-condition: search MovieList array for a Movie title
//                  returns index (int) of Movie in MovieList array
//  
//-----------------------------------------------------------------------------------
//
//  incReviewCount(MovieList)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//
//  Post-condition: increments the user review count
//  
//-----------------------------------------------------------------------------------
//
//  readFile(MovieList)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//
//  Post-condition: reads in a csv file and stores data in the appropriate Movie
//                  variables populates the MovieList array with Movie objects
//  
//-----------------------------------------------------------------------------------
//
//  writeFile(MovieList)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//
//  Post-condition: writes contents of the MovieList array to a file
//                  with .csv formatting
//  
//-----------------------------------------------------------------------------------
//
//  addMovie(MovieList, string, int)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//                  name, string:   represents the name of the Movie
//                                  (passed by value)
//                  year, int:      represents the release year of the Movie
//                                  (passed by value)
//
//  Post-condition: adds a Movie to the MovieList array
//  
//-----------------------------------------------------------------------------------
//
//  updateMovie(MovieList, Movie, int)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//                  mv, Movie:      represents a Movie object
//                                  (passed by reference)
//                  i, int:         represents index of Movie in MovieList array
//                                  (passed by value)
//
//  Post-condition: updates the changes to a Movie in MovieList
//  
//-----------------------------------------------------------------------------------
//
//  recommendMovies(MovieList, int)
//
//  Parameters:     ml, MovieList:  represents a MovieList object
//                                  (passed by reference)
//                  whichCrit, int: represents a specific critic
//                                  (passed by value)
//
//  Post-condition: prints a list of movie recommendations on the screen
//                  recommendations are based on results from distCalc()
//  
//-----------------------------------------------------------------------------------
//
//  distCalc()
//
//  Parameters:
//
//  Post-condition: calculates distance between user and critic reviews
//                  calculations based on results from Movie member
//                  function compareToCritic()
//                  returns an int representing the nearest critic to user
//  
//-----------------------------------------------------------------------------------
//
// TO DO:
//  ~ break this into two files
//      1.  Movie.h
//      2.  MovieList.h


#include <iostream>
//using namespace std;


class Movie{

private:
  std::string title;
  int releaseYear, movieID;
  float cr1, cr2, cr3, ur;

public:
  Movie(std::string = "", int year = -1);
  void setTitle(Movie &, std::string);
  void setYear(Movie &, int);
  void setID(Movie &, int);
  void setReview(Movie &, int, float);
  const std::string getTitle() const;
  const int getYear() const;
  const int getID() const;
  const float getReview(int) const;
  float compareToCritic(int);
  //friend ostream &operator<<(ostream &, Movie &);
  friend std::ostream &operator<<(std::ostream &, Movie &);
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
    const int findMovie(const MovieList &, std::string) const;
    void incReviewCount(MovieList &);
    void readFile(MovieList &);
    void writeFile(MovieList &);
    void addMovie(MovieList &, std::string, int);
    void updateMovie(MovieList &, Movie &, int);
    void recommendMovies(MovieList &, int);
    int distCalc();
};
