#ifndef MYMANAGER_H
#define MYMANAGER_H

#include <bits/stdc++.h>
#include <winsock.h>
#include <mysql.h>
#include <WinSock2.h>
#include "mysqlTransObj.hpp"
#include <QDebug>

using namespace std;



class myManager{
	public:

	bool isConnected;
    MYSQL mysqlClient;
    string hosts;
    string userName;
    string passwd;
    string dbName;
    unsigned int port;

	myManager(string hosts, string userName, string passwd, string dbName, unsigned int port);
	~myManager();
	void setUserName(string userName);
	void setHosts(string hosts);
	void setPasswd(string passwd);
	void setDBName(string dbName);
	void setPort(unsigned int port);

	bool getConnectedStatus();
	int initConnection();
	void destroyConnection();
	int Initialization();

    int newComputer(string computerID, string computerType);
    int newUser(string userID, string userName);
    int newVIP(string VIPID, string userID, int rechargeAmount);
    int newRepairment(int repairmentID, string computerID, int repairmentReason, int repairmentDate, int repairmentStatus);
//  int newUsingRecord(int recordID, string computerID, string vipID, string userID);

    int abandonComputer(string computerID);
//  int abandonUser(string userID);
    int abandonVIP(string vipID);
//  int abandontRepairment(int repairmentID);
//  int abandonUsingRecord(int recordID);

    int selectComputer(string *computerID, string *computerType, int computerStatus, vector<computer> &Res);
    int selectUser(string *userID, string *userName, vector<user> &Res);
    int selectVIP(string *vipID, string *userID, int vipRank, vector<vipCard> &Res);
    int selectRepairment(int repairmentID, string *computerID, int repairmentReason, int repairmentDate, int repairmentStatus, vector<repairment> &Res);
    int selectUsingRecord(int recordID, string *computerID, string *vipID, string *userID, vector<usingRecord> &Res);

    int changeComputerStatus(string computerID, int computerStatus);
//  int changeUserName(string userID, string userName);
//  int changeVIP(string vipID, string userID, int vipRank);
    int changeRepairmentStatus(int repairmentID, int repairmentStatus);
//  int changeUsingRecord(int recordID, string computerID, string vipID, string userID);

    int checkVIPNumber(string);
    int getComputerStatus(string computerID);
    int getUserName(string, string &);
    int rechargeVIP(string vipID, int rechargeAmount);
    int Allocation(int recordID, string computerID, string userID, string VIPid, int startTime, int endTime);
    int getMaxRecordID(int &s);
    int getMaxRepairID(int &s);
};



#endif
