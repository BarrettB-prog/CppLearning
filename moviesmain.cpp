/***************************************************************************************************************************

Name: Barrett Bobilin
Assignment: Movies
Due Date: 4/25/2024
About this project: loads movie files and sorts them
Assumptions: movie files are in the correct format , no trailing whitespace in the file , assume the file will at least contain one movie

All work below was performed by Barrett Bobilin


***************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// movies struct
struct Movies 
{
    string genre;
    string title;
    int year;
    int runtime;
    string rating; 
};


void Menu();
void loadMovieFile(Movies * & movieArr, int & size);
void viewTotalMovieDatabaseRuntime(Movies * movieArr, int size);
void viewMoviesByRating(Movies * movieArr, int size);
void exportMoviesByGenre(Movies * movieArr, int size);
void clearCurrentlyLoadedDatabase(Movies * & movieArr);

int main() {
    Movies * movieArr = NULL; // pointer to dynamic array
    int size = 0; // size of the array

    char selection;
    
    do {
        Menu();
        
        cin >> selection;

        if (selection == 'Q' || selection == 'q')
        {
            cout << "\nThanks for using the Movie Database Organizer!\n\n";
            break;
        } 
        else if (selection == '1') 
        {
            loadMovieFile(movieArr, size);
        } 
        else if (selection == '2')
        {
            viewTotalMovieDatabaseRuntime(movieArr, size);
        } 
        else if (selection == '3') 
        {
             viewMoviesByRating(movieArr, size);
        } 
        else if (selection == '4')
        {
            exportMoviesByGenre(movieArr, size);
        } 
        else if (selection == '5')
        {
            clearCurrentlyLoadedDatabase(movieArr);
        }
        else 
        {
            cout << "Invalid input, try again.\n";
        }
    } while (selection != 'Q' && selection != 'q');

    
    delete[] movieArr;
    return 0;
}

void Menu()
{
    cout << "\n";
    cout << "1 - Load Movie File" << endl;
    cout << "2 - View Total Movie Database Runtime" << endl;
    cout << "3 - View Movies by Rating" << endl;
    cout << "4 - Export Movies by Genre" << endl;
    cout << "5 - Clear Currently Loaded Database" << endl;
    cout << "Q - Quit" << endl;
    cout << "Selection > ";
}

void loadMovieFile(Movies * & movieArr, int & size)
{
    if (movieArr != 0)
    {
        char response;
        cout << "There is a database already loaded. This will overwrite the current database." << endl;
        cout << "Continue? (y/n) > ";
        cin >> response;
        if (response != 'y' && response != 'Y') 
        {
            cout << "Operation aborted." << endl;
            return;
        }
        clearCurrentlyLoadedDatabase(movieArr);
    }

    string filename;
    ifstream inputFile;
    do {
        cout << "Enter the name of the movie input file: ";
        cin >> filename;
        inputFile.open(filename);
        if (!inputFile) 
        {
            cout << "Error opening file. Please try again." << endl;
        }
    } while (!inputFile);

    inputFile >> size; 
    movieArr = new Movies[size]; 

    // Read movie data from file
    for (int i = 0; i < size; ++i)
    {
        inputFile >> movieArr[i].genre;
        inputFile.ignore();                                 // ignore colon 
        getline(inputFile, movieArr[i].title, ',');
        inputFile >> movieArr[i].year >> movieArr[i].runtime >> movieArr[i].rating;
    }

    inputFile.close();
    cout << "File loaded successfully." << endl;
}


void viewTotalMovieDatabaseRuntime(Movies* movieArr, int size) 
{
    if (size == 0)
    {
        cout << "Load movie file first! Use option 1.\n";
        return;
    }

    int total_minutes = 0;
    for (int i = 0; i < size; i++) 
    {
        total_minutes += movieArr[i].runtime;
    }

    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;

    cout << "Total Movie Database Runtime: " << hours << " hrs " << minutes << " mins" << endl;
}

void viewMoviesByRating(Movies * movieArr, int size)
{
    if (size == 0)
    {
        cout << "Load movie file first! Use option 1.\n";
        return;
    }

    string rating;
    cout << "View movies with which rating? (G, PG, PG-13, R) > ";
    cin >> rating;

    bool found = false;
    for (int i = 0; i < size; i++) 
    {
        if (movieArr[i].rating == rating)
        {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No movies with rating " << rating << endl;
        return;
    }

    cout << "\nMOVIES RATED " << rating << endl;
    for (int i = 0; i < size; i++) 
    {
        if (movieArr[i].rating == rating)
        {
            
            size_t found = movieArr[i].title.find(':');
            if (found != string::npos) // I looked this one up and it still didnt work.
            {
                cout << movieArr[i].title.substr(found + 1) << endl; 
            }
            else 
            {
                 
                cout << movieArr[i].title << endl;
            }
        }
    }
}



void exportMoviesByGenre(Movies * movieArr, int size)
{
    if (size == 0) 
    {
        cout << "Load movie file first! Use option 1." << endl;
        return;
    }

    string genres[] = {"ACTION", "DRAMA", "COMEDY", "SCIENCE FICTION"};

    // create and open files for each genre
    ofstream actionFile("action.txt");
    ofstream dramaFile("drama.txt");
    ofstream comedyFile("comedy.txt");
    ofstream scifiFile("scifi.txt");

    // check if files are opened successfully
    if (!actionFile || !dramaFile || !comedyFile || !scifiFile) 
    {
        cout << "Error creating output files." << endl;
        return;
    }

    // loop through movie array and write to appropriate genre files 
    // couldnt get it to write, still dont know why. if you can tell me why in the comments on canvas that would be great, this bothered me
    for (int i = 0; i < size; ++i) 
    {
        ofstream * currentFile = nullptr;
        if (movieArr[i].genre == "ACTION")
        {
            currentFile = & actionFile;
        } 
        else if (movieArr[i].genre == "DRAMA")
        {
            currentFile = & dramaFile;
        } 
        else if (movieArr[i].genre == "COMEDY") 
        {
            currentFile = & comedyFile;
        } 
        else if (movieArr[i].genre == "SCIENCE FICTION")
        {
            currentFile = & scifiFile;
        }

        
        if (currentFile != NULL) {
            * currentFile << movieArr[i].title << " (" << movieArr[i].year << ")" << endl;
        }
    }

    // Close all files
    actionFile.close();
    dramaFile.close();
    comedyFile.close();
    scifiFile.close();

    cout << "Movies exported successfully." << endl;
}

// Function to clear currently loaded database
void clearCurrentlyLoadedDatabase(Movies * & movieArr) 
{
    delete[] movieArr;
    movieArr = 0;
    cout << "Movie database cleared." << endl;
}
