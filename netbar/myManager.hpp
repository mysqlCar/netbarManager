#ifndef MYMANAGER_H
#define MYMANAGER_H

#include <bits/stdc++.h>
#include <winsock.h>
#include <mysql.h>
#include <WinSock2.h>
#include "mysqlTransObj.hpp"
#include <QDebug>

using namespace std;

string ItoS(int x){
    stringstream stream;
    stream << x;
    return stream.str();
}

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

void myManager::setHosts(string hosts){
	this -> hosts = hosts;
}

void myManager::setUserName(string userName){
	this -> userName = userName;
}

void myManager::setPasswd(string passwd){
	this -> passwd = passwd;
}

void myManager::setDBName(string dbName){
	this -> dbName = dbName;
}

void myManager::setPort(unsigned int port){
	this -> port = port;
}

myManager::myManager(string hosts, string userName, string passwd, string dbName, unsigned int port){
    this -> isConnected = 0;
    this -> setHosts(hosts);
	this -> setUserName(userName);
	this -> setPasswd(passwd);
	this -> setDBName(dbName);
	this -> setPort(port);
    mysql_init(&mysqlClient);
    printf("111\n");
}

myManager::~myManager(){
	this -> destroyConnection();
}

bool myManager::getConnectedStatus(){
    if (isConnected){
        cout << "Is Connected to server!" << endl;
        return 1;
    }
    else{
        cout << "Isnt Connected to server!" << endl;
		return 0;
    }
}

int myManager::initConnection(){
	if (getConnectedStatus())
		return 0;
    cout << hosts.c_str() << endl;
    cout << userName.c_str() << endl;
    cout << passwd.c_str() << endl;
    cout << dbName.c_str() << endl;
    cout << port << endl;
    if (mysql_real_connect(&mysqlClient, hosts.c_str(), userName.c_str(), passwd.c_str(), dbName.c_str(), port, NULL, 0)){
        cout <<"Error connected to database: \n" << mysql_error(&mysqlClient) << endl;
		return 1;
    }

    isConnected = true;
    return 0;
}

void myManager::destroyConnection(){
	mysql_close(&mysqlClient);
	this ->isConnected = false;
}

int myManager::Initialization(){
    int flag;
    string mysqlQuery;

	if (!getConnectedStatus())
		return 1;

    mysqlQuery = "drop database if exists internetcafe";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to drop old database!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to drop old database!" << endl;

    mysqlQuery = "create database internetcafe";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to create new database!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to create new database!" << endl;

	flag = mysql_select_db(&mysqlClient, "internetcafe");
	if (flag){
        cout << "Failed to select database!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to select database!" << endl;

	mysqlQuery = "create table Computer\
				(\
					computerID char(10) NOT NULL,\
					computerType char(10),\
					computerStatus int NOT NULL,\
					primary key (computerID)\
				)";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to create table Computer!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to create table Computer!" << endl;

	mysqlQuery = "create table User\
				(\
					userID char(20) NOT NULL,\
					userName char(20),\
					primary key (userID)\
				)";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to create table User!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to create table User!" << endl;

	mysqlQuery = "create table VIP\
				(\
					vipID char(20) NOT NULL,\
					userID char(20),\
					vipRank int,\
					vipBalance int,\
					primary key (vipID),\
					foreign key (userID) references User(userID)\
				)";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to create table VIP!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to create table VIP!" << endl;

	mysqlQuery = "create table UsingRecord\
				(\
					recordID char(20) NOT NULL,\
					computerID char(10) NOT NULL,\
					vipID char(20) NOT NULL,\
					userID char(20) NOT NULL,\
					startTime int,\
					endTime int,\
					primary key (recordID),\
					foreign key (computerID) references Computer(computerID),\
					foreign key (vipID) references VIP(vipID),\
					foreign key (userID) references User(userID)\
				)";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to create table UsingRecord!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to create table UsingRecord!" << endl;

	mysqlQuery = "create table Repairment\
				(\
					repairmentID char(20) NOT NULL,\
					computerID char(10) NOT NULL,\
					repairmentReason char(100) NOT NULL,\
					repairmentDate int NOT NULL,\
					repairmentStatus int NOT NULL,\
					primary key (repairmentID),\
					foreign key (computerID) references Computer(computerID)\
				)";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to create table Repairment!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
    else cout << "Succeed to create table Repairment!" << endl;

	return 0;
}

int myManager::getComputerStatus(string computerID){
	string mysqlQuery;
	MYSQL_RES * result;
	MYSQL_ROW row;
    int flag;

    mysqlQuery = "select computerStatus \
					from Computer \
					where computerID = '" + computerID + "'";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to get computer " + computerID + "'s status" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return -1;
	}

	if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
		return -1;
	}

	if ((row = mysql_fetch_row(result)) != NULL)
        return atoi(row[0]);

	return -1;
}

int myManager::selectComputer(string *computerID, string *computerType, int computerStatus, vector<computer> &Res){
    string mysqlQuery;
    MYSQL_RES * result;
    MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
                    from Computer \
                    where 1";
    if (computerID != NULL)
        mysqlQuery = mysqlQuery + " and computerID = '" + *computerID + "'";
    if (computerType != NULL)
        mysqlQuery = mysqlQuery + " and computerType = '" + *computerType + "'";
    if (computerStatus != -1)
        mysqlQuery = mysqlQuery + " and computerStatus = " + ItoS(computerStatus);

    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to get Computer " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return -1;
    }

    if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
        return -1;
    }

    computer X;
    while ((row = mysql_fetch_row(result)) != NULL){
        X.computerID = row[0];
        X.computerType = row[1];
        X.computerStatus = atoi(row[2]);
        Res.push_back(X);
    }

    return -1;
}

int myManager::abandonComputer(string computerID){
    string mysqlQuery;
    int flag;

    mysqlQuery = "delete from Computer where computerID = '" + computerID + "'";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to abandon the Computer!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
}

int myManager::changeComputerStatus(string computerID, int computerStatus){
    string mysqlQuery;
    int flag;

    mysqlQuery = "update Computer set computerStatus = " + ItoS(computerStatus) +
                    " where computerID = '" + computerID + "'" ;
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to change the computer status + " + computerID << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
}

int myManager::Allocation(string recordID, string computerID, string vipID, string userID, int startTime, int endTime){
    string mysqlQuery;
    int flag;

    mysqlQuery = "insert Into UsingRecord values ('"
					+ recordID + "', '" + computerID + "', '" + vipID + "', '"
					+ userID + "', " + to_string(startTime) + ", " + to_string(endTime) + ")";

    cout << mysqlQuery << endl;

	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to allocation!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::newComputer(string computerID, string computerType){
	string mysqlQuery;
    int flag;

    mysqlQuery = "insert Into Computer values \
					('" + computerID + "', '" + computerType + "', 0)";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to add the computer!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::newVIP(string vipID, string userID, int rechargeAmount){
	string mysqlQuery;
    int flag;

	mysqlQuery = "insert into VIP values ('"
				+ vipID + "', '" + userID + "', 1, " + to_string(rechargeAmount) + ")";

	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to add the VIP card!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::newUser(string userID, string userName){
	string mysqlQuery;
    int flag;

	mysqlQuery = "insert Into User values ('"
				+ userID + "', '" + userName + "')";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to add the User!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::rechargeVIP(string vipID, int rechargeAmount){
	string mysqlQuery;
    int flag;

	mysqlQuery = "update VIP set vipBalance = vipBalance + " + to_string(rechargeAmount) +
					" where vipID = '" + vipID + "'";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to recharge the VIP card + " + vipID << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::newRepairment(string repairmentID, string computerID, int rechargeAmount, string repairmentReason, int repairmentDate){
	string mysqlQuery;
    int flag;

	mysqlQuery = "insert Into Repairment values \
					('" + repairmentID + "', '" + computerID + "', '" + repairmentReason + "', " + to_string(repairmentDate) + ", 0)";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to add the repairment" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::changeRepairmentStatus(string repairmentID, int repairmentStatus){
	string mysqlQuery;
    int flag;

	mysqlQuery = "update Repairment set repairmentStatus = " + to_string(repairmentStatus) +
					" where repairmentID = '" + repairmentID + "'" ;
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to change the repairment status + " + repairmentID << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::abandonVIP(string vipID){
	string mysqlQuery;
    int flag;

	mysqlQuery = "delete from VIP where vipID = '" + vipID + "'";
	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to abandon the VIP card!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return 1;
	}
	return 0;
}

int myManager::selectUsingRecord(string *recordID, string *computerID, string *vipID, string *userID, vector<usingRecord> &Res){
	string mysqlQuery;
	MYSQL_RES * result;
	MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
					from UsingRecord \
					where 1";
    if (recordID != NULL)
        mysqlQuery = mysqlQuery + " and recordID = '" + *recordID + "'";
	if (computerID != NULL)
        mysqlQuery = mysqlQuery + " and computerID = '" + *computerID + "'";
	if (vipID != NULL)
        mysqlQuery = mysqlQuery + " and vipID = '" + *vipID + "'";
	if (userID != NULL)
        mysqlQuery = mysqlQuery + " and userID = '" + *userID + "'";

	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to get usingRecord " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return -1;
	}

	if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
		return -1;
	}

	usingRecord X;
	while ((row = mysql_fetch_row(result)) != NULL){
        X.recordID = row[0];
        X.computerID = row[1];
        X.vipID = row[2];
        X.userID = row[3];
        X.startTime = atoi(row[4]);
        X.endTime = atoi(row[5]);
        Res.push_back(X);
	}

	return -1;
}

int myManager::selectRepairment(string *repairmentID, string *computerID, string *repairmentReason, int repairmentDate, int repairmentStatus, vector<repairment> &Res){
	string mysqlQuery;
	MYSQL_RES * result;
	MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
					from Repairment \
					where 1";
    if (repairmentID != NULL)
        mysqlQuery = mysqlQuery + " and repairmentID = '" + *repairmentID + "'";
	if (computerID != NULL)
        mysqlQuery = mysqlQuery + " and computerID = '" + *computerID + "'";
	if (repairmentReason != NULL)
        mysqlQuery = mysqlQuery + " and repairmentReason = '" + *repairmentReason + "'";
	if (repairmentDate != -1)
        mysqlQuery = mysqlQuery + " and repairmentDate = '" + ItoS(repairmentDate) + "'";
	if (repairmentStatus != -1)
        mysqlQuery = mysqlQuery + " and repairmentStatus = '" + ItoS(repairmentStatus) + "'";

	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to get repairment " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return -1;
	}

	if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
		return -1;
	}

	repairment X;
	while ((row = mysql_fetch_row(result)) != NULL){
        X.repairmentID = row[0];
        X.computerID = row[1];
        X.repairmentReason = row[2];
        X.repairmentDate = atoi(row[3]);
        X.repairmentStatus = atoi(row[4]);
        Res.push_back(X);
	}

	return -1;
}

int myManager::selectVIP(string *vipID, string *userID, int vipRank, vector<vipCard> &Res){
	string mysqlQuery;
	MYSQL_RES * result;
	MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
					from VIP \
					where 1";
    if (vipID != NULL)
        mysqlQuery = mysqlQuery + " and vipID = '" + *vipID + "'";
	if (userID != NULL)
        mysqlQuery = mysqlQuery + " and userID = '" + *userID + "'";
	if (vipRank != -1)
        mysqlQuery = mysqlQuery + " and vipRank = '" + ItoS(vipRank) + "'";

	flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
	if (flag){
        cout << "Failed to get VIP " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
		return -1;
	}

	if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
		return -1;
	}

	vipCard X;

	while ((row = mysql_fetch_row(result)) != NULL){
        X.vipID = row[0];
        X.userID = row[1];
        X.vipBalance = atoi(row[2]);
        X.vipRank = atoi(row[3]);
        Res.push_back(X);
	}

	return -1;
}

#endif
