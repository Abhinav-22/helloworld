#include<iostream>
using namespace std;

int main()
{
    char c;
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'|| c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        cout<<"it is a vowel";
    }
    else{
        cout<<"it is a consonant";
    }
    return 0;
}