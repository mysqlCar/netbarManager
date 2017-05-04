#include "myManager.hpp"

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
                    recordID int NOT NULL,\
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
                    repairmentID int NOT NULL,\
                    computerID char(10) NOT NULL,\
                    repairmentReason int NOT NULL,\
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

    cout << "Complete!" << endl;

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

int myManager::newRepairment(int repairmentID, string computerID, int repairmentReason, int repairmentDate, int repairmentStatus){
    string mysqlQuery;
    int flag;

    mysqlQuery = "insert Into Repairment values \
                    ('" + to_string(repairmentID) + "', '" + computerID + "', '" + to_string(repairmentReason) + "', '" + to_string(repairmentDate) + "', '" + to_string(repairmentStatus) + "')";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to add the repairment" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
}

int myManager::newUsingRecord(int recordID, string computerID, string vipID, string userID, int startTime, int endTime){
    string mysqlQuery;
    int flag;

    mysqlQuery = "insert Into UsingRecord values \
                    ('" + to_string(recordID) + "', '" + computerID + "', '" + vipID + "', " + userID + ", " + to_string(startTime) + ", " + to_string(endTime) + ")";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to add the repairment" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
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

int myManager::abandonUser(string userID){
    string mysqlQuery;
    int flag;

    mysqlQuery = "delete from User where userID = '" + userID + "'";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to abandon the User!" << endl;
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

int myManager::abandonRepairment(int repairmentID){
    string mysqlQuery;
    int flag;

    mysqlQuery = "delete from Repairment where repairmentID = '" + to_string(repairmentID) + "'";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to abandon the Repairment!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
}

int myManager::abandonUsingRecord(int recordID){
    string mysqlQuery;
    int flag;

    mysqlQuery = "delete from UsingRecord where recordID = '" + to_string(recordID) + "'";
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to abandon the UsingRecord!" << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
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
        mysqlQuery = mysqlQuery + " and computerStatus = " + to_string(computerStatus);

    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to get Computer " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }

    if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
        return 1;
    }

    computer X;
    while ((row = mysql_fetch_row(result)) != NULL){
        X.computerID = row[0];
        X.computerType = row[1];
        X.computerStatus = atoi(row[2]);
        Res.push_back(X);
    }

    return 0;
}

int myManager::selectUser(string *userID, string *userName, vector<user> &Res){
    string mysqlQuery;
    MYSQL_RES * result;
    MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
                    from User \
                    where 1";
    if (userID != NULL)
        mysqlQuery = mysqlQuery + " and userID = '" + *userID + "'";
    if (userName != NULL)
        mysqlQuery = mysqlQuery + " and userName = '" + *userName + "'";

    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to get User " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }

    if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
        return 1;
    }

    user X;

    while ((row = mysql_fetch_row(result)) != NULL){
        X.userID = row[0];
        X.userName = row[1];
        Res.push_back(X);
    }

    return 0;
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
        mysqlQuery = mysqlQuery + " and vipRank = '" + to_string(vipRank) + "'";

    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to get VIP " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }

    if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
        return 1;
    }

    vipCard X;

    while ((row = mysql_fetch_row(result)) != NULL){
        X.vipID = row[0];
        X.userID = row[1];
        X.vipBalance = atoi(row[2]);
        X.vipRank = atoi(row[3]);
        Res.push_back(X);
    }

    return 0;
}

int myManager::selectRepairment(int repairmentID, string *computerID, int repairmentReason, int repairmentDate, int repairmentStatus, vector<repairment> &Res){
    string mysqlQuery;
    MYSQL_RES * result;
    MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
                    from Repairment \
                    where 1";
    if (repairmentID != -1)
        mysqlQuery = mysqlQuery + " and repairmentID = '" + to_string(repairmentID) + "'";
    if (computerID != NULL)
        mysqlQuery = mysqlQuery + " and computerID = '" + *computerID + "'";
    if (repairmentReason != -1)
        mysqlQuery = mysqlQuery + " and repairmentReason = '" + to_string(repairmentReason) + "'";
    if (repairmentDate != -1)
        mysqlQuery = mysqlQuery + " and repairmentDate = '" + to_string(repairmentDate) + "'";
    if (repairmentStatus != -1)
        mysqlQuery = mysqlQuery + " and repairmentStatus = '" + to_string(repairmentStatus) + "'";

    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());

    if (flag){
        cout << "Failed to get repairment " << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }

    if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
        return 1;
    }

    repairment X;
    while ((row = mysql_fetch_row(result)) != NULL){
        X.repairmentID = atoi(row[0]);
        X.computerID = row[1];
        X.repairmentReason = atoi(row[2]);
        X.repairmentDate = atoi(row[3]);
        X.repairmentStatus = atoi(row[4]);
        Res.push_back(X);
    }

    return 0;
}

int myManager::selectUsingRecord(int recordID, string *computerID, string *vipID, string *userID, vector<usingRecord> &Res){
    string mysqlQuery;
    MYSQL_RES * result;
    MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * \
                    from UsingRecord \
                    where 1";
    if (recordID != -1)
        mysqlQuery = mysqlQuery + " and recordID = '" + to_string(recordID) + "'";
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
        return 1;
    }

    if ((result = mysql_store_result(&mysqlClient)) == NULL){
        cout << "Failed to save result\n";
        return 1;
    }

    usingRecord X;
    while ((row = mysql_fetch_row(result)) != NULL){
        X.recordID = atoi(row[0]);
        X.computerID = row[1];
        X.vipID = row[2];
        X.userID = row[3];
        X.startTime = atoi(row[4]);
        X.endTime = atoi(row[5]);
        Res.push_back(X);
    }

    return 0;
}

bool myManager::checkVIPNumber(string vipID)
{
    vector<vipCard> Res;
    Res.clear();
    int flag = selectVIP(&vipID, NULL, -1, Res);
    return (Res.size() > 0) & (flag == 0);
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

int myManager::changeComputerStatus(string computerID, int computerStatus){
    string mysqlQuery;
    int flag;

    mysqlQuery = "update Computer set computerStatus = " + to_string(computerStatus) +
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

int myManager::Allocation(int recordID, string computerID, string vipID, string userID, int startTime, int endTime){
    string mysqlQuery;
    int flag;

    mysqlQuery = "insert Into UsingRecord values ('"
                    + to_string(recordID) + "', '" + computerID + "', '" + vipID + "', '"
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

int myManager::getUserName(string userID, string &userName)
{
    string mysqlQuery;
    MYSQL_RES * result;
    MYSQL_ROW row;
    int flag;

    mysqlQuery = "select * from User where userID = ";
    mysqlQuery = mysqlQuery + userID;
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

    row = mysql_fetch_row(result);
    if (row != NULL)
    {
        userName = row[1];
    }
    else
        return -1;
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

int myManager::changeRepairmentStatus(int repairmentID, int repairmentStatus){
    string mysqlQuery;
    int flag;

    mysqlQuery = "update Repairment set repairmentStatus = " + to_string(repairmentStatus) +
                    " where repairmentID = '" + to_string(repairmentID) + "'" ;
    flag = mysql_real_query(&mysqlClient, mysqlQuery.c_str(), mysqlQuery.length());
    if (flag){
        cout << "Failed to change the repairment status + " + to_string(repairmentID) << endl;
        cout << "Error Messege:" << endl;
        cout << mysql_error(&mysqlClient) <<endl << endl;
        return 1;
    }
    return 0;
}

int myManager::getMaxRecordID(int &s){
    vector<usingRecord> Res;
    Res.clear();
    int flag = myManager::selectUsingRecord(-1, NULL, NULL, NULL, Res);
    int len = Res.size();
    s = -1;
    for (int i = 0; i < len; i++)
        if (s < Res[i].recordID)
            s = Res[i].recordID;
    return flag;
}

int myManager::getMaxRepairID(int &s){
    vector<repairment> Res;
    Res.clear();
    int flag = myManager::selectRepairment(-1, NULL, -1, -1, -1, Res);
    int len = Res.size();
    cout << len << endl;
    s = -1;
    for (int i = 0; i < len; i++)
        if (s < Res[i].repairmentID)
            s = Res[i].repairmentID;
    return flag;
}
