#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Div_inf {
private:
    unsigned long long host;
    unsigned long long money;
    unsigned long long caller;
public:
    Div_inf(): caller(0), host(0), money(0) { }
    friend std::ifstream& operator >> (std::ifstream &file, Div_inf &line){
        std::string s;
        line.caller = 0;
        line.host = 0;
        line.money = 0;
        std::getline(file,s,',');
        for(char i : s){
            line.caller=line.caller*10;
            line.caller+=(i - '0');
        }
        std::getline(file,s,',');
        for(char i : s){
            line.host=line.host*10;
            line.host+=(i - '0');
        }
        std::getline(file,s);
        for(char i : s){
            line.money=line.money*10;
            line.money+=(i - '0');
        }
        return file;
    }

    unsigned long long give_caller() const{
        return caller;
    }

    unsigned long long give_host() const{
        return host;
    }

    unsigned long long give_money() const{
        return money;
    }
};

class sbscriber{
private:
    unsigned long long number;
    unsigned long long money;
public:
    sbscriber(): number(0), money(0) { }
    friend std::ofstream& operator << (std::ofstream &out, const sbscriber &sb){
        out << sb.number << " " << sb.money<<std::endl;
        return out;
    }

    friend std::ostream& operator << (std::ostream &out, const sbscriber &sb){
        out << sb.number << " " << sb.money<<std::endl;
        return out;
    }

    friend void operator +=(sbscriber &mp, const sbscriber &sb){
        mp.money += sb.money;
    }

    friend bool operator >(sbscriber &mp, const sbscriber &sb){
        if (mp.money > sb.money)
            return true;
        else
            return false;
    }

    void get_info (const Div_inf& string){
        number = string.give_caller();
        money = string.give_money();
    }
};

int main(){
    std::ifstream file;
    file.open("input_file.txt");
    std::ofstream outfile;
    outfile.open("output.txt");
    Div_inf line;
    sbscriber sb;
    sbscriber max;
    std::map<unsigned long long, sbscriber> mp;

    while (file){
        file >> line;
        sb.get_info(line);

        if (mp.count(line.give_caller())){
            mp[line.give_caller()] += sb;
        }
        else{
            mp[line.give_caller()] = sb;
        }
    }

    for (auto &i : mp){
        if (i.second > max){
            max = i.second;
        }
    }

    outfile << max;
    std::cout << max;

    file.close();
    outfile.close();
    return 0;
}
