# MovieReviews

This was an assignment in my Software Engineering course (Fall 2013).

MovieReviews is a program that reads in a list of movies (with 3 different critic reviews for each)
from a .csv file.

The user has the following options:

```
**1. Get reviews for a movie**
**2. Review a movie**
**3. Add a movie**
**4. Get movie recommendations**
**5. Print movie review file**
**6. Quit**
```

The program stores an array of movies and allows the user to add movies to the list, add reviews to
any movie in the list, view any movie in the list, and if enough movies (min 5) have been reviewed
by the user they can ask for a list of movie recommendations. The recommendations are derived by
calculating the distance from the user's reviews to each other critic. The list contains all movies
rated 3 or higher by whichever critic is closest to the user. The user can also print the updated
list of movies to a new file, so user reviews are stored.

