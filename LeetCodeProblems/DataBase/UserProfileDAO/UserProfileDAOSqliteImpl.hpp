//
//  UserProfileDAOSqliteImpl.hpp
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 10.05.23.
//

#ifndef UserProfileDAOSqliteImpl_hpp
#define UserProfileDAOSqliteImpl_hpp

#include "IUserProfileDAO.hpp"
#include "SQLiteDataBase.hpp"
#import <memory>

class UserProfileDAOSqliteImpl: public IUserProfileDAO
{
public:
    UserProfileDAOSqliteImpl() = delete;
    UserProfileDAOSqliteImpl(const UserProfileDAOSqliteImpl& src) = default;
    UserProfileDAOSqliteImpl& operator=(const UserProfileDAOSqliteImpl& src) = default;
    UserProfileDAOSqliteImpl(UserProfileDAOSqliteImpl&& src) = default;
    UserProfileDAOSqliteImpl& operator=(UserProfileDAOSqliteImpl&& src) = default;
    UserProfileDAOSqliteImpl(SQLiteDataBase* database);
    void SaveUserProfile(const CUserProfileData& user, std::string& err, int& state) override;
    void GetUserProfile(CUserProfileData& user, std::string& err, int& state, int type) override;
    void DeleteUserProfile(std::string& err, int& state, int type) override;
    ~UserProfileDAOSqliteImpl();
private:
    SQLiteDataBase* _database;
    int bindUserProfile(sqlite3_stmt* &stmt, const CUserProfileData& user, std::string& databaseError);
    int fetchUserProfile(sqlite3_stmt* &stmt, CUserProfileData& user, std::string& databaseError);
    int getUserProfileSync(CUserProfileData& user, std::string& err, int type);
};

#endif /* UserProfileDAOSqliteImpl_hpp */
