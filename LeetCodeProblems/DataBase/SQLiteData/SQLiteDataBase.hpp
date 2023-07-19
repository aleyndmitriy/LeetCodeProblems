//
//  SQLiteDataBase.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 30.04.23.
//

#ifndef SQLiteDataBase_hpp
#define SQLiteDataBase_hpp

#import <sqlite3.h>
#import <string>
#import <memory>
#include "CPPUtils.hpp"

class SQLiteDataBase final
{
private:
    std::string databasePath;
    sqlite3* sqliteDatabase;
    int databaseVersion;
    void clean();
    int createUsersTables(std::string& createError);
public:
    SQLiteDataBase(std::string_view basePath);
    SQLiteDataBase(const SQLiteDataBase&)= delete;
    SQLiteDataBase& operator=(const SQLiteDataBase&)= delete;
    SQLiteDataBase(const SQLiteDataBase&&)= delete;
    SQLiteDataBase& operator=(const SQLiteDataBase&&)= delete;
    ~SQLiteDataBase();
    int PrepareSQLquery(const std::string& sql, sqlite3_stmt* &pStmt, std::string& prepareError);
    int StartTransaction(std::string& transactError);
    int CommitTransaction(std::string& transactError);
    int RollbackTransaction(std::string& transactError);
    void GetError(std::string& transactError);
};
#endif /* SQLiteDataBase_hpp */
