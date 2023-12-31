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
#import <shared_mutex>
#import <concepts>
#import <future>
class SQLiteDataBase final
{
private:
    std::string databasePath;
    sqlite3* sqliteDatabase;
    int databaseVersion;
    mutable std::shared_mutex smtx;
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
    template<typename... Arguments, std::invocable<Arguments...>Func> typename std::invoke_result<Func, Arguments...>::type getData(Func&& f, Arguments&&... args);
};

template<typename... Arguments, std::invocable<Arguments...>Func> typename std::invoke_result<Func, Arguments...>::type SQLiteDataBase::getData(Func&& f, Arguments&&... args) {
    std::shared_lock<std::shared_mutex> lock(smtx);
    typename std::invoke_result<Func,Arguments...>::type res = f(args...);
    return res;
}
#endif /* SQLiteDataBase_hpp */
