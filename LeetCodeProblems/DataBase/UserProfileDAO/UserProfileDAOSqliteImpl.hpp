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
    UserProfileDAOSqliteImpl(std::shared_ptr<SQLiteDataBase> database);
    int SaveUserProfile(const CUserProfileData& user) override;
    std::optional<CUserProfileData> GetUserProfile(int type) override;
    int DeleteUserProfile(int type) override;
    ~UserProfileDAOSqliteImpl();
private:
    std::shared_ptr<SQLiteDataBase> _database;
    int bindUserProfile(sqlite3_stmt* &stmt, const CUserProfileData& user, std::string& databaseError);
    int getUserProfile(sqlite3_stmt* &stmt, CUserProfileData& user, std::string& databaseError);
};

#endif /* UserProfileDAOSqliteImpl_hpp */
