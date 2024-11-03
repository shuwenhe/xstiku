#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        // 创建驱动
        driver = get_driver_instance();
        // 建立连接
        con = driver->connect("tcp://127.0.0.1:3306", "xstiku", "Xstiku@_00..");
        con->setSchema("xstiku");

        // 创建语句对象
        stmt = con->createStatement();
        // 执行查询
        res = stmt->executeQuery("SELECT * FROM users");

        // 输出结果
        while (res->next()) {
            cout << res->getInt("1") << " - " << res->getString("username") << endl;
        }

        // 清理资源
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "Error: " << e.what() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
        cout << "ErrorCode: " << e.getErrorCode() << endl;
    }

    return 0;
}
