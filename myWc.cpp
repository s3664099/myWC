#include <iostream>
#include <fstream>
#include <sstream>

#define EXIT_SUCCESS     0

using std::endl;

int countLines(std::ifstream& inFile);
int countCharacters(std::ifstream& inFile);
int countWords(std::ifstream& inFile);

int main(int argc, char** argv)
{

    //converts the command line arguments to strings
    std::string filename = argv[2];
    std::string argument = argv[1];

    //opens the file passed through the the arguments
    std::ifstream inFile;
    inFile.open(filename);

    //Counts the number of lines, characters, and words in a given file
    if(argument=="-l")
       std::cout<<"There are "<<countLines(inFile)<<" lines in the file "<<filename<<endl;
    else if (argument=="-c")
       std::cout<<"The are "<<countCharacters(inFile)<<" characters in the file "<<filename<<endl;
    else if (argument=="-w")
       std::cout<<"The are "<<countWords(inFile)<<" words in the file "<<filename<<endl;
    else
       std::cout<<"Please use either '-l' for a line count or '-c' for a character count"<<endl;

    //closes the file
    inFile.close();

    return EXIT_SUCCESS;
}

// count lines function, though I note it produces one extra line than does the wc program
int countLines(std::ifstream& inFile)
{

    //initialises the number of lines
    int linecount = 0;

    //confirms that the file opened
    if(inFile.good())
    {
      //iterates through each of the lines
      while(!inFile.eof())
      {
          //increases the count by one every time a new line is found
		  linecount++;
          std::string line;

          //gets the line form the file
          std::getline(inFile, line);
      }
    }

    return linecount;
}

//This was taken from https://stackoverflow.com/questions/34190833/number-of-words-in-a-file-c
int countWords(std::ifstream& inFile)
{
    int count=0;
    for (std::string word; inFile >> word; ++ count) {}
    return count;
}

//This function counts the number of characters in a file
int countCharacters(std::ifstream& inFile)
{
   //initialises the number and a variable to hold the character
   int charcount = 0;
   char c;

   //confirms the file has been read
   if(inFile.good())
   {
      //loops through each of the characters and increases the counter by one
      while(inFile.get(c))
      {
         charcount++;
      }
   }

   return charcount;

}


