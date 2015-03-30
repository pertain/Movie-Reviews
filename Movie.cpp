//  Movie.cpp
//
//  Stores Movie objects
//  Written by: William Ersing
//  October 15, 2013


#include "Movie.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


//Parameterized constructor for Movie
Movie::Movie(string name, int year){
    title = name;
    releaseYear = year;
    movieID = -1;
    cr1 = -1.0;
  cr2 = -1.0;
  cr3 = -1.0;
  ur = -1.0;
}

void Movie::setTitle(Movie &mv, string newTitle){
    mv.title = newTitle;
}

void Movie::setYear(Movie &mv, int newYear){
    mv.releaseYear = newYear;
}

void Movie::setID(Movie &mv, int newID){
    mv.movieID = newID;
}

void Movie::setReview(Movie &mv, int whichReview, float rating){
    switch(whichReview){
        case 1:     mv.cr1 = rating;
                            break;
        case 2:     mv.cr2 = rating;
                            break;
        case 3:     mv.cr3 = rating;
                            break;
        case 4:     mv.ur = rating;
                            break;
        default:    break;
    }
}

const string Movie::getTitle() const{
    return title;
}

const int Movie::getYear() const{
    return releaseYear;
}

const int Movie::getID() const{
    return movieID;
}

const float Movie::getReview(int whichReview) const{
    switch(whichReview){
        case 1:     return cr1;
                            break;
        case 2:     return cr2;
                            break;
        case 3:     return cr3;
                            break;
        case 4:     return ur;
                            break;
        default:    return -1.0;
                            break;
    }
}

float Movie::compareToCritic(int critic){
    float diffSquared = pow(abs(getReview(critic) - getReview(4)), 2);
    return diffSquared;
}

// Overload Output stream
ostream &operator<<(ostream &out, Movie &mv){
    out << setw(2) << fixed << setprecision(1);
    return out << "\nID:    " << mv.movieID << "\nTitle: " << mv.title << "\nYear:  " << mv.releaseYear
                         << "\n__________________________________________________________________________"
                         << "\n\tReviews based on a 0-4 scale (0 is terrible, 4 is terrific)"
                         << "\n__________________________________________________________________________"
                         << "\n     Metacritic\t    Rotten Tomatoes\t VideoHound\t  User Rating"
                         << "\n\t" << mv.cr1 << "\t\t  " << mv.cr2 << "\t\t    " << mv.cr3 << "\t\t     " << mv.ur << "\n\n" << endl;
}
