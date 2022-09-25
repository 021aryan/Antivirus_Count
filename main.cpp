#include <iostream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    const char * s = R"(WMIC /Node:localhost /Namespace:\\root\SecurityCenter2 Path AntiVirusProduct Get displayName /Format:List)";
    system(s);

    string data;
    FILE * fp;
    char c[200];
    fp = popen(s, "r");
    while (!feof(fp))
        if (fgets(c, 200, fp) != NULL)
            data.append(c);

    cout<<"The number of virus scanners is = "<<count(data.begin(),data.end(),'=')<<endl;
}
