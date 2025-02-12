#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int diff(char dif);

int main(){
short int answer = 0,seed = 0,count = 100,hi = 0;
char level = {};
clock_t end_time,start_time;

cout << "\033[30mHello guys. can u provide me a number greater than 100.\n choose difficulty level (E - M - H)\033[0m\n";
cin >> answer >> level;
seed = (answer * 3) / 50;
level = toupper(level);

hi = diff(level);
start_time = clock();
cout << "enter ur answer now\n";

while(answer != seed && count != 0){
cin >> answer;
   
if(answer > seed){
    cout << "too high\n";
    count -=hi;        
}
else if(answer < seed){
    cout << "too low\n";
    count -= hi;
}
}
end_time = clock();
double time_taken = (end_time - start_time) / (double)CLOCKS_PER_SEC;


if(time_taken > 15)
count -=10;
else if(time_taken > 10)
count -=5;

if(count < 0)
    count = 0;

if(count == 0){
cout << "\033[33mgame over.\nhard luck.\033[0m\n";
}else{
cout << "\033[32mCongrats! 🎉 You guessed it right!\033[0m\n";
cout << "\033[30mYour final score is:\033[0m " << count << endl;
    }
}

int diff(char dif){
dif = toupper(dif);

if(dif == 'E')
    return 5;
else if(dif == 'M')
    return 10;
else if(dif == 'H')
    return 20;
else{
    cout << "Invalid difficulty! Defaulting to Medium (10 points per mistake).\n";
    return 10;
    }
}