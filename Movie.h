//  Movie.h
//
//  Header file for Movie.cpp
//  Written by: William Ersing
//  October 15, 2013
//
//
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
//
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

#ifndef MOVIE_H

#include <iostream>

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

  friend std::ostream &operator<<(std::ostream &, Movie &);
};

#endif
