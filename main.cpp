/*******************************************************************************
 VIGNERE CIPHER
 
 Author: William Santagata
 Date: July 18, 2018
 ******************************************************************************/
 
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void mode_select();
void encrypt_message();
void decrypt_message();
void encrypt_file();
void decrypt_file();
string key_normalization(string keytext);
string encrypt(string plaintext, string key);
string decrypt(string ciphertext, string key);
void print_title();
void print_menu();
void print_border(int style);


int main(void){
    char mode(0);
    
    print_title();
    mode_select();
    
    return 0;
}

void mode_select(){
    char mode(0);
    
    print_border(1);
    print_menu();
    print_border(1);
    cout << endl;
    
    cin >> mode;
    cout << endl;
        
    switch(mode){
        case '1': encrypt_message();  break;
        case '2': decrypt_message();  break;
        case '3': encrypt_file();     break;
        case '4': decrypt_file();     break;
        
        default:
            return;
    }
    
    print_border(3);
    
    return;
}

void encrypt_message(){
    string plaintext("");
    string key("");
    string ciphertext("");
    
    print_border(2);
    cout << "Enter the plaintext message: " << endl;
    print_border(2);
    cin.ignore(); getline(cin, plaintext);
    cout << endl;
    
    print_border(2);
    cout << "Enter the key: " << endl;
    print_border(2);
    getline(cin, key);
    cout << endl;
    
    key = key_normalization(key);
    ciphertext = encrypt(plaintext, key);
    
    print_border(2);
    cout << "The encrypted ciphertext is: " << endl;
    print_border(2);
    cout << ciphertext << endl;
    
    return;
}

void decrypt_message(){
    string plaintext("");
    string key("");
    string ciphertext("");
    
    print_border(2);
    cout << "Enter the ciphertext message: " << endl;
    print_border(2);
    cin.ignore(); getline(cin, ciphertext);
    cout << endl;
    
    print_border(2);
    cout << "Enter the key: " << endl;
    print_border(2);
    getline(cin, key);
    cout << endl;
    
    key = key_normalization(key);
    plaintext = decrypt(ciphertext, key);
    
    print_border(2);
    cout << "The decrypted plaintext is: " << endl;
    print_border(2);
    cout << plaintext << endl;
    
    return;
}

void encrypt_file(){
    ifstream plaintext_file;
    ofstream ciphertext_file;
    string plain_name("");
    string cipher_name("");
    string plaintext("");
    string ciphertext("");
    string key("");
    
    cout << "Enter the file name to encrypt: ";
    cin >> plain_name;
    cout << endl;
    cipher_name = plain_name + "_ciphertext.txt";
    
    plaintext_file.open(plain_name, ios::in);
    while(!plaintext_file.is_open()){
        cout << "Error locating file. Please re-enter the filename: " << endl;
        cin >> plain_name;
    }
    
    print_border(2);
    cout << "Enter the key: " << endl;
    print_border(2);
    cin >> key;
    cout << endl;
     
    key = key_normalization(key);
    
    ciphertext_file.open(cipher_name, ios::out);

    while(getline(plaintext_file, plaintext)){
        ciphertext = "\n" + encrypt(plaintext, key);
        ciphertext_file << ciphertext;
    }
    
    plaintext_file.close();
    ciphertext_file.close();

return;
}

void decrypt_file(){
    ifstream ciphertext_file;
    ofstream plaintext_file;
    string plain_name("");
    string cipher_name("");
    string plaintext("");
    string ciphertext("");
    string key("");
        
    cout << "Enter the file name to decrypt: ";
    cin >> cipher_name;
    cout << endl;
    plain_name = cipher_name + "_plaintext.txt";
        
    ciphertext_file.open(cipher_name, ios::in);
    while(!ciphertext_file.is_open()){
        cout << "Error locating file. Please re-enter the filename: " << endl;
        cin >> cipher_name;
    }
        
    print_border(2);
    cout << "Enter the key: " << endl;
    print_border(2);
    cin >> key;
    cout << endl;
         
    key = key_normalization(key);
        
    plaintext_file.open(plain_name, ios::out);

    while(getline(ciphertext_file, ciphertext)){
        plaintext = "\n" + decrypt(ciphertext, key);
        plaintext_file << plaintext;
    }
        
    plaintext_file.close();
    ciphertext_file.close();

    return;
}

string key_normalization(string keytext){
    for(int i = 0; i < keytext.length(); i++){
        if(!isalpha(keytext[i]))
            keytext.erase(i,1);
    }
    
    for(int i = 0; i < keytext.length(); i++){
        if(keytext[i] == ' ')
            keytext.erase(i,1);
    }
    
    for(int i = 0; i < keytext.length(); i++){
        keytext[i] = toupper(keytext[i]);
    }
    
    return keytext;
}

string encrypt(string plaintext, string key){
    map<char,int> alpha_num;
    alpha_num['A'] = 1;      alpha_num['a'] = 1;
    alpha_num['B'] = 2;      alpha_num['b'] = 2;
    alpha_num['C'] = 3;      alpha_num['c'] = 3;
    alpha_num['D'] = 4;      alpha_num['d'] = 4;
    alpha_num['E'] = 5;      alpha_num['e'] = 5;
    alpha_num['F'] = 6;      alpha_num['f'] = 6;
    alpha_num['G'] = 7;      alpha_num['g'] = 7;
    alpha_num['H'] = 8;      alpha_num['h'] = 8;
    alpha_num['I'] = 9;      alpha_num['i'] = 9;
    alpha_num['J'] = 10;     alpha_num['j'] = 10;
    alpha_num['K'] = 11;     alpha_num['k'] = 11;
    alpha_num['L'] = 12;     alpha_num['l'] = 12;
    alpha_num['M'] = 13;     alpha_num['m'] = 13;
    alpha_num['N'] = 14;     alpha_num['n'] = 14;
    alpha_num['O'] = 15;     alpha_num['o'] = 15;
    alpha_num['P'] = 16;     alpha_num['p'] = 16;
    alpha_num['Q'] = 17;     alpha_num['q'] = 17;
    alpha_num['R'] = 18;     alpha_num['r'] = 18;
    alpha_num['S'] = 19;     alpha_num['s'] = 19;
    alpha_num['T'] = 20;     alpha_num['t'] = 20;
    alpha_num['U'] = 21;     alpha_num['u'] = 21;
    alpha_num['V'] = 22;     alpha_num['v'] = 22;
    alpha_num['W'] = 23;     alpha_num['w'] = 23;
    alpha_num['X'] = 24;     alpha_num['x'] = 24;
    alpha_num['Y'] = 25;     alpha_num['y'] = 25;
    alpha_num['Z'] = 26;     alpha_num['z'] = 26;
    
    map<int, char> num_alpha;
    num_alpha[1]  = 'A';    num_alpha[-25] = 'A';
    num_alpha[2]  = 'B';    num_alpha[-24] = 'B';
    num_alpha[3]  = 'C';    num_alpha[-23] = 'C';
    num_alpha[4]  = 'D';    num_alpha[-22] = 'D';
    num_alpha[5]  = 'E';    num_alpha[-21] = 'E';
    num_alpha[6]  = 'F';    num_alpha[-20] = 'F';
    num_alpha[7]  = 'G';    num_alpha[-19] = 'G';
    num_alpha[8]  = 'H';    num_alpha[-18] = 'H';
    num_alpha[9]  = 'I';    num_alpha[-17] = 'I';
    num_alpha[10] = 'J';    num_alpha[-16] = 'J';
    num_alpha[11] = 'K';    num_alpha[-15] = 'K';
    num_alpha[12] = 'L';    num_alpha[-14] = 'L';
    num_alpha[13] = 'M';    num_alpha[-13] = 'M';
    num_alpha[14] = 'N';    num_alpha[-12] = 'N';
    num_alpha[15] = 'O';    num_alpha[-11] = 'O';
    num_alpha[16] = 'P';    num_alpha[-10] = 'P';
    num_alpha[17] = 'Q';    num_alpha[-9]  = 'Q';
    num_alpha[18] = 'R';    num_alpha[-8]  = 'R';
    num_alpha[19] = 'S';    num_alpha[-7]  = 'S';
    num_alpha[20] = 'T';    num_alpha[-6]  = 'T';
    num_alpha[21] = 'U';    num_alpha[-5]  = 'U';
    num_alpha[22] = 'V';    num_alpha[-4]  = 'V';
    num_alpha[23] = 'W';    num_alpha[-3]  = 'W';
    num_alpha[24] = 'X';    num_alpha[-2]  = 'X';
    num_alpha[25] = 'Y';    num_alpha[-1]  = 'Y';
    num_alpha[26] = 'Z';    num_alpha[0]   = 'Z';
    
    string ciphertext("");
    
    int k(0);
    int i(0);
    bool lowercase(false);
    char c;
    
    for(char p : plaintext){
        
        if(alpha_num.find(p) == alpha_num.end())
            c = p;
        
        else{
            lowercase = islower(p);
            i = alpha_num.find(p)->second;
            i = (i + alpha_num.find(key[k])->second) % 26;
            c = num_alpha.find(i)->second;
            if(lowercase)
                c = tolower(c);
            
            k++;
            if(k >= key.length())
                k = 0;
        }
        
        ciphertext += c;
    }
    
    return ciphertext;
}

string decrypt(string ciphertext, string key){
    map<char,int> alpha_num;
    alpha_num['A'] = 1;      alpha_num['a'] = 1;
    alpha_num['B'] = 2;      alpha_num['b'] = 2;
    alpha_num['C'] = 3;      alpha_num['c'] = 3;
    alpha_num['D'] = 4;      alpha_num['d'] = 4;
    alpha_num['E'] = 5;      alpha_num['e'] = 5;
    alpha_num['F'] = 6;      alpha_num['f'] = 6;
    alpha_num['G'] = 7;      alpha_num['g'] = 7;
    alpha_num['H'] = 8;      alpha_num['h'] = 8;
    alpha_num['I'] = 9;      alpha_num['i'] = 9;
    alpha_num['J'] = 10;     alpha_num['j'] = 10;
    alpha_num['K'] = 11;     alpha_num['k'] = 11;
    alpha_num['L'] = 12;     alpha_num['l'] = 12;
    alpha_num['M'] = 13;     alpha_num['m'] = 13;
    alpha_num['N'] = 14;     alpha_num['n'] = 14;
    alpha_num['O'] = 15;     alpha_num['o'] = 15;
    alpha_num['P'] = 16;     alpha_num['p'] = 16;
    alpha_num['Q'] = 17;     alpha_num['q'] = 17;
    alpha_num['R'] = 18;     alpha_num['r'] = 18;
    alpha_num['S'] = 19;     alpha_num['s'] = 19;
    alpha_num['T'] = 20;     alpha_num['t'] = 20;
    alpha_num['U'] = 21;     alpha_num['u'] = 21;
    alpha_num['V'] = 22;     alpha_num['v'] = 22;
    alpha_num['W'] = 23;     alpha_num['w'] = 23;
    alpha_num['X'] = 24;     alpha_num['x'] = 24;
    alpha_num['Y'] = 25;     alpha_num['y'] = 25;
    alpha_num['Z'] = 26;     alpha_num['z'] = 26;
    
    map<int, char> num_alpha;
    num_alpha[1]  = 'A';    num_alpha[-25] = 'A';
    num_alpha[2]  = 'B';    num_alpha[-24] = 'B';
    num_alpha[3]  = 'C';    num_alpha[-23] = 'C';
    num_alpha[4]  = 'D';    num_alpha[-22] = 'D';
    num_alpha[5]  = 'E';    num_alpha[-21] = 'E';
    num_alpha[6]  = 'F';    num_alpha[-20] = 'F';
    num_alpha[7]  = 'G';    num_alpha[-19] = 'G';
    num_alpha[8]  = 'H';    num_alpha[-18] = 'H';
    num_alpha[9]  = 'I';    num_alpha[-17] = 'I';
    num_alpha[10] = 'J';    num_alpha[-16] = 'J';
    num_alpha[11] = 'K';    num_alpha[-15] = 'K';
    num_alpha[12] = 'L';    num_alpha[-14] = 'L';
    num_alpha[13] = 'M';    num_alpha[-13] = 'M';
    num_alpha[14] = 'N';    num_alpha[-12] = 'N';
    num_alpha[15] = 'O';    num_alpha[-11] = 'O';
    num_alpha[16] = 'P';    num_alpha[-10] = 'P';
    num_alpha[17] = 'Q';    num_alpha[-9]  = 'Q';
    num_alpha[18] = 'R';    num_alpha[-8]  = 'R';
    num_alpha[19] = 'S';    num_alpha[-7]  = 'S';
    num_alpha[20] = 'T';    num_alpha[-6]  = 'T';
    num_alpha[21] = 'U';    num_alpha[-5]  = 'U';
    num_alpha[22] = 'V';    num_alpha[-4]  = 'V';
    num_alpha[23] = 'W';    num_alpha[-3]  = 'W';
    num_alpha[24] = 'X';    num_alpha[-2]  = 'X';
    num_alpha[25] = 'Y';    num_alpha[-1]  = 'Y';
    num_alpha[26] = 'Z';    num_alpha[0]   = 'Z';
    
    string plaintext("");
    
    int k(0);
    int i(0);
    bool lowercase(false);
    char p;
    
    for(char c : ciphertext){
        
        if(alpha_num.find(c) == alpha_num.end())
            p = c;
        
        else{
            lowercase = islower(c);
            i = alpha_num.find(c)->second;
            i = (i - alpha_num.find(key[k])->second) % 26;
            
            p = num_alpha.find(i)->second;
            if(lowercase)
                p = tolower(p);
            
            k++;
            if(k >= key.length())
                k = 0;
        }
        
        plaintext += p;
    }
    
    return plaintext;
}

void print_title(){
    cout << endl << endl;
    cout << "__      ___                              _____ _       _                          " << endl;
    cout << "\\ \\    / (_)             \\\\             / ____(_)     | |                        " << endl;
    cout << " \\ \\  / / _  __ _ _ __   ___ _ __ ___  | |     _ _ __ | |__   ___ _ __           " << endl;
    cout << "  \\ \\/ / | |/ _` | '_ \\ / _ \\ '__/ _ \\ | |    | | '_ \\| '_ \\ / _ \\ '__|    " << endl;
    cout << "   \\  /  | | (_| | | | |  __/ | |  __/ | |____| | |_) | | | |  __/ |              " << endl;
    cout << "    \\/   |_|\\__, |_| |_|\\___|_|  \\___|  \\_____|_| .__/|_| |_|\\___|_|         " << endl;
    cout << "             __/ |                              | |                                " << endl;
    cout << "            |___/                               |_|                                " << endl << endl;
    
    cout << "Vignere Cipher" << endl;
    cout << "(c) 2018 William Santagata" << endl << endl;
    
    cout << "This program will both encrypt and decrypt messages using\nthe Vignere Cipher cryptographic scheme." << endl << endl;
    
    return;
}

void print_menu(){
    cout << endl << "SELECT OPTION:" << endl << endl <<
    "1\tEncrypt Message" << endl <<
    "2\tDecrypt Message" << endl << endl <<
    "3\tEncrypt File"    << endl <<
    "4\tDecrypt File"    << endl << endl <<
    "Q\tQuit" << endl;
    
    return;
}

void print_border(int style){
    if(style == 1){
        cout << " __________________ " << endl
        <<      "====================";
    }
    else if(style == 2)
        cout << "------------------------------" << endl;
    else
        cout << endl << "=======================================================" << endl;

    return;
}
