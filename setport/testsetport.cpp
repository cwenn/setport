// Programmers: Colton Wenn, Jon Dale
// CS 3370-001
// Assignment testportsetter


#include<iostream>
#include<fstream>

using namespace std;


int main() {

    cout << "\nTesting all English cases//////////////////////////////////////////////////////////////////////////\n" << endl;
    
    //positive tests
    cout << "--------------Testing for unavailable env language (no parameters)---------------" << endl;
    if(system("LANGUAGE=fr ./portsetter.cpp.o >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/badLangFrNoParam.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "-------------------- Testing for -? parameter ------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -? >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }

    
    cout << "------------------------ Testing for -! parameter ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o  -! >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/about_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------ Testing for --about parameter ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o  --about >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/about_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    
    cout << "------------------------ Testing for -v parameter ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o  -v >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/version.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    
    cout << "------------------------ Testing for --version parameter ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o  --version >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/version.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
        
    
    cout << "------------------------ Testing for -e parameter ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p -e >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPortEnv_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
        
    cout << "---------------- Testing for -e PORT (valid PORT value) parameter ---------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p -e PORT >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPortEnv_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------ Testing for -e pORT parameter ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p -e pORT >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/envNotExist_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------ Testing for no parameters ----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------------------Testing for -h flag----------------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -h >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------Testing for --help flag--------------------------" << endl;
    if((system("LANGUAGE=en ./portsetter.cpp.o --help >test.txt")) == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "----------------Testing for valid ranges using -p flag-------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p 4040 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPort_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------Testing for valid ranges using --port flag-----------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o --port 4040 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPort_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
  
    // Negative Tests--------------------------------------------------------------------------------------------------------------------------
    
    cout << "---------------- Testing for bad env language syntax ---------------" << endl;
    if(system("LANGUAGE=fs_EHh ./portsetter.cpp.o -p -e >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/badLangSyntax_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "---------------- Testing for -e PORT (PORT of range) parameter ---------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p -e PORT_OUT_RANGE >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/envNotExist_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "-------------------Testing for invalid help flag-------------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o help >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "----------------------------- Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------Testing for invalid -help flag-------------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -help >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------------Testing for invalid --h flag--------------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o --h >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_en.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------Testing for too many help flags -h --help -------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -h --help >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/tooManyArgs_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------------Testing for invalid -hs flag---------------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -hs >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "----------Testing for too many port flags and too many arguments-----------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p --port 9 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/tooManyArgs_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "------------Testing for too many consecutive port arguments----------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p 77 33 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/tooManyArgs_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "-------------------Testing for negative range value-----------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p -21 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/outOfRange_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "-----------------------Testing for 0 port value---------------------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p 0 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/outOfRange_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "--------------Testing for port range above max port value-----------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -p 90642 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/outOfRange_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "---------Testing for valid ranges using -x flag with valid port-----------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -x 45321 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------Testing for invalid -P flag with valid port---------------" << endl;
    if(system("LANGUAGE=en ./portsetter.cpp.o -P 714 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_en.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    
    cout << "\nTesting all Spanish cases//////////////////////////////////////////////////////////////////////////\n" << endl;
    
    //positive tests
    cout << "-------------------- Testing for -? parameter ------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -? >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }

    
    cout << "------------------------ Testing for -! parameter ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o  -! >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/about_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------ Testing for --about parameter ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o  --about >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/about_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    
    cout << "------------------------ Testing for -v parameter ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o  -v >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/version.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    
    cout << "------------------------ Testing for --version parameter ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o  --version >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/version.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
        
    
    cout << "------------------------ Testing for -e parameter ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p -e >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPortEnv_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
        
    cout << "---------------- Testing for -e PORT (valid PORT value) parameter ---------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p -e PORT >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPortEnv_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------ Testing for -e pORT parameter ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p -e pORT >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/envNotExist_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------ Testing for no parameters ----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------------------Testing for -h flag----------------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -h >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------------Testing for --help flag--------------------------" << endl;
    if((system("LANGUAGE=es ./portsetter.cpp.o --help >test.txt")) == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/usage_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "----------------Testing for valid ranges using -p flag-------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p 4040 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPort_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------Test: Failed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------Testing for valid ranges using --port flag-----------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o --port 4040 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        if(system("diff test.txt testText/listeningPort_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        cout << "------------------------------ Test: Failed ------------------------------\n\n" << endl;
    }
  
    // Negative Tests--------------------------------------------------------------------------------------------------------------------------
    
    cout << "---------------- Testing for -e PORT (PORT of range) parameter ---------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p -e PORT_OUT_RANGE >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/envNotExist_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "-------------------Testing for invalid help flag-------------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o help >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "----------------------------- Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "------------------Testing for invalid -help flag-------------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -help >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------------Testing for invalid --h flag--------------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o --h >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_es.txt") == 0) {
            cout << "Expected output" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------Testing for too many help flags -h --help -------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -h --help >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/tooManyArgs_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------------Testing for invalid -hs flag---------------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -hs >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "----------Testing for too many port flags and too many arguments-----------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p --port 9 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/tooManyArgs_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "------------Testing for too many consecutive port arguments----------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p 77 33 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/tooManyArgs_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "-------------------Testing for negative range value-----------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p -21 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/outOfRange_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "-----------------------Testing for 0 port value---------------------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p 0 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/outOfRange_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "--------------Testing for port range above max port value-----------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -p 90642 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/outOfRange_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
        
    cout << "---------Testing for valid ranges using -x flag with valid port-----------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -x 45321 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }
    
    cout << "--------------Testing for invalid -P flag with valid port---------------" << endl;
    if(system("LANGUAGE=es ./portsetter.cpp.o -P 714 >test.txt") == 0) {
        cout << "Portsetter: Passed" << endl;
        cout << "------------------------------ Test: Failed -----------------------------\n\n" << endl;
    }
    else {
        cout << "Portsetter: Failed" << endl;
        if(system("diff test.txt testText/invalidFlag_es.txt") == 0) {
            cout << "Expected ouput" << endl;
        }
        else {
            cout << "Unexpected output" << endl;
        }
        cout << "------------------------------ Test: Passed ------------------------------\n\n" << endl;
    }

    return 0;
}