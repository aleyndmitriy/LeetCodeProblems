//
//  UserProfileDAOSqliteImpl.cpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.05.23.
//

#include "UserProfileDAOSqliteImpl.hpp"
#include "SQLiteConstants.h"
#import <string>
#import <cstring>
#include "BoostThreadPoolSingleton.hpp"
#include <iostream>
class VariableFirst {
private:
    std::size_t var1;
public:
    VariableFirst(std::size_t var) :var1{ var } { std::cout << "default varfirst" << std::endl; };
    VariableFirst() :VariableFirst{ 0 } {};
    VariableFirst(const VariableFirst& src) :var1{ src.var1 } { std::cout << "copy varfirst crt" << std::endl; };
    VariableFirst& operator=(const VariableFirst& src) {
        std::cout << "copy varfirst assign " << std::endl;
        var1 = src.var1; return *this;
    };
    VariableFirst(VariableFirst&& rhs) noexcept :var1{ std::move(rhs.var1)}  { std::cout << "move varfirst crt" << std::endl; };
    VariableFirst& operator=(VariableFirst&& rhs) noexcept {
        std::cout << "copy varfirst assign " << std::endl;
        var1 = std::move(rhs.var1); return *this; return *this;
    };
    ~VariableFirst() { std::cout << "destructor varfirst" << std::endl; };
    std::size_t GetVal() const { return var1; };
    void SetVal(std::size_t var) { var1 = var; };
};

class VariableSecond {
private:
    std::size_t var2;
public:
    VariableSecond(std::size_t var) :var2{ var } { std::cout << "default varSecond" << std::endl; };
    VariableSecond() :VariableSecond{ 0 } {};
    VariableSecond(const VariableSecond& src) :var2{ src.var2 } { std::cout << "copy varSecond crt" << std::endl; };
    VariableSecond& operator=(const VariableSecond& src) {
        std::cout << "copy varSecond assign " << std::endl;
        var2 = src.var2; return *this;
    };
    VariableSecond(VariableSecond&& rhs) noexcept :var2{ std::move(rhs.var2) } { std::cout << "move varSecond crt" << std::endl; };
    VariableSecond& operator=(VariableSecond&& rhs) noexcept {
        std::cout << "copy varSecond assign " << std::endl;
        var2 = std::move(rhs.var2); return *this; return *this;
    };
    ~VariableSecond() { std::cout << "destructor varSecond" << std::endl; };
    std::size_t GetVal() const { return var2; };
    void SetVal(std::size_t var) { var2 = var; };
};
struct Task1 {
    std::size_t operator()(std::size_t num) {
        std::size_t res{ 0 };
        for (std::size_t index = 0; index < num; ++index)
        {
            ++res;
        }
        return res;
    };
    std::size_t twoArgsRef(VariableFirst& first, VariableSecond& second) {
        std::size_t res{ 0 };
        for (std::size_t index = 0; index < first.GetVal(); ++index)
        {
            ++res;
        }
        second.SetVal(0);
        first.SetVal(0);
        return res;
    };

    std::size_t twoArgsMove(VariableFirst&& first, VariableSecond&& second) {
        std::size_t res{ 0 };
        for (std::size_t index = 0; index < first.GetVal(); ++index)
        {
            ++res;
        }
        second.SetVal(0);
        first.SetVal(0);
        return res;
    };
    std::size_t twoArgsCopy(VariableFirst first, VariableSecond second) {
        std::size_t res{ 0 };
        for (std::size_t index = 0; index < first.GetVal(); ++index)
        {
            ++res;
        }
        second.SetVal(0);
        first.SetVal(0);
        return res;
    };
    std::size_t zeroArgs() {
        std::size_t res{ 0 };
        for (std::size_t t = 0; t < 2560; ++t) {
            res++;
        }
        return res;
    };
    Task1() = default;
    Task1(const Task1& src) { std::cout << "copy constructor" << std::endl; };
    Task1(Task1&& src) noexcept { std::cout << "move constructor" << std::endl; };
};

UserProfileDAOSqliteImpl::UserProfileDAOSqliteImpl(SQLiteDataBase* database):_database(database) {
    
}

UserProfileDAOSqliteImpl::~UserProfileDAOSqliteImpl() {
    _database = nullptr;
}

int UserProfileDAOSqliteImpl::bindUserProfile(sqlite3_stmt* &stmt, const CUserProfileData& user, std::string& databaseError) {
   
    int state = sqlite3_bind_text(stmt,1,user.accessToken,-1,SQLITE_TRANSIENT);
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    if(std::strlen(user.userID) > 1) {
        state = sqlite3_bind_text(stmt,2,user.userID,-1,SQLITE_TRANSIENT);
    } else {
        state = sqlite3_bind_null(stmt, 2);
    }
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    if(std::strlen(user.givenName) > 1) {
        state = sqlite3_bind_text(stmt,3,user.givenName,-1,SQLITE_TRANSIENT);
    } else {
        state = sqlite3_bind_null(stmt, 3);
    }
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    if(std::strlen(user.phone) > 1) {
        state = sqlite3_bind_text(stmt,4,user.phone,-1,SQLITE_TRANSIENT);
    } else {
        state = sqlite3_bind_null(stmt, 4);
    }
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    if(std::strlen(user.email) > 1) {
        state = sqlite3_bind_text(stmt,5,user.email,-1,SQLITE_TRANSIENT);
    } else {
        state = sqlite3_bind_null(stmt, 5);
    }
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    if(std::strlen(user.name) > 1) {
        state = sqlite3_bind_text(stmt,6,user.name,-1,SQLITE_TRANSIENT);
    } else {
        state = sqlite3_bind_null(stmt, 6);
    }
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    if(std::strlen(user.familyName) > 1) {
        state = sqlite3_bind_text(stmt,7,user.familyName,-1,SQLITE_TRANSIENT);
    } else {
        state = sqlite3_bind_null(stmt, 7);
    }
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    state = sqlite3_bind_int(stmt, 8, user.serviceType);
    if(state != SQLITE_OK) {
        _database->GetError(databaseError);
        return state;
    }
    return state;
}

void UserProfileDAOSqliteImpl::SaveUserProfile(const CUserProfileData& user, std::string& err, int& state) {
    std::string query = getFormatingString("INSERT OR REPLACE INTO %s (%s, %s, %s, %s, %s, %s, %s, %s) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", Db_UserProfile_Table, Db_Field_AccessToken, Db_Field_UserId, Db_Field_GivenName, Db_Field_Phone, Db_Field_Email, Db_Field_Name, Db_Field_FamilyName, Db_Field_ServiceType);
    state = _database->StartTransaction(err);
    if(state != SQLITE_OK) {
        state = _database->RollbackTransaction(err);
        return;
    }
    sqlite3_stmt *stmt_save = nullptr;
    state = _database->PrepareSQLquery(query, stmt_save, err);
    if(state != SQLITE_OK || stmt_save == nullptr ) {
        state = _database->RollbackTransaction(err);
        return;
    }
    state = bindUserProfile(stmt_save,user,err);
    if(state != SQLITE_OK) {
        sqlite3_reset(stmt_save);
        sqlite3_finalize(stmt_save);
        state = _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_step(stmt_save);
    if (state != SQLITE_DONE) {
        _database->GetError(err);
        sqlite3_reset(stmt_save);
        sqlite3_finalize(stmt_save);
        _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_reset(stmt_save);
    if(state != SQLITE_OK) {
        _database->GetError(err);
        sqlite3_finalize(stmt_save);
        state = _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_finalize(stmt_save);
    if(state != SQLITE_OK) {
        _database->GetError(err);
        state = _database->RollbackTransaction(err);
        return;
    }
    state = _database->CommitTransaction(err);
    _database->GetError(err);
}

void UserProfileDAOSqliteImpl::GetUserProfile(CUserProfileData& user, std::string& err, int& state, int type) {
    //auto fun = std::bind(&UserProfileDAOSqliteImpl::getUserProfileSync, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    Task1 ts1;
       VariableFirst twolf{ 100 };
       VariableSecond tworf{ 1000 };
    std::size_t threerf{ 100 };
     
    
    
}

int UserProfileDAOSqliteImpl::getUserProfileSync(CUserProfileData& user, std::string& err, int type) {
    std::string query = getFormatingString("SELECT %s, %s, %s, %s, %s, %s, %s, %s FROM %s WHERE %s = ?", Db_Field_AccessToken, Db_Field_UserId, Db_Field_GivenName, Db_Field_Phone, Db_Field_Email, Db_Field_Name, Db_Field_FamilyName, Db_Field_ServiceType, Db_UserProfile_Table, Db_Field_ServiceType);
    sqlite3_stmt *stmt_get = nullptr;
    int state = _database->PrepareSQLquery(query, stmt_get, err);
    if(state != SQLITE_OK) {
        return state;
    }
    state = sqlite3_bind_int(stmt_get, 1, type);
    if(state != SQLITE_OK) {
        sqlite3_reset(stmt_get);
        sqlite3_finalize(stmt_get);
        return state;
    }
    std::memset(&user, '\0', sizeof(CUserProfileData));
    state = fetchUserProfile(stmt_get,user,err);
    if(state != SQLITE_DONE) {
        sqlite3_reset(stmt_get);
        sqlite3_finalize(stmt_get);
        std::memset(&user, '\0', sizeof(CUserProfileData));
        return state;
    }
    state = sqlite3_reset(stmt_get);
    if(state != SQLITE_OK) {
        sqlite3_finalize(stmt_get);
        std::memset(&user, '\0', sizeof(CUserProfileData));
        return state;
    }
    state = sqlite3_finalize(stmt_get);
    if(state != SQLITE_OK) {
        std::memset(&user, '\0', sizeof(CUserProfileData));
    }
    return state;
}

int UserProfileDAOSqliteImpl::fetchUserProfile(sqlite3_stmt* &stmt, CUserProfileData& user, std::string& databaseError) {
    int state = sqlite3_step(stmt);
    if(state != SQLITE_DONE || state != SQLITE_ROW) {
        return state;
    }
    int count = 0;
    while(state == SQLITE_ROW) {
        int fieldNumber = sqlite3_column_count(stmt);
        for(int column = 0; column < fieldNumber; ++column) {
            const char* columnName = sqlite3_column_name(stmt,column);
            if(std::strcmp(columnName, Db_Field_AccessToken)==0) {
                const char* token = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                if(token == nullptr) {
                    return SQLITE_FAIL;
                }
                size_t len = std::strlen(token);
                std::strncpy(user.accessToken, token, len + 1);
            } else if(std::strcmp(columnName, Db_Field_UserId)==0) {
                if (sqlite3_column_type(stmt, column) != SQLITE_NULL) {
                    const char* userId = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                    size_t len = std::strlen(userId);
                    std::strncpy(user.userID, userId, len + 1);
                }
            } else if(std::strcmp(columnName, Db_Field_GivenName)==0) {
                if (sqlite3_column_type(stmt, column) != SQLITE_NULL) {
                    const char* givenName = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                    size_t len = std::strlen(givenName);
                    std::strncpy(user.givenName, givenName, len + 1);
                }
            } else if(std::strcmp(columnName, Db_Field_Phone)==0) {
                if (sqlite3_column_type(stmt, column) != SQLITE_NULL) {
                    const char* phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                    size_t len = std::strlen(phone);
                    std::strncpy(user.phone, phone, len + 1);
                }
            } else if(std::strcmp(columnName, Db_Field_Email)==0) {
                if (sqlite3_column_type(stmt, column) != SQLITE_NULL) {
                    const char* email = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                    size_t len = std::strlen(email);
                    std::strncpy(user.email, email, len + 1);
                }
            } else if(std::strcmp(columnName, Db_Field_Name)==0) {
                if (sqlite3_column_type(stmt, column) != SQLITE_NULL) {
                    const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                    size_t len = std::strlen(name);
                    std::strncpy(user.name, name, len + 1);
                }
            } else if(std::strcmp(columnName, Db_Field_FamilyName)==0) {
                if (sqlite3_column_type(stmt, column) != SQLITE_NULL) {
                    const char* familyName = reinterpret_cast<const char*>(sqlite3_column_text(stmt,column));
                    size_t len = std::strlen(familyName);
                    std::strncpy(user.familyName, familyName, len + 1);
                }
            } else if(std::strcmp(columnName, Db_Field_ServiceType)==0) {
                user.serviceType = sqlite3_column_int(stmt,column);
            }
        }
        state = sqlite3_step(stmt);
        ++count;
    }
    if(state != SQLITE_DONE || state != SQLITE_ROW) {
        return state;
    }
    if(count != 1) {
        return SQLITE_FAIL;
    }
    return state;
}

void UserProfileDAOSqliteImpl::DeleteUserProfile(std::string& err, int& state, int type) {
    std::string query = getFormatingString("DELETE FROM %s WHERE %s = ?", Db_UserProfile_Table, Db_Field_ServiceType);
    state = _database->StartTransaction(err);
    if(state != SQLITE_OK) {
        state = _database->RollbackTransaction(err);
        return;
    }
    sqlite3_stmt *stmt_delete = nullptr;
    state = _database->PrepareSQLquery(query, stmt_delete, err);
    if(state != SQLITE_OK || stmt_delete == nullptr ) {
        state = _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_bind_int(stmt_delete, 1, type);
    if(state != SQLITE_OK) {
        sqlite3_reset(stmt_delete);
        sqlite3_finalize(stmt_delete);
        state = _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_step(stmt_delete);
    if(state != SQLITE_DONE) {
        sqlite3_reset(stmt_delete);
        sqlite3_finalize(stmt_delete);
        state = _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_reset(stmt_delete);
    if(state != SQLITE_OK) {
        sqlite3_finalize(stmt_delete);
        state = _database->RollbackTransaction(err);
        return;
    }
    state = sqlite3_finalize(stmt_delete);
    if(state != SQLITE_OK) {
        state = _database->RollbackTransaction(err);
        return;
    }
    state = _database->CommitTransaction(err);
}
