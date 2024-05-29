#include <iostream>
#include<fstream>
#include<String>
#include<bits/stdc++.h>

using namespace std;

void Solve() {
    map<char, char>mp;
    fstream File;
    fstream File1;
    // read the alphapet letters from the file1
    File.open("Files/file1.txt", ios::in);
    if(File.is_open()){
        string line;
        while (getline(File, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (i == 23) mp[line[23]] = 'A';
                else if(i == 24) mp[line[24]] = 'B';
                else if(i == 25) mp[line[25]] = 'C';
                else {
                    mp[line[i]] = line[i + 3];
                }
            }
        }
        // print the map on the console
        for (auto x : mp) {
            cout << x.first <<" " << x.second << endl;
        }
        File.close();
    }
    // read the message from file2
    File.open("Files/file2.txt", ios::in);
    if (File.is_open()) {
        string line;
        while (getline(File, line)){
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            //print it into file3
            File1.open("Files/File3.txt", ios::out);
            if (File1.is_open()) {
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == ' ') {
                        continue;
                    }
                    File1 << mp[line[i]];
                }
                File1.close();
            }
        }
        File.close();
    }
    File1.open("Files/file3.txt", ios::in);
    if (File1.is_open()) {
        string line;
        while (getline(File1, line)) {
            File.open("Files/file3.txt", ios::app);
            if (File.is_open()) {
                File << endl <<"After Transposition => ";
                string odd = "";
                string even = " ";
                for (int i = 0; i < line.size(); i++) {
                    if ((i + 1) & 1) {
                        odd += line[i];
                        continue;
                    }
                    else {
                        even += line[i];
                        continue;
                    }
                }
                string str = odd + even;
                File << str;
                File.close();
            }
        }
        File.close();
    }
}
int main()
{
    Solve();
    return 0;
}