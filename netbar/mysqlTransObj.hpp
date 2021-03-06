#ifndef MYSQLTRANSOBJ_H
#define MYSQLTRANSOBJ_H

#include <bits/stdc++.h>
#include <QDebug>

using namespace std;

class vipCard{
	public:
    string vipID, userID;
    int vipBalance, vipRank;
    void println(){
        cout << vipID << " " << userID << " " << vipBalance << " " << vipRank <<endl;
    }
};

class computer{
	public:
	string computerID, computerType;
	int computerStatus;
    void println(){
        cout << computerID << " " << computerType << " " << computerStatus <<endl;
    }
};

class user{
	public:
	string userID, userName;
	void println(){
        cout << userID << " " << userName <<endl;
	}
};

class usingRecord{
	public:
    int recordID;
    string computerID, vipID, userID;
	int startTime, endTime;
	void println(){
        cout << recordID << " " << computerID << " " << vipID << " " << userID << " " << startTime << " " << endTime <<endl;
	}
};

class repairment{
	public:
    int repairmentID;
    string computerID;
    int repairmentReason, repairmentDate, repairmentStatus;
	void println(){
        cout << repairmentID << " " << computerID << " " << repairmentReason << " " << repairmentDate << " " << repairmentStatus <<endl;
	}
};

#endif
