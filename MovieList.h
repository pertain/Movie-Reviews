//  MovieList.h
//
//  Header file for MovieList.cpp
//  Written by: William Ersing
//  October 15, 2013
//
//
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

#ifndef MOVIELIST_H

class MovieList{

private:
    static const int MAX_MOVIES = 1900;
    int movieCount;
    int userReviewCount;
    int nextID;
    Movie movieArray[MAX_MOVIES];

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

#endif
