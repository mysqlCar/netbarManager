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
	int getComputerStatus(string computerID);
    int selectComputer(string *computerID, string *computerType, int computerStatus, vector<computer> &Res);
    int changeComputerStatus(string computerID, int computerStatus);
    int abandonComputer(string computerID);
	int Allocation(string recordID, string computerID, string userID, string VIPid, int startTime, int endTime);
	int newComputer(string computerID, string computerType);
	int newUser(string userID, string userName);
	int newVIP(string VIPID, string userID, int rechargeAmount);
	int abandonVIP(string vipID);
	int rechargeVIP(string vipID, int rechargeAmount);
	int newRepairment(string repairmentID, string computerID, int rechargeAmount, string repairmentReason, int repairmentDate);
	int changeRepairmentStatus(string repairmentID, int repairmentStatus);
    int selectUsingRecord(string *recordID, string *computerID, string *vipID, string *userID, vector<usingRecord> &Res);
	int selectRepairment(string *repairmentID, string *computerID, string *repairmentReason, int repairmentDate, int repairmentStatus, vector<repairment> &Res);
	int selectVIP(string *vipID, string *userID, int vipRank, vector<vipCard> &Res);
};



#endif
