// Programmers: Colton Wenn, Jon Dale
// CS 3370-001
// Assignment portsetter


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <regex>

using namespace std;


//findLang function
//checks language for proper perameters, changes language if found or makes no changes if not
bool findLang(string& _lang);

//checkLanguage function
//checks for available language translations
bool checkLanguage(string&);

//getLang function
//Purpose: sets program language according to environment's language
void setLang(string&);

// setMessages function
// Purpose: sets output messages according to language
void setMessages(const string language, vector<string>& _msg);

// usage function
// Purpose: outputs proper use of program
void usage(const string language);

// about function
// Purpose: outputs info about programmers
void about(const string language);

// version function
// Purpose: outputs version of program
void version();

// strIsInt function
// Purpose: checks if each char in string is posotive int value
bool strIsInt(const string& str);

// main
// gets port/help flag and port number from command line
int main(int argc, char* args[]) {
    
    const int MAX_PORT = 65535;
    const int MIN_PORT = 1;
    string lang = "es";
    vector<string> msg;
    // regex r("[a-z]{2}|[a-z]{2}_[A-Z]{2}|[a-z]{2}\.UTF-8|[a-z]{2}_[A-Z]{2}\.UTF-8");
    // smatch result;
    // if(regex_search(input,result,r)) {
    //     cout << result.str() << endl;
    // }
    
    
    enum {
        LISTENING_PORT,
        TOO_MANY_ARGS,
        ENV_VAR_DOESNT_EXIST,
        ONLY_INT_VALUE,
        PORT_OUT_RANGE,
        BAD_FLAG,
        BAD_SYNTAX
    };
    
    setLang(lang);
    if(!checkLanguage(lang)) {
        cout << "Error: set language has bad syntax" << endl;
        usage(lang);
        return 666;
    }
    
    // if no arguments after progrm, output error and usage, end program
    if(argc == 1) {
        usage(lang);
        return 0;
    }
    
    setMessages(lang, msg);
    
    // if more than three arguments after program, output error and usage, end program
    if(argc > 4) {
        cout << msg.at(TOO_MANY_ARGS) << endl;
        usage(lang);
        return 666;
    }
    
    string args1 = args[1];
    
    // check if first argument is a port flag
    if(args1 == "-p" || args1 == "--port") {
        
        // if one argument after program, output usage, end program
        if(argc == 2) {
            usage(lang);
            return 0;
        }
        
        // if there are two arguments after program, chech if second argument is int value or -e
        if(argc == 3) {
            string portArg = args[2];
            char* charPtr = args[2];
            
            // check if second argument is an environment flag, set port to PORT
            if(portArg == "-e") {
                charPtr = getenv("PORT");
                string charStr = "";
                if(charPtr != NULL) charStr = charPtr;
                if(charStr == "") {
                    cout << msg.at(ENV_VAR_DOESNT_EXIST) << endl;
                    usage(lang);
                    return 666;
                }
                
                portArg = charStr;
            }
            
            // if port passed isnt int value, output error and usage
            if(!strIsInt(portArg)) {
                cout << msg.at(ONLY_INT_VALUE) << endl;
                usage(lang);
                return 666;
            }

            int portNum = stoi(charPtr);
            
            // if port number isnt in range, end program
            if(portNum < MIN_PORT || portNum > MAX_PORT) {
                cout << msg.at(PORT_OUT_RANGE) << endl;
                usage(lang);
                return 666;
            }
            
            cout << msg.at(LISTENING_PORT) << portNum << endl;
            return 0;
        }
        
        // if there are four arguments, check if second argument is -e, check if third is environment variable
        if(argc == 4) {
            string args2 = args[2];
            string args3 = args[3];
            
            if(args2 != "-e") {
                cout << msg.at(TOO_MANY_ARGS) << endl;
                usage(lang);
                return 666;
            }

            string charStr = "";
            char* charPtr;
            charPtr = getenv(args[3]);
            if(charPtr != NULL) charStr = charPtr;
            if(charStr == "") {
                cout << msg.at(ENV_VAR_DOESNT_EXIST) << endl;
                usage(lang);
                return 666;
            }
                
            string envPortNum = charStr;
            
            if(strIsInt(envPortNum)) {
                int portNum = stoi(charStr);
            
                // if port number isnt in range, end program
                if(portNum < MIN_PORT || portNum > MAX_PORT) {
                    cout << msg.at(PORT_OUT_RANGE) << endl;
                    usage(lang);
                    return 666;
                }
                
                cout << msg.at(LISTENING_PORT) << portNum << endl;
                return 0;
            }
            
        }
        
    }
    
    // if first argument isnt any of the remaining flags, output error and usage, end program
    if(args1 == "-!" || args1 == "--about" || args1 == "-v" || args1 == "--version" || args1 == "-h" || args1 == "--help" || args1 == "-?") {
        // if more than one of the remaining flags, output error and usage, end program
        if(argc > 2) {
            cout << msg.at(TOO_MANY_ARGS) << endl;
            usage(lang);
            return 666;
        }
        
        // check if first argument is a help flag
        if(args1 == "-h" || args1 == "--help" || args1 == "-?") {
            usage(lang);
            return 0;
        }
        
        // check if first argument is a about flag
        if(args1 == "-!" || args1 == "--about") {
            about(lang);
            return 0;
        }
        
        // check if first argument is a version flag
        if(args1 == "-v" || args1 == "--version") {
            version();
            return 0;
        }
    }
    
    cout << msg.at(BAD_FLAG) << endl;
    usage(lang);
    return 666;
}//end main

bool strIsInt(const string& str) {
    int i = 0;
    
    // if first char is negative, set start point to 1
    if(str.at(0) == '-') {
        i = 1;
    }
    
    // check if every char in string is a number, return false if non num, return true if all are numbers
    for(i; i < str.length(); ++i) {
        if(str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    
    return true;
}

void usage(const string language) {
    // output usage information from text file about portsetter
    string str;
    fstream readUsage;
    
    readUsage.open("portsetter.usage_" + language + ".txt");
    
    while(getline(readUsage, str)) {
        cout << str << endl;
    }
    
    readUsage.close();
}

void about(const string language) {
    // output info from text file about the programmers
    string str;
    fstream readAbout;
    
    readAbout.open("portsetter.about_" + language + ".txt");
    
    while(getline(readAbout, str)) {
        cout << str << endl;
    }
    
    readAbout.close();
}

void version() {
    // output version of program
    cout << "Version: 1.3" << endl;
}

void setLang(string& _lang) {
    string langStr = "";
    char* langPtr;
    
    //check's env LANGUAGE
    langPtr = getenv("LANGUAGE");
    if(langPtr != NULL) langStr = langPtr;
    if(langStr != "C" && langStr != "C.UTF-8" && langStr != "") {
        _lang = langPtr;
        return;
    }
    
    //check's env LC_ALL
    langPtr = getenv("LC_ALL");
    if(langPtr != NULL) langStr = langPtr;
    if(langStr != "C" && langStr != "C.UTF-8" && langStr != "") {
        _lang = langPtr;
        return;
    }
    
    //check's env LC_MESSAGES
    langPtr = getenv("LC_MESSAGES");
    if(langPtr != NULL) langStr = langPtr;
    if(langStr != "C" && langStr != "C.UTF-8" && langStr != "") {
        _lang = langPtr;
        return;
    }
    
    //check's env LANG
    langPtr = getenv("LANG");
    if(langPtr != NULL) langStr = langPtr;
    if(langStr != "C" && langStr != "C.UTF-8" && langStr != "") {
        _lang = langPtr;
        return;
    }
    
    // default language
    _lang = "en";
}

bool checkLanguage(string& _lang) {
    string tmpLang = _lang;
    ifstream langFile;
    string language;
    
    langFile.open("langFile.txt");
    
    bool syntax = findLang(_lang);

    while(getline(langFile, language)) {
        
        if(language == _lang) {
            langFile.close();
            return true;
        }
    }
    
    langFile.close();
    cout << "language " << tmpLang << " doesn't exist.  Defaulting to english"<< endl;
    _lang = "en";
    return syntax;
}

void setMessages(const string language, vector<string>& _msg) {
    // output info from text file about the programmers
    string str;
    fstream readAbout;
    
    readAbout.open("strings_" + language + ".txt");
    
    while(getline(readAbout, str)) {
        _msg.push_back(str);
    }

    readAbout.close();
}

bool findLang(string& _lang) {
    int length = _lang.length();
    
    if(_lang.length() >= 2) {
        
        if(_lang.length() > 2 && _lang.at(2) != '.' && _lang.at(2) != '_') {
            return false;
        }
        if(length != 8 && length != 5 && length != 11) {
            return false;
        }
        if(_lang.at(0) < 'a' || _lang.at(0) > 'z' || _lang.at(1) < 'a' || _lang.at(1) > 'z') {
            return false;
        }
        
        string language;
        string location;
        string utf;
        if(length == 8) {
            utf.push_back(_lang[2]);
            utf.push_back(_lang[3]);
            utf.push_back(_lang[4]);
            utf.push_back(_lang[5]);
            utf.push_back(_lang[6]);
            utf.push_back(_lang[7]);
            if(utf != ".UTF-8") {
                return false;
            }
        }
        if(length == 11 || length == 5) {
            location.push_back(_lang[2]);
            location.push_back(_lang[3]);
            location.push_back(_lang[4]);
            if(location.at(0) != '_' || location.at(1) < 'A' || location.at(1) > 'Z' || location.at(2) < 'A' || location.at(2) > 'Z') {
                return false;
            }
            if(length == 11) {
                utf.push_back(_lang[5]);
                utf.push_back(_lang[6]);
                utf.push_back(_lang[7]);
                utf.push_back(_lang[8]);
                utf.push_back(_lang[9]);
                utf.push_back(_lang[10]);
                if(utf != ".UTF-8") {
                    return false;
                }
            }
        }
        language.push_back(_lang[0]);
        language.push_back(_lang[1]);
        _lang = language;
        return true;
    }
    return false;
}