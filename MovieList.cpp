//  MovieList.cpp
//
//  Stores an array of Movie objects
//  Written by: William Ersing
//  October 15, 2013


#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;


//Constructor for MovieList
MovieList::MovieList(){
    movieCount = 0;
    userReviewCount = 0;
    nextID = 0;
    movieArray[maxMovies];
}

const Movie MovieList::getMovie(Movie &mv, int index) const{
    return movieArray[index];
}

const int MovieList::getMaxMovies() const{
    return maxMovies;
}

const int MovieList::getMovieCount() const{
    return movieCount;
}

const int MovieList::getReviewCount() const{
    return userReviewCount;
}

const int MovieList::findMovie(const MovieList &ml, string nm) const{
    string name = nm;
    string str2;
    
    for(int i = 0; i < movieCount; i++){
        str2 = ml.movieArray[i].getTitle().substr(0, nm.length());
        if(nm == ml.movieArray[i].getTitle() || nm == str2){
            return i;
        }
    }
    return -1;
}

void MovieList::incReviewCount(MovieList &ml){
    ml.userReviewCount++;
}

void MovieList::readFile(MovieList &ml){    
    string line, row, name, inFileName;
    ifstream rowChk, inStr;
    stringstream ss;
    int id, year, attributes;
    int rowIndex = 0;
    float rev1, rev2, rev3, rev4;
    
    cout << "\nEnter the name of the .csv file" << endl;
    cout << "(example: movies.csv)" << endl;
    cout << "Name: ";
    cin >> inFileName;
    
    if(inFileName == "movies.csv"){
        attributes = 6;
    }
    else{
        attributes = 7;
    }
    rowChk.open(inFileName.c_str());        //Read file to determine movieCount
    if(rowChk.is_open()){
        for(int i =0; i < 3; i++){          //Skip first three lines (no movies on these lines)
            rowChk.ignore(100, '\r');
        }
        while(getline(rowChk, row, '\r')){  //Count movies in the file
            ml.movieCount++;
        }
        rowChk.close();
    }
    else{
        cout << "Unable to open file \"" << inFileName << "\"";
    }
  inStr.open(inFileName.c_str());           //Populate movieArray with Movie objects
  if(inStr.is_open()){
        for(int i = 0; i < 3; i++){         //Skip first three lines (no movies on these lines)
            inStr.ignore(100, '\r');
        }
        
        //Read in each csv (each line is a movie) and populate MovieList array with Movies
        while(rowIndex < movieCount){       
            for(int i = 0; i < attributes; i++){
                if(i < 5){
                    getline(inStr, line, ',');
                }
                ss.clear();
                switch(i){
                    case 0:
                        ss << line;
                        ss >> id;
                        movieArray[rowIndex].setID(movieArray[rowIndex], id);
                        if(id > ml.nextID){
                            ml.nextID = id + 1;
                        }
                        break;

                    case 1:
                        name = line;
                        movieArray[rowIndex].setTitle(movieArray[rowIndex], name);
                        break;

                    case 2:
                        ss << line;
                        ss >> year;
                        movieArray[rowIndex].setYear(movieArray[rowIndex], year);
                        break;

                    case 3:
                        ss << line;
                        ss >> rev1;
                        movieArray[rowIndex].setReview(movieArray[rowIndex], 1, rev1);
                        break;

                    case 4:
                        ss << line;
                        ss >> rev2;
                        movieArray[rowIndex].setReview(movieArray[rowIndex], 2, rev2);
                        break;

                    case 5:
                        if(inFileName == "movies.csv"){
                            getline(inStr, line, '\r');
                        }
                        else{
                            getline(inStr, line, ',');
                        }
                        ss << line;
                        ss >> rev3;
                        movieArray[rowIndex].setReview(movieArray[rowIndex], 3, rev3);
                        break;

                    case 6:
                        getline(inStr, line, '\r');
                        ss << line;
                        ss >> rev4;
                        if(rev4 != -1){
                            ml.userReviewCount++;
                        }
                        movieArray[rowIndex].setReview(movieArray[rowIndex], 4, rev4);
                        break;

                }
            }
            rowIndex++;
        }
    inStr.close();
  }
  else{
        cout << "Unable to open file \"" << inFileName << "\"";
    }
}

void MovieList::writeFile(MovieList &ml){
    string outFileName;
    ofstream outStr;
    
    cout << "\nEnter a name for the output file" << endl;
    cout << "(do not use \"movies.csv\", or your personal reviews will be lost)" << endl;
    cout << "Name: ";
    cin >> outFileName;
    
    outStr.open(outFileName.c_str());
  if(outStr.is_open()){
        outStr << "Critic Ratings for years 2000 to 2009 processed,,,,,\r,,,,,\rFilm ID,Film Title,Year (NA),Metacritic,Rotten Tomatoes/4,VideoHound Score (0-4)\r";
        for(int i = 0; i < ml.movieCount; i++){
            outStr  << ml.movieArray[i].getID()         << ","
                    << ml.movieArray[i].getTitle()      << ","
                    << ml.movieArray[i].getYear()       << ","
                    << ml.movieArray[i].getReview(1)    << ","
                    << ml.movieArray[i].getReview(2)    << ","
                    << ml.movieArray[i].getReview(3)    << ","
                    << ml.movieArray[i].getReview(4)    << "\r";
        }
    }
    else{
        cout << "Unable to open file \"" << outFileName << "\"";
    }
}

void MovieList::addMovie(MovieList &ml, string name, int year){
    if(ml.movieCount < ml.maxMovies){
        if(findMovie(ml, name) == -1){
            Movie mv = Movie(name, year);
            mv.setID(mv, ml.nextID);
            ml.nextID++;
            updateMovie(ml, mv, ml.movieCount);
            cout << "\n\"" << name << "\" was added to the movie list\n" << endl;
            ml.movieCount++;
        }
        else{
            cout << "\n\"" << name << "\" was not added. It is already in the movie list\n" << endl;
        }
    }
    else{
        cout << "\nThe movie list is full. New movies cannot be added." << endl;
    }
}

void MovieList::updateMovie(MovieList &ml, Movie &mv, int i){
    ml.movieArray[i] = mv;
}

void MovieList::recommendMovies(MovieList &ml, int whichCrit){
    int crit = whichCrit;
    string critic;
    Movie mov;
    switch(whichCrit){
        case 1:
            critic = "Metacritic";
            break;
        case 2:
            critic = "Rotten Tomatoes";
            break;
        case 3:
            critic = "VideoHound";
            break;
        default:
            break;
    }
    cout << "\nYour reviews are closest to \"" << critic << "\"" << endl;
    cout << "The following is your list of recommended movies" << endl;
    cout << "along with the review scores from " << critic << "\n\n" << endl;
    cout << "  [Score] \t[Movie Title]" << endl;
    cout << "_______________________________________________________\n" << endl;
    for(int i = 0; i < movieCount; i++){
        mov = ml.movieArray[i];
        if(mov.getReview(crit) >= 3){
            cout << "    ";
            cout << setw(2) << fixed << setprecision(1) << mov.getReview(crit);
            cout << " \t" << mov.getTitle() << endl;
        }
    }
}

int MovieList::distCalc(){
    float sum1, sum2, sum3, dist1, dist2, dist3, nearestCrit;
    
    for(int i = 0; i < movieCount; i++){
        if(movieArray[i].getReview(4) != -1){
            sum1 += movieArray[i].compareToCritic(1);
            sum2 += movieArray[i].compareToCritic(2);
            sum3 += movieArray[i].compareToCritic(3);
        }
    }
    dist1 = sqrt(sum1);
    dist2 = sqrt(sum2);
    dist3 = sqrt(sum3);
    nearestCrit = min(min(dist1, dist2), dist3);
    if(nearestCrit == dist1) return 1;
    else if(nearestCrit == dist2) return 2;
    else if(nearestCrit == dist3) return 3;
}
