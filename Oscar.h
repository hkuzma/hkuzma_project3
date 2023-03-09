//
// Created by Henry Kuzma on 1/27/2023.
//

#ifndef PROJECT1_OSCAR_H
#define PROJECT1_OSCAR_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl, std::ifstream, std::left, std::ostream;
using std::right, std::setw, std::string, std::vector;

class Oscar {
private:
    int row;
    int year_release;
    int ceremony;
    string category;
    string name;
    string film;
    string winner;
public:
    //constructor
    Oscar(){
        row = 0;
        year_release = 0;
        ceremony = 0;
        category = "-1";
        name = "-1";
        film = "-1";
        winner = "-1";
    }
    Oscar(int row, int year, int ceremony, string category, string name, string film, string winner) {

        //set variable values

        this->row = row;
        year_release = year;
        this->ceremony = ceremony;
        this->category = category;
        this->name = name;
        this->film = film;
        this->winner = winner;

    }

    //getters
    int getRow() const {
        return row;
    }

    int getYear() const {
        return year_release;
    }

    int getCeremony() const {
        return ceremony;
    }

    string getCategory() const {
        return category;
    }

    string getName() const {
        return name;
    }

    string getFilm() const {
        return film;
    }

    string getWinner() const {
        return winner;
    }

    //setters
    void setRow(int row) {
        this->row = row;
    }

    void setYear(int year) {
        year_release = year;
    }

    void setCeremony(int ceremony) {
        this->ceremony = ceremony;
    }

    void setCategory(string category) {
        this->category = category;
    }

    void setFilm(string film) {
        this->film = film;
    }

    void setWinner(string winner) {
        this->winner = winner;
    }


    //overload operators

    //print an oscar object
    friend std::ostream& operator << (std::ostream& outs, const Oscar& kObj) {
        outs << std::fixed
             << std::right
             << std::setprecision(4)
             << std::setw(5) << kObj.getRow()
             << std::setw(7) << kObj.getYear()
             << std::left
             << "  "
             << std::setw(7) << kObj.getCeremony()
             << std::setw(22) << kObj.getCategory()
             << std::setw(26) << kObj.getName()
             << std::right
             << std::setw(18) << kObj.getFilm()
             << std::setw(10) << kObj.getWinner();
        return outs;
    }
    //<
    //overload <
    //allows you to check if an oscar is less than another
    friend bool operator < (const Oscar& lhs, const Oscar& rhs) {
        return lhs.getRow() < rhs.getRow();
    }
    //overload >
    friend bool operator > (const Oscar& lhs, const Oscar& rhs) {
        return lhs.getRow() > rhs.getRow();
    }
    friend bool operator <= (const Oscar& lhs, const Oscar& rhs) {
        return lhs.getRow() <= rhs.getRow();
    }
    friend bool operator >= (const Oscar& lhs, const Oscar& rhs) {
        return lhs.getRow() >= rhs.getRow();
    }
    friend bool operator == (const Oscar& lhs, const Oscar& rhs) {
        return lhs.getRow() == rhs.getRow();
    }
    friend bool operator != (const Oscar& lhs, const Oscar& rhs) {
        return lhs.getRow() != rhs.getRow();
    }

};

void getDataFromFile(string filename, vector<Oscar>& oscars){
    //create file
    ifstream inFile;
    //open file
    inFile.open(filename);

    //variables to read into
    string header = "", headerStorage;
    int year_release = -1, ceremony = -1 , intjunk = -1, row =-1;
    string category = "", name = "", film = "", winner = "", junk = "";
    char comma, quote;

    //check file is good to read
    if (inFile) {
        //get header
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, junk, ',');
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, ',');
        header += headerStorage + " ";
        getline(inFile, headerStorage, '\n');
        header += headerStorage + " ";
    }

    //while file can be read from and not at end of file
    while(inFile && inFile.peek() != EOF){

        //row
        if (inFile.peek() == '"') {
            inFile >> quote;
            inFile >> row >> comma;
        }else{
            inFile >> row >> comma;
        }

        //year_release
        inFile >> year_release >> comma;

        //don't take ceremony year
        inFile >> intjunk >> comma;

        //ceremony
        inFile >> ceremony >> comma;

        //category
        getline(inFile, category, ',');

        //name
        if(inFile.peek() == '"'){
            inFile >> quote;
            getline(inFile, name, '"');
            inFile >> comma;
        }
        else {
            getline(inFile, name, ',');
        }

        //film
        getline(inFile, film, ',');

        //winner
        getline(inFile, winner, '\n');
        //create oscar object and place into vector
        oscars.push_back(Oscar(row, year_release, ceremony, category, name, film, winner));
    }

    //CLOSE FILE
    inFile.close();
}




#endif //PROJECT1_OSCAR_H
