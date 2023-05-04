#pragma once
#include "Human.h"
class Client :
    public Human
{
private:
    static int IDs;
    int ID;
    static void GenIDs();
    int category;
    int status;
public:
    Client(int, string, string, string, int, int);
    int getIDs(string);
    void set_ID();
    static void SetIDs(int);
    void setID(string);
    void setCategory();
    void toString();

};

