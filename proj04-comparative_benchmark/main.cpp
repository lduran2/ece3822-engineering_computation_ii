#include <iostream>
#include <fstream>

using namespace std;

void sample_load_function(){
    
    string filename_complete = "/data/courses/ece_3822/current/proj_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){


        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split); // band name is everything up till the comma
        line.erase(0,i_split+2); // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // check to make sure it worked
        cout << band_name << " <<- " << song_title << endl;
     cout << song_title << " <<- " << band_name << endl;
    }
    f_id.close();

}

