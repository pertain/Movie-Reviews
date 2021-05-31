//  MovieReviews.cpp
//
//  Driver program for Movie.cpp and MovieList.cpp
//  Written by: William Ersing
//  October 15, 2013


#include "Movie.h"
#include "MovieList.h"


int main(void){
    Movie mov;
    MovieList ml;
    ml.readFile(ml);
    int relYear, nearCrit;
    float userRev;
    std::string movieName;
    int movIndex;
    int userChoice = 0;

    //  User interface
    std::cout << "\n\nWelcome to MovieReview!" << std::endl;
    while(userChoice != 6){
        std::cout << "\n\nPlease select an option\n" << std::endl;
        std::cout << "1. Get reviews for a movie" << std::endl;
        std::cout << "2. Review a movie" << std::endl;
        std::cout << "3. Add a movie" << std::endl;
        std::cout << "4. Get movie recommendations" << std::endl;
        std::cout << "5. Print movie review file" << std::endl;
        std::cout << "6. Quit\n" << std::endl;
        std::cout << "Selection: ";
        int tempIn = 0;
        std::cin >> tempIn;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "\nNot a valid selection\n" << std::endl;
        }
        else{
            userChoice = tempIn;
        }
        switch(userChoice){
            case 1:
                while(getline(std::cin, movieName) && userChoice == 1){
                    std::cout << "\nEnter a movie name (Capitalize first letter of each word)" << std::endl;
                    std::cout << "Title: ";
                    getline(std::cin, movieName);
                    movIndex = ml.findMovie(ml, movieName);
                    if(movIndex != -1){
                        mov = ml.getMovie(mov, movIndex);
                        std::cout << "\n" << mov;
                    }
                    else{
                        std::cout << movieName << " is not a valid selection" << std::endl;
                    }
                    userChoice = 0;
                    std::cout << "\nPress \"ENTER\" to continue" << std::endl;
                }
                break;
            case 2:
                while(getline(std::cin, movieName) && userChoice == 2){
                    std::cout << "\nEnter a movie name (Capitalize first letter of each word)" << std::endl;
                    std::cout << "Title: ";
                    getline(std::cin, movieName);
                    movIndex = ml.findMovie(ml, movieName);
                    if(movIndex != -1){
                        mov = ml.getMovie(mov, movIndex);
                        std::cout << "\nEnter your review (low 0-4 high): ";
                        std::cin >> userRev;
                        mov.setReview(mov, 4, userRev);
                        ml.updateMovie(ml, mov, movIndex);
                        ml.incReviewCount(ml);
                        std::cout << "\n" << mov;
                    }
                    else{
                        std::cout << "\n" << movieName << " is not a valid selection" << std::endl;
                        std::cout << "\nPress \"ENTER\" to continue" << std::endl;
                    }
                    userChoice = 0;
                }
                break;
            case 3:
                while(getline(std::cin, movieName) && userChoice == 3){
                    std::cout << "\nEnter a movie name (Capitalize first letter of each word)" << std::endl;
                    std::cout << "Title: ";
                    getline(std::cin, movieName);
                    std::cout << "\nWhat year was \"" << movieName << "\" released? " << std::endl;
                    std::cout << "Year: ";
                    std::cin >> relYear;
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
                        std::cout << "\nYou must add at least 5 reviews to calculate movie recommendations." << std::endl;
                        std::cout << "Current review count: " << ml.getReviewCount() << std::endl;
                    }
                break;
            case 5:
                ml.writeFile(ml);
                break;
            case 6:
                std::cout << "\nGoodbye!\n" << std::endl;
            default:
                break;
        }
    }
}
