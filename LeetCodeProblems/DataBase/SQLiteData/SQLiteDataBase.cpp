//
//  SQLiteDataBase.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 30.04.23.
//
#include "SQLiteDataBase.hpp"
#include "SQLiteConstants.h"
#include "CUserProfileData.h"

#import <stdexcept>

SQLiteDataBase::SQLiteDataBase(std::string_view basePath):databasePath(basePath),sqliteDatabase(nullptr),databaseVersion(0)
{
    int state = sqlite3_open_v2(databasePath.data(), &sqliteDatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_NOMUTEX, nullptr);
    if(state == SQLITE_OK) {
        sqlite3_stmt *stmt_version = nullptr;
        if (sqlite3_prepare_v2(sqliteDatabase, "PRAGMA user_version;", -1, &stmt_version, nullptr) == SQLITE_OK) {
            while(sqlite3_step(stmt_version) == SQLITE_ROW) {
                databaseVersion = sqlite3_column_int(stmt_version, 0);
            }
        } else {
            std::string err{sqlite3_errmsg(sqliteDatabase)};
            clean();
            throw std::runtime_error { err };
        }
        sqlite3_finalize(stmt_version);
    } else {
        clean();
        state = sqlite3_open_v2(databasePath.data(), &sqliteDatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_CREATE, nullptr);
        if(state != SQLITE_OK) {
            std::string err{sqlite3_errmsg(sqliteDatabase)};
             clean();
             throw std::runtime_error { err };
        }
        std::string err;
        state = createUsersTables(err);
        if(state != SQLITE_OK) {
            throw std::runtime_error { err };
        }
    }
}

SQLiteDataBase::~SQLiteDataBase() {
    clean();
}

void SQLiteDataBase::clean() {
    int state = sqlite3_close_v2(sqliteDatabase);
    if(state == SQLITE_OK) {
        databasePath.clear();
        databaseVersion = 0;
        sqliteDatabase = nullptr;
    }
}

int SQLiteDataBase::createUsersTables(std::string& createError) {
    std::string query = getFormatingString("CREATE TABLE %s IF NOT EXIST (%s TEXT PRIMARY KEY NOT NULL, %s TEXT NULL, %s TEXT NULL, %s TEXT NULL, %s TEXT NULL, %s TEXT NULL, %s TEXT NULL, %s INTEGER NOT NULL, UNIQUE (%s) ON CONFLICT REPLACE) WITHOUT ROWID;", Db_UserProfile_Table, Db_Field_AccessToken, Db_Field_UserId, Db_Field_GivenName, Db_Field_Phone, Db_Field_Email, Db_Field_Name, Db_Field_FamilyName, Db_Field_ServiceType, Db_Field_ServiceType);
    int state = StartTransaction(createError);
    if(state != SQLITE_OK) {
        return state;
    }
    state = sqlite3_exec(sqliteDatabase, query.data(), 0, 0, 0);
    if(state != SQLITE_OK) {
        std::string err{sqlite3_errmsg(sqliteDatabase)};
        createError = err;
        state = RollbackTransaction(err);
        return state;
    }
    state = CommitTransaction(createError);
    return state;
}

int SQLiteDataBase::PrepareSQLquery(const std::string& sql, sqlite3_stmt* &pStmt, std::string& prepareError) {
    pStmt = nullptr;
    int state = sqlite3_prepare_v2(sqliteDatabase, sql.data(), -1, &pStmt, nullptr);
    if(state != SQLITE_OK) {
        std::string err{sqlite3_errmsg(sqliteDatabase)};
        prepareError = err;
    }
    return state;
}

int SQLiteDataBase::StartTransaction(std::string& transactError) {
    int state = sqlite3_exec(sqliteDatabase, "BEGIN TRANSACTION", 0, 0, 0);
    if (state != SQLITE_OK) {
        std::string err{sqlite3_errmsg(sqliteDatabase)};
        transactError = err;
    }
    return state;
}

int SQLiteDataBase::CommitTransaction(std::string& transactError) {
    int state = sqlite3_exec(sqliteDatabase, "COMMIT TRANSACTION", 0, 0, 0);
    if (state != SQLITE_OK) {
        std::string err{sqlite3_errmsg(sqliteDatabase)};
        transactError = err;
    }
    return state;
}

int SQLiteDataBase::RollbackTransaction(std::string& transactError) {
    int state = sqlite3_exec(sqliteDatabase, "ROLLBACK TRANSACTION", 0, 0, 0);
    if (state != SQLITE_OK) {
        std::string err{sqlite3_errmsg(sqliteDatabase)};
        transactError = err;
    }
    return state;
}

void SQLiteDataBase::GetError(std::string& transactError) {
    std::string err{sqlite3_errmsg(sqliteDatabase)};
    transactError = err;
}

